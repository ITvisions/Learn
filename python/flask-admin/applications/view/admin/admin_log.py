from flask import Blueprint, request, render_template
from sqlalchemy import desc, schema
from applications.common.utils.http import table_api
from applications.common.utils.rights import authorize
from applications.models import AdminLog
from applications.schemas import LogOutSchema
from applications.common.curd import model_to_dicts

admin_log = Blueprint('adminLog', __name__, url_prefix = '/admin/log')

@admin_log.get('/')
@authorize("admin:log:main")
def index():
  return render_template('admin/admin_log/main.html')

@admin_log.get('loginLog')
@authorize("admin:log:main")
def login_log():
  log = AdminLog.query.filter_by(url='/passport/login').order_by(desc(AdminLog.create_time)).layui_paginate()
  count = log.total
  return table_api(data = model_to_dicts(schema = LogOutSchema, data = log.items), count = count)

@admin_log.get('/operateLog')
@authorize("admin:log:main")
def operate_log():
  log = AdminLog.query.filter(
    AdminLog.url != '/passport/login'
  ).order_by(
    desc(AdminLog.create_time)
  ).layui_paginate()
  count = log.total
  return table_api(data = model_to_dicts(schema = LogOutSchema, data = log.items), count = count)
