from sqlalchemy import sql
from app.Vendor.Decorator import classTransaction
from app.Models.Users import Users
from app import dBSession

class TableService:
  @classTransaction
  def lock(self):
    # 行级锁
    query = dBSession.query(Users).filter(Users.id == 34).with_for_update().first()
    print('SQL: %s' % str(query))
    dBSession.execute('select sleep(10)')
