import cerberus

class CustomErrorHandler(cerberus.errors.BasicErrorHandler):
  def __init__(self, tree = None, custom_messages = None):
    super(CustomErrorHandler, self).__init__(tree)
    self.custom_message = custom_messages or {}
  
  def format_message(self, field, error):
    tmp = self.custom_message
    for x in error.schema_path:
      try:
        tmp = tmp[x]
      except KeyError:
        return super(CustomErrorHandler, self).format_message(field, error)
    if isinstance(tmp, dict):
      return super(CustomErrorHandler, self).format_message(field, error)
    else:
      return tmp
