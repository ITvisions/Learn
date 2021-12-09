from sqlalchemy import and_
from applications.extensions import db

class ModelFilter:
  filter_field = {}
  filter_list = []

  type_exact = 'exact'
  type_neq = 'neq'
  type_greater = 'greater'
  type_less = 'less'
  type_vague = 'vague'
  type_contains = 'contains'
  type_between = 'between'

  def __init__(self):
    self.filter_field = {}
    self.filter_list = []
  
  def exact(self, field_name, value):
    if value and value != '':
      self.filter_field[field_name] = {'data': value, 'type': self.type_exact}
  
  def neq(self, field_name, value):
    if value and value != '':
      self.filter_field[field_name] = {'data': value, 'type': self.type_neq}
  
  def greater(self, field_name, value):
    if value and value != '':
      self.filter_field[field_name] = {'data': value, 'type': self.type_greater}
  
  def less(self, field_name, value):
    if value and value != '':
      self.filter_field[field_name] = {'data': value, 'type': self.type_less}
    
  def vague(self, field_name, value):
    if value and value != '':
      self.filter_field[field_name] = {'data': ('%' + value + '%'), 'type': self.type_vague}
  
  def left_vague(self, field_name, value: str):
    if value and value != '':
      self.filter_field[field_name] = {'data': ('%' + value), 'type': self.type_vague}

  def right_vague(self, field_name, value: str):
    if value and value != '':
      self.filter_field[field_name] = {'data': (value + '%'), 'type': self.type_vague}

  def contains(self, field_name, value: str):
    if value and value != '':
      self.filter_field[field_name] = {'data': value, 'type': self.type_contains}

  def between(self, field_name, value1, value2):
    if value1 and value2 and value1 != '' and value2 != '':
      self.filter_field[field_name] = {'data': [value1, value2], 'type': self.type_vague}
  
  def get_filter(self, model: db.Model):
    for k, v in self.filter_field.items():
      if v.get('type') == self.type_vague:
        self.filter_list.append(getattr(mode, k).like(v.get('data')))
      if v.get('type') == self.type_contains:
        self.filter_list.append(getattr(model, k).contains(v.get('data')))
      if v.get('type') == self.type_exact:
        self.filter_list.append(getattr(model, k) == v.get('data'))
      if v.get('type') == self.type_neq:
        self.filter_list.append(getattr(model, k) != v.get('type_neq'))
      if v.get('type') == self.type_greater:
        self.filter_list.append(getattr(model, k) > v.get('data'))
      if v.get('type') == self.type_less:
        self.filter_list.append(getattr(model, k) < v.get('data'))
      if v.get('type') == self.type_between:
        self.filter_list.append(getattr(model, k).between(v.get('data')[0], v.get('data')[1]))
    return and_(*self.filter_list)
