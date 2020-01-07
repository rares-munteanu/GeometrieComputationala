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

	friend int position(QPointF& P, QPointF& Q, QPointF& R) {
		float delta = Q.x() * R.y() + P.x() * Q.y() + R.x() * P.y() - Q.x() * P.y() - Q.y() * R.x() - P.x() * R.y();
		if (delta == 0)
			return 0;
		else
			if (delta > 0)
				return 1; // R este in stanga lui PQ
			else
				return -1; // R este in dreapta lui PQ
	}

	friend bool isInside(QPointF& P, QPointF& Q, QPointF& R, QPointF& S) {
		int p1, p2, p3;
		p1 = position(P, Q, S);
		p2 = position(R, P, S);
		p3 = position(Q, R, S);
		if (p1 == p2 and p2 == p3)
			return true;
		return false;
	}

private:
	Ui::Form ui;
	bool displayed;
protected:
	QPointF* points;
	int length;
	QPointF pointA;
	QLineF* triangLines;
	int nrOfLines;

};