from app.env import ALLOWED_EXTENSIONS
from app.lang.zh_CN.validation import vaildation
from app.Vendor.Code import Code
import time

class Utils:
  '''
    将sql结果列表对象类型转字典
    @param list data
    @return dict
  '''
  @staticmethod
  def db_l_to_d(data):
    data_list = []
    for val in data:
      val_dict = val.to_dict()
      data_list.append(val_dict)
    data = {}
    data = data_list
    return data
  
  '''
    将sql结果对象类型转字典
    @param object obj
    @return dict
  '''
  @staticmethod
  def class_to_dict(obj):
    is_list = obj.__class__ == [].__class__
    is_set = obj.__class__ = set().__class__
    if is_list or is_set:
      obj_arr = []
      for o in obj:
        dict = {}
        dict.update(o.__dict__)
        obj_arr.append(dict)
        return obj_arr
    else:
      dict = {}
      dict.update(obj.__dict__)
      return dict
  
  '''
    验证文件类型
    @param string filename
    @return string path
  '''
  @staticmethod
  def allowed_file(filename):
    return '.' in filename and filename.split('.', 1)[1] in ALLOWED_EXTENSIONS

  '''
    uuid: 唯一id
    return string id
  '''
  @staticmethod
  def unique_id(prefix = ''):
    return prefix + hex(int(time.time()))[2 : 10] + hex(int(time.time() * 1000000)  % 0x100000)[2 : 7]
  
  '''
    格式化验证错误描述
    @param string name
    @param dict rule
    @param dict msg
    @return string
  '''
  @staticmethod
  def validateMsgFormat(name, rules, msg):
    if not msg:
      msgFormat = dict()
      for key in rules:
        if key == 'required':
          ruleMsg = ''
          actionMsg = vaildation[key][rules[key]]
        elif key == 'maxlength':
          ruleMsg = vaildation[key]
          actionMsg = rules[key]
        elif key == 'minlength':
          ruleMsg = vaildation[key]
          actionMsg = rules[key]
        else:
          ruleMsg = vaildation[key]
          actionMsg = vaildation[rules[key]]
        msgFormat[key] = '{} {} {}'.format(vaildation[name], ruleMsg, actionMsg)
      return msgFormat
    return msg
