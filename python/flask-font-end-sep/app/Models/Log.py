from app import dBSession
from sqlalchemy import desc, asc
from app.Models.BaseModel import BaseModel
from sqlalchemy_serializer import SerializerMixin
from app.Vendor.Decorator import classTransaction
from app.Models.Model import HtLog

class Log(HtLog, BaseModel, SerializerMixin):
  def getOne(self, filters, order = 'id desc', field = ()):
    res = dBSession.query(Log).filter(*filters)
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
