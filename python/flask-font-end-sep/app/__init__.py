from flask import Flask, app
# 权限模块

# 定时任务
from apscheduler.schedulers.blocking import BlockingScheduler 
# ORM框架
from sqlalchemy import create_engine, engine
# 用于创建DBSession
from sqlalchemy.orm import sessionmaker
# 全双工通信模块
from flask_socketio import SocketIO
# 导入http相应码
from app.Vendor.Code import Code

import environment as e
from app.env import SQLALCHEMY_DATABASE_URI, SQLALCHEMY_TRACK_MODIFICATIONS, UPLOAD_FOLDER, MAX_CONTENT_LENGTH
import os, json

#读取启动环境
environment = e.read()

#普通json带error_code风格使用此app示例
app = Flask(__name__)

# 注册权限
#perms = Permissions(app, db, None)

# 实例化websocket
async_mode = 'gevent'
socketio = SocketIO(app, async_mode = async_mode)
# 配置 sqlalchemy  数据库驱动://数据库用户名:密码@主机地址:端口/数据库?编码
app.config['SQLALCHEMY_DATABASE_URI'] = SQLALCHEMY_DATABASE_URI
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = SQLALCHEMY_TRACK_MODIFICATIONS
# 上传文件配置
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER # 上传目录
app.config['MAX_CONTENT_LENGTH'] = MAX_CONTENT_LENGTH # 上传大小
#创建数据库及连接
engine = create_engine(SQLALCHEMY_DATABASE_URI)
#创建DBSession类型
DBSession = sessionmaker(bind = engine)
dBSession = DBSession
from app.Vendor.ExceptionApi import ExceptionApi
@app.teardown_appcontext
def shutdown_session(exception = None):
  dBSession.close()

#挂载500异常处理,并记录日志
#if environment == 'run' or environment == 'restful':
@app.errorhandler(Exception)
def error_handler(e):
  return ExceptionApi(Code.ERROR, e)

if environment == 'socket':
  @socketio.on_error_default  # Handles the default namespace
  def error_handler(e):
    return ExceptionApi(Code.ERROR, e)

# 引入使用的控制器
if environment == 'run' or environment == 'restful':
  from app.Controllers import UsersController, RestfulController, AdminController
  # 蓝图
  from app.Controllers.AdminController import admin
  app.register_blueprint(admin, url_prefix='/admin')

if environment == 'scoket':
  # 引入scoketio控制层
  from app.Controllers import SocketController

# 引入数据库事件
from app.Event import Log

# 在socket模式下使用后台线程作为计划任务
if environment == 'job':
  # 任务调剂
  sched = BlockingScheduler()
  # 引入任务
  from app.Job import Cron, Interval
  