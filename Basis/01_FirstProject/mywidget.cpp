#include "mywidget.h"
#include <QPushButton> // 按钮控件的头文件
#include "mypushbutton.h"

// 命名规范
// 类名首字母大写，单词和单词之间首字母大写
// 函数名变量名称首字母小写，单词和单词之间首字母大写

// 快捷键
// 注释 ctrl + /
// 运行 ctrl + r
// 编译 ctrl + b
// 整行移动 ctrl + shift + ↑ 或者 ↓
// 帮助文档 F1
// 自动对齐 ctrl + i
// 同名之间的.h和.cpp切换 F4

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    // 创建一个按钮
    QPushButton *btn = new QPushButton;
    // btn->show(); // show以顶层的方式弹出窗口控件

    // 让btn对象依赖在myWidget窗口中
    btn->setParent(this);

    // 显示文本
    btn->setText("first button");

    // 创建第二个按钮
    QPushButton *btn2 = new QPushButton("second button",this);

    // 移动btn2按钮
    btn2->move(100,100);

    // 重置窗口的大小
    resize(600,400);

    // 设置固定窗口大小
    setFixedSize(600,400);

    // 设置窗口标题
    setWindowTitle("first window");

    // 设置按钮的大小
    btn2->resize(100,100);

    // 创建一个自己的按钮对象
    MyPushButton * myBtn = new MyPushButton;
    myBtn->setText("my button");
    myBtn->move(200,200);
    myBtn->setParent(this); // 设置到对象树中

    // 需求：点击我的按钮，关闭当前窗口，使用信号与槽
    // 参数1：信号的发送者
    // 参数2：发送的信号(函数的地址)
    // 参数3：信号的接收者
    // 参数4：处理的槽函数
    connect(myBtn,&QPushButton::clicked,this,&myWidget::close);
}

myWidget::~myWidget()
{
}

