#include "qt_app.h"
#include <QtGui/QApplication>
#include <assert.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_app w;
    w.show();

    MyThread m_thread;
    bool bResult = QObject::connect( &m_thread, SIGNAL( trigger(void) ), &w, SLOT( GVUpdate( void ) ) );
    assert( bResult );
    m_thread.start();

    return a.exec();
}
