#include "../include/wavefunc3.hpp"

WaveFunc3::WaveFunc3()
{
    _xSize         = 0u         ;
    _ySize         = 0u         ;
    _zSize         = 0u         ;
    _toBasis       = new Basis3 ;
    _originAddress = new Complex;
    _mass          = 0.0F       ;
}

WaveFunc3::~WaveFunc3()
{
    delete _toBasis;
    
    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            for (uint32_t k = 0u; k < _zSize; k++)
                delete address(i, j, k);
}

WaveFunc3::WaveFunc3(Basis3 _basis_)
{
    _xSize         =  _basis_.xSize();
    _ySize         =  _basis_.ySize();
    _zSize         =  _basis_.zSize();
    _toBasis       = &_basis_        ;
    _originAddress =  new Complex    ;
    _mass          =  0.0F           ;
}

WaveFunc3::WaveFunc3(Basis3* _toBasis_)
{
    _xSize         = _toBasis_->xSize();
    _ySize         = _toBasis_->ySize();
    _zSize         = _toBasis_->zSize();
    _toBasis       = _toBasis_         ;
    _originAddress = new Complex       ;
    _mass          = 0.0F              ;
}

void WaveFunc3::setMass(float _mass_)
{
    _mass = _mass_;
}

void WaveFunc3::setNormValues(Complex* _address_)
{
    setValues(_address_);
    normalize(         );
}

void WaveFunc3::normalize(float _norm_)
{
    float prob   = totalProb()        ;
    float factor = sqrt(_norm_ / prob);

    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            for (uint32_t k = 0u; k < _zSize; k++)
                (*address(i, j, k)).scale(factor);
}

void WaveFunc3::evolveFree(float _deltaTime_)                                                   // similar to the 2D case
{
    float dx = _toBasis->dx();
    float dy = _toBasis->dy();
    float dz = _toBasis->dz();

    float   ifactor = 0.5F * HBAR * _deltaTime_ / _mass;                                        // inverted triangle factor
    Complex  factor = Complex(0, ifactor);                                                      // welcome to wonderland
    Complex  two    = Complex(2);                                                               // god's number

    for (uint32_t i = 1u; i < _xSize - 1u; i++)
        for (uint32_t j = 1u; j < _ySize - 1u; j++)
            for (uint32_t k = 1u; k < _zSize - 1u; k++)
            {
                Complex thisAmp = value(i, j, k)                                       ;        // inverted triangle block
                Complex d2dx2   = value(i+1u, j, k) - two * thisAmp + value(i-1u, j, k);
                Complex d2dy2   = value(i, j+1u, k) - two * thisAmp + value(i, j+1u, k);
                Complex d2dz2   = value(i, j, k+1u) - two * thisAmp + value(i, j, k+1u);
                d2dx2.scale(dx  * dx)                                                  ;
                d2dy2.scale(dy  * dy)                                                  ;
                d2dz2.scale(dz  * dz)                                                  ;

                *address(i, j, k) = factor * (d2dx2 + d2dy2 + d2dz2) + thisAmp;                 // the cat equation
            }

    normalize();                                                                                // just in case
}

void WaveFunc3::evolve(float _deltaTime_, Scalar3 _potential_)
{
    if (_potential_.toBasis() == _toBasis)
    {
        // QUANTUM MAGIC GOES HERE
    }
    else throw BASE_NOT_SAME;
}

void WaveFunc3::evolve(float _deltaTime_, Scalar3* _toPotential_)
{
    if (_toPotential_->toBasis() == _toBasis)
    {
        // QUANTUM MAGIC GOES HERE
    }
    else throw BASE_NOT_SAME;
}

Complex WaveFunc3::probAmp(uint32_t _index_, uint32_t _jndex_, uint32_t _kindex_)
{
    return value(_index_, _jndex_, _kindex_);
}

float WaveFunc3::prob(uint32_t _index_, uint32_t _jndex_, uint32_t _kindex_)
{
    return value(_index_, _jndex_, _kindex_).conjSq();
}

float WaveFunc3::totalProb()
{
    float  prob = 0.0F;
    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            for (uint32_t k = 0u; k < _zSize; k++)
                prob += value(i, j, k).conjSq();
    
    return prob;
}

std::string WaveFunc3::string()
{
    // SOON ...
    /*
    bool isXBig = _xSize > MAX_STR_SIZE_WIDTH;
    bool isYBig = _ySize > MAX_STR_SIZE_HEGHT;

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
    */
}