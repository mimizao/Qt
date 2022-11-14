#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);

    // 启动定时器，会返回定时器的一个唯一标识
    id1 = startTimer(1000);
    id2 = startTimer(2000);

    // 定时器的第二种方式
    QTimer *timer = new QTimer(this);
    timer->start(500);
    connect(timer, &QTimer::timeout, this, [ = ]() {
        static int num3 = 1;
        // laber3 2s+1
        ui->label_3->setText(QString::number(num3++));
    });

    // 点击暂停按钮停止定时器
    connect(ui->btn, &QPushButton::clicked, this, [ = ]() {
        timer->stop();
    });
}

void Widget::timerEvent(QTimerEvent *ev) {
    if (ev->timerId() == id1) {
        static int num1 = 1;
        // label1 1s+1
        ui->label_1->setText(QString::number(num1++));
    }
    if (ev->timerId() == id2) {
        static int num2 = 1;
        // laber2 2s+1
        ui->label_2->setText(QString::number(num2++));
    }
}

Widget::~Widget() {
    delete ui;
}
