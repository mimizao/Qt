#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QPicture>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);

//    // Pixmap绘图设备
//    QPixmap pix(300, 300);

//    // 声明画家
//    QPainter painter(&pix);
//    painter.drawEllipse(QPoint(150, 150), 100, 100);

//    // 保存
//    pix.save("E:\\pix.png");

    // QPicture绘图设备，可以记录和重现绘图指令
    // 这里调了很长时间，如果不把上面注释掉就是一片空白
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);
    painter.setPen(QPen(Qt::black));
    painter.drawEllipse(QPoint(150, 150), 100, 100);
    painter.end();
    pic.save("E:\\pic.biy");

}

void Widget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
//    QImage img;
//    img.load(":/IMG_20181117_191035.jpg");

//    // 修改像素点
//    for (int i = 50; i < 100; i++) {
//        for (int j = 50; j < 100; j++) {
//            QRgb value = qRgb(255, 0, 0);
//            img.setPixel(i, j, value);
//        }
//    }
    // painter.drawImage(0, 0, img);

    // 重现QPitcure的绘图指令
    QPicture pic;
    pic.load("E:\\pic.biy");
    painter.drawPicture(0, 0, pic);

}

Widget::~Widget() {
    delete ui;
}

