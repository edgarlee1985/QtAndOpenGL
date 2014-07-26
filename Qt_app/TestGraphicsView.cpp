#include "TestGraphicsView.h"

TestGraphicsView::TestGraphicsView(QWidget* parent) : QGLWidget(parent)
{
    m_pPlanet_1 = new Planet( 5 );
    m_pPlanet_1->SetRevolution( new PlanetSpin() );

    m_pPlanet_2 = new Planet( 5 );
    m_pPlanet_2->SetRevolution( new PlanetSpin( new PlanetSpin(), 40, 40 ) );

    m_pPlanet_3 = new Planet( 5 );
    m_pPlanet_3->SetRevolution( new PlanetSpin( new PlanetSpin( new PlanetSpin(), 40, 40 ), 10, 10 ) );

}

TestGraphicsView::~TestGraphicsView()
{
    if ( m_pPlanet_1 != NULL )
        delete m_pPlanet_1;
    if ( m_pPlanet_2 != NULL )
        delete m_pPlanet_2;
    if ( m_pPlanet_3 != NULL )
        delete m_pPlanet_3;
}

void TestGraphicsView::resizeGL( int nWidth, int nHeight )
{
    if ( nWidth <= 0 )
    {
        nWidth = 1;
    }
    if ( nHeight <= 0 )
    {
        nHeight = 1;
    }
    glViewport( 0, 0, (GLint)nWidth, (GLint)nHeight );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 60.0, (GLfloat)nWidth/(GLfloat)nHeight, 0.1, 500.0 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void TestGraphicsView::initializeGL()
{
	glShadeModel( GL_SMOOTH );
	glClearColor( 0.0, 0.0, 0.0, 0.5 );
	glClearDepth( 1.0 );
	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LEQUAL );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}

void TestGraphicsView::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f( 0.0, 0.0, 1.0 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    gluLookAt( 0.0, 100.0, -150.0,   // Camera position
               0.0,   0.0,    0.0,   // Look-at point
               0.0,   0.0,    1.0 ); // Up vector

    m_pPlanet_1->Draw();
    m_pPlanet_2->Draw();
    m_pPlanet_3->Draw();
}
