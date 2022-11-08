#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // 用绝对路径或者相对路径的方式添加资源
    // ui->actionNew->setIcon(QIcon("E:\\Qt\\Basis\\04_QtSource\\IMG.jpg"));

    // 使用添加Qt资源 ": + 前缀名 + 文件名"
    ui->actionNew->setIcon(QIcon(":/IMG.jpg"));

}

MainWindow::~MainWindow() {
    delete ui;
}

