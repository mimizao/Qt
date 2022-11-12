#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);

    // 切换stackWidget
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->btn_stack0, &QPushButton::clicked, [ = ]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btn_stack1, &QPushButton::clicked, [ = ]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->btn_stack2, &QPushButton::clicked, [ = ]() {
        ui->stackedWidget->setCurrentIndex(2);
    });

}

Widget::~Widget() {
    delete ui;
}

