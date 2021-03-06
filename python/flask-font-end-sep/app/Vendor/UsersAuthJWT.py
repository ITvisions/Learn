from sqlalchemy.sql.functions import user
from app.Controllers.BaseController import BaseController
from app.Vendor.Utils import Utils
from app.Models.Users import Users
from app.env import SECRET_KEY, JWT_LEEWAY
import datetime
import jwt
import time

class UsersAuthJWT():
  @staticmethod
  def encode_auth_token(user_id, update_at):
    '''
      生成认证Token
      @param user_id: int,
      @param login_time: int(timestamp)
      @return string
    '''
    try:
      payload = {
        'exp': datetime.datetime.utcnow() + datetime.timedelta(seconds = JWT_LEEWAY),
        'iat': datetime.datetime.utcnow(),
        'iss': 'ken',
        'data': {
          'id': user_id,
          'updated_at': update_at
        }
      }
      return jwt.encode(payload, SECRET_KEY, algorithm = 'HS256')
    except Exception as e:
      return e
  
  @staticmethod
  def decode_auth_token(auth_token):
    '''
      验证Token
      @param auth_token
      @return integer|string
    '''
    try:
      payload = jwt.decode(auth_token, SECRET_KEY)
      if ('data' in payload and 'id' in payload['data']):
        return payload
      else:
        raise jwt.InvalidTokenError
    except jwt.ExpiredSignatureError:
      return 'Token过期'
    except jwt.InvalidTokenError:
      return '无效Token'
  
  @staticmethod
  def authenticate(email, password):
    '''
      用户登录，登录成功返回token，将登录时间写入数据库；登录失败返回失败原因
      @param password
      @return json
    '''
    filters = {
      Users.email == email
    }
    userInfo = Users().getOne(filters)
    userInfoPas = Users().getOne(filters, order = 'id desc', field = ('password',))
    if (userInfo is None):
      return BaseController().error('user not found')
    else:
      if (Users.check_password(userInfoPas['password'], password)):
        update_at = int(time.time())
        Users.update(email, update_at)
        token = UsersAuthJWT.encode_auth_token(userInfo['id'], update_at)
        return BaseController().successData({'token': token.decode(), 'user': userInfo}, '登陆成功')
  
  def identify(self, request):
    '''
      用户鉴权
      @return list
    '''
    auth_header = request.headers.get('Authorization')
    if (auth_header):
      auth_tokenArr = auth_header.split(' ')
      if (not auth_tokenArr or auth_tokenArr[0] != 'JWT' or len(auth_tokenArr) != 2):
        return '请传递正确的验证头信息'
      else:
        auth_token = auth_tokenArr[1]
        payload = self.decode_auth_token(auth_token)
        if not isinstance(payload, str):
          user = Users.get(payload['data']['id'])
          if (user is None):
            return '找不到该用户信息'
          else:
            if (user.updated_at == payload['data']['updated_at']):
              result = payload
            else:
              return 'Token已更改，请重新登录获取'
        else:
          result = payload
    else:
      return '没有提供认证token'
    return result
  