#include "data_persistancy/ConstVisitor.h"
#include "Headers/TaskListManager.h"
#include "Headers/Activity.h"
#include <iostream>
using std::cout;
using std::endl;

Activity::Activity(QString title, QString description,
                   QString assignee, QDate creationDate,
                   QDate startDate, QDate endDate,
                   QString startTime, int totalDuration,
                   QString location, int participantCount,
                   QString eventType, bool online, QString meetingLink)
    : AbstractTask(title, description, assignee, creationDate),
    TimedTask(title, description, assignee, creationDate,
              startDate, endDate, startTime, totalDuration),
    location(location), participantCount(participantCount),
    eventType(eventType), online(online), meetingLink(meetingLink)
{}

QString Activity::getLocation()         const { return location;         }
int    Activity::getParticipantCount() const { return participantCount; }
QString Activity::getEventType()        const { return eventType;        }
bool   Activity::isOnline()            const { return online;           }
QString Activity::getMeetingLink()      const { return meetingLink;      }

void Activity::setLocation        (const QString& newLocation)          { location         = newLocation;        }
void Activity::setParticipantCount(const int& newParticipantCount)     { participantCount = newParticipantCount; }
void Activity::setEventType       (const QString& newEventType)         { eventType        = newEventType;        }
void Activity::setOnline          (const bool& newOnline)              { online           = newOnline;           }
void Activity::setMeetingLink     (const QString& newMeetingLink)       { meetingLink      = newMeetingLink;      }

bool Activity::remove() {
    return TaskListManager::getInstance().removeTask(getId());
}

void Activity::accept(ConstVisitor& v) {
    v.visit(*this);
}

void Activity::accept(Visitor &v) {
    v.visit(this);
}

Activity::~Activity(){
}
