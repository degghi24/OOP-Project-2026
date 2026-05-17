#ifndef PROJECTEDIT_H
#define PROJECTEDIT_H

#include "DeadlineEditPage.h"
#include "Model/Headers/Project.h"

#include <QWidget>
#include <QSpinBox>

class ProjectEdit: public DeadlineEditPage{
    Q_OBJECT

private:
    QLineEdit *milestone = nullptr;
    QLineEdit *team = nullptr;
    QSpinBox *budget = nullptr;
    QLineEdit *status = nullptr;
    QLineEdit *tags = nullptr;

    QVBoxLayout *teamScrollAreaLayout = nullptr;
    QVBoxLayout *tagScrollAreaLayout = nullptr;

    void setUp();

private slots:
    void addTeamMember();
    void addTag();

public slots:
    void createTask();

signals:
    void returnTask(Project *task);

public:
    std::string getMilestone() const;
    QStringList getTeam() const;
    int getBudget() const;
    std::string getStatus() const;
    QStringList getTags() const;

    ProjectEdit(Project *task, QWidget *parent = nullptr);
    ProjectEdit(QWidget *parent = nullptr);
};

#endif // PROJECTEDIT_H
