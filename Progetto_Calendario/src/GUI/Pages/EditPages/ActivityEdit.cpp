#include "ActivityEdit.h"

ActivityEdit::ActivityEdit(Activity *task, QWidget *parent): TimedEditPage(task, parent) {

    setUp();

    if(task){
        location->setText(task->getLocation().c_str());
        partecipationCount->setValue(task->getParticipantCount());
        eventType->setText(task->getEventType().c_str());
        online->setChecked(task->isOnline());
        meetingLink->setText(task->getMeetingLink().c_str());
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

std::string ActivityEdit::getLocation() const{
    return location->text().toStdString();
}
int ActivityEdit::getPartecipationCount() const{
    return partecipationCount->value();
}
std::string ActivityEdit::getEventType() const{
    return eventType->text().toStdString();
}
bool ActivityEdit::isOnline() const{
    return online->isChecked();
}
std::string ActivityEdit::getMeetingLink() const{
    return meetingLink->text().toStdString();
}

void ActivityEdit::createTask(){
    Activity *newActivity = new Activity(getTitle(),getDescription(),getAssignee(), QDate::currentDate(),
                                         getStartDate(),getEndDate(),getStartTime(),getDuration(),
                                         getLocation(),getPartecipationCount(),getEventType(),isOnline(),getMeetingLink());
    emit returnTask(newActivity);
}
