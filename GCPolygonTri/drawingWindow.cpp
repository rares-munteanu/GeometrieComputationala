#include "drawingWindow.h"

drawingWindow::drawingWindow(QWidget* parent)
	: QWidget(parent) 
{	
	displayed = false;
	ui.setupUi(this);
}

void drawingWindow::startTriangulation(QPointF *polygonPoints,int numberPointsPolygon, QList <float> pointA) {
	this->show();
}

//void drawingWindow::paintEvent(QPaintEvent* event)
//{
//	QPainter painter(this);
//	painter.setRenderHint(QPainter::Antialiasing);
//	painter.setPen(Qt::black);
//}

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
