#include "../include/wavefunc2.hpp"

#include <iostream>

WaveFunc2::WaveFunc2() : Field2<Complex>(), WaveFunc()
{

}

WaveFunc2::~WaveFunc2()
{
    delete _toBasis;
    
    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            delete address(i, j);
}

WaveFunc2::WaveFunc2(Basis2 _basis_) : Field2<Complex>(_basis_), WaveFunc()
{

}

WaveFunc2::WaveFunc2(Basis2* _toBasis_) : Field2<Complex>(_toBasis_), WaveFunc()
{

}

void WaveFunc2::evolve(float _dt_)
{
    uint32_t fullSize  = size()               ;
    float*   nullArray = new float[fullSize]  ;
    Scalar2* nullField = new Scalar2(_toBasis);

    for (uint32_t i  = 0u  ; i < fullSize; i++)
        nullArray[i] = 0.0f;

    nullField->setValues(nullArray);
    evolve(    _dt_,     nullField);

    free(nullArray);
    free(nullField);
}

void WaveFunc2::evolve(float _dt_, Scalar2 _potential_)
{
    evolve(_dt_, &_potential_);
}

void WaveFunc2::evolve(float _dt_, Scalar2* _toPotential_)
{
    if (_toPotential_->toBasis() == _toBasis)
    {
        checkMass();
        
        Complex  thisAmp  ;
        Complex    d2Amp  ;
        float    potential;
        float   icoreCoef ;
        Complex  coreCoef ;

        float   ilaplCoef = 0.5f * HBAR / _mass * _dt_;                         // inverted triangle factor
        Complex  laplCoef = Imag(ilaplCoef)           ;                         // welcome to wonderland

        for (uint32_t i = 0u; i < _xSize; i++)
            for (uint32_t j = 0u; j < _ySize; j++)
            {
                thisAmp =   value(i, j       );
                d2Amp   = laplace(i, j, false);

                potential = _toPotential_->value(i, j);                         // unleash your full potential
                icoreCoef = -  potential * _dt_ / HBAR;
                coreCoef  = Complex(1, icoreCoef)     ;

                *address(i, j) = laplCoef * d2Amp + coreCoef * thisAmp;         // the cat equation
            }
    }
    else throw BASE_NOT_SAME;
}

Complex WaveFunc2::probAmp(uint32_t _index_, uint32_t _jndex_, bool _isNormed_)
{
    if   (_isNormed_) return cmpFactor() * value(_index_,_jndex_);
    else              return               value(_index_,_jndex_);
}

float WaveFunc2::prob(uint32_t _index_, uint32_t _jndex_, bool _isNormed_)
{
    if   (_isNormed_) return prbFactor() * value(_index_,_jndex_).conjSq();
    else              return               value(_index_,_jndex_).conjSq();
}

float WaveFunc2::prob(bool _isNormed_)
{
    if   (_isNormed_) return _norm * _norm;
    else
    {
        float sum = 0.0f;
        for (uint32_t i = 0u; i < _xSize; i++)
            for (uint32_t j = 0u; j < _ySize; j++)
                sum += value(i, j).conjSq();

        return  sum;
    }
}

Complex WaveFunc2::ddx(uint32_t _index_, uint32_t _jndex_, bool _isNormed_)
{
    float   dx   = _toBasis->dx();
    Complex dAmp                 ;

    if      (_index_ <=        0u) dAmp =  value(_index_+1u,_jndex_)   /*         NULL        */;
    else if (_index_ >= _xSize-1u) dAmp =  /*         NULL        */ - value(_index_-1u,_jndex_);
    else                           dAmp =  value(_index_+1u,_jndex_) - value(_index_-1u,_jndex_);

    dAmp.shrink(2.0f * dx);

    if (_isNormed_) dAmp.scale(ampFactor());

    return dAmp;
}

Complex WaveFunc2::ddy(uint32_t _index_, uint32_t _jndex_, bool _isNormed_)
{
    float   dy   = _toBasis->dy();
    Complex dAmp                 ;

    if      (_jndex_ <=        0u) dAmp =  value(_index_,_jndex_+1u)   /*         NULL        */;
    else if (_jndex_ >= _ySize-1u) dAmp =  /*         NULL        */ - value(_index_,_jndex_-1u);
    else                           dAmp =  value(_index_,_jndex_+1u) - value(_index_,_jndex_-1u);

    dAmp.shrink(2.0f * dy);

    if (_isNormed_) dAmp.scale(ampFactor());

    return dAmp;
}

Complex WaveFunc2::grad(uint32_t _index_, uint32_t _jndex_, bool _isNormed_)
{
    return ddx(_index_,_jndex_,_isNormed_) + ddy(_index_,_jndex_,_isNormed_);
}

Complex WaveFunc2::d2dx2(uint32_t _index_, uint32_t _jndex_, bool _isNormed_)
{
    float   dx      = _toBasis->dx()        ;
    Complex thisAmp = value(_index_,_jndex_);
    Complex two     = Real(2)               ;
    Complex d2Amp                           ;

    if      (_index_ <=        0u) d2Amp = value(_index_+1u,_jndex_) - two * thisAmp   /*         NULL        */;
    else if (_index_ >= _xSize-1u) d2Amp = /*         NULL        */ - two * thisAmp + value(_index_-1u,_jndex_);
    else                           d2Amp = value(_index_+1u,_jndex_) - two * thisAmp + value(_index_-1u,_jndex_);

    d2Amp.shrink(dx * dx);

    if (_isNormed_) d2Amp.scale(ampFactor());

    return d2Amp;
}

Complex WaveFunc2::d2dy2(uint32_t _index_, uint32_t _jndex_, bool _isNormed_)
{
    float   dy      = _toBasis->dy()        ;
    Complex thisAmp = value(_index_,_jndex_);
    Complex two     = Real(2)               ;
    Complex d2Amp                           ;

    if      (_jndex_ <=        0u) d2Amp = value(_index_,_jndex_+1u) - two * thisAmp   /*         NULL        */;
    else if (_jndex_ >= _ySize-1u) d2Amp = /*         NULL        */ - two * thisAmp + value(_index_,_jndex_-1u);
    else                           d2Amp = value(_index_,_jndex_+1u) - two * thisAmp + value(_index_,_jndex_-1u);

    d2Amp.shrink(dy * dy);

    if (_isNormed_) d2Amp.scale(ampFactor());

    return d2Amp;
}

Complex WaveFunc2::laplace(uint32_t _index_, uint32_t _jndex_, bool _isNormed_)
{
    return d2dx2(_index_,_jndex_,_isNormed_) + d2dy2(_index_,_jndex_,_isNormed_);
}

std::string WaveFunc2::string()
{
    bool isXBig  =    _xSize > MAX_STR_SIZE_WIDTH;
    bool isYBig  =    _ySize > MAX_STR_SIZE_HEGHT;

    uint32_t     xStringSize                     ;
    uint32_t     yStringSize                     ;
    if (isXBig)  xStringSize = MAX_STR_SIZE_WIDTH;                              // code from hell ⛧
    else         xStringSize = _xSize            ;
    if (isYBig)  yStringSize = MAX_STR_SIZE_HEGHT;
    else         yStringSize = _ySize            ;

    std::string result = "[";    
    for (uint32_t j = 0u; j < yStringSize; j++)
    {
        if (j != 0u) result += " ";
        result += "[ ";
        for (uint32_t i = 0u; i < xStringSize; i++)
        {
            result += probAmp(i, j).string();

            if      (i == _xSize - 1u     ) result += " ]"   ;
            else if (i == xStringSize - 1u) result += ",...]";                  // devil's language ⛧
            else                            result += ", "   ;
        }

        if      (j == _ySize - 1u     ) result += "]"   ;
        else if (j == yStringSize - 1u) result += "...]";                       // 666
        else                            result += ",\n" ;
    }

    return result;
}