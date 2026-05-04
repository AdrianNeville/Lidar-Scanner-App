#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QOpenGLFunctions>
#include <QFileDialog>
#include <visualizer.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void addKeyFrameToTable(int index);

private slots:
    void on_comboBox_currentIndexChanged(int index);
    void updateServo(QByteArray command);
    void on_tiltEdit_returnPressed();
    void on_panEdit_returnPressed();
    void on_getDistanceButton_clicked();
    void sendData(int instruction, int msg);
    void readLidarData();
    void on_scanButton_clicked();
    void on_rotCheck_stateChanged(int arg1);

    void on_leftRot_pressed();

    void on_rightRot_pressed();

    void on_leftRot_released();

    void on_rightRot_released();

    void on_elevEdit_returnPressed();

    void openClicked();

    void saveKeyframe();
    void saveKeyframes();
    void saveKeyframesAsOne();
    void saveSession();
    void loadSession();

    // void on_nextKeyframe_clicked();

    // void on_prevKeyframe_clicked();

    // void on_clearKeyframe_clicked();

    // void on_clearAllKeyframes_clicked();

    void on_registerButton_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void onAddKeyframeClicked();

    void onKeyframeTableRowSelected(const QModelIndex &current, const QModelIndex &previous);

    void on_constructMeshButton_clicked();

    void on_lowerButton_clicked();

    void on_higherButton_clicked();

    void on_stopButton_clicked();

    void on_pauseButton_clicked();

    void on_lineScanButton_clicked();

    void on_rotAzimButton_clicked();

    void on_panScanButton_clicked();

    void on_filterButton_clicked();

    void on_revertButton_clicked();

    void on_combineButton_clicked();

    void on_cleanButton_clicked();

    void on_passButton_clicked();

    void on_voxButton_clicked();

    void on_sorButton_clicked();

    void on_applyAlltoCurButton_clicked();

    void on_applyAlltoAllButton_clicked();

    void on_revertCleanButton_clicked();

    void on_undoCleanButton_clicked();

    void on_redoCleanButton_clicked();

    void on_pairRegisButton_clicked();

    void onUpdateComboCount(int kfCount);

    void on_targetIndC_currentIndexChanged(int index);

    void on_sourceIndC_currentIndexChanged(int index);

    void on_scanOneButton_clicked();

    void on_mirrorCorrectButton_clicked();

    void on_mirrorCorrectButton_2_clicked();

    void on_passButton_2_clicked();

    void on_voxButton_2_clicked();

    void on_sorButton_2_clicked();

    void on_pairRegisButton_2_clicked();

    void on_voxButton_3_clicked();

signals:
    void onShapeChanged(int shapeType);
    void onRotChanged(int rot);
    void stopRot();
    void updateRot(bool dir);
    void sendLidarData(GLfloat d, GLfloat r, GLfloat s, int active, int sq);
    void pcdFileSelected(const QString& filePath);
    void changeKeyframe(int oldIndex, int newIndex);
    void loadEmptyFrame(int index);
    void clearKeyframe(int KFNum);
    void clearAllKeyframes();
    void onRegisterPressed();
    void onConstructMesh();
    void currentTab(int index);
    void radioRowSelected(int index);
    void applyPairwiseRegistration(double maxCorrDist, int maxIter, double fitThresh);
    void applyVoxeltoCombined(double leafSize);

    void updateScanSettings(quint8 eAngles, quint8 aAngles);

    void changeFloatParam(QString name, float value);
    void changeIntParam(QString name, int value);

    void applyFilter(float radius, float upsampleRadius, float upsampleStep, int order);
    void revertKeyframe();

    void triggerUpdate();
    void triggerKeyframeChange(int index);

    void combineKeyframes();
    void cleanKeyframe();

    void applyPassThrough(std::string axis, int min, int max);
    void applyVoxelGrid(double leafSize);
    void applySOR(int meanK, double stddev);
    void applyMirrorCorrect(double maxY);
    void revertClean();
    void undoClean();
    void redoClean();

    void tryRegistration(int sourceIndex, int targetIndex, double maxCorrDist, int maxIter, double fitThresh);

private:
    Visualizer* vis;
    QString servoSetting;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendorID = 6790;
    static const quint16 arduino_uno_productID = 29987;
    QString arduino_port_name;
    bool arduino_is_available;
    QString arrayToString;
    Ui::MainWindow *ui;
    void setupTable();
    void setupScan(int code);
    int keyframe_counter = -1;
    int lastKeyframeRowIndex = -1;
};
#endif // MAINWINDOW_H
