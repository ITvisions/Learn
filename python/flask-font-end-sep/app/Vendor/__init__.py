from  flask import Blueprint
from app.Controllers.BaseController import BaseController
admin = Blueprint('admin', __name__)

@admin.route('/register')
def register():
  return BaseController().successData(msg='register successful')
