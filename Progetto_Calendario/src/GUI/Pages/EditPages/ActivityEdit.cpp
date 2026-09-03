#include "ActivityEdit.h"

ActivityEdit::ActivityEdit(Activity *task, QWidget *parent): TimedEditPage(task, parent) {

    savedActivity =  task;

    setUp();

    if(task){
        location->setText(task->getLocation());
        partecipationCount->setValue(task->getParticipantCount());
        eventType->setText(task->getEventType());
        online->setChecked(task->isOnline());
        meetingLink->setText(task->getMeetingLink());
    }
}

ActivityEdit::ActivityEdit(QWidget *parent): TimedEditPage(parent) {
    setUp();
}

void ActivityEdit::setUp(){

    location = new QLineEdit();
    partecipationCount = new QSpinBox();
    eventType = new QLineEdit();
    online = new QCheckBox();
    meetingLink = new QLineEdit();

    page->addWidget(new QLabel("Location:"));
    page->addWidget(location);
    page->addWidget(new QLabel("Number of Partecipants:"));
    page->addWidget(partecipationCount);
    page->addWidget(new QLabel("Type of Event:"));
    page->addWidget(eventType);
    QHBoxLayout *line = new QHBoxLayout();
    line->setAlignment(Qt::AlignLeft);
    line->addWidget(new QLabel("Is Online:"));
    line->addWidget(online);
    page->addLayout(line);
    page->addWidget(new QLabel("Meeting Link:"));
    page->addWidget(meetingLink);

}

QString ActivityEdit::getLocation() const{
    return location->text();
}
int ActivityEdit::getPartecipationCount() const{
    return partecipationCount->value();
}
QString ActivityEdit::getEventType() const{
    return eventType->text();
}
bool ActivityEdit::isOnline() const{
    return online->isChecked();
}
QString ActivityEdit::getMeetingLink() const{
    return meetingLink->text();
}

void ActivityEdit::createTask(){
    Activity *newActivity = new Activity(getTitle(),getDescription(),getAssignee(), QDate::currentDate(),
                                         getStartDate(),getEndDate(),getStartTime(),getDuration(),
                                         getLocation(),getPartecipationCount(),getEventType(),isOnline(),getMeetingLink());
    emit returnTask(newActivity);
}

void ActivityEdit::saveEdit(){

    savedActivity->setTitle(getTitle());
    savedActivity->setDescription(getDescription());
    savedActivity->setAssignee(getAssignee());
    savedActivity->setStartDate(getStartDate());
    savedActivity->setEndDate(getEndDate());
    savedActivity->setStartTime(getStartTime());
    savedActivity->setDuration(getDuration());
    savedActivity->setLocation(getLocation());
    savedActivity->setParticipantCount(getPartecipationCount());
    savedActivity->setEventType(getEventType());
    savedActivity->setOnline(isOnline());
    savedActivity->setMeetingLink(getMeetingLink());
}
