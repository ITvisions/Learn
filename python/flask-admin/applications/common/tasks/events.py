from apscheduler.events import (
  EVENT_JOB_ADDED,
  EVENT_JOB_ERROR,
  EVENT_JOB_EXECUTED,
  EVENT_JOB_MISSED,
  EVENT_JOB_REMOVED,
  EVENT_JOB_SUBMITTED
)

from applications.extensions.init_apscheduler import scheduler

def job_missed(event):
  with scheduler.app.app_context():
    print(event)

def job_error(event):
  with scheduler.app.app_context():
    print(event)

def job_executed(event):
  with scheduler.app.app_context():
    print(event)

def job_added(event):
  with scheduler.app.app_context():
    print(event)

def job_removed(event):
  with scheduler.app.app_context():
    print(event)

def job_submitted(event):
  with scheduler.app.app_context():
    print(event)

scheduler.add_listener(job_missed, EVENT_JOB_MISSED)
scheduler.add_listener(job_error, EVENT_JOB_ERROR)
scheduler.add_listener(job_executed, EVENT_JOB_EXECUTED)
scheduler.add_listener(job_added, EVENT_JOB_ADDED)
scheduler.add_listener(job_removed, EVENT_JOB_REMOVED)
scheduler.add_listener(job_submitted, EVENT_JOB_SUBMITTED)
