from flask import jsonify
from flask_login import login_required
from . import right_bp
from ...common import admin

@right_bp.get('/configs')
@login_required
def configs():
  return admin.get_render_config()

@right_bp.get('/menu')
@login_required
def menu():
  menu_tree = admin.make_menu_tree()
  return jsonify(menu_tree)
