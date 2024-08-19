#include "warmitemwidget.h"
#include "ui_warmitemwidget.h"
#include <QObject>
#include <QDebug>

WarmItemWidget::WarmItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WarmItemWidget)
{
    ui->setupUi(this);

    QObject::connect(ui->spinBoxAimTemp,  QOverload<int>::of(&QSpinBox::valueChanged),
                     ui->lcdNumberAimTemp, static_cast<void (QLCDNumber::*)(int)>(&QLCDNumber::display));


}

WarmItemWidget::~WarmItemWidget()
{
    delete ui;
}

void WarmItemWidget::setLocationName(const QString &locationName)
{
    this->ui->labelName->setText(locationName);
}

void WarmItemWidget::setLocation(const QString &location)
{
    this->ui->labelLocation->setText(location);
}

void WarmItemWidget::setDescription(const QString &description)
{
    this->ui->labelDescription->setText(description);
}

void WarmItemWidget::setPower(const QString &power)
{
    this->ui->labelPower->setText(power);
}
