#include "qt_app.h"

Qt_app::Qt_app(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
    ui.setupUi(this);
}

Qt_app::~Qt_app()
{

}
