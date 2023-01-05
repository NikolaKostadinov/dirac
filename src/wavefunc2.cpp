#include "../include/wavefunc2.hpp"

WaveFunc2::WaveFunc2() : Field2<Complex>(), WaveFunc()
{

}

WaveFunc2::~WaveFunc2()
{
    uint32_t  tempXSize = xSize();
    uint32_t  tempYSize = ySize();
    delete   _toBasis;
    
    for (uint32_t i = 0u; i < tempXSize; i++)
        for (uint32_t j = 0u; j < tempYSize; j++)
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
    evolve(_dt_,         nullField);

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
        checkMass(false);
        
        uint32_t  tempXSize =             xSize();
        uint32_t  tempYSize =             ySize();
        float     dx2       = _toBasis->xDelta2();
        float     dy2       = _toBasis->yDelta2();
        
        Complex   thisAmp;
        Complex   upprAmp;
        Complex   lastAmp;
        Complex   laplAmp;
        Complex   d2dxAmp;
        Complex   d2dyAmp;

        Complex*  cache = new Complex[tempXSize];

        float    iwingCoef = 0.5f * HBAR * _dt_ / _mass;
        Complex   wingCoef = Imag(iwingCoef)           ;
        Complex   two      = Real(2.0f)                ;

        for (uint32_t i = 0u; i < tempXSize; i++)
            for (uint32_t j = 0u; j < tempYSize; j++)
            {
                if (i == 0u)
                {
                    upprAmp = cache[          0u];
                    lastAmp = cache[tempXSize-1u];
                }
                else
                {
                    lastAmp = cache[i-1u];
                    upprAmp = cache[i   ];
                }

                thisAmp = value(i   ,j   );
                d2dxAmp = value(i+1u,j   ) + lastAmp - two * thisAmp;
                d2dyAmp = value(i   ,j+1u) + upprAmp - two * thisAmp;
                d2dxAmp.shrink(dx2);
                d2dyAmp.shrink(dy2);
                laplAmp = d2dxAmp + d2dyAmp;

                float   potential = _toPotential_->value(i, j);
                float  icoreCoef  = -  potential * _dt_ / HBAR;
                Complex coreCoef  = Complex(1, icoreCoef)     ;

                *address(i, j) = wingCoef * laplAmp + coreCoef * thisAmp;

                cache[i] = thisAmp;
            }

        delete[] cache;
    }
    else throw BASE_NOT_SAME;
}

Complex WaveFunc2::probAmp(uint32_t _index_, uint32_t _jndex_, bool _isNormed_) const
{
    if   (_isNormed_) return cmpFactor() * value(_index_,_jndex_);
    else              return               value(_index_,_jndex_);
}

float WaveFunc2::prob(uint32_t _index_, uint32_t _jndex_, bool _isNormed_) const
{
    if   (_isNormed_) return prbFactor() * value(_index_,_jndex_).conjSq();
    else              return               value(_index_,_jndex_).conjSq();
}

float WaveFunc2::prob(bool _isNormed_) const
{
    if   (_isNormed_) return _norm * _norm;
    else
    {
        uint32_t tempXSize = xSize();
        uint32_t tempYSize = ySize();
        float    sum       =    0.0f;
        for (uint32_t i = 0u; i < tempXSize; i++)
            for (uint32_t j = 0u; j < tempYSize; j++)
                sum += value(i, j).conjSq();

        return  sum;
    }
}

Complex WaveFunc2::ddx(uint32_t _index_, uint32_t _jndex_, bool _isNormed_) const
{
    uint32_t tempXSize =            xSize();
    float    dx        = _toBasis->xDelta();
    Complex  dAmp                          ;

    if      (_index_ <=           0u) dAmp =  value(_index_+1u,_jndex_)   /*         NULL        */;
    else if (_index_ >= tempXSize-1u) dAmp =  /*         NULL        */ - value(_index_-1u,_jndex_);
    else                              dAmp =  value(_index_+1u,_jndex_) - value(_index_-1u,_jndex_);

    dAmp.shrink(2.0f * dx);

    if (_isNormed_) dAmp.scale(ampFactor());

    return dAmp;
}

Complex WaveFunc2::ddy(uint32_t _index_, uint32_t _jndex_, bool _isNormed_) const
{
    uint32_t tempYSize =            ySize();
    float    dy        = _toBasis->yDelta();
    Complex  dAmp                          ;

    if      (_jndex_ <=           0u) dAmp =  value(_index_,_jndex_+1u)   /*         NULL        */;
    else if (_jndex_ >= tempYSize-1u) dAmp =  /*         NULL        */ - value(_index_,_jndex_-1u);
    else                              dAmp =  value(_index_,_jndex_+1u) - value(_index_,_jndex_-1u);

    dAmp.shrink(2.0f * dy);

    if (_isNormed_) dAmp.scale(ampFactor());

    return dAmp;
}

Complex WaveFunc2::grad(uint32_t _index_, uint32_t _jndex_, bool _isNormed_) const
{
    return ddx(_index_,_jndex_,_isNormed_) + ddy(_index_,_jndex_,_isNormed_);
}

Complex WaveFunc2::d2dx2(uint32_t _index_, uint32_t _jndex_, bool _isNormed_) const
{
    uint32_t tempXSize =                xSize();
    float    dx2       =    _toBasis->xDelta2();
    Complex  thisAmp   = value(_index_,_jndex_);
    Complex  two       =                Real(2);
    Complex  d2Amp                             ;

    if      (_index_ <=           0u) d2Amp = value(_index_+1u,_jndex_) - two * thisAmp   /*         NULL        */;
    else if (_index_ >= tempXSize-1u) d2Amp = /*         NULL        */ - two * thisAmp + value(_index_-1u,_jndex_);
    else                              d2Amp = value(_index_+1u,_jndex_) - two * thisAmp + value(_index_-1u,_jndex_);

    d2Amp.shrink(dx2);

    if (_isNormed_) d2Amp.scale(ampFactor());

    return d2Amp;
}

Complex WaveFunc2::d2dy2(uint32_t _index_, uint32_t _jndex_, bool _isNormed_) const
{
    uint32_t tempYSize =                xSize();
    float    dy2       =    _toBasis->yDelta2();
    Complex  thisAmp   = value(_index_,_jndex_);
    Complex  two       =                Real(2);
    Complex  d2Amp                             ;

    if      (_jndex_ <=           0u) d2Amp = value(_index_,_jndex_+1u) - two * thisAmp   /*         NULL        */;
    else if (_jndex_ >= tempYSize-1u) d2Amp = /*         NULL        */ - two * thisAmp + value(_index_,_jndex_-1u);
    else                              d2Amp = value(_index_,_jndex_+1u) - two * thisAmp + value(_index_,_jndex_-1u);

    d2Amp.shrink(dy2);

    if (_isNormed_) d2Amp.scale(ampFactor());

    return d2Amp;
}

Complex WaveFunc2::laplace(uint32_t _index_, uint32_t _jndex_, bool _isNormed_) const
{
    return d2dx2(_index_,_jndex_,_isNormed_) + d2dy2(_index_,_jndex_,_isNormed_);
}

std::string WaveFunc2::string()
{
    uint32_t tempXSize = xSize();
    uint32_t tempYSize = ySize();

    bool isXBig  = tempXSize > MAX_STR_SIZE_WIDTH;
    bool isYBig  = tempYSize > MAX_STR_SIZE_HEGHT;

    uint32_t     xStringSize                     ;
    uint32_t     yStringSize                     ;
    if (isXBig)  xStringSize = MAX_STR_SIZE_WIDTH;                              // code from hell ⛧
    else         xStringSize = tempXSize         ;
    if (isYBig)  yStringSize = MAX_STR_SIZE_HEGHT;
    else         yStringSize = tempYSize         ;

    std::string result = "[";    
    for (uint32_t j = 0u; j < yStringSize; j++)
    {
        if (j != 0u) result += " ";
        result += "[ ";
        for (uint32_t i = 0u; i < xStringSize; i++)
        {
            result += probAmp(i, j).string();

            if      (i ==   tempXSize-1u) result += " ]"   ;
            else if (i == xStringSize-1u) result += ",...]";                  // devil's language ⛧
            else                          result += ", "   ;
        }

        if      (j ==   tempYSize-1u) result += "]"   ;
        else if (j == yStringSize-1u) result += "...]";                       // 666
        else                          result += ",\n" ;
    }

    return result;
}