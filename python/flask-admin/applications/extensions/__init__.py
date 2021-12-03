from flask import Flask

from .init_sqlalchemy import db, ma, init_databases
from .init_login import init_login_manager

def init_plugs(app: Flask) -> None:
  init_databases(app)
  init_login_manager(app)
