#include "ActivityEdit.h"

ActivityEdit::ActivityEdit(Activity *task, QWidget *parent): TimedEditPage(task, parent) {

    setUp();

    if(task){
        location->setText(task->getLocation().c_str());
        partecipationCount->setValue(task->getParticipantCount());
        eventType->setText(task->getEventType().c_str());
        isOnline->setChecked(task->isOnline());
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
    isOnline = new QCheckBox();
    meetingLink = new QLineEdit();

    page->addWidget(new QLabel("Location:"));
    page->addWidget(location);
    page->addWidget(new QLabel("Number of Partecipants:"));
    page->addWidget(partecipationCount);
    page->addWidget(new QLabel("Type of Event:"));
    page->addWidget(eventType);
    page->addWidget(new QLabel("Is Online:"));
    page->addWidget(isOnline);
    page->addWidget(new QLabel("Meeting Link:"));
    page->addWidget(meetingLink);

}
