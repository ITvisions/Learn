from flask_mail import Message
from applications.extensions.init_mail import mail

def send_mail(subject, recipients, content):
  try:
    message = Message(subject = subject, recipients = recipients, body = content)
    mail.send(message)
  except Exception as e:
    print('邮箱发送出错')
    raise
