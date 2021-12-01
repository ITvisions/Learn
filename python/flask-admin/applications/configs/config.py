import logging
import os

class BaseConfig:
  SYSTEM_NAME = os.getenv('SYSTEM', 'Admin')
  # 主题面板的链接列表配置
  SYSTEM_PANEL_LINKS = [
    {
      "icon": "layui-icon layui-icon-auz",
      "title": "官方网站",
      "href": "#" 
    },
    {
      "icon": "layui-icon layui-icon-auz",
      "title": "开发文档",
      "href": "#" 
    },
    {
      "icon": "layui-icon layui-icon-auz",
      "title": "开源地址",
      "href": "#" 
    }
  ]

  UPLOAD_PHOTOS_DEST = 'static/upload'
  UPLOAD_FILES_ALLOW = ['gif', 'jpg']

  # JSON配置
  JSON_AS_ASCII = False
  SECRET_KEY = os.getenv('SECRET_KEY', 'dev key')

  # redis配置
  REDIS_HOST = os.getenv('REDIS_HOST') or '127.0.0.1'
  REDIS_PORT = int(os.getenv('REDIS_PORT') or 6379)

  # mysql配置
  MYSQL_USERNAME = os.getenv('MYSQL_USERNAME') or 'root'
  MYSQL_PASSWORD = os.getenv('MYSQL_PASSWORD') or '123456'
  MYSQL_HOST = os.getenv('MYSQL_HOST') or '127.0.0.1'
  MYSQL_PORT = int(os.getenv('MYSQL_PORT') or 3306)
  MYSQL_DATABASE = os.getenv('MYSQL_DATABASE' or 'AdminFlask')

  # mysql 数据库配置信息
  SQLALCHEMY_DATABASE_URI = f"mysql+pymysql://{MYSQL_USERNAME}:{MYSQL_PASSWORD}@{MYSQL_HOST}:{MYSQL_PORT}/{MYSQL_DATABASE}"
  
  # 默认日志等级
  LOG_LEVEL = logging.WARN
  
  # 邮箱配置
  MAIL_SERVER = os.getenv('MAIL_SERVER') or 'smtp.qq.com'
  MAIL_USE_TLS = False
  MAIL_USE_SSL = True
  MAIL_PORT = 465
  MAIL_USERNAME = os.getenv('MAIL_USERNAME') or '123@qq.com'
  MAIL_PASSWORD = os.getenv('MAIL_PASSWORD') or 'XXX' #生成的授权码
  # 默认发件人邮箱
  MAIL_DEFAULT_SENDER = ('admin flask', os.getenv('MAIL_USERNAME') or '123@qq.com')

class TESTingConfig(BaseConfig):
  # 测试配置
  SQLALCHEMY_DATABASE_URI = 'sqlite:///:memory:' # 内存数据

class DevelopmentConfig(BaseConfig):
  # 开发配置
  SQLALCHEMY_TRACK_MODIFICATIONS = True
  SQLALCHEMY_ECHO = False

class ProductionConfig(BaseConfig):
  # 生成环境配置
  SQLALCHEMY_TRACK_MODIFICATIONS = False
  SQLALCHEMY_ECHO = False
  SQLCHEMY_POOL_RECYCLE = 8

config = {
  'development': DevelopmentConfig,
  'testing': TESTingConfig,
  'production': ProductionConfig
}
