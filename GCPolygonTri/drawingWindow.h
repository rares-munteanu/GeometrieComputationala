#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_drawingWindow.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QPolygon>
#include <QPainter>
#include <QPainterPath>
#include <QCloseEvent>

class drawingWindow : public QWidget
{
	Q_OBJECT
public:
	drawingWindow(QWidget* parent = Q_NULLPTR);
	void setDisplayed(bool state) {
		displayed = state;
	}
	bool isDisplayed() {
		return displayed;
	}
	void startTriangulation(QPointF*,int, QPointF);
	void paintEvent(QPaintEvent* event);
	void closeEvent(QCloseEvent* event);
private:
	Ui::Form ui;
	bool displayed;
protected:
	QPointF* points;
	int length;
	QPointF pointA;
};