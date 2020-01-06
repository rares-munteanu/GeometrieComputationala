#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GCPolygonTri.h"
#include <drawingWindow.h>
#include <qdebug.h>

class GCPolygonTri : public QMainWindow
{
	Q_OBJECT
	drawingWindow* sWindow;
public:
	GCPolygonTri(QWidget *parent = Q_NULLPTR);
	bool getStartedTry() {
		return startedTry;
	}
public slots:
	void showText() {
		if (!sWindow->isDisplayed()) {
			QString text = ui.textEdit->toPlainText();
			QString text2 = ui.textEdit_2->toPlainText();

			//parse the first textEdit
			QRegExp rx("[, ;\n#@]");
			QStringList list = text.split(rx, QString::SkipEmptyParts);
			QPointF* nums = new QPointF[list.length() / 2];
			int numberPointsPolygon = list.length() / 2, j = 0;
			int listLength = list.length();
			for (int i = 0; i < listLength; i+=2) {
				nums[j].setX( list[i].toFloat() );
				nums[j].setY( list[i + 1].toFloat() );
				j++;
			}

			for (int i = 0; i < numberPointsPolygon; i++) {
				qDebug() << nums[i].x() << " ";
				qDebug() << nums[i].y() << "\n";
			}

			QStringList list2 = text2.split(rx, QString::SkipEmptyParts);
			QList <float> nums2;
			for (auto i : list2) {
				nums2.append(i.toFloat());
			}
			//check if the 2 textBoxes have the specified format
			if (list.length() == 0 || list.length() % 2 != 0 || nums2.size() != 2) {
				QMessageBox msgBox;
				msgBox.setIcon(QMessageBox::Warning);
				msgBox.setStyleSheet("QLabel{width: 170px; height: 100px; font-size: 24px;}");
				msgBox.setText("Date introduse gresit!");
				msgBox.setWindowTitle("Wrong Input");
				msgBox.exec();
			}
			else {
				QPointF pointA;
				pointA.setX( nums2[0]);
				pointA.setY( nums2[1]);
				sWindow->setDisplayed(true);
				sWindow->startTriangulation(nums, numberPointsPolygon, pointA);
			}
		}
	}
private:
	Ui::GCPolygonTriClass ui;
	bool startedTry = false;
};
