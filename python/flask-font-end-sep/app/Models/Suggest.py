from app import dBSession
from app.Models.BaseModel import BaseModel
from app.Models.Users import Users
from sqlalchemy_serializer import SerializerMixin
from sqlalchemy.orm import relationship, foreign, remote
from app.Vendor.Utils import Utils
from app.Models.Model import HtSuggest
from app.Models.Users import Users

class Suggets(HtSuggest, BaseModel, SerializerMixin):
  user = relationship('Users', uselist = False, primaryjoin = foreign(HtSuggest.user_id) == remote(Users.id))

  # 一对多普通方式
  @staticmethod
  def no_to_many():
    data = dBSession.query(Suggest).filter(Users.id == Suggest.users_id).all()
    data_msg = Utils.db_l_to_d(data)
    return data_msg

  # 一对多join方式
  @staticmethod
  def join():
    data = dBSession.query(Suggest).join(Users, Users.id == Sugget.users_id).all()
    data_msg = Utils.db_l_to_d(data)
    return data_msg

  # 一对多left join
  @staticmethod
  def leftJoin():
    data = dBSession.query(Suggest).outerjoin(Users, Users.id == Suggest.users_id).all()
    data_msg = Utils.db_l_to_d(data)
    return data_msg
