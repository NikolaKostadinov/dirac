#include "../include/wavefunc.hpp"
#include "../include/quick.h"

WaveFunc::WaveFunc()
{
    _norm = 0.0f;
    _mass = 0.0f;
}

WaveFunc::~WaveFunc()
{
    
}

void WaveFunc::setNorm(float _norm_)
{
    _norm =  _norm_;
    checkNorm(    );
}

void WaveFunc::setMass(float _mass_)
{
    _mass =  _mass_;
    checkMass(    );
}

void WaveFunc::checkNorm()
{
    if      (_norm == 0.0f) throw     ZERO_NORM;
    else if (_norm <  0.0f) throw NEGATIVE_NORM;
}

void WaveFunc::checkMass()
{
    if      (_mass == 0.0f) throw     ZERO_MASS;
    else if (_mass <  0.0f) throw NEGATIVE_MASS;
}

bool WaveFunc::isNormValid()
{
    if   (_norm <= 0.0f) return false;
    else                 return true ;
}

bool WaveFunc::isMassValid()
{
    if   (_mass <= 0.0f) return false;
    else                 return true ;
}

float WaveFunc::norm()
{
    return _norm;
}

float WaveFunc::mass()
{
    return _mass;
}

float WaveFunc::ampFactor()
{
    checkNorm();
    return _norm * invSqrt( prob(false) );                          // 0x5f3759df
}

Complex WaveFunc::cmpFactor()
{
    return Real(ampFactor());
}

float WaveFunc::prbFactor()
{
    checkNorm();
    return prob(true) / prob(false);
}

float WaveFunc::prob(bool _isNormed_)
{
    if (_isNormed_) return _norm * _norm;
    else            return  DEFAULT_NORM;
}