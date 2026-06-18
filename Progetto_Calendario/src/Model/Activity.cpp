#include "data_persistancy/ConstVisitor.h"
#include "Headers/Activity.h"
#include <iostream>
using std::cout;
using std::endl;

Activity::Activity(string title, string description,
                   string assignee, QDate creationDate,
                   QDate startDate, QDate endDate,
                   string startTime, int totalDuration,
                   string location, int participantCount,
                   string eventType, bool online, string meetingLink)
    : AbstractTask(title, description, assignee, creationDate),
    TimedTask(title, description, assignee, creationDate,
              startDate, endDate, startTime, totalDuration),
    location(location), participantCount(participantCount),
    eventType(eventType), online(online), meetingLink(meetingLink)
{}

string Activity::getLocation()         const { return location;         }
int    Activity::getParticipantCount() const { return participantCount; }
string Activity::getEventType()        const { return eventType;        }
bool   Activity::isOnline()            const { return online;           }
string Activity::getMeetingLink()      const { return meetingLink;      }

void Activity::setLocation        (const string& newLocation)          { location         = newLocation;        }
void Activity::setParticipantCount(const int& newParticipantCount)     { participantCount = newParticipantCount; }
void Activity::setEventType       (const string& newEventType)         { eventType        = newEventType;        }
void Activity::setOnline          (const bool& newOnline)              { online           = newOnline;           }
void Activity::setMeetingLink     (const string& newMeetingLink)       { meetingLink      = newMeetingLink;      }

bool Activity::remove() {
    return true; // placeholder
}

void Activity::accept(ConstVisitor& v) {
    v.visit(*this);
}

void Activity::accept(Visitor &v) {
    v.visit(this);
}

