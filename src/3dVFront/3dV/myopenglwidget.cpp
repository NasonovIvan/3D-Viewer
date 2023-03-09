#include "myopenglwidget.h"

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent) : QOpenGLWidget{parent} {
  //    setGeometry(600, 600, 600, 600);
}

void MyOpenGLWidget::initializeGL() {
  glLoadIdentity();  // загружаем единичную матрицу для корректной работы
  initializeOpenGLFunctions();
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);
  glTranslatef(0, 0,
               -3);  // сдвигаем систему координат по оси z видимую область

  //    float r,g,b;  //, a;
  //    a = normaliza_0_1(255.0f , RGB_MIN, RGB_MAX);

  //  initializeOpenGLFunctions();
  //    qColorToRGB(Qt::darkGray, r,g,b);// цвет фона
  //  glClearColor(r,g,b,a);
  //  glEnable(GL_DEPTH_TEST); //активировать глубину(тест глубины)
  //  glEnable(GL_LIGHT0); // включили освещение
  //  glEnable(GL_LIGHTING); // цветной материал
  //  glEnable(GL_LIGHTING); // цветной материал
  //  glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); // цветной
  //  материал спереди и сзади glEnable(GL_COLOR_MATERIAL);
}

void MyOpenGLWidget::resizeGL(int w, int h) {
  //    glViewport(0 ,0, w, h);
  //    glMatrixMode(GL_PROJECTION);
  //    glLoadIdentity();
  //  glOrtho(-2, 2, -2, 2, 1, 3);
  //  glMatrixMode(GL_MODELVIEW);
  //  glLoadIdentity();

  //    glFrustum(minVertexesX - 1, maxVertexesX + 1, minVertexesY - 1,
  //    maxVertexesY + 1, 1, -3);
  //  glEnable(GL_DEPTH_TEST);
  //  glTranslatef(0, 0, 3); // сдвигает систему координат
}

void MyOpenGLWidget::paintGL() {
  glLoadIdentity();

  glClearColor(BackR / 100, BackG / 100, BackB / 100, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT |
          GL_DEPTH_BUFFER_BIT);  // очищаем буфер цвета и буфер глубины
  glEnableClientState(GL_VERTEX_ARRAY);

  glColor3d(LineR / 100, LineG / 100, LineB / 100);

  glMatrixMode(GL_MODELVIEW);

  if (LineTypeIndex == 1) {
    glEnable(GL_LINE_STIPPLE);  // рисование пунктиром
    glLineStipple(1, 0x0101);   // . . . .
  } else if (LineTypeIndex == 2) {
    glEnable(GL_LINE_STIPPLE);  // рисование пунктиром
    glLineStipple(1, 0x00F0);   // - - - -
  }
  update();

  glLineWidth(LineWidth);

  ChangeProjection();

  glRotatef(xRot, 1, 0, 0);
  glRotatef(yRot, 0, 1, 0);

  glVertexPointer(3, GL_DOUBLE, 0, V_arr);
  glDrawElements(GL_LINES, F_num, GL_UNSIGNED_INT, F_arr);  // sega

  if (VertTypeIndex == 0) {
    glPointSize(0);
  } else if (VertTypeIndex == 1) {  // circle
    glColor3d(VertR / 100, VertG / 100, VertB / 100);
    glEnable(GL_POINT_SMOOTH);  // сглаживание
    glPointSize(VertScale);
    //      glDrawArrays(GL_POINTS, 0, V_num);
    glDrawElements(GL_POINTS, F_num, GL_UNSIGNED_INT, F_arr);
  } else if (VertTypeIndex == 2) {  // square
    glColor3d(VertR / 100, VertG / 100, VertB / 100);
    glPointSize(VertScale);
    //      glDrawArrays(GL_POINTS, 0, V_num);
    glDrawElements(GL_POINTS, F_num, GL_UNSIGNED_INT, F_arr);
  }

  update();

  glDisable(GL_POINT_SMOOTH);  // отключаем сглаживание
  glDisable(GL_LINE_STIPPLE);  // отключаем пунктирные линии
  glDisableClientState(GL_VERTEX_ARRAY);
}

void MyOpenGLWidget::qColorToRGB(const QColor &C, float &r, float &g,
                                 float &b) const {
  //  int red = C.red();
  //  int green = C.green();
  //  int blue = C.blue();

  r = normaliza_0_1(C.red(), RGB_MIN, RGB_MAX);
  g = normaliza_0_1(C.green(), RGB_MIN, RGB_MAX);
  b = normaliza_0_1(C.blue(), RGB_MIN, RGB_MAX);
}

inline float MyOpenGLWidget::normaliza_0_1(float val, float min,
                                           float max) const {
  return (val - min) / (max - min);
}

void MyOpenGLWidget::mousePressEvent(QMouseEvent *mo) { mPos = mo->pos(); }

void MyOpenGLWidget::mouseMoveEvent(QMouseEvent *mo) {
  xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
  yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
  update();
}

void MyOpenGLWidget::ChangeProjection() {
  if (projection_type == 0) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  } else {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 2, 6);
    glTranslatef(0, 0, -3);
  }
}