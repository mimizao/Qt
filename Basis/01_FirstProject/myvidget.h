#ifndef MYVIDGET_H
#define MYVIDGET_H

#include <QWidget>

class myVidget : public QWidget
{
    Q_OBJECT

public:
    myVidget(QWidget *parent = nullptr);
    ~myVidget();
};
#endif // MYVIDGET_H
