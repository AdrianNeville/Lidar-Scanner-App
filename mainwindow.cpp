#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "visualizer.h"
#include <QRadioButton>
#include "propdialog.h"
#include "position.h"
#include "registrationresult.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Visualizer");

    vis = ui -> visWidget;
    connect(this, SIGNAL(onShapeChanged(int)), vis, SLOT(changeShape(int)));
    connect(this, SIGNAL(onRotChanged(int)), vis, SLOT(changeRot(int)));
    connect(this, SIGNAL(updateRot(bool)), vis, SLOT(updateRot(bool)));
    connect(this, SIGNAL(stopRot()), vis, SLOT(stopRot()));
    connect(this, SIGNAL(sendLidarData(GLfloat,GLfloat,GLfloat,int, int)), vis, SLOT(receiveLidarData(GLfloat,GLfloat,GLfloat,int, int)));
    connect(this, SIGNAL(pcdFileSelected(QString)), vis, SLOT(loadPCD(QString)));
    connect(this, SIGNAL(loadEmptyFrame(int)), vis, SLOT(loadEmptyFrame(int)));
    connect(this, SIGNAL(changeKeyframe(int, int)), vis, SLOT(loadKeyframe(int,int)));
    connect(this, SIGNAL(onRegisterPressed()), vis, SLOT(registerKeyframe()));
    connect(this, SIGNAL(onConstructMesh()), vis, SLOT(constructMesh()));
    connect(this, SIGNAL(currentTab(int)), vis, SLOT(updateCurrentTab(int)));
    connect(this, SIGNAL(updateScanSettings(quint8, quint8)), vis, SLOT(receiveScanSettings(quint8, quint8)));
    connect(this, SIGNAL(triggerUpdate()), vis, SLOT(triggerUpdate()));
    connect(this, SIGNAL(triggerKeyframeChange(int)), vis, SLOT(triggerKeyframeChange(int)));
    connect(vis->getPointCloudHandler(), &PointCloudHandler::newKeyframe, this, &MainWindow::addKeyFrameToTable);
    connect(this, &MainWindow::radioRowSelected, vis->getPointCloudHandler(), &PointCloudHandler::setReference);
    connect(this, &MainWindow::changeFloatParam, vis->getPointCloudHandler(), &PointCloudHandler::changeFloatParam);
    connect(this, &MainWindow::changeIntParam, vis->getPointCloudHandler(), &PointCloudHandler::changeIntParam);
    connect(this, &MainWindow::applyFilter, vis->getPointCloudHandler(), &PointCloudHandler::filterKeyframe);
    connect(this, &MainWindow::revertKeyframe, vis->getPointCloudHandler(), &PointCloudHandler::revertKeyframe);
    connect(this, &MainWindow::combineKeyframes, vis->getPointCloudHandler(), &PointCloudHandler::combineKeyframes);
    connect(this, &MainWindow::cleanKeyframe, vis->getPointCloudHandler(), &PointCloudHandler::cleanKeyframe);
    connect(this, &MainWindow::applyPassThrough, vis->getPointCloudHandler(), &PointCloudHandler::applyPassThrough);
    connect(this, &MainWindow::applyVoxelGrid, vis->getPointCloudHandler(), &PointCloudHandler::applyVoxelGrid);
    connect(this, &MainWindow::applySOR, vis->getPointCloudHandler(), &PointCloudHandler::applySOR);
    connect(this, &MainWindow::applyMirrorCorrect, vis->getPointCloudHandler(), &PointCloudHandler::applyMirrorCorrect);
    connect(this, &MainWindow::revertClean, vis->getPointCloudHandler(), &PointCloudHandler::revertToPreClean);
    connect(this, &MainWindow::undoClean, vis->getPointCloudHandler(), &PointCloudHandler::undoLatestClean);
    connect(this, &MainWindow::redoClean, vis->getPointCloudHandler(), &PointCloudHandler::redoLatestClean);
    connect(this, &MainWindow::tryRegistration, vis->getPointCloudHandler(), &PointCloudHandler::tryRegister);
    connect(this, &MainWindow::applyPairwiseRegistration, vis->getPointCloudHandler(), &PointCloudHandler::registerPairwise);
    connect(this, &MainWindow::applyVoxeltoCombined, vis->getPointCloudHandler(), &PointCloudHandler::applyVoxedToCombined);

    connect(vis->getPointCloudHandler(), &PointCloudHandler::visRegisterKeyframe, vis, &Visualizer::visRegisterKeyframe);

    connect(ui->actionImportK, SIGNAL(triggered()), this, SLOT(openClicked()));
    connect(ui->actionExpCurKeyframe, SIGNAL(triggered()), this, SLOT(saveKeyframe()));
    connect(ui->actionExpAll, SIGNAL(triggered()), this, SLOT(saveKeyframes()));
    connect(ui->actionExpAllAsOne, SIGNAL(triggered()), this, SLOT(saveKeyframesAsOne()));
    connect(ui->actionSave_Session, SIGNAL(triggered()), this, SLOT(saveSession()));
    connect(ui->actionLoad_Session, SIGNAL(triggered()), this, SLOT(loadSession()));

    connect(vis->getPointCloudHandler(), &PointCloudHandler::updateComboCount, this, &MainWindow::onUpdateComboCount);

    arduino = new QSerialPort;
    arduino_is_available = false;
    arduino_port_name = "";

    qDebug() << "Number of Ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            qDebug() << "Vendor: " << serialPortInfo.vendorIdentifier();
            qDebug() << "Identifier: " << serialPortInfo.productIdentifier();

            if(serialPortInfo.productIdentifier() == arduino_uno_productID &&
                serialPortInfo.vendorIdentifier() == arduino_uno_vendorID){
                arduino_port_name = serialPortInfo.portName();
                arduino_is_available = true;
                qDebug() << "Port Available!";
            }
        }
    }

    if(arduino_is_available){
        arduino->setPortName(arduino_port_name);
        if (arduino->open(QSerialPort::ReadWrite)) {
            qDebug() << "Serial port opened successfully!";
        }else{
            qDebug() << "Failed to open port: " << arduino->errorString();
        }
        arduino->setBaudRate(QSerialPort::Baud115200);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);

        connect(arduino, &QSerialPort::readyRead, this, &MainWindow::readLidarData);

        qDebug() << "Arduino is Set!";
    }else{
        // QMessageBox::warning(this, "Port error", "Couldn't find arduino");
    }


    setupTable();

}

void MainWindow::setupTable(){

    ui->keyframeTable->resizeColumnsToContents();
    ui->keyframeTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->keyframeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->keyframeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->keyframeTable->verticalHeader()->setVisible(false);

    connect(ui->keyframeTable->selectionModel(),
            &QItemSelectionModel::currentRowChanged,
            this,
            &MainWindow::onKeyframeTableRowSelected);

    int newRow = ui->keyframeTable->rowCount();
    ui->keyframeTable->insertRow(newRow);

    // Create the button
    QPushButton* addButton = new QPushButton("Add Keyframe");
    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddKeyframeClicked);

    // Center the button using a layout (optional but makes it cleaner)
    QWidget* widget = new QWidget();
    QHBoxLayout* layout = new QHBoxLayout(widget);
    layout->addWidget(addButton);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(0, 0, 0, 0);
    widget->setLayout(layout);

    // Set the widget in column 0 of the new row
    ui->keyframeTable->setCellWidget(newRow, 0, widget);

    // Optional: span across columns if you want the button to take the whole row
    ui->keyframeTable->setSpan(newRow, 0, 1, ui->keyframeTable->columnCount());

    for (int col = 0; col < ui->keyframeTable->columnCount(); ++col) {
        QTableWidgetItem* item = ui->keyframeTable->item(newRow, col);
        if (!item) {
            item = new QTableWidgetItem();
            ui->keyframeTable->setItem(newRow, col, item);
        }
        item->setFlags(item->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable);
    }
}

void MainWindow::onKeyframeTableRowSelected(const QModelIndex &current, const QModelIndex &previous){
    int index = current.row();
    qDebug() << "Table Row: " +QString::number(index);

    int rowCount = ui->keyframeTable->rowCount()-1;
    qDebug() << "Row Count: " << rowCount;
    if(index != rowCount){
        emit MainWindow::changeKeyframe(lastKeyframeRowIndex , index);
        lastKeyframeRowIndex = index;
    }
}

void MainWindow::onAddKeyframeClicked(){
    int curFrame = ui->keyframeTable->rowCount()-1;
    emit MainWindow::loadEmptyFrame(curFrame);
}

void MainWindow::addKeyFrameToTable(int index){

    int row = ui->keyframeTable->rowCount()-1;
    ui->keyframeTable->insertRow(row);

    // --- Label column ---
    QTableWidgetItem* indexItem = new QTableWidgetItem(QString("%1").arg(index+1));
    indexItem->setTextAlignment(Qt::AlignCenter);
    ui->keyframeTable->setItem(row, 0, indexItem);

    // --- Checkbox column ---
    QWidget* checkboxWidget = new QWidget();
    QCheckBox* checkbox = new QCheckBox();
    checkbox->setChecked(true); // default: visible

    QHBoxLayout* layout = new QHBoxLayout(checkboxWidget);
    layout->addWidget(checkbox);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(0, 0, 0, 0);
    checkboxWidget->setLayout(layout);

    // --- Connect checkbox to visibility toggle ---
    connect(checkbox, &QCheckBox::toggled, this, [=](bool checked) {
        vis->setKeyframeVisible(index, checked);
    });

    ui->keyframeTable->setCellWidget(row, 1, checkboxWidget);

    // --- Active (radio button) column ---
    QRadioButton* radio = new QRadioButton();

    if (row == 0) {
        radio->setChecked(true);
    }

    QWidget* radioWidget = new QWidget();
    QHBoxLayout* radioLayout = new QHBoxLayout(radioWidget);
    radioLayout->addWidget(radio);
    radioLayout->setAlignment(Qt::AlignCenter);
    radioLayout->setContentsMargins(0, 0, 0, 0);
    radioWidget->setLayout(radioLayout);
    ui->keyframeTable->setCellWidget(row, 2, radioWidget);

    // Store the radio button for exclusive behavior
    connect(radio, &QRadioButton::clicked, this, [this, radio]() {
        int rows = ui->keyframeTable->rowCount();
        for (int r = 0; r < rows; ++r) {
            QWidget* widget = ui->keyframeTable->cellWidget(r, 2);
            if (!widget) continue;
            QRadioButton* otherRadio = widget->findChild<QRadioButton*>();
            if (otherRadio) {
                if (otherRadio != radio) {
                    otherRadio->setChecked(false);
                } else {
                    // 🎯 This is the selected radio, emit or log it
                    qDebug() << "Radio button selected at row:" << r;
                    emit MainWindow::radioRowSelected(r); // <- Optional custom signal
                }
            }
        }
    });

    // --- Properties button column ---
    QPushButton* propButton = new QPushButton();
    QIcon icon(":/icons/settings.png");
    propButton->setIcon(icon);
    propButton->setIconSize(QSize(16, 16)); // adjust size
    propButton->setFlat(true);              // optional: remove button border
    propButton->setToolTip("Show properties");

    connect(propButton, &QPushButton::clicked, this, [this, index]() {
        auto *dialog = new PropDialog(vis->getPointCloudHandler(), index, this);
        dialog->setAttribute(Qt::WA_DeleteOnClose); // cleans itself up
        dialog->setModal(false);                    // non-modal
        dialog->show();
    });
    ui->keyframeTable->setCellWidget(row, 3, propButton);
}

MainWindow::~MainWindow()
{
    if(arduino->isOpen()){
        qDebug() << "Closing Port";
        arduino->close();
    }
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    emit onShapeChanged(index);
}


void MainWindow::updateServo(QByteArray command){
    if (arduino->isOpen()) {
        qDebug() << "Port is open";
    } else {
        qDebug() << "Port is NOT open";
    }

    if(arduino->isWritable()){
        arduino->write(command);
        arduino->flush();
    }else{
        qDebug() << "Not Writable";
    }
}


void MainWindow::on_tiltEdit_returnPressed()
{
    QString ss = ui->tiltEdit->text();

    bool ok;
    float value = ss.toFloat(&ok);
    value = qBound(45.0, value, 135.0);
    int valInt = value*10;

    if(ok){
        MainWindow::sendData(0x01, valInt);
    }else{
        qDebug() << "Construction failed";
    }
}


void MainWindow::on_panEdit_returnPressed()
{
    QString ss = ui->panEdit->text();

    bool ok;
    float value = ss.toFloat(&ok);
    value = qBound(45.0, value, 135.0);
    int valInt = value*10;

    if(ok){
        MainWindow::sendData(0x02, valInt);
    }else{
        qDebug() << "Construction failed";
    }
}

void MainWindow::on_elevEdit_returnPressed()
{
    QString ss = ui->elevEdit->text();

    bool ok;
    float value = ss.toFloat(&ok);
    value = qBound(0.0, value, 90.0);
    int valInt = value*10;

    if(ok){
        // MainWindow::sendData(0x24, valInt);
    }else{
        qDebug() << "Construction failed";
    }
}

void MainWindow::sendData(int instruction, int value){
    quint8 l = value & 0xFF;
    quint8 u = (value >> 8) & 0xFF;
    quint8 command[] = {0xEF,static_cast<quint8>(instruction),l,u, static_cast<quint8>(instruction+l+u),0xCD};

    qDebug() << "Command Array: "
             << QString("0x%1 0x%2 0x%3 0x%4 0x%5")
                    .arg(command[0], 2, 16, QChar('0'))
                    .arg(command[1], 2, 16, QChar('0'))
                    .arg(command[2], 2, 16, QChar('0'))
                    .arg(command[3], 2, 16, QChar('0'))
                    .arg(command[4], 2, 16, QChar('0'))
                    .toUpper();

    updateServo(QByteArray::fromRawData(reinterpret_cast<const char*>(command), sizeof(command)));
}

void MainWindow::on_getDistanceButton_clicked()
{
    quint8 cs = 0x03 + 0x12 + 0x34;
    quint8 command[] = {0xEF,static_cast<quint8>(0x03), 0x12, 0x34, cs,0xCD};
    updateServo(QByteArray::fromRawData(reinterpret_cast<const char*>(command), sizeof(command)));
}

void MainWindow::on_stopButton_clicked()
{
    quint8 cs = 0x0A + 0x12 + 0x34;
    quint8 command[] = {0xFF,0x0A, 0x12, 0x34, cs,0xCD};
    updateServo(QByteArray::fromRawData(reinterpret_cast<const char*>(command), sizeof(command)));

    ui -> scanButton -> setEnabled(true);
    ui->pauseButton->setText("Pause");
}

void MainWindow::on_pauseButton_clicked()
{
    static bool isPaused = false;
    quint8 cmd = isPaused ? 0xD0 : 0x0D;

    ui->pauseButton->setText(isPaused ? "Pause" : "Continue");
    isPaused = !isPaused;

    quint8 cs = cmd + 0x34 + 0x56;
    quint8 command[] = {0xFF, cmd, 0x34, 0x56, cs, 0xCD};

    updateServo(QByteArray::fromRawData(reinterpret_cast<const char*>(command), sizeof(command)));
}



void MainWindow::readLidarData(){
    QByteArray data = arduino->readAll();
    // qDebug() << "Received:" << data.toHex();

    if (data.startsWith(0xEA) && data.endsWith(0xEB) && data.size() == 6) {
        int value = (uint8_t)data[1] | ((uint8_t)data[2] << 8);
        ui->distLabel->setText(QString::number(value));
        qDebug() << "Received Value: " << value;

        // if(keyframe_counter != active){
        //     keyframe_counter = active;
        //     ui->sourceIndC->addItem(QString::number(keyframe_counter));
        //     ui->targetIndC->addItem(QString::number(keyframe_counter));
        //     emit MainWindow::loadEmptyFrame(keyframe_counter);
        // }

        // emit MainWindow::sendLidarData(value, (int16_t)pan, (int16_t)tilt, active, sq);
    }else if (data.startsWith(0xFA) && data.endsWith(0xFB) && data.size() == 12){
        int value = (uint8_t)data[1] | ((uint8_t)data[2] << 8);
        int sq = (uint8_t)data[3] | ((uint8_t)data[4] << 8);
        int pan = (uint8_t)data[5] | ((uint8_t)data[6] << 8);
        int tilt = (uint8_t)data[7] | ((uint8_t)data[8] << 8) ;
        int active = (uint8_t)data[9] | ((uint8_t)data[10] << 8) ;
        // qDebug() << "Received Scan Value: " << value + 53;
        // qDebug() << "Received Strength Value: " << sq;
        // qDebug() << "Received Pan Value: " << (int16_t)pan;
        // qDebug() << "Received Tilt Value: " << (int16_t)tilt;
        // qDebug() << "Received Keyframe: " << active;

        if(keyframe_counter != active){
            keyframe_counter = active;
            ui->sourceIndC->addItem(QString::number(keyframe_counter));
            ui->targetIndC->addItem(QString::number(keyframe_counter));
            emit MainWindow::loadEmptyFrame(keyframe_counter);
        }

        emit MainWindow::sendLidarData(value, (int16_t)pan, (int16_t)tilt, active, sq);
    }
}

void MainWindow::onUpdateComboCount(int kfCount){
    for(int i=0;i<kfCount;i++){
        ui->sourceIndC->addItem(QString::number(i));
        ui->targetIndC->addItem(QString::number(i));
    }
}

void MainWindow::on_scanButton_clicked()
{
    setupScan(0);
}


void MainWindow::on_lineScanButton_clicked()
{
    setupScan(1);
}

void MainWindow::on_panScanButton_clicked()
{
    setupScan(2);
}


void MainWindow::on_scanOneButton_clicked()
{
    setupScan(3);
    int activeFrame = ui->frameIndex->value();
    vis->changeActiveFrame(activeFrame);
}



void MainWindow::setupScan(int code){

    //0x04 = Full Scan
    //0x06 = Line Scan
    //0x07 = Pan Scan
    //0x20 = One Scan

    quint8 scanType = 0x00;

    if(code == 0){
        scanType = 0x04;
    }else if (code == 1){
        scanType = 0x06;
    }else if (code == 2){
        scanType = 0x07;
    }else if(code == 3){
        scanType = 0x20;
    }

    quint8 aAngles = 4;
    quint8 eAngles = 9;
    // quint8 aAngles = static_cast<quint8>(ui->azimuthNo->displayText().toInt());
    // quint8 eAngles = static_cast<quint8>(ui->elevationNo->displayText().toInt());
    quint8 hAnglePan = ui->highAnglePan->displayText().toInt();
    quint8 hAnglePitch = ui->highAnglePitch->displayText().toInt();
    float panRes = ui->panRes->displayText().toFloat();
    float pitchRes = ui->pitchRes->displayText().toFloat();
    int keyframe = ui->frameIndex->value();

    quint8 cs = scanType + aAngles + eAngles;

    QByteArray command;
    command.append(0xAF);
    command.append(scanType);
    command.append(aAngles);
    command.append(eAngles);
    command.append(cs);
    command.append(hAnglePan);
    command.append(hAnglePitch);

    float floats[] = {panRes, pitchRes};
    for (float f : floats) {
        command.append(reinterpret_cast<const char*>(&f), sizeof(float));
    }

    command.append(keyframe);
    command.append(0xCD);

    qDebug() << sizeof(command);
    updateServo(command);

    ui->scanButton->setEnabled(false);
    emit MainWindow::updateScanSettings(eAngles, aAngles);
}



void MainWindow::on_lowerButton_clicked()
{
    quint8 cs = 0x05 + 0x11 + 0x22;
    quint8 command[] = {0xEF, 0x05, 0x11, 0x22, cs, 0xCD};
    qDebug() << sizeof(command);
    updateServo(QByteArray::fromRawData(reinterpret_cast<const char*>(command), sizeof(command)));
}


void MainWindow::on_higherButton_clicked()
{
    quint8 cs = 0x05 + 0x24 + 0x42;
    quint8 command[] = {0xEF, 0x05, 0x24, 0x42, cs, 0xCD};
    qDebug() << sizeof(command);
    updateServo(QByteArray::fromRawData(reinterpret_cast<const char*>(command), sizeof(command)));
}


void MainWindow::on_rotAzimButton_clicked()
{
    quint8 cs = 0x05 + 0x33 + 0x66;
    quint8 command[] = {0xEF, 0x05, 0x33, 0x66, cs, 0xCD};
    qDebug() << sizeof(command);
    updateServo(QByteArray::fromRawData(reinterpret_cast<const char*>(command), sizeof(command)));
}

void MainWindow::on_rotCheck_stateChanged(int arg1)
{
    if(arg1 == 0){
        ui->leftRot->setEnabled(true);
        ui->rightRot->setEnabled(true);
    }else{
        ui->leftRot->setEnabled(false);
        ui->rightRot->setEnabled(false);
    }

    emit onRotChanged(arg1);
}


void MainWindow::on_leftRot_pressed()
{
    emit updateRot(true);
}


void MainWindow::on_rightRot_pressed()
{
    emit updateRot(false);
}


void MainWindow::on_leftRot_released()
{
    emit stopRot();
}


void MainWindow::on_rightRot_released()
{
    emit stopRot();
}


void MainWindow::openClicked()
{
    QString filePath = QFileDialog::getOpenFileName(
        this,
        tr("Open PCD File"),
        "",
        tr("Point Cloud Data (*.pcd)")
        );

    if (!filePath.isEmpty()) {
        emit pcdFileSelected(filePath);
    }
}

void MainWindow::saveKeyframe(){

    QString defaultDir = "C:\\Users\\naird\\Downloads\\Torus";
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Save Combined Keyframes",
        defaultDir + "/torus_.pcd",
        "PCD Files (*.pcd)"
        );

    if (!filePath.isEmpty()) {
        // Ensure file ends with .pcd
        if (!filePath.endsWith(".pcd", Qt::CaseInsensitive)) {
            filePath += ".pcd";
        }
        vis->getPointCloudHandler()->saveKeyframe(filePath, 0, 0);
    }
}

void MainWindow::saveKeyframesAsOne(){

    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Save Combined Keyframes",
        QDir::homePath() + "/combined.pcd",
        "PCD Files (*.pcd)"
        );

    if (!filePath.isEmpty()) {
        // Ensure file ends with .pcd
        if (!filePath.endsWith(".pcd", Qt::CaseInsensitive)) {
            filePath += ".pcd";
        }
        vis->getPointCloudHandler()->saveKeyframe(filePath,0,1);
    }
}

void MainWindow::saveKeyframes(){

    QString baseFile = QFileDialog::getSaveFileName(
        this,
        "Save Keyframes With Base Name",
        QDir::homePath() + "/scan1.pcd",
        "PCD Files (*.pcd)"
        );

    if (!baseFile.isEmpty()) {
        QFileInfo fileInfo(baseFile);
        QString baseName = fileInfo.completeBaseName();
        QString dir = fileInfo.absolutePath();

        vis->getPointCloudHandler()->saveKeyframe(baseName, dir, 2);
    }
}

void MainWindow::saveSession(){
    QString baseFile = QFileDialog::getSaveFileName(
        this,
        tr("Save Session"),                                // dialog title
        QDir::homePath() + "/scan1.pcd",                  // default path + name
        tr("Point Cloud Data (*.pcd)")                    // file filter
        );

    if (!baseFile.isEmpty()) {
        QFileInfo fileInfo(baseFile);

        QString baseName = fileInfo.completeBaseName();   // "scan1"
        QString dir = fileInfo.absolutePath();            // "/home/user"
        QString ext = fileInfo.suffix();                  // "pcd"

        // Example usage: generate keyframe files
        vis->getPointCloudHandler()->saveKeyframe(baseName, dir, 3);

        qDebug() << "Session saved to:" << baseFile;
    }

}

void MainWindow::loadSession(){
    QString sessionFile = QFileDialog::getOpenFileName(
        this,
        tr("Load Session"),                              // dialog title
        QDir::homePath(),                                // default location
        tr("Session Files (*.session.json)")             // only show session files
        );

    if (!sessionFile.isEmpty()) {
        QFileInfo fileInfo(sessionFile);

        QString baseName = fileInfo.completeBaseName();  // "scan1"
        QString dir = fileInfo.absolutePath();           // "/home/user"

        // Load session (JSON + PCDs)
        vis->getPointCloudHandler()->loadSession(sessionFile, dir);

        qDebug() << "Session loaded from:" << sessionFile;
    }
}

void MainWindow::on_registerButton_clicked()
{
    emit MainWindow::onRegisterPressed();
}

void MainWindow::on_constructMeshButton_clicked()
{
    emit MainWindow::onConstructMesh();
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    emit MainWindow::currentTab(index);
}

void MainWindow::on_filterButton_clicked()
{
    float radius = (ui->searchRadiusEdit->text()).toFloat();
    float upsampleRadius = (ui->upsampleRadiusEdit->text()).toFloat();
    float upsampleStep = (ui->upsampleStepEdit->text()).toFloat();
    int order = (ui->orderEdit->text()).toInt();

    emit MainWindow::applyFilter(radius, upsampleRadius, upsampleStep, order);
    emit MainWindow::triggerUpdate();
}


void MainWindow::on_revertButton_clicked()
{
    emit MainWindow::revertKeyframe();
    emit MainWindow::triggerUpdate();
}


void MainWindow::on_combineButton_clicked()
{
    emit MainWindow::combineKeyframes();
    emit MainWindow::triggerUpdate();

    ui->filterSettings->setEnabled(true);
    // ui->combineNotify->setVisible(false);
}


void MainWindow::on_cleanButton_clicked()
{
    int index = vis->getPointCloudHandler()->getCurrentKeyframeIndex();

    emit MainWindow::cleanKeyframe();
    emit MainWindow::triggerKeyframeChange(index);
}

void MainWindow::on_passButton_clicked()
{
    int index = vis->getPointCloudHandler()->getCurrentKeyframeIndex();
    std::string axis = ui->passCombo->currentText().toStdString();
    int min = ui->passMin->value();
    int max = ui->passMax->value();

    emit MainWindow::applyPassThrough(axis, min, max);
    emit MainWindow::triggerKeyframeChange(index);
}


void MainWindow::on_passButton_2_clicked()
{

    int count = vis->getPointCloudHandler()->getKeyframeCount();

    for(int index = 0; index < count; index++){
        vis->getPointCloudHandler()->setActiveKeyframe(index);
        std::string axis = ui->passCombo->currentText().toStdString();
        int min = ui->passMin->value();
        int max = ui->passMax->value();

        emit MainWindow::applyPassThrough(axis, min, max);
        emit MainWindow::triggerKeyframeChange(index);
    }
}



void MainWindow::on_voxButton_clicked()
{
    int index = vis->getPointCloudHandler()->getCurrentKeyframeIndex();
    double leafSize = ui->voxLeafSize->value();

    emit MainWindow::applyVoxelGrid(leafSize);
    emit MainWindow::triggerKeyframeChange(index);
}

void MainWindow::on_voxButton_2_clicked()
{
    int count = vis->getPointCloudHandler()->getKeyframeCount();

    for(int index = 0; index < count; index++){
        vis->getPointCloudHandler()->setActiveKeyframe(index);
        double leafSize = ui->voxLeafSize->value();

        emit MainWindow::applyVoxelGrid(leafSize);
        emit MainWindow::triggerKeyframeChange(index);
    }
}


void MainWindow::on_sorButton_clicked()
{
    int index = vis->getPointCloudHandler()->getCurrentKeyframeIndex();
    int meanK = ui->sorMean->value();
    double stddev= ui->doubleSpinBox->value();

    emit MainWindow::applySOR(meanK, stddev);
    emit MainWindow::triggerKeyframeChange(index);
}

void MainWindow::on_sorButton_2_clicked()
{
    int count = vis->getPointCloudHandler()->getKeyframeCount();

    for(int index = 0; index < count; index++){
        vis->getPointCloudHandler()->setActiveKeyframe(index);
        int meanK = ui->sorMean->value();
        double stddev= ui->doubleSpinBox->value();

        emit MainWindow::applySOR(meanK, stddev);
        emit MainWindow::triggerKeyframeChange(index);
    }
}



void MainWindow::on_applyAlltoCurButton_clicked()
{
    int index = vis->getPointCloudHandler()->getCurrentKeyframeIndex();
    std::string axis = ui->passCombo->currentText().toStdString();
    int min = ui->passMin->value();
    int max = ui->passMax->value();
    double leafSize = ui->voxLeafSize->value();
    int meanK = ui->sorMean->value();
    double stddev= ui->doubleSpinBox->value();

    emit MainWindow::applyPassThrough(axis, min, max);
    emit MainWindow::applyVoxelGrid(leafSize);
    emit MainWindow::applySOR(meanK, stddev);
    emit MainWindow::triggerKeyframeChange(index);
}


void MainWindow::on_applyAlltoAllButton_clicked()
{
    int count = vis->getPointCloudHandler()->getKeyframeCount();

    for(int index = 0; index < count; index++){
        vis->getPointCloudHandler()->setActiveKeyframe(index);
        double leafSize = ui->voxLeafSize->value();
        int meanK = ui->sorMean->value();
        double stddev= ui->doubleSpinBox->value();

        emit MainWindow::applyVoxelGrid(leafSize);
        emit MainWindow::applySOR(meanK, stddev);
        emit MainWindow::triggerKeyframeChange(index);
    }
}


void MainWindow::on_revertCleanButton_clicked()
{
    int index = vis->getPointCloudHandler()->getCurrentKeyframeIndex();
    emit MainWindow::revertClean();
    emit MainWindow::triggerKeyframeChange(index);
}



void MainWindow::on_undoCleanButton_clicked()
{
    int index = vis->getPointCloudHandler()->getCurrentKeyframeIndex();
    emit MainWindow::undoClean();
    emit MainWindow::triggerKeyframeChange(index);
}


void MainWindow::on_redoCleanButton_clicked()
{
    int index = vis->getPointCloudHandler()->getCurrentKeyframeIndex();
    emit MainWindow::redoClean();
    emit MainWindow::triggerKeyframeChange(index);
}


void MainWindow::on_pairRegisButton_clicked()
{
    int sourceIndex = ui->sourceIndC->currentText().toInt();
    int targetIndex = ui->targetIndC->currentText().toInt();

    int maxCorrDist = ui->regisMaxDist->value();
    int maxIter = ui->regisMaxIter->value();
    double fitThresh = ui->registFitThresh->value();

    emit MainWindow::tryRegistration(sourceIndex, targetIndex, maxCorrDist/50, maxIter, fitThresh);
}


void MainWindow::on_targetIndC_currentIndexChanged(int index)
{
    vis->changeTargetIndex(index);
}


void MainWindow::on_sourceIndC_currentIndexChanged(int index)
{
    vis->changeSourceIndex(index);
}

void MainWindow::on_mirrorCorrectButton_clicked()
{
    int index = vis->getPointCloudHandler()->getCurrentKeyframeIndex();
    double maxY = ui->mirrorMaxY->value();
    emit MainWindow::applyMirrorCorrect(maxY);
    emit MainWindow::triggerKeyframeChange(index);
}


void MainWindow::on_mirrorCorrectButton_2_clicked()
{
    int count = vis->getPointCloudHandler()->getKeyframeCount();

    for(int index = 0; index < count; index++){

        vis->getPointCloudHandler()->setActiveKeyframe(index);
        double maxY = ui->mirrorMaxY->value();
        emit MainWindow::applyMirrorCorrect(maxY);
        emit MainWindow::triggerKeyframeChange(index);
    }


}

void MainWindow::on_pairRegisButton_2_clicked()
{
    int maxCorrDist = ui->regisMaxDist->value();
    int maxIter = ui->regisMaxIter->value();
    double fitThresh = ui->registFitThresh->value();

    emit MainWindow::applyPairwiseRegistration(maxCorrDist, maxIter, fitThresh);
    emit MainWindow::triggerUpdate();
}


void MainWindow::on_voxButton_3_clicked()
{
    double leafSize = ui->voxLeafSize->value();
    emit MainWindow::applyVoxeltoCombined(leafSize);
    emit MainWindow::triggerUpdate();
}

