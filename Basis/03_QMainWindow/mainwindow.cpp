#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QDebug>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    resize(600, 400);
    // 记住一点，只能有一个的都是set，可以有多个的都是add

    // 菜单栏创建，菜单栏最多只能有一个
    QMenuBar *bar = menuBar();
    // 将菜单栏放入到窗口中
    setMenuBar(bar);
    // 创建菜单
    QMenu *fileMenu = bar->addMenu("File");
    // QMenu *editMenu = bar->addMenu("Edit");
    // 创建菜单项
    QAction *newAction = fileMenu->addAction("New");
    // 添加分割线
    fileMenu->addSeparator();
    QAction *openAction = fileMenu->addAction("Open");

    // 工具栏可以有多个
    QToolBar *toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolBar);
    // 后期设置，只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    // 设置浮动操作
    toolBar->setFloatable(false);
    // 设置移动（总开关）
    toolBar->setMovable(false);
    // 工具栏中可以设置内容
    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);
    // 工具栏中添加控件
    QPushButton *btn = new QPushButton("btn", this);
    toolBar->addWidget(btn);

    // 状态栏，最多有一个
    QStatusBar *stBar = statusBar();
    // 设置到窗口中
    setStatusBar(stBar);
    // 放标签控件
    QLabel *leftLabel = new QLabel("left", this);
    stBar->addWidget(leftLabel);
    QLabel *rightLabel = new QLabel("right", this);
    stBar->addPermanentWidget(rightLabel);

    // 铆接部件（浮动窗口）
    QDockWidget *dockWidget = new QDockWidget("float", this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
    // 设置后期允许停靠的区域
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    // 设置中心部件，也就是核心窗口，这个也是只能有一个
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

}

MainWindow::~MainWindow() {
}

