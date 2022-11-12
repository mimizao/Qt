#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget) {
    ui->setupUi(this);

    // 通过调整数字改变
    void (QSpinBox:: *spSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spSignal, ui->horizontalSlider, &QSlider::setValue);

    // 通过滑动调整这个值
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

SmallWidget::~SmallWidget() {
    delete ui;
}
