#include "student.h"
#include <QDebug>
Student::Student(QObject *parent)
    : QObject{parent}
{

}

void Student::treat()
{
    qDebug() << "eat";
}

void Student::treat(QString foodName)
{
    // 这里的话如果不转的话，foodName会带引号
    qDebug() << "eat" << foodName.toUtf8().data();
}
