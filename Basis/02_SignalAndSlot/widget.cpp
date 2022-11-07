#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);
    this->resize(600, 400);

    // 创建一个老师对象
    this->teacher = new Teacher(this);

    // 创建一个学生对象
    this->student = new Student(this);

    // 老师饿了和学生请客的连接
    // connect(teacher,&Teacher::hungry,student,&Student::treat);

    // 当自定义的信号和槽出现重载，需要用指针指向函数地址
    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void(Student:: *studentSlot)(QString) = &Student::treat;
    connect(teacher, teacherSignal, student, studentSlot);

    // 调用下课函数
    classIsOver();

    // 点击一个下课的按钮，再触发下课，不过这里依然是用信号去触发一个槽函数
    QPushButton *btn = new QPushButton("class is over", this);
    // connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);

    // 无参信号和槽连接
    void(Teacher::*teacherSignal2)(void) = &Teacher::hungry;
    void(Student::*studentSlot2)(void) = &Student::treat;
    connect(teacher, teacherSignal2, student, studentSlot2);

    // 信号连接信号
    connect(btn, &QPushButton::clicked, teacher, teacherSignal2);

    // 断开信号，参数和连接是一样的
    disconnect(teacher, teacherSignal2, student, studentSlot2);

    // 扩展
    // 1、信号可以连接信号
    // 2、一个信号可以连接多个槽函数
    // 3、多个信号可以连接同一个槽函数
    // 4、信号和槽函数的参数必须类型一一对应
    // 5、信号和槽的参数个数是否必须一致？ 信号的参数个数是可以大于槽函数参数个数

    // Lambda表达式测试
    QPushButton *myBtn1 = new QPushButton(this);
    QPushButton *myBtn2 = new QPushButton(this);
    myBtn1->move(100, 100);
    myBtn2->move(200, 200);
    int m = 10;
    connect(myBtn1, &QPushButton::clicked, this, [m]() mutable{m = 100 + 10; qDebug() << m;});
    connect(myBtn2, &QPushButton::clicked, this, [ = ]() {
        qDebug() << m;
    });
    qDebug() << m;
    int ret = []()->int{return 1000;}();
    qDebug() << "ret =" << ret;

    // 利用lambda表达式实现点击按钮关闭窗口
    QPushButton *myBtn3 = new QPushButton("close", this);
    myBtn3->move(300, 300);
    connect(myBtn3, &QPushButton::clicked, this, [ = ]() {
        this->close();
        emit teacher->hungry("rice");
    });

}

void Widget::classIsOver() {
    // 下课函数，调用后触发老师饿了的信号
    // emit teacher->hungry();
    emit teacher->hungry("rice");
}


Widget::~Widget() {
    delete ui;
}

