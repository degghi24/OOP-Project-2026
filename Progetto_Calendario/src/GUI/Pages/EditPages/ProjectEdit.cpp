#include "ProjectEdit.h"
#include "LabelBlock.h"

#include <QScrollArea>

ProjectEdit::ProjectEdit(Project *task, QWidget *parent): DeadlineEditPage(task,parent) {
    setUp();

    if(task){
        milestone->setText(task->getMilestone().c_str());
        for(const auto &it : task->getTeam()){
            team->setText(it);
            addTeamMember();
        }
        budget->setValue(task->getBudget());
        status->setText(task->getStatus().c_str());
        for(const auto &it : task->getTags()){
            tags->setText(it);
            addTag();
        }
    }
}

ProjectEdit::ProjectEdit(QWidget *parent): DeadlineEditPage(parent) {
    setUp();
}

void ProjectEdit::setUp(){
    milestone = new QLineEdit();
    team = new QLineEdit(); // multi insert
    budget = new QSpinBox();
    status = new QLineEdit();
    tags = new QLineEdit(); // multi insert

    page->addWidget(new QLabel("Milestone:"));
    page->addWidget(milestone);

    QHBoxLayout *lineTeam = new QHBoxLayout();
    lineTeam->setAlignment(Qt::AlignLeft);
    lineTeam->addWidget(new QLabel("Team:"));
    lineTeam->addWidget(team);
    QPushButton *addTeamMemberButton = new QPushButton();
    addTeamMemberButton->setText("Add");
    addTeamMemberButton->setFixedSize(40,20);
    connect(addTeamMemberButton, &QPushButton::clicked, this, &ProjectEdit::addTeamMember);
    lineTeam->addWidget(addTeamMemberButton);
    page->addLayout(lineTeam);

    //scroll area for Team list
    QScrollArea *teamScrollArea = new QScrollArea();
    teamScrollArea->setWidgetResizable(true);
    page->addWidget(teamScrollArea);
    QWidget *teamList = new QWidget();
    teamScrollArea->setWidget(teamList);
    teamScrollAreaLayout = new QVBoxLayout(teamList);
    teamScrollAreaLayout->setAlignment(Qt::AlignTop);
    teamScrollAreaLayout->setContentsMargins(1,1,1,1);
    teamScrollAreaLayout->setSpacing(1);

    QHBoxLayout *lineBuidget = new QHBoxLayout();
    lineBuidget->setAlignment(Qt::AlignLeft);
    lineBuidget->addWidget(new QLabel("Budget:"));
    lineBuidget->addWidget(budget);
    page->addLayout(lineBuidget);

    QHBoxLayout *lineStatus = new QHBoxLayout();
    lineStatus->setAlignment(Qt::AlignLeft);
    lineStatus->addWidget(new QLabel("Status:"));
    lineStatus->addWidget(status);
    page->addLayout(lineStatus);

    QHBoxLayout *lineTags = new QHBoxLayout();
    lineTags->setAlignment(Qt::AlignLeft);
    lineTags->addWidget(new QLabel("Tags:"));
    lineTags->addWidget(tags);
    QPushButton *addTagButton = new QPushButton();
    addTagButton->setText("Add");
    addTagButton->setFixedSize(40,20);
    connect(addTagButton, &QPushButton::clicked, this, &ProjectEdit::addTag);
    lineTags->addWidget(addTagButton);
    page->addLayout(lineTags);

    //scroll area for Tag list
    QScrollArea *tagScrollArea = new QScrollArea();
    tagScrollArea->setWidgetResizable(true);
    page->addWidget(tagScrollArea);
    QWidget *tagList = new QWidget();
    tagScrollArea->setWidget(tagList);
    tagScrollAreaLayout = new QVBoxLayout(tagList);
    tagScrollAreaLayout->setAlignment(Qt::AlignTop);
    tagScrollAreaLayout->setContentsMargins(1,1,1,1);
    tagScrollAreaLayout->setSpacing(1);

}



void ProjectEdit::addTeamMember(){
    teamScrollAreaLayout->addWidget(new LabelBlock(team->text()));
    team->clear();
}

void ProjectEdit::addTag(){
    tagScrollAreaLayout->addWidget(new LabelBlock(tags->text()));
    tags->clear();
}



std::string ProjectEdit::getMilestone() const{
    return milestone->text().toStdString();
}

QStringList ProjectEdit::getTeam() const{
    QStringList teamList;
    for(int i = 0; i < teamScrollAreaLayout->count(); ++i){
        teamList.append((static_cast<LabelBlock*>(teamScrollAreaLayout->itemAt(i)->widget()))->getText());
    }
    return teamList;
}

int ProjectEdit::getBudget() const{
    return budget->value();
}
std::string ProjectEdit::getStatus() const{
    return status->text().toStdString();
}
QStringList ProjectEdit::getTags() const{
    QStringList tagList;
    for(int i = 0; i < tagScrollAreaLayout->count(); ++i){
        tagList.append((static_cast<LabelBlock*>(tagScrollAreaLayout->itemAt(i)->widget()))->getText());
    }
    return tagList;
}

void ProjectEdit::createTask(){
    Project *newProject = new Project(getTitle(),getDescription(),getAssignee(), QDate::currentDate(),
                             getDueDate(),static_cast<Deadline::Priority>(getPriority()),isCompleted(),isSkipped(),
                             getMilestone(),getTeam(),getBudget(),getStatus(),getTags());
    emit returnTask(newProject);
}
