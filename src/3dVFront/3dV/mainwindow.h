#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QMoveEvent>
#include <QSettings>
#include <QTimer>
#include <QtOpenGL>
#include <QtWidgets/QWidget>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#include "../../gifimage/qgifimage.h"

extern "C" {
#include "../../viewer.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow
    : public QMainWindow /*, public QOpenGLWidget, public QOpenGLFunctions */ {
  Q_OBJECT

  // protected:
  //  void initializeGL() override;
  //  void paintGL() override;
  //  void resizeGL(int w, int h) override;

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  //  MainWindow(QWidget *parent = nullptr);
  QString Path = QDir::homePath();
  QString filename = NULL;
  QString JPGfile = NULL;
  QString BMPfile = NULL;
  QString GIFfile = NULL;
  ~MainWindow();
  QSettings *settings;

  QTimer *Timer;
  int FramesCount = 0;

 private slots:
  void on_pushButtonOpenFile_clicked();

  void on_ScaleButton_clicked();

  void on_MoveButton_clicked();

  void on_RotateButton_clicked();

  void on_radioOrtho_clicked();

  void on_radioPerspective_clicked();

  void on_sliderScale_valueChanged(int value);

  void on_sliderMoveX_valueChanged(int value);

  void on_sliderMoveY_valueChanged(int value);

  void on_sliderMoveZ_valueChanged(int value);

  void on_sliderRotateX_valueChanged(int value);

  void on_sliderRotateY_valueChanged(int value);

  void on_sliderRotateZ_valueChanged(int value);

  void on_sliderBackroundB_valueChanged(int value);

  void on_sliderBackroundR_valueChanged(int value);

  void on_sliderBackroundG_valueChanged(int value);

  void on_sliderLineR_valueChanged(int value);

  void on_sliderLineG_valueChanged(int value);

  void on_sliderLineB_valueChanged(int value);

  void on_sliderLineWidth_valueChanged(int value);

  void on_comboBox_currentIndexChanged(int index);

  void on_sliderVertR_valueChanged(int value);

  void on_sliderVertG_valueChanged(int value);

  void on_sliderVertB_valueChanged(int value);

  void on_comboBoxVert_currentIndexChanged(int index);

  void on_sliderVertScale_valueChanged(int value);

  void on_pushButtonJPG_clicked();
  void on_pushButtonBMP_clicked();
  void on_pushButtonGIF_clicked();
  void AddFrameInGifTime();
  void SaveGif();

  void SaveSettings();
  void on_ResetSettings_clicked();
  void on_LoadSettings_clicked();

 private:
  Ui::MainWindow *ui;
  QVector<QImage> gif;
};
#endif  // MAINWINDOW_H