from flask_socketio import emit, join_room, leave_room
from app.Models.VirtualCoin import VirtualCoin
from app import socketio
from flask import session, request
from threading import Lock

thread = None
global thread_pool
thread_lock = Lock()
thread_pool = {}

def background_thread():
  '''
    增加一个线程处理后台程序，这里需要自己设置条件关闭，
    或者一直为生产者返回消息会增加一个线程，这个还需要
    看下websocket底层实现，会全局广播
  '''
  count = 1
  while True:
    socketio.sleep(1)
    count += 1
    socketio.emit(
      'my_request', {
        'data': 'Server generated event',
        'count': count
      },
      namespace = '/test'
    )

'''
  后台异步执行推送开线程法：
  对应view层的system_response.html
'''
@socketio.on('my_request', namespace='/test')
def test_connect(message):
  global thread
  with thread_lock:
    if thread is None:
      thread = socketio.start_background_task(
        target = background_thread
      )
      emit('my_request', {'data': 'Connected', 'sid': request.sid})

'''
  后台异步推送不开线程法：
  对应view层的system_response.html
'''
@socketio.on('my_unthread_request', namespace = '/test')
def test_unthread_connect(message):
  count = 0
  while True:
    socketio.sleep(1)
    count += 1
    emit('my_request', {'data': 'Connected', 'unthreadCount': count})

@socketio.on('request_for_response', namespace = '/test')
def give_response(message):
  value = message.get('param')
  print(value)

'''
  全局广播，不加只是单个页面通信，
  对应view层的my_broadcast_eventA, B.html
'''
@socketio.on('my_broadcast_event', namespace='/test')
def test_broadcast_message(message):
  session['receive_count'] = session.get('receive', 0) + 1
  emit(
    'my_broadcast_event',
    {
      'msg': message['data'],
      'count': session['receive_count']
    },
    broadcast = True
  )

'''
  聊天室模式，进入，离开，聊天
  对应view层的chatRoom1_A,B.hmtl 客户端可以设置房间号，用来区分响应作用域
'''
@socketio.on('join', namespace='/ChatRoom')
def join(message):
  name = message['name']
  room = message['room']
  join_room(room)
  session['receive_count'] = session.get('receive_count', 0) + 1
  emit(
    'join', {
      'room': 'Welcom %s into the room %s' % (name, room),
      'count': session['receive_count']
    },
    room = room
  )

@socketio.on('leave', namespace='/ChatRoom')
def leave(message):
  name = message['name']
  room  = message['room']
  leave_room(room)
  emit('leave', {'room': '%s leave up room %s' % (name, room)}, room = room)

'''
  实时推送虚拟货币详情
  注意这里不该开多个线程
'''
@socketio.on('Virtual', namespace='/VirtualCoin')
def Virtual(message):
  if 'leave' in message:
    print('leave')
    thread_pool[request.sid]['status'] = False
  elif request.sid in thread_pool:
    print(request.sid)
    thread_pool[request.sid]['coinName'] = message['coinName']
  else:
    thread_pool[request.sid] = {
      'status': True,
      'thread': '',
      'sid': request.sid,
      'coinName': message['coinName']
    }
    print('add_thread')
    thread_pool[request.sid]['thread'] = socketio.start_background_task(
      background_virtual_thread, request.sid
    )

def background_virtual_thread(sid):
  while thread_pool[sid]['status']:
    socketio.sleep(1)
    try:
      data = VirtualCoin().getWsContent(thread_pool[sid]['coinName'])
      socketio.emit(
        'Virtual', {'data': data},
        namespace = '/VirtualCoin', room = thread_pool[sid]['sid']
      )
    except:
      pass
  del thread_pool[sid]

# 连接事件
@socketio.on('connect', namespace = '/test')
def connect():
  emit('my response', {'data': 'Connected'})

# 断开事件
@socketio.on('disconnect', namespace = '/VirtualCoin')
def virtualCoinDisconnect():
  thread_pool[request.sid]['status'] = False
  print('Client disconnected')

