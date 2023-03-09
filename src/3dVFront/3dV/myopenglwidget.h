#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H
#define GL_SILENCE_DEPRECATION

#include <QColor>
#include <QDebug>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
// #include <QGLWidget>

extern "C" {
#include "../../viewer.h"
}

#define RGB_MIN 1
#define RGB_MAX 255

class MyOpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions {
  Q_OBJECT
 public:
  int V_num;
  int F_num;
  double *V_arr;
  int *F_arr;
  double minVertexesX;
  double maxVertexesX;
  double minVertexesY;
  double maxVertexesY;
  double minVertexesZ;
  double maxVertexesZ;
  double MaxVertexValue;
  double MinVertexValue;

  float BackR;
  float BackG;
  float BackB;

  float LineR;
  float LineG;
  float LineB;

  float VertR;
  float VertG;
  float VertB;

  float LineWidth;

  int LineTypeIndex;
  int VertTypeIndex;

  float VertScale;

  MyOpenGLWidget(QWidget *parent = nullptr);
  void ChangeProjection();
  int projection_type;

  // protected:

 private:
  float xRot, yRot, zRot;
  QPoint mPos;
  void qColorToRGB(const QColor &C, float &r, float &g, float &b) const;
  float normaliza_0_1(float val, float min, float max) const;
  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;
};

#endif  // MYOPENGLWIDGET_H