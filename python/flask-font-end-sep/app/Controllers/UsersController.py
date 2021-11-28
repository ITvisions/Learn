from logging import error
from app import app
from app.Controllers.BaseController import BaseController
from app.Vendor.Utils import Utils
from app.Service.TableService import TableService
from app.Models.Users import Users
from app.Models.Suggest import Suggest
from app.Models.Comments import Comments
from app.Models.ImgShard import ImgShard
from app.Models.Log import Log
from app.Vendor.UsersAuthJWT import UserAuthJWT
from app.Vendor.Decorator import validator
from flask import request
from werkzeug.utils import secure_filename
import os, base64

@app.route('/', methods = ['GET'])
def index():
  '''测试'''
  Log().add({
    'type'  : 1,
    'level' : 1,
    'data'  : '1'
  })
  return BaseController().successData(msg='run successful')

@app.route('/api/v2/lock/table')
def lockTable():
  TableService().lock()
  return BaseController().successData(msg='add lock successful')

@app.route('/api/v2/register', methods = ['POST'])
@validator(name = 'email', rules = {'required': True, 'type': 'string', 'minlength': 10, 'maxlength': 20})
@validator(name = 'password', rules = {'required': True, 'type': 'string', 'minlength': 6, 'maxlength': 20})
def register(params):
  '''注册'''
  filters = {
    Users.email == params['email']
  }
  userData = Users().getOne(filters)
  if (userData == None):
    user = Users(
      email = params['email'],
      password = Users.set_password(params['password']),
      status = 1 
    )
    status = Users.add(user)
    if status == True:
      return BaseController().successData(msg = 'register successful')
    return BaseController().error(msg = 'register failed')
  return BaseController().error(msg = 'had been registered')

@app.route('/api/v2/login', methods = ['POST'])
def login():
  '''登陆'''
  email = request.json.get('email')
  password = request.json.get('password')
  if (not email or password):
    return BaseController().error('username and password is required')
  else:
    result = UserAuthJWT.authenticate(email, password)
    return result

@app.route('/api/v2/user', methods = ['GET'])
def get():
  '''获取用户信息'''
  result = UserAuthJWT.identify(request)
  if isinstance(result, str):
    return BaseController().error(result)
  if (result['data']):
    user = Users.get(result['data']['id'])
    returnUser = {
      'id': user.id,
      'name': user.name,
      'email': user.email,
      'login_time': user.updated_at
    }
    return BaseController().successData(returnUser)
  return BaseController().error('user not found')

@app.route('/api/v2/userInfo', methods = ['POST'])
def getInfo():
  '''不通过鉴权获取用户信息'''
  id = request.json.get('id')
  data = Users.query.filter_by(id = id).all()
  datas = Utils.db_l_to_d(data)
  return BaseController().successData(datas)

@app.route('/api/v2/user/suggest', methods = ['GET'])
def userSuggest():
  '''查询用户留言记录， 一对多'''
  data_msg = Suggest.on_to_many()
  return BaseController().successData(data_msg)

@app.route('/api/v2/user/suggest/join', methods = ['GET'])
def userSuggestJoin():
  data_msg = Suggest.join()
  print(data_msg)
  return BaseController().successData(data_msg)

@app.route('/api/v2/user/suggest/left', methods = ['GET'])
def userSuggestLeft():
  data_msg = Suggest.leftJoin()
  return BaseController().successData(data_msg)

@app.route('/api/v2/document/upload', methods = ['POST'])
def documentUpload():
  '''上传文件并验证'''
  files = request.files['document']
  filename = secure_filename(files.filename)
  if(files and Utils.allowed_file(filename)):
    path = os.getcwd() + '/upload/' + filename
    files.save(path)
    return BaseController().error('upload successful')
  return BaseController().error('file type error')

@app.route('/api/v2/document/upload/base64', methods = ['POST'])
def documentUploadBase64():
  '''
   上传base64形式文件并验证需要前端传入的文件类型
  '''
  # 二维数组验证
  rules = {
    'userImgOne': {
      'type': 'dict',
      'schema': {
        'imgBase64': {
          'required': True,
          'type': 'string',
          'minlength': 2
        },
        'name': {
          'required': True,
          'type': 'string',
          'minlength': 2
        },
        'size': {
          'required': True,
          'type': 'integer',
          'minlength': 2
        },
        'type': {
          'required': True,
          'type': 'string',
          'minlength': 2
        }
      }
    },
    'userImgTwo': {
      'type': 'dict',
      'schema': {
        'imgBase64': {
          'required': True,
          'type': 'string',
          'minlength': 2
        },
        'name': {
          'required': True,
          'type': 'string',
          'minlength': 2
        },
        'size': {
          'required': True,
          'type': 'integer',
          'minlength': 2
        },
        'type': {
          'required': True,
          'type': 'string',
          'minlength': 2
        }
      }
    },
    'userImgThree': {
      'type': 'dict',
      'schema': {
        'imgBase64': {
          'required': True,
          'type': 'string',
          'minlength': 2
        },
        'name': {
          'required': True,
          'type': 'string',
          'minlength': 2
        },
        'size': {
          'required': True,
          'type': 'integer',
          'minlength': 2
        },
        'type': {
          'required': True,
          'type': 'string',
          'minlength': 2
        }
      }
    }
  }
  error_msg = {
    'userImgOne': {
      'type': 'dict',
      'schema': {
        'imgBase64': {
          'required': u'图一是必须的',
          'type': u'图一必须是字符串',
          'minlength': u'图一字符最小是2'
        },
        'name': {
          'required': u'图一是必须的',
          'type':  u'图一必须是字符串',
          'minlength': u'图一字符最小是2'
        },
        'size': {
          'required': u'图一是必须的',
          'type': u'图一必须是字符串',
          'minlength': u'图一字符最小是2'
        },
        'type': {
          'required': u'图一是必须的',
          'type': u'图一必须是字符串',
          'minlength': u'图一字符最小是2'
        }
      }
    },
    'userImgTwo': {
      'type': 'dict',
      'schema': {
        'imgBase64': {
          'required': u'图二是必须的',
          'type': u'图二必须是字符串',
          'minlength': u'图二字符最小是2'
        },
        'name': {
          'required': u'图二是必须的',
          'type':  u'图二必须是字符串',
          'minlength': u'图二字符最小是2'
        },
        'size': {
          'required': u'图二是必须的',
          'type': u'图二必须是整数',
          'minlength': u'图二字符最小是2'
        },
        'type': {
          'required': u'图二是必须的',
          'type': u'图二必须是字符串',
          'minlength': u'图二字符最小是2'
        }
      }
    },
    'userImgThree': {
      'type': 'dict',
      'schema': {
        'imgBase64': {
          'required': u'图三是必须的',
          'type': u'图三必须是字符串',
          'minlength': u'图三字符最小是2'
        },
        'name': {
          'required': u'图三是必须的',
          'type':  u'图三必须是字符串',
          'minlength': u'图三字符最小是2'
        },
        'size': {
          'required': u'图三是必须的',
          'type': u'图三必须是整数',
          'minlength': u'图三字符最小是2'
        },
        'type': {
          'required': u'图三是必须的',
          'type': u'图三必须是字符串',
          'minlength': u'图三字符最小是2'
        }
      }
    }
  }
  error = BaseController().validateInput(rules, error_msg)
  if (error is not True):
    return error
  for(k, v) in request.json.items():
        userImg = v['imgBase64'].split(',')[1]
        imgdata = base64.b64decode(userImg)
        path = os.getcwd()+"/uploads/"+Utils.unique_id()+'.jpg'
        file = open(path, 'wb')
        file.write(imgdata)
        file.close()
        userImgOne = request.json.get('userImgOne')['imgBase64'].split(',')[1]
        userImgTwo = request.json.get('userImgTwo')['imgBase64'].split(',')[1]
        userImgThree = request.json.get('userImgThree')['imgBase64'].split(',')[1]
        imgdata = base64.b64decode(userImgOne)
  return BaseController().successData(msg='img upload success')

@app.route('/api/v2/comments/get', methods = ['POST'])
def commentsGet():
  rules = {
    'pageNo': {
      'required': True,
      'type': 'integer'
    },
    'pageSize': {
      'required': True,
      'type': 'integer'
    }
  }
  error_msg = {
    'pageNo': {
      'required': u'当前页是必须的',
      'type': u'当前页必须是整数'
    },
    'pageSize': {
      'required': u'当前页是必须的',
      'type': u'当前页必须是整数'
    }
  }
  error = BaseController().validateInput(rules, error_msg)
  if (error is not True):
    return error
  pageNo = request.json.get('pageNo')
  pageSize = request.json.get('pageSize')
  data = Comments().getCommentsList(pageNo, pageSize)
  return BaseController().json(data)

@app.route('/api/v2/imgShard/save', methods = ['POST'])
def imgShard():
  '''接收图片分片数据并存入数据库'''
  rules = {
    'index': {
      'required': True,
      'type': 'integer'
    },
    'uuid': {
      'required': True,
      'type': 'string'
    },
    'imgString': {
      'required': True,
      'type': 'string'
    }
  }
  error_msg = {
    'index': {
      'required': u'图片索引是必须的',
      'type': u'图片索引必须是字符串'
    },
    'uuid': {
      'required': u'唯一id是必须的',
      'type': u'唯一id必须是字符串'
    },
    'imgString': {
      'required': u'当前页是必须的',
      'type': u'当前页必须是字符串'
    }
  }
  error = BaseController().validateInput(rules, error_msg)
  if (error is not True):
    return error
  index = request.json.get('index')
  uuid = request.json.get('uuid')
  imgString = request.json.get('imgString')
  data = ImgShard.add(index, uuid, imgString)
  if data:
    return BaseController().successData(data = 0, msg = '图片分片提交失败')
  else:
    return BaseController().successData(data = index, msg = '图片分片提交成功')
  
@app.route('/api/v2/imgShard/switch', methods = ['POST'])
def imgSwitch():
  '''接收图片uuid并转换成图片'''
  rules = {
    'uuid': {
      'required': True,
      'type': 'string'
    }
  }
  error_msg = {
    'uuid': {
      'required': u'唯一id是必须的',
      'type': u'唯一id必须是字符串'
    }
  }
  error = BaseController().validateInput(rules, error_msg)
  if (error is not True):
    return error
  uuid = request.json.get('uuid')
  data = imgShard.getData(uuid)
  base64Data = ''
  for i in data:
    base64Data += i['imgString']
  userImg = base64Data.split(',')[1]
  imgdata = base64.b64decode(userImg)
  rela_path = '/uploads/' + Utils.unique_id() + '.jpg'
  path = os.getcwd() + rela_path
  file = open(path, 'wb')
  file.write(imgdata)
  file.close()
  return BaseController().successData(data = {'url': rela_path}, msg = 'image upload successful')
