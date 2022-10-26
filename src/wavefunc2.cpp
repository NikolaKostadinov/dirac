#include "../include/wavefunc2.hpp"

WaveFunc2::WaveFunc2()
{
    _xSize         = 0u         ;
    _ySize         = 0u         ;
    _toBasis       = new Basis2 ;
    _originAddress = new Complex;
    _mass          = 0.0F       ;
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
    _mass          =  0.0F           ;
}

WaveFunc2::WaveFunc2(Basis2* _toBasis_)
{
    _xSize         = _toBasis_->xSize();
    _ySize         = _toBasis_->ySize();
    _toBasis       = _toBasis_         ;
    _originAddress = new Complex       ;
    _mass          = 0.0F              ;
}

void WaveFunc2::setMass(float _mass_)
{
    _mass = _mass_;
}

void WaveFunc2::setNormValues(Complex* _address_)
{
    setValues(_address_);
    normalize(         );
}

void WaveFunc2::normalize(float _norm_)
{
    float prob   = totalProb()        ;
    float factor = sqrt(_norm_ / prob);

    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            (*address(i, j)).scale(factor);
}

void WaveFunc2::evolveFree(float _deltaTime_)
{
    Scalar2* nullPtntl = new Scalar2(_toBasis);

    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            *nullPtntl->address(i, j) = 0.0f;

    evolve(_deltaTime_, nullPtntl);

    delete nullPtntl;
}

void WaveFunc2::evolve(float _deltaTime_, Scalar2 _potential_)
{
    evolve(_deltaTime_, &_potential_);
}

void WaveFunc2::evolve(float _deltaTime_, Scalar2* _toPotential_)
{
    if (_toPotential_->toBasis() == _toBasis)
    {
        float dx = _toBasis->dx();
        float dy = _toBasis->dy();

        float   ifactor = 0.5f * HBAR * _deltaTime_ / _mass;                            // inverted triangle factor
        Complex  factor = Complex(0, ifactor);                                          // welcome to wonderland
        Complex  two    = Complex(2);                                                   // god's number

        for (uint32_t i = 1u; i < _xSize-1u; i++)
            for (uint32_t j = 1u; j < _ySize-1u; j++)
            {
                Complex thisAmp = value(i,    j)                                 ;      // inverted triangle block
                Complex d2dx2   = value(i+1u, j) - two * thisAmp + value(i-1u, j);
                Complex d2dy2   = value(i, j+1u) - two * thisAmp + value(i, j-1u);
                d2dx2.scale(dx  * dx)                                            ;
                d2dy2.scale(dy  * dy)                                            ;

                float   ptntl     = _toPotential_->value(i, j);                         // unleash your full potential
                float  iptntlCoef = ptntl * _deltaTime_ / HBAR;
                Complex ptntlCoef = Complex(0,  iptntlCoef)   ;
                ptntlCoef         = Complex(1) - ptntlCoef    ;
                
                *address(i, j) = factor * (d2dx2 + d2dy2) + ptntlCoef * thisAmp;        // the cat equation
            }

        normalize();                                                                    // just in case
    }
    else throw BASE_NOT_SAME;
}

Complex WaveFunc2::probAmp(uint32_t _index_, uint32_t _jndex_)
{
    return value(_index_, _jndex_);
}

float WaveFunc2::prob(uint32_t _index_, uint32_t _jndex_)
{
    return value(_index_, _jndex_).conjSq();
}

float WaveFunc2::totalProb()
{
    float  prob = 0.0F;
    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            prob += value(i, j).conjSq();
    
    return prob;
}

std::string WaveFunc2::string()
{
    bool isXBig  = _xSize    > MAX_STR_SIZE_WIDTH;
    bool isYBig  = _ySize    > MAX_STR_SIZE_HEGHT;

    uint32_t     xStringSize                     ;
    uint32_t     yStringSize                     ;
    if (isXBig)  xStringSize = MAX_STR_SIZE_WIDTH;              // code from hell ⛧
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
            result += value(i, j).string();

            if      (i == _xSize - 1u     ) result += " ]"   ;
            else if (i == xStringSize - 1u) result += ",...]";  // devil's language ⛧
            else                            result += ", "   ;
        }

        if      (j == _ySize - 1u     ) result += "]"   ;
        else if (j == yStringSize - 1u) result += "...]";       // 666
        else                            result += ",\n" ;
    }

    return result;
}