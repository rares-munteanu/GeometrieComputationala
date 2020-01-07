#include "drawingWindow.h"

drawingWindow::drawingWindow(QWidget* parent)
	: QWidget(parent) 
{	
	displayed = false;
	ui.setupUi(this);
}

void drawingWindow::startTriangulation(QPointF *polygonPoints,int numberPointsPolygon, QPointF pointA) {
	this->points = polygonPoints;
	this->length = numberPointsPolygon;
	this->pointA = pointA;
	
	for (int i = 0; i < length; i++) {

	}

	this->show();
}

void drawingWindow::paintEvent(QPaintEvent* event)
{	
	qDebug() << this->length;
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(Qt::black);
	painter.drawPolygon(points, length);
}

void drawingWindow::closeEvent(QCloseEvent* event)
{
	QMessageBox::StandardButton resBtn = QMessageBox::question(this, "GCPolygonTri",
		tr("Are you sure?\n"),
		QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
		QMessageBox::Yes);
	if (resBtn != QMessageBox::Yes) {
		event->ignore();
	}
	else {
		displayed = false;
		event->accept();
	}
}
