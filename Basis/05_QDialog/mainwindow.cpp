#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // 点击新建按钮，弹出对话框
    connect(ui->actionNew, &QAction::triggered, [ = ]() {
        // 对话框分类
        // 模态对话框（不可以对其他窗口进行操作） 非模块对话框（可以对其他窗口进行操作）
        // 模态对话框，有阻塞的功能
//        QDialog dlg(this);
//        dlg.resize(200, 100);
//        dlg.exec();
//        qDebug() << "dlg";

        // 非模态对话框
//        QDialog *dlg2 = new QDialog(this);
//        dlg2->resize(200, 100);
//        dlg2->show();
//        // 因为这个是创建在堆上的，为了能够在关闭的时候自动回收，所以加上这个属性。
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);
//        qDebug() << "dlg2";

        // 消息对话框
        // 至关重要的一般用来表示错误
        // QMessageBox::critical(this, "critical", "error");
        // 消息
        // QMessageBox::information(this, "info", "information");
        // 提问
        if (QMessageBox::Save == QMessageBox::question(this, "ques", "question", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel)) {
            qDebug() << "save";
        }
        // 警告
        QMessageBox::warning(this, "warn", "warn");

    });
}

MainWindow::~MainWindow() {
    delete ui;
}
