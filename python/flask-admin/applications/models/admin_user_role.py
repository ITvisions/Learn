from applications.extensions import db

# 创建中间表
user_role = db.Table(
  'admin_user_role',
  db.Column('id', db.Integer, primary_key = True, autoincrement = True, comment = '标识'),
  db.Column('user_id', db.Integer, db.ForeignKey('admin_user.id'), comment = '用户编号'),
  db.Column('role_id', db.Integer, db.ForeignKey('admin_role.id'), comment = '角色编号')
)
