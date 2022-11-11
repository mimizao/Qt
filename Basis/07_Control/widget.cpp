#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);

    // 设置单选按钮，默认选中man
    ui->rBtnMan->setChecked(true);

    // 选中woman后，打印信息
    connect(ui->rBtnWoman, &QRadioButton::clicked, [ = ]() {
        qDebug() << "woman is checked!";
    });
}

Widget::~Widget() {
    delete ui;
}

