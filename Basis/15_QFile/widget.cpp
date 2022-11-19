#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);

    // 点击选取文件按钮，弹出文件对话框
    connect(ui->pushButton, &QPushButton::clicked, this, [ = ]() {
        QString path = QFileDialog::getOpenFileName(this, "open file", "‪C:\\Users\\Sven\\Desktop");
        // 将路径放入到lineEdit中
        ui->lineEdit->setText(path);

        // 读取内容，放入到textEdit中
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        QByteArray arr = file.readAll();
        ui->textEdit->setText(arr);
        file.close();
    });


}

Widget::~Widget() {
    delete ui;
}

