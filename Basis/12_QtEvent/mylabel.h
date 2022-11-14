#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QEvent>
class MyLabel : public QLabel {
    Q_OBJECT
  public:
    explicit MyLabel(QWidget *parent = nullptr);

    // 鼠标进入
    void enterEvent(QEvent *event);
    // 鼠标离开
    void leaveEvent(QEvent *);

    // 鼠标按下
    virtual void mousePressEvent(QMouseEvent *ev);
    // 鼠标释放
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    // 鼠标移动,注意这里需要鼠标按下了之后在移动才行
    virtual void mouseMoveEvent(QMouseEvent *ev);

    // 通过event时间分发器拦截鼠标按下事件
    bool event(QEvent *e);

  signals:

};

#endif // MYLABEL_H
