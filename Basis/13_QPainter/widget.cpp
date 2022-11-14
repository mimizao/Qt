#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);
}

void Widget::paintEvent(QPaintEvent *event) {
    // 实例化画家对象，this指定的是绘图设备
    QPainter painter(this);

    // 设置笔
    QPen pen(QColor(255, 0, 0));
    painter.setPen(pen);

    // 画线
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));
    // 画圆
    painter.drawEllipse(QPoint(100, 100), 50, 50);

}

Widget::~Widget() {
    delete ui;
}

