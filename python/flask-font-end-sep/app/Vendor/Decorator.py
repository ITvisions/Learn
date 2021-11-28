from app import dBSession
from flask import request, make_response
from functools import wraps
from app.Vendor.Code import Code
from app.Vendor.Utils import Utils
from app.Vendor.CustomErrorHandler import CustomErrorHandler
from app.Vendor.ExceptionApi import ExceptionApi
from app.Controllers.BaseController import BaseController
import cerberus, json

# 事务装饰器
def transaction(func):
  @wraps
  def inner_wrappar(*args, **kwargs):
    try:
      result = func(*args, **kwargs)
      dBSession.commit()
      return result
    except Exception as e:
      dBSession.rollback()
      return ExceptionApi(Code.ERROR, e)
  return inner_wrappar

def classTransaction(func):
  @wraps(func)
  def wrappar(self, *args, **kwrags):
    try:
      result = func(self, *args, **kwrags)
      dBSession.commit()
      return result
    except Exception as e:
      dBSession.rollback()
      return ExceptionApi(Code.ERROR, e)
  return wrappar

'''
 根据字段名验证输入信息
 @param string name
 @param dict rules
 @param string error_msg
 @param string default
 @return response
'''
def validateInputByName(name, rules, error_msg = dict(), default = ''):
  # 不准使用error关键字作为请求参数,请求参数都会被格式化成string，无法使用int去验证
  if name == 'error':
    error = {}
    error['msg'] = '不能使用error关键字作用请求参数'
    error['error_code'] = Code.ERROR
    error['error'] = True
    return error
  v = cerberus.Validator(
    rules, error_handler = CustomErrorHandler(custom_message = error_msg)
  )
  try:
    requests = request.values()
  except TypeError:
    requests = request.get_json()
  
  if name not in requests:
    requests[name] = default
  cookedReqVal = {name: requests[name]}
  if (v.validate(cookedReqVal)):
    return requests
  error = {}
  error['msg'] = v.error
  error['error_code'] = Code.ERROR
  error['error'] = True
  return error

def validator(name, rules, msg = dict(), default = ''):
  '''
    验证装饰器
    @param name  字段名
    @param rules 规则
    @param msg   描述
    @return func|json
  '''
  def wrappar(func):
    @wraps(func)
    def inner_wrapar(*args, **kwargs):
      msgFormat = Utils.validateMsgFormat(name, rules, msg)
      error = validateInputByName(name, {name: rules}, {name: msgFormat}, default)
      if 'error' in error:
        return make_response(json.dumps(error))
      if 'params' in kwargs.keys():
        kwargs['params'][name] = error[name]
        kwargs = kwargs['params']
      else:
        kwargs = error
      return func(kwargs)
    return inner_wrapar
  return wrappar
  