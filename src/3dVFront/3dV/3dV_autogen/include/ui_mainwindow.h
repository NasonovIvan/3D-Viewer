/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <myopenglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonOpenFile;
    QGroupBox *groupBoxMove;
    QSlider *sliderMoveZ;
    QSlider *sliderMoveX;
    QLabel *labelY;
    QLabel *labelMove;
    QLabel *labelZ;
    QLabel *labelX;
    QSlider *sliderMoveY;
    QPushButton *MoveButton;
    QLineEdit *lineX;
    QLineEdit *lineY;
    QLineEdit *lineZ;
    QGroupBox *groupBoxProjection;
    QRadioButton *radioPerspective;
    QRadioButton *radioOrtho;
    QGroupBox *groupBoxEdges;
    QLabel *labelEdges;
    QLabel *lineLineR;
    QLabel *lineLineB;
    QSlider *sliderLineB;
    QLabel *lineLineG;
    QSlider *sliderLineG;
    QSlider *sliderLineR;
    QSlider *sliderLineWidth;
    QLabel *labelEdgesWidth;
    QLineEdit *lineLineWidth;
    QComboBox *comboBox;
    QGroupBox *groupBoxRotate;
    QSlider *sliderRotateZ;
    QSlider *sliderRotateX;
    QLabel *lineRotateY;
    QLabel *lineRotate;
    QLabel *lineRotateZ;
    QLabel *lineRotateX;
    QSlider *sliderRotateY;
    QPushButton *RotateButton;
    QLineEdit *lineRotX;
    QLineEdit *lineRotY;
    QLineEdit *lineRotZ;
    QGroupBox *groupBoxVertices;
    QLabel *labelVertices;
    QLabel *labelVertScale;
    QLineEdit *lineVertScale;
    QSlider *sliderVertR;
    QSlider *sliderVertScale;
    QSlider *sliderVertG;
    QLabel *lineVertG;
    QLabel *lineVertB;
    QLabel *lineVertR;
    QSlider *sliderVertB;
    QComboBox *comboBoxVert;
    QLabel *labelPashFile;
    QLabel *labelF;
    QLabel *labelCountV;
    QLabel *labelCountF;
    QLabel *labelV;
    QPushButton *pushButtonJPG;
    QPushButton *pushButtonBMP;
    QPushButton *pushButtonGIF;
    MyOpenGLWidget *widget;
    QGroupBox *groupBoxScale;
    QSlider *sliderScale;
    QLabel *labelScale;
    QPushButton *ScaleButton;
    QLineEdit *lineScale;
    QGroupBox *groupBoxBackround;
    QSlider *sliderBackroundR;
    QLabel *labelBackround;
    QLabel *lineBackR;
    QSlider *sliderBackroundG;
    QSlider *sliderBackroundB;
    QLabel *lineBackG;
    QLabel *lineBackB;
    QPushButton *ResetSettings;
    QPushButton *LoadSettings;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1500, 1207);
        MainWindow->setMinimumSize(QSize(1000, 1000));
        MainWindow->setMaximumSize(QSize(1500, 1500));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButtonOpenFile = new QPushButton(centralwidget);
        pushButtonOpenFile->setObjectName(QString::fromUtf8("pushButtonOpenFile"));
        pushButtonOpenFile->setGeometry(QRect(20, 20, 271, 41));
        pushButtonOpenFile->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(100, 100, 100);\n"
"    color: white;\n"
"	font: 15px \"Apple\";\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(180, 180, 180);\n"
"}"));
        groupBoxMove = new QGroupBox(centralwidget);
        groupBoxMove->setObjectName(QString::fromUtf8("groupBoxMove"));
        groupBoxMove->setGeometry(QRect(20, 200, 271, 151));
        sliderMoveZ = new QSlider(groupBoxMove);
        sliderMoveZ->setObjectName(QString::fromUtf8("sliderMoveZ"));
        sliderMoveZ->setGeometry(QRect(50, 90, 131, 25));
        sliderMoveZ->setMaximumSize(QSize(200, 200));
        sliderMoveZ->setLayoutDirection(Qt::LeftToRight);
        sliderMoveZ->setSliderPosition(50);
        sliderMoveZ->setOrientation(Qt::Horizontal);
        sliderMoveZ->setInvertedAppearance(false);
        sliderMoveZ->setInvertedControls(false);
        sliderMoveX = new QSlider(groupBoxMove);
        sliderMoveX->setObjectName(QString::fromUtf8("sliderMoveX"));
        sliderMoveX->setGeometry(QRect(50, 30, 131, 25));
        sliderMoveX->setMaximumSize(QSize(200, 200));
        sliderMoveX->setLayoutDirection(Qt::LeftToRight);
        sliderMoveX->setSliderPosition(50);
        sliderMoveX->setOrientation(Qt::Horizontal);
        sliderMoveX->setInvertedAppearance(false);
        sliderMoveX->setInvertedControls(false);
        labelY = new QLabel(groupBoxMove);
        labelY->setObjectName(QString::fromUtf8("labelY"));
        labelY->setGeometry(QRect(20, 60, 21, 16));
        labelMove = new QLabel(groupBoxMove);
        labelMove->setObjectName(QString::fromUtf8("labelMove"));
        labelMove->setGeometry(QRect(100, 10, 58, 16));
        labelZ = new QLabel(groupBoxMove);
        labelZ->setObjectName(QString::fromUtf8("labelZ"));
        labelZ->setGeometry(QRect(20, 90, 21, 16));
        labelX = new QLabel(groupBoxMove);
        labelX->setObjectName(QString::fromUtf8("labelX"));
        labelX->setGeometry(QRect(20, 30, 21, 16));
        sliderMoveY = new QSlider(groupBoxMove);
        sliderMoveY->setObjectName(QString::fromUtf8("sliderMoveY"));
        sliderMoveY->setGeometry(QRect(50, 60, 131, 25));
        sliderMoveY->setMaximumSize(QSize(200, 200));
        sliderMoveY->setLayoutDirection(Qt::LeftToRight);
        sliderMoveY->setSliderPosition(50);
        sliderMoveY->setOrientation(Qt::Horizontal);
        sliderMoveY->setInvertedAppearance(false);
        sliderMoveY->setInvertedControls(false);
        MoveButton = new QPushButton(groupBoxMove);
        MoveButton->setObjectName(QString::fromUtf8("MoveButton"));
        MoveButton->setGeometry(QRect(60, 120, 141, 21));
        MoveButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(200, 200, 200);\n"
"    color: black;\n"
"	font: 13px \"Apple\";\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(150, 150, 150);\n"
"}"));
        lineX = new QLineEdit(groupBoxMove);
        lineX->setObjectName(QString::fromUtf8("lineX"));
        lineX->setGeometry(QRect(190, 30, 71, 21));
        lineY = new QLineEdit(groupBoxMove);
        lineY->setObjectName(QString::fromUtf8("lineY"));
        lineY->setGeometry(QRect(190, 60, 71, 21));
        lineZ = new QLineEdit(groupBoxMove);
        lineZ->setObjectName(QString::fromUtf8("lineZ"));
        lineZ->setGeometry(QRect(190, 90, 71, 21));
        groupBoxProjection = new QGroupBox(centralwidget);
        groupBoxProjection->setObjectName(QString::fromUtf8("groupBoxProjection"));
        groupBoxProjection->setGeometry(QRect(20, 560, 271, 61));
        radioPerspective = new QRadioButton(groupBoxProjection);
        radioPerspective->setObjectName(QString::fromUtf8("radioPerspective"));
        radioPerspective->setGeometry(QRect(40, 30, 181, 20));
        radioPerspective->setChecked(false);
        radioOrtho = new QRadioButton(groupBoxProjection);
        radioOrtho->setObjectName(QString::fromUtf8("radioOrtho"));
        radioOrtho->setGeometry(QRect(40, 10, 181, 20));
        radioOrtho->setChecked(false);
        groupBoxEdges = new QGroupBox(centralwidget);
        groupBoxEdges->setObjectName(QString::fromUtf8("groupBoxEdges"));
        groupBoxEdges->setGeometry(QRect(50, 970, 571, 151));
        labelEdges = new QLabel(groupBoxEdges);
        labelEdges->setObjectName(QString::fromUtf8("labelEdges"));
        labelEdges->setGeometry(QRect(250, 10, 58, 16));
        lineLineR = new QLabel(groupBoxEdges);
        lineLineR->setObjectName(QString::fromUtf8("lineLineR"));
        lineLineR->setGeometry(QRect(20, 50, 21, 16));
        lineLineB = new QLabel(groupBoxEdges);
        lineLineB->setObjectName(QString::fromUtf8("lineLineB"));
        lineLineB->setGeometry(QRect(20, 110, 21, 16));
        sliderLineB = new QSlider(groupBoxEdges);
        sliderLineB->setObjectName(QString::fromUtf8("sliderLineB"));
        sliderLineB->setGeometry(QRect(60, 110, 181, 25));
        sliderLineB->setMaximumSize(QSize(200, 200));
        sliderLineB->setLayoutDirection(Qt::LeftToRight);
        sliderLineB->setSliderPosition(50);
        sliderLineB->setOrientation(Qt::Horizontal);
        sliderLineB->setInvertedAppearance(false);
        sliderLineB->setInvertedControls(false);
        lineLineG = new QLabel(groupBoxEdges);
        lineLineG->setObjectName(QString::fromUtf8("lineLineG"));
        lineLineG->setGeometry(QRect(20, 80, 21, 16));
        sliderLineG = new QSlider(groupBoxEdges);
        sliderLineG->setObjectName(QString::fromUtf8("sliderLineG"));
        sliderLineG->setGeometry(QRect(60, 80, 181, 25));
        sliderLineG->setMaximumSize(QSize(200, 200));
        sliderLineG->setLayoutDirection(Qt::LeftToRight);
        sliderLineG->setSliderPosition(50);
        sliderLineG->setOrientation(Qt::Horizontal);
        sliderLineG->setInvertedAppearance(false);
        sliderLineG->setInvertedControls(false);
        sliderLineR = new QSlider(groupBoxEdges);
        sliderLineR->setObjectName(QString::fromUtf8("sliderLineR"));
        sliderLineR->setGeometry(QRect(60, 50, 181, 25));
        sliderLineR->setMaximumSize(QSize(200, 200));
        sliderLineR->setLayoutDirection(Qt::LeftToRight);
        sliderLineR->setSliderPosition(50);
        sliderLineR->setOrientation(Qt::Horizontal);
        sliderLineR->setInvertedAppearance(false);
        sliderLineR->setInvertedControls(false);
        sliderLineWidth = new QSlider(groupBoxEdges);
        sliderLineWidth->setObjectName(QString::fromUtf8("sliderLineWidth"));
        sliderLineWidth->setGeometry(QRect(310, 110, 181, 25));
        sliderLineWidth->setMaximumSize(QSize(200, 200));
        sliderLineWidth->setLayoutDirection(Qt::LeftToRight);
        sliderLineWidth->setSliderPosition(50);
        sliderLineWidth->setOrientation(Qt::Horizontal);
        sliderLineWidth->setInvertedAppearance(false);
        sliderLineWidth->setInvertedControls(false);
        labelEdgesWidth = new QLabel(groupBoxEdges);
        labelEdgesWidth->setObjectName(QString::fromUtf8("labelEdgesWidth"));
        labelEdgesWidth->setGeometry(QRect(370, 80, 91, 16));
        lineLineWidth = new QLineEdit(groupBoxEdges);
        lineLineWidth->setObjectName(QString::fromUtf8("lineLineWidth"));
        lineLineWidth->setGeometry(QRect(500, 110, 51, 21));
        comboBox = new QComboBox(groupBoxEdges);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(320, 40, 201, 32));
        groupBoxRotate = new QGroupBox(centralwidget);
        groupBoxRotate->setObjectName(QString::fromUtf8("groupBoxRotate"));
        groupBoxRotate->setGeometry(QRect(20, 380, 271, 151));
        sliderRotateZ = new QSlider(groupBoxRotate);
        sliderRotateZ->setObjectName(QString::fromUtf8("sliderRotateZ"));
        sliderRotateZ->setGeometry(QRect(50, 90, 131, 25));
        sliderRotateZ->setMaximumSize(QSize(200, 200));
        sliderRotateZ->setLayoutDirection(Qt::LeftToRight);
        sliderRotateZ->setSliderPosition(50);
        sliderRotateZ->setOrientation(Qt::Horizontal);
        sliderRotateZ->setInvertedAppearance(false);
        sliderRotateZ->setInvertedControls(false);
        sliderRotateX = new QSlider(groupBoxRotate);
        sliderRotateX->setObjectName(QString::fromUtf8("sliderRotateX"));
        sliderRotateX->setGeometry(QRect(50, 30, 131, 25));
        sliderRotateX->setMaximumSize(QSize(200, 200));
        sliderRotateX->setLayoutDirection(Qt::LeftToRight);
        sliderRotateX->setSliderPosition(50);
        sliderRotateX->setOrientation(Qt::Horizontal);
        sliderRotateX->setInvertedAppearance(false);
        sliderRotateX->setInvertedControls(false);
        lineRotateY = new QLabel(groupBoxRotate);
        lineRotateY->setObjectName(QString::fromUtf8("lineRotateY"));
        lineRotateY->setGeometry(QRect(20, 60, 21, 16));
        lineRotate = new QLabel(groupBoxRotate);
        lineRotate->setObjectName(QString::fromUtf8("lineRotate"));
        lineRotate->setGeometry(QRect(100, 10, 58, 16));
        lineRotateZ = new QLabel(groupBoxRotate);
        lineRotateZ->setObjectName(QString::fromUtf8("lineRotateZ"));
        lineRotateZ->setGeometry(QRect(20, 90, 21, 16));
        lineRotateX = new QLabel(groupBoxRotate);
        lineRotateX->setObjectName(QString::fromUtf8("lineRotateX"));
        lineRotateX->setGeometry(QRect(20, 30, 21, 16));
        sliderRotateY = new QSlider(groupBoxRotate);
        sliderRotateY->setObjectName(QString::fromUtf8("sliderRotateY"));
        sliderRotateY->setGeometry(QRect(50, 60, 131, 25));
        sliderRotateY->setMaximumSize(QSize(200, 200));
        sliderRotateY->setLayoutDirection(Qt::LeftToRight);
        sliderRotateY->setSliderPosition(50);
        sliderRotateY->setOrientation(Qt::Horizontal);
        sliderRotateY->setInvertedAppearance(false);
        sliderRotateY->setInvertedControls(false);
        RotateButton = new QPushButton(groupBoxRotate);
        RotateButton->setObjectName(QString::fromUtf8("RotateButton"));
        RotateButton->setGeometry(QRect(60, 120, 141, 21));
        RotateButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(200, 200, 200);\n"
"    color: black;\n"
"	font: 13px \"Apple\";\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(150, 150, 150);\n"
"}"));
        lineRotX = new QLineEdit(groupBoxRotate);
        lineRotX->setObjectName(QString::fromUtf8("lineRotX"));
        lineRotX->setGeometry(QRect(190, 30, 71, 21));
        lineRotY = new QLineEdit(groupBoxRotate);
        lineRotY->setObjectName(QString::fromUtf8("lineRotY"));
        lineRotY->setGeometry(QRect(190, 60, 71, 21));
        lineRotZ = new QLineEdit(groupBoxRotate);
        lineRotZ->setObjectName(QString::fromUtf8("lineRotZ"));
        lineRotZ->setGeometry(QRect(190, 90, 71, 21));
        groupBoxVertices = new QGroupBox(centralwidget);
        groupBoxVertices->setObjectName(QString::fromUtf8("groupBoxVertices"));
        groupBoxVertices->setGeometry(QRect(740, 970, 601, 151));
        labelVertices = new QLabel(groupBoxVertices);
        labelVertices->setObjectName(QString::fromUtf8("labelVertices"));
        labelVertices->setGeometry(QRect(270, 10, 58, 16));
        labelVertScale = new QLabel(groupBoxVertices);
        labelVertScale->setObjectName(QString::fromUtf8("labelVertScale"));
        labelVertScale->setGeometry(QRect(390, 80, 91, 16));
        lineVertScale = new QLineEdit(groupBoxVertices);
        lineVertScale->setObjectName(QString::fromUtf8("lineVertScale"));
        lineVertScale->setGeometry(QRect(520, 110, 51, 21));
        sliderVertR = new QSlider(groupBoxVertices);
        sliderVertR->setObjectName(QString::fromUtf8("sliderVertR"));
        sliderVertR->setGeometry(QRect(80, 50, 181, 25));
        sliderVertR->setMaximumSize(QSize(200, 200));
        sliderVertR->setLayoutDirection(Qt::LeftToRight);
        sliderVertR->setSliderPosition(50);
        sliderVertR->setOrientation(Qt::Horizontal);
        sliderVertR->setInvertedAppearance(false);
        sliderVertR->setInvertedControls(false);
        sliderVertScale = new QSlider(groupBoxVertices);
        sliderVertScale->setObjectName(QString::fromUtf8("sliderVertScale"));
        sliderVertScale->setGeometry(QRect(330, 110, 181, 25));
        sliderVertScale->setMaximumSize(QSize(200, 200));
        sliderVertScale->setLayoutDirection(Qt::LeftToRight);
        sliderVertScale->setSliderPosition(50);
        sliderVertScale->setOrientation(Qt::Horizontal);
        sliderVertScale->setInvertedAppearance(false);
        sliderVertScale->setInvertedControls(false);
        sliderVertG = new QSlider(groupBoxVertices);
        sliderVertG->setObjectName(QString::fromUtf8("sliderVertG"));
        sliderVertG->setGeometry(QRect(80, 80, 181, 25));
        sliderVertG->setMaximumSize(QSize(200, 200));
        sliderVertG->setLayoutDirection(Qt::LeftToRight);
        sliderVertG->setSliderPosition(50);
        sliderVertG->setOrientation(Qt::Horizontal);
        sliderVertG->setInvertedAppearance(false);
        sliderVertG->setInvertedControls(false);
        lineVertG = new QLabel(groupBoxVertices);
        lineVertG->setObjectName(QString::fromUtf8("lineVertG"));
        lineVertG->setGeometry(QRect(40, 80, 21, 16));
        lineVertB = new QLabel(groupBoxVertices);
        lineVertB->setObjectName(QString::fromUtf8("lineVertB"));
        lineVertB->setGeometry(QRect(40, 110, 21, 16));
        lineVertR = new QLabel(groupBoxVertices);
        lineVertR->setObjectName(QString::fromUtf8("lineVertR"));
        lineVertR->setGeometry(QRect(40, 50, 21, 16));
        sliderVertB = new QSlider(groupBoxVertices);
        sliderVertB->setObjectName(QString::fromUtf8("sliderVertB"));
        sliderVertB->setGeometry(QRect(80, 110, 181, 25));
        sliderVertB->setMaximumSize(QSize(200, 200));
        sliderVertB->setLayoutDirection(Qt::LeftToRight);
        sliderVertB->setSliderPosition(50);
        sliderVertB->setOrientation(Qt::Horizontal);
        sliderVertB->setInvertedAppearance(false);
        sliderVertB->setInvertedControls(false);
        comboBoxVert = new QComboBox(groupBoxVertices);
        comboBoxVert->addItem(QString());
        comboBoxVert->addItem(QString());
        comboBoxVert->addItem(QString());
        comboBoxVert->setObjectName(QString::fromUtf8("comboBoxVert"));
        comboBoxVert->setGeometry(QRect(330, 40, 201, 32));
        labelPashFile = new QLabel(centralwidget);
        labelPashFile->setObjectName(QString::fromUtf8("labelPashFile"));
        labelPashFile->setGeometry(QRect(20, 930, 1161, 16));
        labelF = new QLabel(centralwidget);
        labelF->setObjectName(QString::fromUtf8("labelF"));
        labelF->setGeometry(QRect(1320, 930, 58, 16));
        labelCountV = new QLabel(centralwidget);
        labelCountV->setObjectName(QString::fromUtf8("labelCountV"));
        labelCountV->setGeometry(QRect(1250, 930, 58, 16));
        labelCountF = new QLabel(centralwidget);
        labelCountF->setObjectName(QString::fromUtf8("labelCountF"));
        labelCountF->setGeometry(QRect(1390, 930, 58, 16));
        labelV = new QLabel(centralwidget);
        labelV->setObjectName(QString::fromUtf8("labelV"));
        labelV->setGeometry(QRect(1190, 930, 58, 16));
        pushButtonJPG = new QPushButton(centralwidget);
        pushButtonJPG->setObjectName(QString::fromUtf8("pushButtonJPG"));
        pushButtonJPG->setGeometry(QRect(1010, 20, 100, 32));
        pushButtonJPG->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(100, 100, 100);\n"
"    color: white;\n"
"	font: 14px \"Apple\";\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(180, 180, 180);\n"
"}"));
        pushButtonBMP = new QPushButton(centralwidget);
        pushButtonBMP->setObjectName(QString::fromUtf8("pushButtonBMP"));
        pushButtonBMP->setGeometry(QRect(1130, 20, 100, 32));
        pushButtonBMP->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(100, 100, 100);\n"
"    color: white;\n"
"	font: 14px \"Apple\";\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(180, 180, 180);\n"
"}"));
        pushButtonGIF = new QPushButton(centralwidget);
        pushButtonGIF->setObjectName(QString::fromUtf8("pushButtonGIF"));
        pushButtonGIF->setGeometry(QRect(1250, 20, 100, 32));
        pushButtonGIF->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(100, 100, 100);\n"
"    color: white;\n"
"	font: 14px \"Apple\";\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(180, 180, 180);\n"
"}"));
        widget = new MyOpenGLWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(310, 60, 1161, 831));
        groupBoxScale = new QGroupBox(centralwidget);
        groupBoxScale->setObjectName(QString::fromUtf8("groupBoxScale"));
        groupBoxScale->setGeometry(QRect(20, 80, 271, 91));
        sliderScale = new QSlider(groupBoxScale);
        sliderScale->setObjectName(QString::fromUtf8("sliderScale"));
        sliderScale->setGeometry(QRect(30, 30, 131, 25));
        sliderScale->setMaximumSize(QSize(200, 200));
        sliderScale->setLayoutDirection(Qt::LeftToRight);
        sliderScale->setSliderPosition(50);
        sliderScale->setOrientation(Qt::Horizontal);
        sliderScale->setInvertedAppearance(false);
        sliderScale->setInvertedControls(false);
        labelScale = new QLabel(groupBoxScale);
        labelScale->setObjectName(QString::fromUtf8("labelScale"));
        labelScale->setGeometry(QRect(100, 10, 58, 16));
        ScaleButton = new QPushButton(groupBoxScale);
        ScaleButton->setObjectName(QString::fromUtf8("ScaleButton"));
        ScaleButton->setGeometry(QRect(60, 60, 141, 21));
        ScaleButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(200, 200, 200);\n"
"    color: black;\n"
"	font: 13px \"Apple\";\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(150, 150, 150);\n"
"}"));
        lineScale = new QLineEdit(groupBoxScale);
        lineScale->setObjectName(QString::fromUtf8("lineScale"));
        lineScale->setGeometry(QRect(170, 30, 81, 21));
        groupBoxBackround = new QGroupBox(centralwidget);
        groupBoxBackround->setObjectName(QString::fromUtf8("groupBoxBackround"));
        groupBoxBackround->setGeometry(QRect(20, 650, 271, 131));
        sliderBackroundR = new QSlider(groupBoxBackround);
        sliderBackroundR->setObjectName(QString::fromUtf8("sliderBackroundR"));
        sliderBackroundR->setGeometry(QRect(60, 40, 181, 25));
        sliderBackroundR->setMaximumSize(QSize(200, 200));
        sliderBackroundR->setLayoutDirection(Qt::LeftToRight);
        sliderBackroundR->setSliderPosition(50);
        sliderBackroundR->setOrientation(Qt::Horizontal);
        sliderBackroundR->setInvertedAppearance(false);
        sliderBackroundR->setInvertedControls(false);
        labelBackround = new QLabel(groupBoxBackround);
        labelBackround->setObjectName(QString::fromUtf8("labelBackround"));
        labelBackround->setGeometry(QRect(100, 10, 91, 16));
        lineBackR = new QLabel(groupBoxBackround);
        lineBackR->setObjectName(QString::fromUtf8("lineBackR"));
        lineBackR->setGeometry(QRect(20, 40, 21, 16));
        sliderBackroundG = new QSlider(groupBoxBackround);
        sliderBackroundG->setObjectName(QString::fromUtf8("sliderBackroundG"));
        sliderBackroundG->setGeometry(QRect(60, 70, 181, 25));
        sliderBackroundG->setMaximumSize(QSize(200, 200));
        sliderBackroundG->setLayoutDirection(Qt::LeftToRight);
        sliderBackroundG->setSliderPosition(50);
        sliderBackroundG->setOrientation(Qt::Horizontal);
        sliderBackroundG->setInvertedAppearance(false);
        sliderBackroundG->setInvertedControls(false);
        sliderBackroundB = new QSlider(groupBoxBackround);
        sliderBackroundB->setObjectName(QString::fromUtf8("sliderBackroundB"));
        sliderBackroundB->setGeometry(QRect(60, 100, 181, 25));
        sliderBackroundB->setMaximumSize(QSize(200, 200));
        sliderBackroundB->setLayoutDirection(Qt::LeftToRight);
        sliderBackroundB->setSliderPosition(50);
        sliderBackroundB->setOrientation(Qt::Horizontal);
        sliderBackroundB->setInvertedAppearance(false);
        sliderBackroundB->setInvertedControls(false);
        lineBackG = new QLabel(groupBoxBackround);
        lineBackG->setObjectName(QString::fromUtf8("lineBackG"));
        lineBackG->setGeometry(QRect(20, 70, 21, 16));
        lineBackB = new QLabel(groupBoxBackround);
        lineBackB->setObjectName(QString::fromUtf8("lineBackB"));
        lineBackB->setGeometry(QRect(20, 100, 21, 16));
        ResetSettings = new QPushButton(centralwidget);
        ResetSettings->setObjectName(QString::fromUtf8("ResetSettings"));
        ResetSettings->setGeometry(QRect(20, 800, 261, 41));
        ResetSettings->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(200, 200, 200);\n"
"    color: black;\n"
"	font: 13px \"Apple\";\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(150, 150, 150);\n"
"}"));
        LoadSettings = new QPushButton(centralwidget);
        LoadSettings->setObjectName(QString::fromUtf8("LoadSettings"));
        LoadSettings->setGeometry(QRect(20, 860, 261, 41));
        LoadSettings->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(200, 200, 200);\n"
"    color: black;\n"
"	font: 13px \"Apple\";\n"
"	border-radius: 10px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(150, 150, 150);\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1500, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonOpenFile->setText(QCoreApplication::translate("MainWindow", "open file", nullptr));
        groupBoxMove->setTitle(QString());
        labelY->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        labelMove->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        labelZ->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        labelX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        MoveButton->setText(QCoreApplication::translate("MainWindow", "Do", nullptr));
        groupBoxProjection->setTitle(QString());
        radioPerspective->setText(QCoreApplication::translate("MainWindow", "Perspective Projection", nullptr));
        radioOrtho->setText(QCoreApplication::translate("MainWindow", "Orthographic Projection", nullptr));
        groupBoxEdges->setTitle(QString());
        labelEdges->setText(QCoreApplication::translate("MainWindow", "Lines", nullptr));
        lineLineR->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        lineLineB->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        lineLineG->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        labelEdgesWidth->setText(QCoreApplication::translate("MainWindow", "Lines Width", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "_______________", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", ". . . . . . . . . . . . . . . . . ", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "- - - - - - - - - - - - ", nullptr));

        groupBoxRotate->setTitle(QString());
        lineRotateY->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        lineRotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        lineRotateZ->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        lineRotateX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        RotateButton->setText(QCoreApplication::translate("MainWindow", "Do", nullptr));
        groupBoxVertices->setTitle(QString());
        labelVertices->setText(QCoreApplication::translate("MainWindow", "Vertices", nullptr));
        labelVertScale->setText(QCoreApplication::translate("MainWindow", "Vertices Scale", nullptr));
        lineVertG->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        lineVertB->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        lineVertR->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        comboBoxVert->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        comboBoxVert->setItemText(1, QCoreApplication::translate("MainWindow", "\342\227\217", nullptr));
        comboBoxVert->setItemText(2, QCoreApplication::translate("MainWindow", "\342\226\240", nullptr));

        labelPashFile->setText(QString());
        labelF->setText(QCoreApplication::translate("MainWindow", "F", nullptr));
        labelCountV->setText(QString());
        labelCountF->setText(QString());
        labelV->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        pushButtonJPG->setText(QCoreApplication::translate("MainWindow", "JPG", nullptr));
        pushButtonBMP->setText(QCoreApplication::translate("MainWindow", "BMP", nullptr));
        pushButtonGIF->setText(QCoreApplication::translate("MainWindow", "GIF", nullptr));
        groupBoxScale->setTitle(QString());
        labelScale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        ScaleButton->setText(QCoreApplication::translate("MainWindow", "Do", nullptr));
        groupBoxBackround->setTitle(QString());
        labelBackround->setText(QCoreApplication::translate("MainWindow", "Backround", nullptr));
        lineBackR->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        lineBackG->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        lineBackB->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        ResetSettings->setText(QCoreApplication::translate("MainWindow", "Reset Settings", nullptr));
        LoadSettings->setText(QCoreApplication::translate("MainWindow", "Load Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
