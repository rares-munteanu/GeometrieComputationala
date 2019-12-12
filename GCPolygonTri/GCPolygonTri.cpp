#include "GCPolygonTri.h"


GCPolygonTri::GCPolygonTri(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(showText()));
}
