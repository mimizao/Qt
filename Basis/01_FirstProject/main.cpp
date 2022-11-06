#include "mywidget.h"

#include <QApplication> // 包含一个应用程序类的头文件

///
/// \brief main 程序入口
/// \param argc 命令行变量的数量
/// \param argv 命令行变量的数组
/// \return
///
int main(int argc, char *argv[])
{
    // a应用程序对象，在Qt中，应用程序对象，有且仅有一个
    QApplication a(argc, argv);
    // 窗口对象 myWidget父类 -> QWidget
    myWidget w;
    // 窗口显示，默认不会显示，必须要调用show方法显示窗口
    w.show();
    // 让应用程序对象进入消息循环
    return a.exec();
}
