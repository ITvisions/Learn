import logging
import time

def log():
  log = logging.getLogger('error_msg')
  log.setLevel(logging.DEBUG)
  # 建立一个filehandler来把日志记录在文件里，级别为debug以上
  fh = logging.FileHandler(time.strftime('%Y-%m-%d', time.localtime()) + '.log')
  fh.setLevel(logging.ERROR)
  # 建立一个streamhandler来把日志打在CMD窗口上，级别为error以上
  ch = logging.StreamHandler()
  ch.setLevel(logging.ERROR)
  # 设置日志格式
  formatter = logging.Formatter(
    "%(asctime)s - %(name)s - %(levelname)s - %(message)s"
  )
  ch.setFormatter(formatter)
  fh.setFormatter(formatter)
  # 将相应的handler添加在logger对象中
  log.addHandler(ch)
  log.addHandler(fh)
  return log
