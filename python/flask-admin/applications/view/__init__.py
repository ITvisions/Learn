from applications.view.admin import register_admin_views
from applications.view.index import register_index_views
from applications.view.passport import register_password_views
from applications.view.rights import register_rights_views
from applications.view.department import register_dept_views

def init_veiw(app):
  register_admin_views(app)
  register_index_views(app)
  register_rights_views(app)
  register_password_views(app)
  register_dept_views(app)
