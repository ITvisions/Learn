from applications.view.index.index import index_bp

def register_index_view(app):
  app.register_blueprint(index_bp)
