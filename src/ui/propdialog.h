#ifndef PROPDIALOG_H
#define PROPDIALOG_H

#include <QDialog>
#include "pointcloudhandler.h"

namespace Ui {
class PropDialog; // Forward declare the UI class generated from propdialog.ui
}

class PropDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PropDialog(PointCloudHandler* h, int index, QWidget *parent = nullptr);
    ~PropDialog();

private slots:
    void on_closeButton_clicked();

    void on_revertButton_clicked();

    void on_applyButton_clicked();

private:
    Ui::PropDialog *ui; // Pointer to the generated UI
    PointCloudHandler* handler;
    int index;
    std::array<double, 6> originalPosition;
};

#endif // PROPDIALOG_H
