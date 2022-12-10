#include "../include/wavefunc.hpp"
#include "../include/dmath.h"

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

void WaveFunc::checkNorm() const
{
    if      (_norm == 0.0f) throw     ZERO_NORM;
    else if (_norm <  0.0f) throw NEGATIVE_NORM;
}

void WaveFunc::checkMass(bool _isMassless_) const
{
    if      (_mass == 0.0f && !_isMassless_) throw     ZERO_MASS;
    else if (_mass <  0.0f                 ) throw NEGATIVE_MASS;
}

bool WaveFunc::isNormValid() const
{
    if   (_norm <= 0.0f) return false;
    else                 return true ;
}

bool WaveFunc::isMassValid(bool _isMassless_) const
{
    if      (_mass == 0.0f && !_isMassless_) return false;
    else if (_mass <  0.0f)                  return false;
    else                                     return true ;
}

float WaveFunc::norm() const
{
    return _norm;
}

float WaveFunc::mass() const
{
    return _mass;
}

float WaveFunc::ampFactor() const
{
    checkNorm();
    return _norm * invSqrt( prob(false) );                          // 0x5f3759df
}

Complex WaveFunc::cmpFactor() const
{
    return Real(ampFactor());
}

float WaveFunc::prbFactor() const
{
    checkNorm();
    return prob(true) / prob(false);
}

float WaveFunc::prob(bool _isNormed_) const
{
    if (_isNormed_) return         _norm *        _norm;
    else            return  DEFAULT_NORM * DEFAULT_NORM;
}