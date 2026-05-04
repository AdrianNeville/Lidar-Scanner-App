#include "propdialog.h"
#include "ui_propdialog.h"
#include "types/position.h"

PropDialog::PropDialog(PointCloudHandler* h, int idx,
                       QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PropDialog)
{
    this->handler = h;
    this->index = idx;

    ui->setupUi(this);
    setFixedSize(size());

    auto p = h->getPosData(idx);

    this->originalPosition = p;

    ui->xSpinBox->setValue(p[0]);
    ui->ySpinBox->setValue(p[1]);
    ui->zSpinBox->setValue(p[2]);
    ui->rollSpinBox->setValue(p[3]);
    ui->pitchSpinBox->setValue(p[4]);
    ui->yawSpinBox->setValue(p[5]);
}

PropDialog::~PropDialog()
{
    delete ui;
}

void PropDialog::on_closeButton_clicked()
{
    this->close();
}


void PropDialog::on_revertButton_clicked()
{
    ui->xSpinBox->setValue(this->originalPosition[0]);
    ui->ySpinBox->setValue(this->originalPosition[1]);
    ui->zSpinBox->setValue(this->originalPosition[2]);
    ui->rollSpinBox->setValue(this->originalPosition[3]);
    ui->pitchSpinBox->setValue(this->originalPosition[4]);
    ui->yawSpinBox->setValue(this->originalPosition[5]);

    std::array<double,6> arr = {
        ui->xSpinBox->value(),
        ui->ySpinBox->value(),
        ui->zSpinBox->value(),
        ui->rollSpinBox->value(),
        ui->pitchSpinBox->value(),
        ui->yawSpinBox->value()
    };
    this->handler->setPosData(arr, index);
}


void PropDialog::on_applyButton_clicked()
{
    std::array<double,6> arr = {
        ui->xSpinBox->value(),
        ui->ySpinBox->value(),
        ui->zSpinBox->value(),
        ui->rollSpinBox->value(),
        ui->pitchSpinBox->value(),
        ui->yawSpinBox->value()
    };
    this->handler->setPosData(arr, index);
}

