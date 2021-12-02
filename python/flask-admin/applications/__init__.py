import os
from flask import Flask

from applications.configs import config
from applications.extensions import init_plugs

def create_app(config_name = None):
  app = Flask(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

  if not config_name:
    # 从本地环境中读取
    config_name = os.getenv('FLASK_CONFIG', 'development')
  
  # 引入数据库配置
  app.config.from_object(config[config_name])

  # 注册插件
  init_plugs(app)

  # 注册路由
  # init_view(app)

  # 注册命令
  # init_script(app)

  if os.environ.get('WERKZEUG_RUN_MAIN')  == 'true':
    logo()
  
  return app

def logo():
  print(
    '''
                  _           _         ______ _           _    
          /\      | |         (_)       |  ____| |         | |   
         /  \   __| |_ __ ___  _ _ __   | |__  | | __ _ ___| | __
        / /\ \ / _` | '_ ` _ \| | '_ \  |  __| | |/ _` / __| |/ /
       / ____ \ (_| | | | | | | | | | | | |    | | (_| \__ \   < 
      /_/    \_\__,_|_| |_| |_|_|_| |_| |_|    |_|\__,_|___/_|\_\\

    '''
  )
