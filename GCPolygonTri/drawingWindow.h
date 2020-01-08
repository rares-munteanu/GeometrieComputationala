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
#include <QStaticText>

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
	void reset() {
		length = 0;
		correspondingTriangleFound = false;
		isOnTriangleInsideEdge = false;
		msgBoxDisplayed = false;
		nrOfLines = 0;
		/*if (triangLines)
			delete[]triangLines;
		if (points)
			delete[]points;
		if (pointATriangle)
			delete[]pointATriangle;*/
	}
	
	friend int position(QPointF& P, QPointF& Q, QPointF& R) {
		float delta = Q.x() * R.y() + P.x() * Q.y() + R.x() * P.y() - Q.x() * P.y() - Q.y() * R.x() - P.x() * R.y();
		if (delta == 0)
			return 0;
		else
			if (delta > 0)
				return -1; // R este in stanga lui PQ
			else
				return 1; // R este in dreapta lui PQ
	}

	friend bool isInside(QPointF& P, QPointF& Q, QPointF& R, QPointF& S) {
		int p1, p2, p3;
		p1 = position(P, Q, S);
		p2 = position(R, P, S);
		p3 = position(Q, R, S);
		if (p1 == p2 && p2 == p3)
			return true;
		return false;
	}
	friend bool isBetween(QPointF& P, QPointF& Q, QPointF& R) {
		QPointF aux1, aux2, aux3, aux4;
		if (P.x() < Q.x()) {
			aux1 = P;
			aux2 = Q;
		}
		else {
			aux1 = Q;
			aux2 = P;
		}
		if (R.x() >= aux1.x() && R.x() <= aux2.x()) {
			if (aux1.y() < aux2.y()){
				aux3 = aux1;
				aux4 = aux2;
			}
			else{
				aux3 = aux2;
				aux4 = aux1;				
			}
			if(R.y() >= aux3.y() && R.y() <= aux4.y())
				return true;
			else
				return false;
		}
		else
			return false;
	}

private:
	Ui::Form ui;
	bool displayed;
	bool msgBoxDisplayed = false;
protected:
	QPointF* points;
	int length;
	QPointF pointA;
	bool correspondingTriangleFound = false;
	bool isOnTriangleInsideEdge = false;
	QLineF pointAOnTriangleEdge;
	QLineF* triangLines;
	int nrOfLines;
	QPointF* pointATriangle;
	QPointF offset;
};