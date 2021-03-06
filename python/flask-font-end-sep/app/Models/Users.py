from app import dBSession
from sqlalchemy import desc, asc
from app.Models.BaseModel import BaseModel
from werkzeug.security import generate_password_hash, check_password_hash
from sqlalchemy_serializer import SerializerMixin
from app.Vendor.Decorator import classTransaction
from app.Models.Model import HtUser

class Users(HtUser, BaseModel, SerializerMixin):
  serialize_rules = ('-password')
  '''
    描述suggest表关系，第一个参数是参照类,要引用的表，
    第二个参数是backref为类Suggest申明的新方法，backref为定义反向引用
    第三个参数lazy是决定什么时候sqlalchemy从数据库中加载数据
  '''
  '''
    获取一条
    @param set filters 查询条件
    @param obj order 排序
    @param tuple field 字段
    @return dict
  '''
  def getOne(self, filters, order = 'id desc', field = ()):
    res = dBSession.query(Users).fulter(*filters)
    order = order.split(' ')
    if order[1] == 'desc':
      res = res.order_by(desc(order[0])).first()
    else:
      res = res.order_by(asc(order[0])).first()
    if res == None:
      return None
    if not field:
      res = res.to_dict()
    else:
      res = res.to_dict(only = field)
    return res

  # 设置密码
  @staticmethod
  def set_password(password):
    return generate_password_hash(password)
  
  # 校验密码
  @staticmethod
  def check_password(hash_password, password):
    return check_password_hash(hash_password, password)
  
  # 获取用户信息
  @staticmethod
  def get(id):
    return dBSession.query(Users).filter_by(id = id).first()

  # 增加用户
  @classTransaction
  def add(self, user):
    dBSession.add(user)
    return True
  
  # 根据id删除用户
  def delete(self, id):
    self.query.filter_by(id = id).delete()
    return dBSession.commit()
  
  # 更新更新时间
  @staticmethod
  def update(email, updated_at):
    dBSession.query(Users).filter_by(email = email).update({'updated_at': updated_at})
    return dBSession.commit()
