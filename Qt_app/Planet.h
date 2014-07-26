#pragma once

#ifndef M_PI
#define M_PI       3.14159265358979323846
#endif

class PlanetSpin
{
public:
    PlanetSpin();
    PlanetSpin( PlanetSpin* pPlanetSpin );

    PlanetSpin( PlanetSpin* pPlanetSpin, float fRotate, float fRadius );

    ~PlanetSpin();

    void Spin();

public:
    float Rotate;
    float Radius;
private:
    PlanetSpin* m_pPlanetSpin;
};

class Planet
{
public:
    Planet( float fRadius );

    ~Planet();

    void Draw();
    void SetRevolution( PlanetSpin* pRevolution ){ m_pRevolution = pRevolution; }
private:
    PlanetSpin* m_pRevolution;
    float m_fRadius;
    int m_nSample;
    float* m_pVectorX;
    float* m_pVectorY;
};