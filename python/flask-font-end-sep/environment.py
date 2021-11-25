import os, json

def init(name:str):
  # 初始化运行环境
  path = os.getcwd() + '/.runtime/environment.json'
  data = {"environment": name}
  with open(path, 'w+') as f:
    f.write(json.dumps(data))

def read()->dict:
  # 读取环境变量
  with open(os.getcwd() + '/.runtime/environment.json', 'r') as f:
    environment = json.loads(f.read())['environment']
    return environment