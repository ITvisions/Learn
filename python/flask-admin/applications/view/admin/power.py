from flask import Blueprint, render_template, request, jsonify
from flask_marshmallow import schema
from applications.common import curd
from applications.common.utils.http import success_api, fail_api
from applications.common.utils.rights import authorize
from applications.common.utils.validate import xss_escape
from applications.extensions import db
from applications.models import Power
from applications.schemas import PowerOutSchema2

admin_power = Blueprint('adminPower', __name__, url_prefix = '/admin/power')

@admin_power.get('/')
@authorize("admin:power:main", log = True)
def index():
  return render_template('admin/power/main.html')

@admin_power.post('/data')
@authorize("admin:power:main", log = True)
def data():
  power = Power.query.all()
  res = {
    "data": curd.model_to_dicts(schema = PowerOutSchema2, data = power)
  }
  return jsonify(res)

@admin_power.get('/add')
@authorize("admin:power:main", log = True)
def select_parent():
  power = Power.query.all()
  res = curd.model_to_dicts(schema = PowerOutSchema2, data = power)
  res.append({"powerId": 0, "powerName": "顶级权限","parentId": -1})
  res = {
    "status": {"code": 200, "message": "默认"},
    "data": res
  }
  return jsonify(res)
  