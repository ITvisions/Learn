from captcha.image import ImageCaptcha

from PIL import Image
from random import choices

def gen_captcha(content = '2345689abcdefghijklmnpqrstuvwxyzABCDEFGHIJKLMNPQRSTUVWXYZ'):
  # 生成验证码
  image = ImageCaptcha()

  capcha_text = ''.join(choices, k = 4).lower()
  capcha_image = image.open(image.generate(capcha_text))
  return capcha_text, capcha_image
