#include "data_persistancy/Visitor.h"
#include "Headers/Activity.h"
#include <iostream>
using std::cout;
using std::endl;

Activity::Activity(string id, string title, string description,
                   string assignee, string creationDate,
                   string startDate, string endDate,
                   string startTime, int totalDuration,
                   string location, int participantCount,
                   string eventType, bool online, string meetingLink)
    : AbstractTask(id, title, description, assignee, creationDate),
    TimedTask(id, title, description, assignee, creationDate,
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

void Activity::display() {
    cout << "Activity: " << getTitle() << endl;
    cout << "Date: " << getStartDate() << " - " << getEndDate() << endl;
    cout << "Location: " << location << endl;
    cout << "Participants: " << participantCount << endl;
    cout << "Online: " << (online ? "Yes" : "No") << endl;
}

bool Activity::remove() {
    return true; // placeholder
}

void Activity::accept(Visitor& v) {
    v.visit(*this);
}
