from html.entities import codepoint2name
from itertools import count
from operator import imod
from os import name
from types import resolve_bases
from flask import Blueprint, json, render_template, request, jsonify
from flask_login import login_required
from applications.common.curd import model_to_dicts, enable_status, disable_status, get_one_by_id
from applications.common.helper import ModelFilter
from applications.common.utils.http import table_api, success_api, fail_api
from applications.common.utils.rights import authorize
from applications.common.utils.validate import xss_escape
from applications.extensions import db
from applications.models import Role, Power, User
from applications.schemas import RoleOutSchema, PowerOutSchema2

admin_role = Blueprint('adminRole', __name__, url_prefix = '/admin/role')

@admin_role.get('/')
@authorize("admin:role:main", log = True)
def main():
  return render_template('admin/role/main.html')

@admin_role.get('/data')
@authorize("admin:role:main", log = True)
def table():
  role_name = xss_escape(request.args.get('roleName', type = str))
  role_code = xss_escape(request.args.get('roleName', type = str))
  mf = ModelFilter()
  if role_name:
    mf.vague(field_name = 'name', value = role_name)
  if role_code:
    mf.vague(field_name = 'code', value = role_code)
  role = Role.query.filter(mf.get_filter(Role)).layui_paginate()
  count = role.total
  return table_api(data = model_to_dicts(schema = RoleOutSchema, data = role.items), count = count)

@admin_role.get('/add')
@authorize("admin:role:add", log = True)
def add():
  return render_template('admin/role/add.html')

@admin_role.post('/save')
@authorize("admin:role:add", log = True)
def save():
  req = request.json
  details = xss_escape(req.get('details'))
  enable = xss_escape(req.get('enable'))
  roleCode = xss_escape(req.get('roleCode'))
  roleName = xss_escape(req.get('roleName'))
  sort = xss_escape(req.get('sort'))
  role = Role(
    details = details,
    enable = enable,
    code = roleCode,
    name = roleName,
    sort = sort
  )
  db.session.add(role)
  db.session.commit()
  return success_api(msg = '??????')

@admin_role.get('/power/<int:_id>')
@authorize("admin:role:power", log = True)
def power(_id):
  return render_template('admin/role/power.html', id = _id)

@admin_role.get('/getRolePower/<int:id>')
@authorize("admin:role:main", log = True)
def get_role_power(id):
  role = Role.query.filter_by(id = id).first()
  check_powers = role.power
  check_powers_list = []
  for cp in check_powers:
    check_powers_list.append(cp.id)
  powers = Power.query.all()
  power_schema = PowerOutSchema2(many = True)
  output = power_schema.dump(powers)
  for i in output:
    if int(i.get('powerId') in check_powers_list):
      i['checkArr'] = '1'
    else:
      i['checkArr'] = '0'
  res = {
    'data': output,
    'status': {'code': 200, 'message': '??????'}
  }
  return jsonify(res)

@admin_role.put('/saveRolePower')
@authorize("admin:role:edit", log = True)
def save_role_power():
  req_form = request.form
  power_ids = request.get('powerIds')
  power_list = power_ids.split(',')
  role_id = req_form.get('roleId')
  role = Role.query.filter_by(id = role_id).first()

  powers = Power.query.filter(Power.id.in_(power_list)).all()
  role.power = powers

  db.session.commit()
  return success_api(msg = '????????????')

@admin_role.get('/edit/<int:id>')
@authorize("admin:role:edit", log = True)
def edit(id):
  r = get_one_by_id(model = Role, id = id)
  return render_template('admin/role/edit.html', role = r)

@admin_role.put('/update')
@authorize("admin:role:edit", log = True)
def update():
  req_json = request.json
  id = req_json.get('roleId')
  data = {
    'code': xss_escape(req_json.get('roleCode')),
    'name': xss_escape(req_json.get('roleName')),
    'sort': xss_escape(req_json.get('sort')),
    'enable': xss_escape(req_json.get('enable')),
    'details': xss_escape(req_json.get('details'))
  }
  role = Role.query.filter_by(id = id).update(data)
  db.session.commit()
  if not role:
    return fail_api(msg = '??????????????????')
  return success_api(msg = '??????????????????')

@admin_role.put('/enable')
@authorize("admin:role:edit", log = True)
def enable():
  id = request.json.get('roleId')
  if id:
    res = enable_status(Role, id)
    if not res:
      return fail_api(msg = '?????????')
    return success_api(msg = '????????????')
  return fail_api(msg = '????????????')

@admin_role.put('/disable')
@authorize("admin:role:edit", log = True)
def dis_enable():
  _id = request.json.get('roleId')
  if _id:
    res = disable_status(Role, _id)
    if not res:
      return fail_api(msg = '?????????')
    return success_api(msg = '????????????')
  return fail_api(msg = '????????????')

@admin_role.delete('/remove/<int:id>')
@authorize("admin:role:remove", log = True)
def remove(id):
  role = Role.query.filter_by(id = id).first()
  role.power = []
  role.user = []
  r = Role.query.filter_by(id = id).delete()
  db.session.commit()
  if not r:
    return fail_api(msg = '??????????????????')
  return success_api(msg = '??????????????????')

@admin_role.delete('/batchRemove')
@authorize("admin:role:remove", log = True)
@login_required
def batch_remove():
  ids = request.form.getlist('ids[]')
  for id in ids:
    role = Role.query.filter_by(id = id).first()
    role.power = []
    role.user = []
    r = Role.query.filter_by(id = id).delete()
    db.session.commit()
  return success_api(msg = '??????????????????')
