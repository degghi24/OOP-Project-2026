#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
using std::string;
#include "TimedTask.h"

class Activity : public TimedTask {
private:
    string location;
    int participantCount;
    string eventType;
    bool online;
    string meetingLink;

public:
    Activity(string id, string title, string description,
             string assignee, string creationDate,
             string startDate, string endDate,
             string startTime, int totalDuration,
             string location, int participantCount,
             string eventType, bool online, string meetingLink);
    virtual ~Activity() = default;

    string getLocation()         const;
    int    getParticipantCount() const;
    string getEventType()        const;
    bool   isOnline()            const;
    string getMeetingLink()      const;

    void setLocation        (const string& newLocation);
    void setParticipantCount(const int& newParticipantCount);
    void setEventType       (const string& newEventType);
    void setOnline          (const bool& newOnline);
    void setMeetingLink     (const string& newMeetingLink);

    void display()          override;
    bool remove()           override;
    void accept(Visitor& v) override;
};

#endif // ACTIVITY_H
