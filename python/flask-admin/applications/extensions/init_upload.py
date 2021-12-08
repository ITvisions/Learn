from flask import Flask
from flask_uploads import configure_uploads
from flask_uploads import UploadSet, IMAGES
from flask_uploads.flask_uploads import uploaded_file

photos = UploadSet('photos', IMAGES)

def init_upload(app: Flask):
  configure_uploads(app, photos)
