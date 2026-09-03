#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "TimedTask.h"

class Activity : public TimedTask {
private:
    QString location;
    int participantCount;
    QString eventType;
    bool online;
    QString meetingLink;

public:
    Activity(QString title, QString description,
             QString assignee, QDate creationDate,
             QDate startDate, QDate endDate,
             QString startTime, int totalDuration,
             QString location, int participantCount,
             QString eventType, bool online, QString meetingLink);
    virtual ~Activity() override;

    QString getLocation()         const;
    int    getParticipantCount() const;
    QString getEventType()        const;
    bool   isOnline()            const;
    QString getMeetingLink()      const;

    void setLocation        (const QString& newLocation);
    void setParticipantCount(const int& newParticipantCount);
    void setEventType       (const QString& newEventType);
    void setOnline          (const bool& newOnline);
    void setMeetingLink     (const QString& newMeetingLink);

    bool remove()           override;
    void accept(ConstVisitor& v) override;
    void accept(Visitor& v) override;
};

#endif // ACTIVITY_H
