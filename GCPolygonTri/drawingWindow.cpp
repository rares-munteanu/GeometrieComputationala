#include "drawingWindow.h"

drawingWindow::drawingWindow(QWidget* parent)
	: QWidget(parent) 
{	
	displayed = false;
	ui.setupUi(this);
}

//primim punctele ordonate dupa x crescator si dupa y descrescator
void drawingWindow::startTriangulation(QPointF *polygonPoints,int numberPointsPolygon, QPointF pointA) {
	this->points = polygonPoints;
	this->length = numberPointsPolygon;
	this->pointA = pointA;
	QList<QPointF> polyPointsList;
	triangLines = new QLineF[length];
	for (int i = 0; i < length; i++)
		polyPointsList.push_back(polygonPoints[i]);
	int currentPoint = 0, noTriangles = 0, listLength;
	bool earFound = true;
	correspondingTriangleFound = false;
	//poligon cu n varfuri => n - 2 triunghiuri => n-3 laturi noi desenate
	while (polyPointsList.length() > 3) {
	    listLength = polyPointsList.length();
		if (position(polyPointsList[currentPoint], polyPointsList[(currentPoint + 1) % listLength], 
			polyPointsList[(currentPoint + 2) % listLength]) < 0) { // inseamna ca punctul de pe pozitia currentPoint + 1 este convex
				earFound = true;
				for(int i = 0; i < listLength; i++)
					if (isInside(polyPointsList[currentPoint], polyPointsList[(currentPoint + 1) % listLength],
						polyPointsList[(currentPoint + 2) % listLength], polyPointsList[i])) {
						i = listLength;
						currentPoint++;
						currentPoint %= listLength;
						earFound = false;
					}
				if (earFound) {
					//currentPoint + 1 trebuie eliminat. avem muchia currentPoint, currentPoint + 2
					if (!correspondingTriangleFound && !isOnTriangleInsideEdge) {
						if (isInside(polyPointsList[currentPoint], polyPointsList[(currentPoint + 1) % listLength],
							polyPointsList[(currentPoint + 2) % listLength], pointA)) {
							correspondingTriangleFound = true;
							pointATriangle = new QPointF[3];
							pointATriangle[0] = polyPointsList[currentPoint];
							pointATriangle[1] = polyPointsList[(currentPoint + 1) % listLength];
							pointATriangle[2] = polyPointsList[(currentPoint + 2) % listLength];
						}
						else if (position(polyPointsList[currentPoint], polyPointsList[(currentPoint + 2) % listLength], pointA) == 0 &&
							isBetween(polyPointsList[currentPoint], polyPointsList[(currentPoint + 2) % listLength], pointA) &&
							pointA != polyPointsList[currentPoint] && pointA != polyPointsList[(currentPoint + 1) % listLength] &&
							pointA != polyPointsList[(currentPoint + 2) % listLength]) {
								isOnTriangleInsideEdge = true;
								pointAOnTriangleEdge.setP1(polyPointsList[currentPoint]);
								pointAOnTriangleEdge.setP2(polyPointsList[(currentPoint + 2) % listLength]);
									/*Punctul A apartine celor 2 triunghiuri adiacente cu segmentul pi pi+2
									correspondingTriangleFound = true;
									pointATriangle = new QPointF[3];
									pointATriangle[0] = polyPointsList[currentPoint];
									pointATriangle[1] = polyPointsList[(currentPoint + 1) % listLength];
									pointATriangle[2] = polyPointsList[(currentPoint + 2) % listLength];*/
						}
					}
					triangLines[noTriangles].setLine(polyPointsList[currentPoint].x(),polyPointsList[currentPoint].y(),
					polyPointsList[(currentPoint + 2) % listLength].x(), polyPointsList[(currentPoint + 2) % listLength].y());
					polyPointsList.removeAt((currentPoint + 1) % listLength);
					noTriangles++;
					currentPoint = currentPoint % polyPointsList.length();
				}
		}
		else 
			currentPoint = (currentPoint + 1) % listLength;
	}	
	nrOfLines = noTriangles;
	if (isInside(polyPointsList[currentPoint], polyPointsList[(currentPoint + 1) % listLength],
		polyPointsList[(currentPoint + 2) % listLength], pointA)) {
		correspondingTriangleFound = true;
		pointATriangle = new QPointF[3];
		pointATriangle[0] = polyPointsList[currentPoint];
		pointATriangle[1] = polyPointsList[(currentPoint + 1) % listLength];
		pointATriangle[2] = polyPointsList[(currentPoint + 2) % listLength];
	}
	this->show();
}

void drawingWindow::paintEvent(QPaintEvent* event)
{
	bool pointOnEdge = false;
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(QPen(Qt::black, 3));
	painter.drawPolygon(points, length);
	
	painter.setPen(QPen(Qt::blue, 3));
	painter.drawLines(triangLines, nrOfLines);
	if (correspondingTriangleFound) {
		//este in interiorul poligonului
		QPainterPath path;
		QPolygonF pointATri;
		for (int i = 0; i < 3; i++)
			pointATri << pointATriangle[i];
		path.addPolygon(pointATri);
		painter.setPen(Qt::NoPen);
		painter.fillPath(path, QBrush(QColor("yellow")));
		painter.setPen(QPen(Qt::red, 3));
		painter.setFont(QFont("times", 13));
		painter.drawPoint(pointA);
		QStaticText pointAText("A");
		painter.drawStaticText(pointA.x() - 5, pointA.y() - 25, pointAText);


		//scris coordonatele
		painter.setPen(QPen(Qt::magenta, 3));
		painter.setFont(QFont("times", 10));
		for (int i = 0; i < length; i++) {
			painter.drawText(QPointF(points[i].x() - 15, points[i].y() - 10), QString("(") +
				QString::number(points[i].x()) + QString(", ") + QString::number(points[i].y()) + QString(")"));
		}

		if (!msgBoxDisplayed) {
			QMessageBox msgBox;
			msgBox.setText(QString("Punctul A(") + QString::number(pointA.x()) + QString(", ") + QString::number(pointA.y()) + QString(") se afla in interiorul poligonului in triunghiul format de punctele:  (") + QString::number(pointATriangle[0].x()) +
				QString(",") + QString::number(pointATriangle[0].y()) + QString("),") + QString("(") + QString::number(pointATriangle[1].x()) +
				QString(",") + QString::number(pointATriangle[1].y()) + QString("),") + QString("(") + QString::number(pointATriangle[2].x()) +
				QString(",") + QString::number(pointATriangle[2].y()) + QString(")"));
			msgBox.setWindowTitle("Point A");
			msgBox.exec();
			msgBoxDisplayed = true;
		}
	}
	else {
		//ori pe latura, ori in exterior, ori pe o latura nou desenata a unui triunghi
		//Verificam daca este pe vreuna din laturile poligonului
		painter.setPen(QPen(Qt::red, 3));
		painter.setFont(QFont("times", 13));
		painter.drawPoint(pointA);
		QStaticText pointAText("A");
		painter.drawStaticText(pointA.x() - 5, pointA.y() - 25, pointAText);

		if (!msgBoxDisplayed) {
			 	//scris coordonatele
				painter.setPen(QPen(Qt::magenta, 3));
				painter.setFont(QFont("times", 10));
				for (int i = 0; i < length; i++) {
					painter.drawText(QPointF(points[i].x() - 15, points[i].y() - 10), QString("(") +
				QString::number(points[i].x()) + QString(", ") + QString::number(points[i].y()) + QString(")"));
			}		
			//Punctul A se aflsa pe un segment interior poligonului care este adiacent cu 2 triunghiuri
			if (isOnTriangleInsideEdge) {
				QMessageBox msgBox;
				msgBox.setText(QString("Punctul A(") + QString::number(pointA.x()) + QString(", ") + QString::number(pointA.y()) + QString(") se afla in interiorul poligonului pe segmentul") + QString("(") + QString::number(pointAOnTriangleEdge.x1()) +
					QString(",") + QString::number(pointAOnTriangleEdge.y1()) + QString(")") + QString("(") + QString::number(pointAOnTriangleEdge.x2()) +
					QString(",") + QString::number(pointAOnTriangleEdge.y2()) + QString(")"));
				msgBox.setWindowTitle("Point A ");
				msgBox.exec();
				msgBoxDisplayed = true;
			}
			//Verificam daca puncutl A este pe vreo latura a poligonului
			for (int i = 0; i < length; i++) {
				if (position(points[i], points[(i + 1) % length], pointA) == 0) { // Se afla pe dreapta pi - pi+1
					if (isBetween(points[i], points[(i + 1) % length], pointA)) {
						//e pe segmentul pi - pi+1
						QMessageBox msgBox;
						msgBox.setText(QString("Punctul A(") + QString::number(pointA.x()) + QString(", ") + QString::number(pointA.y()) + QString(") se afla pe poligon pe segmentul") + QString("[(") + QString::number(points[i].x()) +
							QString(", ") + QString::number(points[i].y()) + QString("), ") + QString("(") + QString::number(points[(i + 1) % length].x()) +
							QString(", ") + QString::number(points[(i + 1) % length].y()) + QString(")]"));
						msgBox.setWindowTitle("Point A ");
						msgBox.exec();
						msgBoxDisplayed = true;
						pointOnEdge = true;
						break;
					}
				}
			}
			if (pointOnEdge == false && isOnTriangleInsideEdge == false) {
																																			
				QMessageBox msgBox;
				msgBox.setText(QString("Punctul A(") + QString::number(pointA.x()) + QString(", ") + QString::number(pointA.y()) + QString(") se afla in exteriorul poligonului."));
				msgBox.setWindowTitle("Point A");
				msgBox.exec();
				msgBoxDisplayed = true;
			}
		}
	}
	//scris coordonatele
	painter.setPen(QPen(Qt::magenta, 3));
	painter.setFont(QFont("times", 10));
	for (int i = 0; i < length; i++) {
		painter.drawText(QPointF(points[i].x() - 15, points[i].y() - 10), QString("(") +
			QString::number(points[i].x()) + QString(", ") + QString::number(points[i].y()) + QString(")"));
	}
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
		msgBoxDisplayed = false;
		reset();
		event->accept();
	}
}
