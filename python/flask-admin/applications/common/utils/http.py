from flask import jsonify

def success_api(msg: str = '成功'):
  return jsonify(success = True, msg = msg)

def fail_api(msg: str = '失败'):
  return jsonify(success = False, msg = msg)

def table_api(msg: str = "", count = 0, data = None, limit = 10):
  res = {
    'msg': msg,
    'code': 0,
    'data': data,
    'count': count,
    'limit': limit
  }
  return jsonify(res)
