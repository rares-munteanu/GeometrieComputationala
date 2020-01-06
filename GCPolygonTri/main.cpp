#include "GCPolygonTri.h"
#include "drawingWindow.h"
#include <QtWidgets/QApplication>
#include <qdebug.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GCPolygonTri w;
	w.show();
	return a.exec();
}
