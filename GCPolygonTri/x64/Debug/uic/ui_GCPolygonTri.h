/********************************************************************************
** Form generated from reading UI file 'GCPolygonTri.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GCPOLYGONTRI_H
#define UI_GCPOLYGONTRI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GCPolygonTriClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GCPolygonTriClass)
    {
        if (GCPolygonTriClass->objectName().isEmpty())
            GCPolygonTriClass->setObjectName(QString::fromUtf8("GCPolygonTriClass"));
        GCPolygonTriClass->resize(880, 630);
        GCPolygonTriClass->setMinimumSize(QSize(880, 630));
        GCPolygonTriClass->setMouseTracking(true);
        centralWidget = new QWidget(GCPolygonTriClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 280, 151, 51));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(240, 30, 321, 41));
        textEdit->setMouseTracking(false);
        textEdit->setTabChangesFocus(true);
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(240, 150, 321, 41));
        textEdit_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        textEdit_2->setTabChangesFocus(true);
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 30, 200, 41));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(10, 150, 200, 41));
        textBrowser_2->setAutoFillBackground(false);
        textBrowser_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        GCPolygonTriClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GCPolygonTriClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 880, 26));
        GCPolygonTriClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GCPolygonTriClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GCPolygonTriClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GCPolygonTriClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GCPolygonTriClass->setStatusBar(statusBar);

        retranslateUi(GCPolygonTriClass);

        QMetaObject::connectSlotsByName(GCPolygonTriClass);
    } // setupUi

    void retranslateUi(QMainWindow *GCPolygonTriClass)
    {
        GCPolygonTriClass->setWindowTitle(QApplication::translate("GCPolygonTriClass", "GCPolygonTri", nullptr));
        pushButton->setText(QApplication::translate("GCPolygonTriClass", "Start", nullptr));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("GCPolygonTriClass", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        textEdit->setPlaceholderText(QApplication::translate("GCPolygonTriClass", "Introduceti coordonatelui poligonului in ordine normala", nullptr));
        textEdit_2->setPlaceholderText(QApplication::translate("GCPolygonTriClass", "Introduceti coordonatelui lui A", nullptr));
        textBrowser->setHtml(QApplication::translate("GCPolygonTriClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600;\">Introduceti coordonatele </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600;\">varfurilor poligonului P</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:600;\"><br /></p>\n"
"<p align=\"center"
                        "\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"> </span></p></body></html>", nullptr));
        textBrowser_2->setHtml(QApplication::translate("GCPolygonTriClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600;\">Introduceti coordonatele </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:600;\">punctului A</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GCPolygonTriClass: public Ui_GCPolygonTriClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GCPOLYGONTRI_H
