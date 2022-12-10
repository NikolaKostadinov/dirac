#include "../include/wavefunc3.hpp"

WaveFunc3::WaveFunc3() : Field3<Complex>(), WaveFunc()
{

}

WaveFunc3::~WaveFunc3()
{
    uint32_t  tempXSize = xSize();
    uint32_t  tempYSize = ySize();
    uint32_t  tempZSize = zSize();
    delete   _toBasis;
    
    for (uint32_t i = 0u; i < tempXSize; i++)
        for (uint32_t j = 0u; j < tempYSize; j++)
            for (uint32_t k = 0u; k < tempZSize; k++)
                delete address(i, j, k);
}

WaveFunc3::WaveFunc3(Basis3 _basis_) : Field3<Complex>(_basis_), WaveFunc()
{

}

WaveFunc3::WaveFunc3(Basis3* _toBasis_) : Field3<Complex>(_toBasis_), WaveFunc()
{

}

void WaveFunc3::evolve(float _dt_)
{
    uint32_t fullSize  = size()               ;
    float*   nullArray = new float[fullSize]  ;
    Scalar3* nullField = new Scalar3(_toBasis);

    for (uint32_t i  = 0u  ; i < fullSize; i++)
        nullArray[i] = 0.0f;

    nullField->setValues(nullArray);
    evolve(    _dt_,     nullField);

    free(nullArray);
    free(nullField);
}

void WaveFunc3::evolve(float _dt_, Scalar3 _potential_)
{
    evolve(_dt_, &_potential_);
}

void WaveFunc3::evolve(float _dt_, Scalar3* _toPotential_)
{
    if (_toPotential_->toBasis() == _toBasis)
    {
        checkMass();

        /*float   ilaplCoef = 0.5f * HBAR / _mass * _dt_;                                 // inverted triangle factor
        Complex  laplCoef = Imag(ilaplCoef)           ;                                 // welcome to wonderland
        Complex  thisAmp                              ;
        Complex    d2Amp                              ;

        for (uint32_t i = 0u; i < _xSize; i++)
            for (uint32_t j = 0u; j < _ySize; j++)
                for (uint32_t k = 0u; k < _zSize; k++)
                {
                    thisAmp =   value(i, j, k       );
                    d2Amp   = laplace(i, j, k, false);

                    float   potential = _toPotential_->value(i, j, k);                  // unleash your full potential
                    float  icoreCoef  = -  potential * _dt_ / HBAR   ;
                    Complex coreCoef  = Complex(1, icoreCoef)        ;

                    *address(i, j, k) = laplCoef * d2Amp + coreCoef * thisAmp;         // the cat equation
                }*/
    }
    else throw BASE_NOT_SAME;
}

Complex WaveFunc3::probAmp(uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_) const
{
    if   (_isNormed_) return cmpFactor() * value(_index_,_jndex_,_kndex_);
    else              return               value(_index_,_jndex_,_kndex_);
}

float WaveFunc3::prob(uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_) const
{
    if   (_isNormed_) return prbFactor() * value(_index_,_jndex_,_kndex_).conjSq();
    else              return               value(_index_,_jndex_,_kndex_).conjSq();
}

float WaveFunc3::prob(bool _isNormed_) const
{
   if   (_isNormed_) return _norm * _norm;
    else
    {
        uint32_t tempXSize = xSize();
        uint32_t tempYSize = ySize();
        uint32_t tempZSize = zSize();
        float    sum       =    0.0f;
        for (uint32_t i = 0u; i < tempXSize; i++)
            for (uint32_t j = 0u; j < tempYSize; j++)
                for (uint32_t k = 0u; j < tempZSize; k++)
                    sum += value(i, j, k).conjSq();

        return  sum;
    }
}

Complex WaveFunc3::ddx(uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_) const
{
    uint32_t tempXSize =            xSize();
    float    dx        = _toBasis->xDelta();
    Complex  dAmp                          ;

    if      (_index_ <=           0u) dAmp =  value(_index_+1u,_jndex_,_kndex_)   /*             NULL            */;
    else if (_index_ >= tempXSize-1u) dAmp =  /*             NULL            */ - value(_index_-1u,_jndex_,_kndex_);
    else                              dAmp =  value(_index_+1u,_jndex_,_kndex_) - value(_index_-1u,_jndex_,_kndex_);

    dAmp.shrink(2.0f * dx);

    if (_isNormed_) dAmp.scale(ampFactor());

    return dAmp;
}

Complex WaveFunc3::ddy(uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_) const
{
    uint32_t tempYSize =            ySize();
    float    dy        = _toBasis->yDelta();
    Complex  dAmp                          ;

    if      (_jndex_ <=           0u) dAmp =  value(_index_,_jndex_+1u,_kndex_)   /*             NULL            */;
    else if (_jndex_ >= tempYSize-1u) dAmp =  /*             NULL            */ - value(_index_,_jndex_-1u,_kndex_);
    else                              dAmp =  value(_index_,_jndex_+1u,_kndex_) - value(_index_,_jndex_-1u,_kndex_);

    dAmp.shrink(2.0f * dy);

    if (_isNormed_) dAmp.scale(ampFactor());

    return dAmp;
}

Complex WaveFunc3::ddz(uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_) const
{
    uint32_t tempZSize =            zSize();
    float    dz        = _toBasis->zDelta();
    Complex  dAmp                          ;

    if      (_kndex_ <=           0u) dAmp =  value(_index_,_jndex_,_kndex_+1u)   /*             NULL            */;
    else if (_kndex_ >= tempZSize-1u) dAmp =  /*             NULL            */ - value(_index_,_jndex_,_kndex_-1u);
    else                              dAmp =  value(_index_,_jndex_,_kndex_+1u) - value(_index_,_jndex_,_kndex_-1u);

    dAmp.shrink(2.0f * dz);

    if (_isNormed_) dAmp.scale(ampFactor());

    return dAmp;
}

Complex WaveFunc3::grad(uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_) const
{
    return   ddx(_index_,_jndex_,_kndex_,_isNormed_)
           + ddy(_index_,_jndex_,_kndex_,_isNormed_)
           + ddz(_index_,_jndex_,_kndex_,_isNormed_);
}

Complex WaveFunc3::d2dx2(uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_) const
{
    uint32_t tempXSize =                        xSize();
    float    dx2       =            _toBasis->xDelta2();
    Complex  thisAmp   = value(_index_,_jndex_,_kndex_);
    Complex  two       =                        Real(2);
    Complex  d2Amp                                     ;

    if      (_index_ <=           0u) d2Amp = value(_index_+1u,_jndex_,_kndex_) - two * thisAmp   /*             NULL            */;
    else if (_index_ >= tempXSize-1u) d2Amp = /*             NULL            */ - two * thisAmp + value(_index_-1u,_jndex_,_kndex_);
    else                              d2Amp = value(_index_+1u,_jndex_,_kndex_) - two * thisAmp + value(_index_-1u,_jndex_,_kndex_);

    d2Amp.shrink(dx2);

    if (_isNormed_) d2Amp.scale(ampFactor());

    return d2Amp;
}

Complex WaveFunc3::d2dy2(uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_) const
{
    uint32_t tempYSize =                        ySize();
    float    dy2       =            _toBasis->yDelta2();
    Complex  thisAmp   = value(_index_,_jndex_,_kndex_);
    Complex  two       =                        Real(2);
    Complex  d2Amp                                     ;

    if      (_jndex_ <=           0u) d2Amp = value(_index_,_jndex_+1u,_kndex_) - two * thisAmp   /*             NULL            */;
    else if (_jndex_ >= tempYSize-1u) d2Amp = /*             NULL            */ - two * thisAmp + value(_index_,_jndex_-1u,_kndex_);
    else                              d2Amp = value(_index_,_jndex_+1u,_kndex_) - two * thisAmp + value(_index_,_jndex_-1u,_kndex_);

    d2Amp.shrink(dy2);

    if (_isNormed_) d2Amp.scale(ampFactor());

    return d2Amp;
}

Complex WaveFunc3::d2dz2(uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_) const
{
    uint32_t tempZSize =                        zSize();
    float    dz2       =            _toBasis->zDelta2();
    Complex  thisAmp   = value(_index_,_jndex_,_kndex_);
    Complex  two       =                        Real(2);
    Complex  d2Amp                                     ;

    if      (_kndex_ <=           0u) d2Amp = value(_index_,_jndex_,_kndex_+1u) - two * thisAmp   /*             NULL            */;
    else if (_kndex_ >= tempZSize-1u) d2Amp = /*             NULL            */ - two * thisAmp + value(_index_,_jndex_,_kndex_-1u);
    else                              d2Amp = value(_index_,_jndex_,_kndex_+1u) - two * thisAmp + value(_index_,_jndex_,_kndex_-1u);

    d2Amp.shrink(dz2);

    if (_isNormed_) d2Amp.scale(ampFactor());

    return d2Amp;
}

Complex WaveFunc3::laplace(uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_) const
{
    return   d2dx2(_index_,_jndex_,_kndex_,_isNormed_)
           + d2dy2(_index_,_jndex_,_kndex_,_isNormed_)
           + d2dz2(_index_,_jndex_,_kndex_,_isNormed_);
}

std::string WaveFunc3::string()
{
    // SOON ?
}