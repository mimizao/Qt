#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建一个老师对象
    this->teacher=new Teacher(this);

    // 创建一个学生对象
    this->student=new Student(this);

    // 老师饿了和学生请客的连接
    connect(teacher,&Teacher::hungry,student,&Student::treat);

    // 调用下课函数
    classIsOver();
}

void Widget::classIsOver()
{
    // 下课函数，调用后触发老师饿了的信号
    emit teacher->hungry();
}


Widget::~Widget()
{
    delete ui;
}

