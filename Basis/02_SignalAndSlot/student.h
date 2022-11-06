#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

// 早期Qt版本必须要写在publish slots下，新版本可以写到public或者全局下
// 返回值void，需要声明也需要实现
// 可以有参数，可以发生重载
class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

    void treat();

signals:

};

#endif // STUDENT_H
