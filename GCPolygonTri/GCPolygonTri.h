#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GCPolygonTri.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QPolygon>
#include <QPainter>
#include <QPainterPath>

class GCPolygonTri : public QMainWindow
{
	Q_OBJECT

public:
	GCPolygonTri(QWidget *parent = Q_NULLPTR);
public slots:
	void showText() {
		if (!startedTri) {
			QString text = ui.textEdit->toPlainText();
			QString text2 = ui.textEdit_2->toPlainText();

			QRegExp rx("[, ;\n#@]");
			QStringList list = text.split(rx, QString::SkipEmptyParts);
			QList <float> nums;
			for (int i = 0; i < list.size(); i++) {
				nums.append(list.at(i).toFloat());
			}
			for (int i = 0; i < list.size(); i++) {
				qDebug() << nums[i] << " ";
			}

			if (nums.size() == 0 || nums.size() % 2 != 0) {
				QMessageBox msgBox;
				msgBox.setText("Date introduse gresit");
				msgBox.setWindowTitle("Wrong Input");
				msgBox.exec();
			}
			QPolygon polygon;
			for (int i = 0; i < nums.size() - 1; i+=2) {
				polygon << QPoint(nums[i], nums[i + 1]);
			}
			QPainter painter(this);
			QPen pen(Qt::red, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
			painter.setPen(pen);
			painter.drawPolygon(polygon);
			//qDebug() << list;

			//qDebug() << text << text2;
			//startedTri = true;
		}
	}
private:
	Ui::GCPolygonTriClass ui;
	bool startedTri = false;
};
