#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);

    // TableWidget控件
    // 设置列数
    ui->tableWidget->setColumnCount(3);
    // 设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Gender" << "Age");
    // 设置行数
    ui->tableWidget->setRowCount(5);
    // 设置正文
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("sven"));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString::number(i + j)));
        }
    }


}

Widget::~Widget() {
    delete ui;
}

