#ifndef TESTGRAPHICSVIEW_H
#define TESTGRAPHICSVIEW_H

#include <QtOpenGL/QtOpenGL>
#include <gl\GLU.h>

#include "Planet.h"

class TestGraphicsView : public QGLWidget
{
public:
	TestGraphicsView(QWidget* parent);
	~TestGraphicsView();

	void resizeGL( int width, int height );
	void paintGL();

	void initializeGL();
private:

	Planet* m_pPlanet_1;
	Planet* m_pPlanet_2;
	Planet* m_pPlanet_3;
};

#endif