from applications.extensions import db

# 创建中间表
role_power = db.Table(
  'admin_role_power',
  db.Column('id', db.Integer, primary_key = True, autoincrement = True, comment = '标识'),
  db.Column('power_id', db.Integer, db.ForeignKey('admin_power.id'), comment = '用户编号'), # 外键
  db.Column('role_id', db.Integer, db.ForeignKey('admin_role.id'), comment = '角色编号') # 外键
)
