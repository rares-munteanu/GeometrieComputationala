#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GCPolygonTri.h"
#include <QString>
#include <QDebug>

class GCPolygonTri : public QMainWindow
{
	Q_OBJECT

public:
	GCPolygonTri(QWidget *parent = Q_NULLPTR);
public slots:
	void showText() {
		QString text = ui.textEdit->toPlainText();
		qDebug() << text;
	}
private:
	Ui::GCPolygonTriClass ui;
};
