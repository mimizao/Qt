#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);

    // treeWidget树控件使用
    ui->treeWidget->setHeaderLabels(QStringList() << "Hero" << "Hero Introduct");
    QTreeWidgetItem *powerItem = new QTreeWidgetItem(QStringList() << "Power");
    QTreeWidgetItem *agileItem = new QTreeWidgetItem(QStringList() << "Agile");
    QTreeWidgetItem *witItem = new QTreeWidgetItem(QStringList() << "Wit");
    // 加载顶层节点
    ui->treeWidget->addTopLevelItem(powerItem);
    ui->treeWidget->addTopLevelItem(agileItem);
    ui->treeWidget->addTopLevelItem(witItem);

    // 追加子节点
    QStringList heroList;
    heroList << "sven" << "really man";
    QTreeWidgetItem *sven = new QTreeWidgetItem(heroList);
    powerItem->addChild(sven);
}

Widget::~Widget() {
    delete ui;
}

