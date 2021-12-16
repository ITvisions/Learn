from flask import Blueprint, Flask

right_bp = Blueprint('right', __name__, url_prefix = '/rights')

def register_rights_view(app: Flask):
  app.register_blueprint(right_bp)
