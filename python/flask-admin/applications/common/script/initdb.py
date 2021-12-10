from dotenv import dotenv_values
import sqlparse
import pymysql
config = dotenv_values('.flaskenv')

HOST = config.get('MYSQL_HOST') or '127.0.0.1'
PORT = config.get('MYSQL_PORT') or 3306
DATABASE = config.get('MYSQL_DATABASE') or 'AdminFlask'
USERNAME = config.get('MYSQL_USERNAME') or 'root'
PASSWORD = config.get('MYSQL_PASSWORD') or 'MiMa123456'

def is_exit_database():
  db = pymysql.connect(host = HOST, port = int(PORT), user = USERNAME, password = PASSWORD, charset = 'utf8mb4')
  cursorl = db.cursor()
  sql = "select * from infomation_schema.SCHEMATA WHERE SCHEMA_NAME = '%s' ;" % DATABASE
  res = cursorl.execute(sql)
  db.close()
  return res

def init_database():
  db = pymysql.connect(host = HOST, port = int(PORT), user = USERNAME, password = PASSWORD, charset = 'utf8mb4')
  cursorl = db.cursor()
  sql = "CREATE DATABASE IF NOT EXISTS %s" % DATABASE
  res = cursorl.execute(sql)
  db.close()
  return res
