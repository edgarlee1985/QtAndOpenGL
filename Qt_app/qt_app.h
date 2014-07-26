#ifndef QT_APP_H
#define QT_APP_H

#include <QtGui/QMainWindow>
#include "ui_qt_app.h"
#include <QThread>

class MyThread : public QThread
{
	Q_OBJECT
public:

	MyThread()
	{
	}
	void run()
    {
        while (1)
        {
            msleep( 200 );
            emit trigger();
        }
        exec();
	}

signals:
	void trigger();
};

class Qt_app : public QMainWindow
{
	Q_OBJECT

public:
	Qt_app(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Qt_app();

public slots:
	void GVUpdate()
	{
		ui.graphicsView->update();
	}

private:
	Ui::Qt_appClass ui;
	MyThread m_thread;
};


#endif // QT_APP_H
