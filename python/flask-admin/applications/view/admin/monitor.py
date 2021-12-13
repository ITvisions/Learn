import os
import platform
import re
from datetime import datetime
import time
import psutil
from flask import Blueprint, render_template, jsonify
from applications.common.utils.rights import authorize

admin_monitor_bp = Blueprint('adminMonitor', __name__, url_prefix = '/admin/monitor')

@admin_monitor_bp.get('/')
@authorize("admin:monitor:main", log = True)
def main():
  hostname = platform.node()
  system_version = platform.platform()
  python_version = platform.python_version()
  cpu_count = psutil.cpu_count()
  cpus_percent = psutil.cpu_percent(interval = 0.1)
  memory_infomation = psutil.virtual_memory()
  memory_usage = memory_infomation.percent
  memory_used = str(round(memory_infomation.used / 1024 / 1024))
  memory_total = str(round(memory_infomation.total / 1024 / 1024))
  memory_free = str(round(memory_infomation.free / 1024 / 1024))

  disk_partitions_list = []
  if not os.path.exists('/.dockerenv'):
    disk_partitions = psutil.disk_partitions()
    for i in disk_partitions:
      a = psutil.disk_usage(i.device)
      disk_partitions_dict = {
        'device': i.device,
        'fstype': i.fstype,
        'total': str(round(a.total / 1024 / 1024)),
        'used': str(round(a.used / 1024 / 1024)),
        'free': str(round(a.free / 1024 / 1024)),
        'percent': a.percent
      }
      disk_partitions_list.append(disk_partitions_dict)

  boot_time = datetime.fromtimestamp(psutil.boot_time()).replace(microsecond = 0)
  up_time = datetime.now().replace(microsecond = 0) - boot_time
  up_time_list = re.split(r':', str(up_time))
  up_time_format = "{}小时{}分钟{}秒".format(up_time_list[0], up_time_list[1], up_time_list[2])
  time_now =time.strftime('%H:%M:%S', time.localtime(time.time()))
  return render_template('admin/monitor.html',
                          hostname = hostname,
                          system_version = system_version,
                          python_version = python_version,
                          memory_usage = memory_usage,
                          cpu_count = cpu_count,
                          memory_used = memory_used,
                          memory_total = memory_total,
                          memory_free = memory_free,
                          boot_time = boot_time,
                          up_time_format = up_time_format,
                          disk_partitions_list = disk_partitions_list,
                          time_now = time_now
                          )

@admin_monitor_bp.get('/polling')
@authorize("admin:monitor:main")
def ajax_polling():
  cpus_percent = psutil.cpu_percent(interval = 0.1)
  memory_infomation = psutil.virtual_memory()
  memory_usage = memory_infomation.percent
  time_now = time.strftime('%H:%M:%S', time.localtime(time.time()))
  return jsonify(cpus_percent = cpus_percent, memory_used = memory_usage, time_now = time_now)
