#include "Planet.h"
#include <windows.h>
#include "gl\GL.h"
#include "math.h"

PlanetSpin::PlanetSpin()
: Rotate( 0.f )
, Radius( 0.f )
{
    m_pPlanetSpin = NULL;
}

PlanetSpin::PlanetSpin( PlanetSpin* pPlanetSpin )
: Rotate( 0.f )
, Radius( 0.f )
{
    m_pPlanetSpin = pPlanetSpin;
}

PlanetSpin::PlanetSpin( PlanetSpin* pPlanetSpin, float fRotate, float fRadius )
{
    m_pPlanetSpin = pPlanetSpin;
    Rotate = fRotate;
    Radius = fRadius;
}

PlanetSpin::~PlanetSpin()
{
    delete m_pPlanetSpin;
}

void PlanetSpin::Spin()
{
    if ( m_pPlanetSpin != NULL )
        m_pPlanetSpin->Spin();
    Rotate += 5.f;
    glTranslatef( 0.f, 0.f, Radius );
    glRotatef( Rotate, 0.f, 1.f, 0.f );
}

Planet::Planet( float fRadius )
: m_fRadius( fRadius )
, m_nSample( 10 )
{
    m_pVectorX = new float[ m_nSample ];
    m_pVectorY = new float[ m_nSample ];

    float fTheta = 360.f / m_nSample;
    for ( int i = 0; i < m_nSample; ++i )
    {
        m_pVectorX[ i ] = cos( M_PI * fTheta * i / 180 );
        m_pVectorY[ i ] = sin( M_PI * fTheta * i / 180);
    }
}

Planet::~Planet()
{
    if ( m_pVectorX != NULL )
        delete [] m_pVectorX;
    if ( m_pVectorY != NULL )
        delete [] m_pVectorY;
}

void Planet::Draw()
{
    glPushMatrix();
    {
        m_pRevolution->Spin();
        for ( int i = 0; i < m_nSample; ++i )
        {
            glBegin(GL_LINE_LOOP);
            for ( int j = 0; j < m_nSample; ++j )
            {
                glColor3f( 1.0f,0.0f,0.0f );
                glNormal3d( 0, 0, 1 );
                glVertex3f( m_pVectorY[ i ] * m_pVectorX[ j ] * m_fRadius
                          , m_pVectorY[ i ] * m_pVectorY[ j ] * m_fRadius
                          , m_pVectorX[ i ] * m_fRadius );
            }
            glEnd();
        }

        for ( int i = 0; i < m_nSample; ++i )
        {
            glBegin(GL_LINE_LOOP);
            for ( int j = 0; j < m_nSample; ++j )
            {
                glColor3f( 1.f,0.f,0.f );
                glNormal3d( 0, 0, 1 );
                glVertex3f( m_pVectorY[ j ] * m_pVectorX[ i ] * m_fRadius
                          , m_pVectorY[ j ] * m_pVectorY[ i ] * m_fRadius
                          , m_pVectorX[ j ] * m_fRadius );
            }
            glEnd();
        }

    }
    glPopMatrix();

}