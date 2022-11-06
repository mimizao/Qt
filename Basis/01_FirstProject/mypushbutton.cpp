#include "mypushbutton.h"
#include <QDebug>
MyPushButton::MyPushButton(QWidget *parent)
    : QPushButton{parent}
{
    qDebug() << "my button constructor";
}

MyPushButton::~MyPushButton(){
    qDebug() << "my button destructor";
}
