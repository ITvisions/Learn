from app.Models.Log import Log
from sqlalchemy import event
import time

@event.listens_for(Log, 'before_insert')
def log_before_insert(mapper, connection, target):
  target.create_time = int(time.time())
