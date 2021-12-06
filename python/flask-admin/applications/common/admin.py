import copy
from collections import OrderedDict
from io import BytesIO
from flask import session, make_response, current_app
from flask_login import current_user

from applications.common.utils.gen_captcha import gen_captcha
from applications.schemas import PowerOutSchema

def add_auth_session():
  role = current_user.role
  user_power = []
  for i in role:
    if i.enable == 0:
      continue
    for p in i.power:
      if p.enable == 0:
        continue
      user_power.append(p.code)
  session['permissions'] = user_power

def make_menu_tree():
  role = current_user.role
  powers = []
  for i in role:
    if i.enable == 0:
      continue
    for p in i.power:
      if p.enable == 0:
        continue
      if int(p.type) == 0 or int(p.type) == 1:
        powers.append(p)
  power_chema = PowerOutSchema(many = True)
  power_dict = power_chema.dump(powers)
  power_dict.sort(key = lambda x: x['id'], reverse = True)

  menu_dict = OrderedDict()
  for _dict in power_dict:
    if _dict['id'] in menu_dict:
      _dict['children'] = copy.deepcopy(menu_dict[_dict['id']])
      _dict['children'].sort(key = lambda item: item['sort'])
      del menu_dict[_dict['id']]
    
    if _dict['parent_id'] not in menu_dict:
      menu_dict[_dict['parent_id']] = [_dict]
    else:
      menu_dict[_dict['parent_id']].append(_dict)
  return sorted(menu_dict.get(0), key = lambda item: item['sort'])

# 生成验证码
def get_captcha():
  code, image = gen_captcha()
  out = BytesIO()
  session['code'] = code
  image.save(out, 'png')
  out.seek(0)
  resp = make_response(out.read())
  resp.content_type = 'image/png'
  return resp, code

def get_render_config():
  config = dict(logo = {
    'title': current_app.config.get('SYSTEM_NAME'),
    'image': '/static/admin/admin/images/logo.png'
  }, menu = {
    'data': '/rights/menu',
    'collaspe': False,
    'accordion': True,
    'method': 'GET',
    'control': False,
    'controlWidth': 500,
    'select': '0',
    'async': True
  }, tab = {
    'enable': True,
    'keepState': True,
    'session': True,
    'max': 30,
    'index': {
      'id': '10',
      'href': '/admin/welcome',
      'title': '首页'
    }
  }, theme = {
    'defaultColor': '2',
    'defaultMenu': 'dark-theme',
    'allowCustom': True
  }, colors = [
    {
      'id': '1',
      'color': '#2d8cf0'
    },
    {
      'id': '2',
      'color': '#5FB878'
    },
    {
      'id': '3',
      'color': '#1E9FFF'
    },
    {
      'id': '4',
      'color': 'FFB800'
    },
    {
      'id': '5',
      'color': 'darkgray'
    }
  ], links = current_app.config.get('SYSTEM_PANEL_LINKS')
   , other = {
     'keepLoad': 200,
     'autoHead': False
   }, header = False)
  return config