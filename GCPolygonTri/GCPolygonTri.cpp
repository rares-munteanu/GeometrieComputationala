#include "GCPolygonTri.h"


GCPolygonTri::GCPolygonTri(QWidget *parent)
	: QMainWindow(parent)
{	
	sWindow = new drawingWindow();
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(showText()));
}
