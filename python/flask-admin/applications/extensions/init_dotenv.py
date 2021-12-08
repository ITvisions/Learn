import os
from dotenv import load_dotenv

root_path = os.path.abspath(os.path.dirname(__file__)).split('applications')[0]
flask_env_path = os.path.join(root_path, '.flaskenv')

def init_dotenv():
  if os.path.exists(flask_env_path):
    load_dotenv(flask_env_path)
