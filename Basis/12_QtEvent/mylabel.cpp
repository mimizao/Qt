#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>
MyLabel::MyLabel(QWidget *parent)
    : QLabel{parent} {
    // 设置鼠标追踪
    setMouseTracking(true);
}

// 鼠标进入
void MyLabel::enterEvent(QEvent *event) {
    qDebug() << "enter";
}

// 鼠标离开
void MyLabel::leaveEvent(QEvent *) {
    qDebug() << "leave";
}


// 鼠标按下
void MyLabel:: mousePressEvent(QMouseEvent *ev) {
    if (ev->button() == Qt::LeftButton) {
        QString str =  QString("press x = %1,y = %2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}
// 鼠标释放
void MyLabel:: mouseReleaseEvent(QMouseEvent *ev) {
    if (ev->button() == Qt::LeftButton) {
        QString str = QString("release global x = %1, global y = %2").arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
}
// 鼠标移动,注意这里需要鼠标按下了之后在移动才行
void MyLabel:: mouseMoveEvent(QMouseEvent *ev) {
    // 因为移动是一个持续的状态，所以再像上面那么写就不行了，有可能会存在偷换按键的情况
//    if (ev->button() == Qt::LeftButton) {
//        QString str = QString("move x = %1, y = %2").arg(ev->x()).arg(ev->y());
//        qDebug() << str;
//    }

    // 如果是状态的操作的话就需要用这种按位与的判断才行
//    if (ev->buttons() & Qt::LeftButton) {
//        QString str = QString("move x = %1, y = %2").arg(ev->x()).arg(ev->y());
//        qDebug() << str;
//    }

    // 如果设置了鼠标追踪就不需要按下才能生效
    QString str = QString("move x = %1, y = %2").arg(ev->x()).arg(ev->y());
    qDebug() << str;
}

// 如果是ture代表用户处理这个事件，不向下分发
bool MyLabel::event(QEvent *e) {
    if (e->type() == QEvent::MouseButtonPress) {
        QMouseEvent *ev = static_cast<QMouseEvent *>(e); // 静态类型转换
        QString str = QString("event: global x = %1, global y = %2").arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
        return true;
    }
    // 其他事件，交给父类处理，默认处理
    return QLabel::event(e);
}
