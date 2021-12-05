import datetime
from applications.extensions import db

class Photo(db.Model):
  __tablename__ = 'admin_photo'
  id = db.Column(db.Integer, primary_key = True)
  name = db.Column(db.String(255), nullable = False)
  href = db.Column(db.String(255))
  mine = db.Column(db.CHAR(50), nullable = False)
  size = db.Column(db.CHAR(50), nullable = False)
  create_time = db.Column(db.DateTime, default = datetime.datetime.now)
