#include "../include/wavefunc2.hpp"

WaveFunc2::WaveFunc2()
{
    _xSize         = 0u         ;
    _ySize         = 0u         ;
    _toBasis       = new Basis2 ;
    _originAddress = new Complex;
    _norm          = 0.0f       ;
    _mass          = 0.0f       ;
}

WaveFunc2::~WaveFunc2()
{
    delete _toBasis;
    
    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            delete address(i, j);
}

WaveFunc2::WaveFunc2(Basis2 _basis_)
{
    _xSize         =  _basis_.xSize();
    _ySize         =  _basis_.ySize();
    _toBasis       = &_basis_        ;
    _originAddress =  new Complex    ;
    _norm          =  0.0f           ;
    _mass          =  0.0f           ;
}

WaveFunc2::WaveFunc2(Basis2* _toBasis_)
{
    _xSize         = _toBasis_->xSize();
    _ySize         = _toBasis_->ySize();
    _toBasis       = _toBasis_         ;
    _originAddress = new Complex       ;
    _norm          = 0.0f              ;
    _mass          = 0.0f              ;
}

void WaveFunc2::setNorm(float _norm_)
{
    _norm =  _norm_;
    checkNorm(    );
}

void WaveFunc2::setMass(float _mass_)
{
    _mass =  _mass_;
    checkMass(    );
}

void WaveFunc2::checkNorm()
{
    if      (_norm == 0.0f) throw     ZERO_NORM;
    else if (_norm <  0.0f) throw NEGATIVE_NORM;
}

void WaveFunc2::checkMass()
{
    if      (_mass == 0.0f) throw     ZERO_MASS;
    else if (_mass <  0.0f) throw NEGATIVE_MASS;
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
        
        float dx = _toBasis->dx();
        float dy = _toBasis->dy();

        float   ilaplCoef = 0.5f * HBAR / _mass * _dt_;                                                 // inverted triangle factor
        Complex  laplCoef = Imag(ilaplCoef)           ;                                                 // welcome to wonderland
        Complex  two      = Complex(2)                ;                                                 // god's number

        for (uint32_t i = 0u; i < _xSize; i++)
            for (uint32_t j = 0u; j < _ySize; j++)
            {
                Complex thisAmp = value(i, j);
                
                Complex d2dx2;
                if      (i ==        0u) d2dx2 = value(       1u, j) - two * thisAmp                 ;
                else if (i == _xSize-1u) d2dx2 = value(_xSize-2u, j) - two * thisAmp                 ;
                else                     d2dx2 = value(     i+1u, j) - two * thisAmp + value(i-1u, j);

                Complex d2dy2;
                if      (j ==        0u) d2dy2 = value(i,        1u) - two * thisAmp                 ;
                else if (j == _ySize-1u) d2dy2 = value(i, _ySize-2u) - two * thisAmp                 ;
                else                     d2dy2 = value(i,      j+1u) - two * thisAmp + value(i, j-1u);

                d2dx2.shrink(dx * dx);
                d2dy2.shrink(dy * dy);

                float   potential = _toPotential_->value(i, j);                                         // unleash your full potential
                float  icoreCoef  = -  potential * _dt_ / HBAR;
                Complex coreCoef  = Complex(1, icoreCoef)     ;
                
                *address(i, j) = laplCoef * (d2dx2 + d2dy2) + coreCoef * thisAmp;                       // the cat equation
            }
    }
    else throw BASE_NOT_SAME;
}

bool WaveFunc2::isNormValid()
{
    if   (_norm <= 0.0f) return false;
    else                 return true ;
}

bool WaveFunc2::isMassValid()
{
    if   (_mass <= 0.0f) return false;
    else                 return true ;
}

float WaveFunc2::norm()
{
    return _norm;
}

float WaveFunc2::mass()
{
    return _mass;
}

Complex WaveFunc2::probAmp(uint32_t _index_, uint32_t _jndex_)
{
    float  sumsqr = sumSqr()                       ;
    float  factor = _norm / sqrt(sumsqr)           ;
    return Real(factor)   * value(_index_, _jndex_);
}

float WaveFunc2::prob()
{
    return _norm * _norm;
}

float WaveFunc2::prob(uint32_t _index_, uint32_t _jndex_)
{
    float  sumsqr = sumSqr()                        ;
    float  sqrlen = prob()                          ;
    float  factor = sqrlen / sumsqr                 ;
    return factor * value(_index_, _jndex_).conjSq();
}

float WaveFunc2::sumSqr()
{
    float sum = 0.0f;
    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            sum += value(i, j).conjSq();

    return  sum;
}

Complex WaveFunc2::ddx(uint32_t _index_, uint32_t _jndex_)
{
    float   dx   = _toBasis->dx();
    Complex dAmp                 ;

    if      (_index_ ==        0u) dAmp =  value(        1u, _jndex_)                             ;
    else if (_index_ == _xSize-1u) dAmp = -value(_index_-1u, _jndex_)                             ;
    else                           dAmp =  value(_index_+1u, _jndex_) - value(_index_-1u, _jndex_);

    dAmp.shrink(2 * dx);

    return dAmp;
}

Complex WaveFunc2::ddy(uint32_t _index_, uint32_t _jndex_)
{
    float   dy   = _toBasis->dy();
    Complex dAmp                 ;

    if      (_jndex_ ==        0u) dAmp =  value(_index_,         1u)                             ;
    else if (_jndex_ == _ySize-1u) dAmp = -value(_index_, _jndex_-1u)                             ;
    else                           dAmp =  value(_index_, _jndex_+1u) - value(_index_, _jndex_-1u);

    dAmp.shrink(2 * dy);

    return dAmp;
}

Complex WaveFunc2::grad(uint32_t _index_, uint32_t _jndex_)
{
    return ddx(_index_, _jndex_) + ddy(_index_, _jndex_);
}

Complex WaveFunc2::d2dx2(uint32_t _index_, uint32_t _jndex_)
{
    float   dx      = _toBasis->dx()         ;
    Complex thisAmp = value(_index_, _jndex_);
    Complex two     = Real(2)                ;
    Complex d2Amp                            ;

    if      (_index_ ==        0u) d2Amp = value(        1u, _jndex_) - two * thisAmp                             ;
    else if (_index_ == _xSize-1u) d2Amp = value( _xSize-2u, _jndex_) - two * thisAmp                             ;
    else                           d2Amp = value(_index_+1u, _jndex_) - two * thisAmp + value(_index_-1u, _jndex_);

    d2Amp.shrink(dx * dx);

    return d2Amp;
}

Complex WaveFunc2::d2dy2(uint32_t _index_, uint32_t _jndex_)
{
    float   dy      = _toBasis->dy()         ;
    Complex thisAmp = value(_index_, _jndex_);
    Complex two     = Real(2)                ;
    Complex dAmp                             ;

    if      (_jndex_ ==        0u) dAmp = value(_index_,        1u) - two * thisAmp                             ;
    else if (_jndex_ == _ySize-1u) dAmp = value(_index_, _ySize-2u) - two * thisAmp                             ;
    else                           dAmp = value(_index_,_jndex_+1u) - two * thisAmp + value(_index_, _jndex_-1u);

    dAmp.shrink(dy * dy);

    return dAmp;
}

Complex WaveFunc2::laplace(uint32_t _index_, uint32_t _jndex_)
{
    return d2dx2(_index_, _jndex_) + d2dy2(_index_, _jndex_);
}

std::string WaveFunc2::string()
{
    bool isXBig  =    _xSize > MAX_STR_SIZE_WIDTH;
    bool isYBig  =    _ySize > MAX_STR_SIZE_HEGHT;

    uint32_t     xStringSize                     ;
    uint32_t     yStringSize                     ;
    if (isXBig)  xStringSize = MAX_STR_SIZE_WIDTH;                                                      // code from hell ⛧
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
            else if (i == xStringSize - 1u) result += ",...]";                                          // devil's language ⛧
            else                            result += ", "   ;
        }

        if      (j == _ySize - 1u     ) result += "]"   ;
        else if (j == yStringSize - 1u) result += "...]";                                               // 666
        else                            result += ",\n" ;
    }

    return result;
}