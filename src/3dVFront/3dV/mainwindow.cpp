#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  settings = new QSettings("Setting", "3dV", this);

  this->setWindowTitle("3D Viewer");

  Timer = new QTimer(this);

  ui->sliderMoveX->setMinimum(-100);
  ui->sliderMoveX->setMaximum(100);
  ui->sliderMoveX->setSliderPosition(0);
  ui->sliderMoveY->setMinimum(-100);
  ui->sliderMoveY->setMaximum(100);
  ui->sliderMoveY->setSliderPosition(0);
  ui->sliderMoveZ->setMinimum(-100);
  ui->sliderMoveZ->setMaximum(100);
  ui->sliderMoveZ->setSliderPosition(0);

  ui->sliderRotateX->setMinimum(-100);
  ui->sliderRotateX->setMaximum(100);
  ui->sliderRotateX->setSliderPosition(0);
  ui->sliderRotateY->setMinimum(-100);
  ui->sliderRotateY->setMaximum(100);
  ui->sliderRotateY->setSliderPosition(0);
  ui->sliderRotateZ->setMinimum(-100);
  ui->sliderRotateZ->setMaximum(100);
  ui->sliderRotateZ->setSliderPosition(0);

  ui->sliderScale->setMinimum(1);
  ui->sliderScale->setMaximum(200);
  ui->sliderScale->setSliderPosition(100);
  ui->sliderScale->setSingleStep(1);

  ui->sliderBackroundR->setMinimum(0);
  ui->sliderBackroundR->setMaximum(100);
  ui->sliderBackroundG->setMinimum(0);
  ui->sliderBackroundG->setMaximum(100);
  ui->sliderBackroundB->setMinimum(0);
  ui->sliderBackroundB->setMaximum(100);

  ui->sliderLineR->setMinimum(0);
  ui->sliderLineR->setMaximum(100);
  ui->sliderLineG->setMinimum(0);
  ui->sliderLineG->setMaximum(100);
  ui->sliderLineB->setMinimum(0);
  ui->sliderLineB->setMaximum(100);

  ui->sliderLineR->setSliderPosition(100);
  ui->sliderLineG->setSliderPosition(100);
  ui->sliderLineB->setSliderPosition(100);

  ui->sliderLineWidth->setMinimum(0);
  ui->sliderLineWidth->setMaximum(50);
  ui->sliderLineWidth->setSliderPosition(0);

  ui->sliderVertR->setMinimum(0);
  ui->sliderVertR->setMaximum(100);
  ui->sliderVertG->setMinimum(0);
  ui->sliderVertG->setMaximum(100);
  ui->sliderVertB->setMinimum(0);
  ui->sliderVertB->setMaximum(100);

  ui->sliderVertR->setSliderPosition(100);
  ui->sliderVertG->setSliderPosition(100);
  ui->sliderVertB->setSliderPosition(100);

  ui->sliderVertScale->setMinimum(0);
  ui->sliderVertScale->setMaximum(50);
  ui->sliderVertScale->setSliderPosition(0);
}

MainWindow::~MainWindow() {
  SaveSettings();
  delete ui;
}

void MainWindow::on_pushButtonOpenFile_clicked() {
  filename = QFileDialog::getOpenFileName(
      this, "Open file", "../../../../../fileObj",
      "OBJ Files (*.obj)");  // добавьте себе папку fileObj в src и диалоговое
                             // окно будет открыватся в ней
  if (filename.isEmpty()) {
    QMessageBox::information(this, "ERROR", "🙀");
    return;
  }
  std::string str = filename.toStdString();
  char *cstr = new char[str.length() + 1];
  strcpy(cstr, str.c_str());
  ui->labelPashFile->setText(filename);

  dataStruct DataStr;

  DataStr = parser(cstr);

  ui->widget->V_num = DataStr.countVertexes;
  ui->widget->F_num = DataStr.countFacets * 2;
  //  ui->widget->F_num = DataStr.countFacets;
  ui->widget->V_arr = DataStr.dataVertexes;
  ui->widget->F_arr = DataStr.dataFacets;
  ui->widget->minVertexesX = DataStr.minVertexesX;
  ui->widget->maxVertexesX = DataStr.maxVertexesX;
  ui->widget->minVertexesY = DataStr.minVertexesY;
  ui->widget->maxVertexesY = DataStr.maxVertexesY;
  ui->widget->minVertexesZ = DataStr.minVertexesZ;
  ui->widget->maxVertexesZ = DataStr.maxVertexesZ;

  ui->widget->MaxVertexValue = ui->widget->V_arr[0];
  for (int i = 0; i < ui->widget->V_num; i++) {
    if (ui->widget->V_arr[i] > ui->widget->MaxVertexValue)
      ui->widget->MaxVertexValue = ui->widget->V_arr[i];
  }
  ui->widget->minVertexesX = 100;
  ui->widget->maxVertexesX = -100;
  for (int i = 0; i < ui->widget->V_num; i++) {
    ui->widget->V_arr[i] =
        ui->widget->V_arr[i] / (ui->widget->MaxVertexValue + 2);
    if (ui->widget->V_arr[i] < ui->widget->minVertexesX)
      ui->widget->minVertexesX = ui->widget->V_arr[i];
    if (ui->widget->V_arr[i] > ui->widget->maxVertexesX)
      ui->widget->maxVertexesX = ui->widget->V_arr[i];
  }
  double shift = (ui->widget->minVertexesX + ui->widget->maxVertexesX) / 2;
  for (int i = 0; i < ui->widget->V_num; i++) {
    if (i % 3 == 1) ui->widget->V_arr[i] -= shift;  // центрируем по Х
  }

  int V = DataStr.countVertexes;
  int F = DataStr.countFaset;

  std::string strV = std::to_string(V / 3);  // переводим инт в стр
  char *cstrV = new char[strV.length() + 1];
  strcpy(cstrV, strV.c_str());
  std::string strF = std::to_string(F);  // переводим инт в стр
  char *cstrF = new char[strF.length() + 1];
  strcpy(cstrF, strF.c_str());
  ui->labelCountV->setText(cstrV);  // выводим стр в окно
  ui->labelCountF->setText(cstrF);  // выводим стр в окно

  delete[] cstr;
}

void MainWindow::on_sliderScale_valueChanged(int value) {
  ui->lineScale->setText(QString::number(value));
}

void MainWindow::on_ScaleButton_clicked() {
  QString StrScale = ui->lineScale->text();
  double scale = StrScale.toDouble();
  affine_scale(ui->widget->V_num, &ui->widget->V_arr, scale);
  ui->widget->update();
}

void MainWindow::on_sliderMoveX_valueChanged(int value) {
  ui->lineX->setText(QString::number(value));
}

void MainWindow::on_sliderMoveY_valueChanged(int value) {
  ui->lineY->setText(QString::number(value));
}

void MainWindow::on_sliderMoveZ_valueChanged(int value) {
  ui->lineZ->setText(QString::number(value));
}

void MainWindow::on_MoveButton_clicked() {
  QString StrMoveX = ui->lineX->text();
  QString StrMoveY = ui->lineY->text();
  QString StrMoveZ = ui->lineZ->text();
  double moveX = StrMoveX.toDouble();
  double moveY = StrMoveY.toDouble();
  double moveZ = StrMoveZ.toDouble();

  double move[3] = {0, 0, 0};
  move[0] = moveX / 100;
  move[1] = moveY / 100;
  move[2] = moveZ / 100;

  affine_move(ui->widget->V_num, &ui->widget->V_arr, move);
  ui->widget->update();
}

void MainWindow::on_sliderRotateX_valueChanged(int value) {
  ui->lineRotX->setText(QString::number(value));
}

void MainWindow::on_sliderRotateY_valueChanged(int value) {
  ui->lineRotY->setText(QString::number(value));
}

void MainWindow::on_sliderRotateZ_valueChanged(int value) {
  ui->lineRotZ->setText(QString::number(value));
}

void MainWindow::on_RotateButton_clicked() {
  QString StrRotX = ui->lineRotX->text();
  QString StrRotY = ui->lineRotY->text();
  QString StrRotZ = ui->lineRotZ->text();
  double rotateX = StrRotX.toDouble();
  double rotateY = StrRotY.toDouble();
  double rotateZ = StrRotZ.toDouble();

  double rotate[3] = {0, 0, 0};
  rotate[0] = rotateX;
  rotate[1] = rotateY;
  rotate[2] = rotateZ;

  affine_rotate(ui->widget->V_num, &ui->widget->V_arr, rotate);
  ui->widget->update();
}

void MainWindow::on_radioOrtho_clicked() {
  ui->widget->projection_type = 0;
  ui->widget->update();
}

void MainWindow::on_radioPerspective_clicked() {
  ui->widget->projection_type = 1;
  ui->widget->update();
}

void MainWindow::on_sliderBackroundR_valueChanged(int value) {
  ui->widget->BackR = value;
  ui->widget->update();
}

void MainWindow::on_sliderBackroundG_valueChanged(int value) {
  ui->widget->BackG = value;
  ui->widget->update();
}

void MainWindow::on_sliderBackroundB_valueChanged(int value) {
  ui->widget->BackB = value;
  ui->widget->update();
}

void MainWindow::on_sliderLineR_valueChanged(int value) {
  ui->widget->LineR = value;
  ui->widget->update();
}

void MainWindow::on_sliderLineG_valueChanged(int value) {
  ui->widget->LineG = value;
  ui->widget->update();
}

void MainWindow::on_sliderLineB_valueChanged(int value) {
  ui->widget->LineB = value;
  ui->widget->update();
}

void MainWindow::on_sliderLineWidth_valueChanged(int value) {
  ui->lineLineWidth->setText(QString::number(value));
  ui->widget->LineWidth = value;
  ui->widget->update();
}

void MainWindow::on_comboBox_currentIndexChanged(int index) {
  ui->widget->LineTypeIndex = index;
  ui->widget->update();
}

void MainWindow::on_sliderVertR_valueChanged(int value) {
  ui->widget->VertR = value;
  ui->widget->update();
}

void MainWindow::on_sliderVertG_valueChanged(int value) {
  ui->widget->VertG = value;
  ui->widget->update();
}

void MainWindow::on_sliderVertB_valueChanged(int value) {
  ui->widget->VertB = value;
  ui->widget->update();
}

void MainWindow::on_comboBoxVert_currentIndexChanged(int index) {
  ui->widget->VertTypeIndex = index;
  ui->widget->update();
}

void MainWindow::on_sliderVertScale_valueChanged(int value) {
  ui->lineVertScale->setText(QString::number(value));
  ui->widget->VertScale = value;
  ui->widget->update();
}

void MainWindow::on_pushButtonJPG_clicked() {
  JPGfile = QFileDialog::getSaveFileName(this, tr("Save screenshot JPG"), Path,
                                         tr("JPG files (*.jpg)"));
  QImage Screenshot = ui->widget->grabFramebuffer();
  Screenshot.save(JPGfile, nullptr, 80);
}

void MainWindow::on_pushButtonBMP_clicked() {
  BMPfile = QFileDialog::getSaveFileName(this, tr("Save screenshot BMP"), Path,
                                         tr("BMP files (*.bmp)"));
  QImage Screenshot = ui->widget->grabFramebuffer();
  Screenshot.save(BMPfile, nullptr, 80);
}

void MainWindow::on_pushButtonGIF_clicked() {
  connect(Timer, SIGNAL(timeout()), this, SLOT(AddFrameInGifTime()));
  Timer->start(100);  // 100 милисекунд => 50 кадров за 5 сек
  ui->pushButtonGIF->setDisabled(true);  // отключаем кнопку на время записи
  //    AddFrameInGifTime();
}

void MainWindow::AddFrameInGifTime() {
  if (FramesCount <= 50) {
    gif.push_back(ui->widget->grabFramebuffer());
    FramesCount++;
  } else {
    Timer->stop();
    SaveGif();
  }
}

void MainWindow::SaveGif() {
  GIFfile = QFileDialog::getSaveFileName(this, tr("Save gif"), Path,
                                         tr("GIF files (*.gif)"));
  if (!GIFfile.isNull()) {
    QGifImage gif_file(
        QSize(ui->widget->width() * 2, ui->widget->height() * 2));
    gif_file.setDefaultDelay(100);  //выставляем задержку
    for (QVector<QImage>::Iterator frames = gif.begin(); frames != gif.end();
         frames++) {
      gif_file.addFrame(*frames);
    }
    gif_file.save(GIFfile);
  }
  gif.clear();
  FramesCount = 0;
  ui->pushButtonGIF->setEnabled(true);
}

void MainWindow::SaveSettings() {
  settings->setValue("BackR", ui->widget->BackR);
  settings->setValue("BackG", ui->widget->BackG);
  settings->setValue("BackB", ui->widget->BackB);

  settings->setValue("LineR", ui->widget->LineR);
  settings->setValue("LineG", ui->widget->LineG);
  settings->setValue("LineB", ui->widget->LineB);

  settings->setValue("VertR", ui->widget->VertR);
  settings->setValue("VertG", ui->widget->VertG);
  settings->setValue("VertB", ui->widget->VertB);

  settings->setValue("LineWidth", ui->widget->LineWidth);

  settings->setValue("LineTypeIndex", ui->widget->LineTypeIndex);
  settings->setValue("VertTypeIndex", ui->widget->VertTypeIndex);

  settings->setValue("VertScale", ui->widget->VertScale);
  settings->setValue("projection_type", ui->widget->projection_type);
}

void MainWindow::on_LoadSettings_clicked() {
  ui->widget->BackR = settings->value("BackR").toDouble();
  ui->widget->BackG = settings->value("BackG").toDouble();
  ui->widget->BackB = settings->value("BackB").toDouble();

  ui->widget->LineR = settings->value("LineR").toDouble();
  ui->widget->LineG = settings->value("LineG").toDouble();
  ui->widget->LineB = settings->value("LineB").toDouble();

  ui->widget->VertR = settings->value("VertR").toDouble();
  ui->widget->VertG = settings->value("VertG").toDouble();
  ui->widget->VertB = settings->value("VertB").toDouble();

  ui->widget->LineWidth = settings->value("LineWidth").toDouble();

  ui->widget->LineTypeIndex = settings->value("LineTypeIndex").toInt();
  ui->widget->VertTypeIndex = settings->value("VertTypeIndex").toInt();

  ui->widget->VertScale = settings->value("VertScale").toDouble();
  ui->widget->projection_type = settings->value("projection_type").toInt();
}

void MainWindow::on_ResetSettings_clicked() {
  ui->widget->BackR = 0;
  ui->widget->BackG = 0;
  ui->widget->BackB = 0;

  ui->widget->LineR = 100;
  ui->widget->LineG = 100;
  ui->widget->LineB = 100;

  ui->widget->VertR = 100;
  ui->widget->VertG = 100;
  ui->widget->VertB = 100;

  ui->widget->LineWidth = 0;

  ui->widget->LineTypeIndex = 0;
  ui->widget->VertTypeIndex = 0;

  ui->widget->VertScale = 0;
  ui->widget->projection_type = 0;

  ui->widget->update();
}
