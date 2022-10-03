#include "../include/wavefunc2.hpp"

WaveFunc2::WaveFunc2()
{
    _xSize = 0U;
    _ySize = 0U;
    _toBasis = new Basis2;
    _originAddress = new Complex;
}

WaveFunc2::~WaveFunc2()
{
    delete _toBasis;
    //delete[] _originAddress;
}

WaveFunc2::WaveFunc2(Basis2 _basis_)
{
    _xSize = _basis_.xSize();
    _ySize = _basis_.ySize();
    _toBasis = &_basis_;
    _originAddress = new Complex;
}

WaveFunc2::WaveFunc2(Basis2* _toBasis_)
{
    _xSize = _toBasis_->xSize();
    _ySize = _toBasis_->ySize();
    _toBasis = _toBasis_;
    _originAddress = new Complex;
}

void WaveFunc2::normalize(float _norm_)
{
    float prob = totalProb();
    float factor = sqrt(_norm_ / prob);

    for (unsigned int i = 0U; i < _xSize; i++)
        for (unsigned int j = 0U; j < _ySize; j++)
            (*address(i, j)).scale(factor);
}

void WaveFunc2::evolve(float _deltaTime_)
{
    float dx = _toBasis->dx();
    float dy = _toBasis->dy();
    float ifactor = 0.5F * HBAR * _deltaTime_;
    Complex factor = Complex(0, ifactor);
    Complex two = Complex(2);

    for (unsigned int i = 1U; i < _xSize - 1; i++)
    {
        for (unsigned int j = 1U; j < _ySize - 1; j++)
        {
            Complex d2dx2 = value(i+1, j) - two * value(i, j) + value(i-1, j);
            Complex d2dy2 = value(i, j+1) - two * value(i, j) + value(i, j+1);
            d2dx2.scale(dx * dx);
            d2dy2.scale(dy * dy);

            *address(i, j) = factor * (d2dx2 + d2dy2) + value(i, j);
        }
    }

    normalize();
}

Complex WaveFunc2::probAmp(unsigned int _index_, unsigned int _jndex_)
{
    return value(_index_, _jndex_);
}

float WaveFunc2::prob(unsigned int _index_, unsigned int _jndex_)
{
    return value(_index_, _jndex_).conjSq();
}

float WaveFunc2::totalProb()
{
    float prob = 0;
    for (unsigned int i = 0U; i < _xSize; i++)
        for (unsigned int j = 0U; j < _ySize; j++)
            prob += value(i, j).conjSq();
    
    return prob;
}

std::string WaveFunc2::string()
{
    bool isXBig = _xSize > MAX_STR_SIZE_WIDTH;
    bool isYBig = _ySize > MAX_STR_SIZE_HEGHT;

    unsigned int xStringSize                     ;
    unsigned int yStringSize                     ;
    if (isXBig)  xStringSize = MAX_STR_SIZE_WIDTH;
    else         xStringSize = _xSize            ;
    if (isYBig)  yStringSize = MAX_STR_SIZE_HEGHT;
    else         yStringSize = _ySize            ;

    std::string result = "[";    
    for (unsigned int j = 0U; j < yStringSize; j++)
    {
        if (j != 0U) result += " ";
        result += "[ ";
        for (unsigned int i = 0U; i < xStringSize; i++)
        {
            result += value(i, j).string();

            if      (i == _xSize - 1)      result += " ]"    ;
            else if (i == xStringSize - 1) result += ",...]" ;
            else                           result += ", "    ;
        }

        if      (j == _ySize - 1)      result += "]"   ;
        else if (j == yStringSize - 1) result += "...]";
        else                           result += ",\n" ;
    }

    return result;
}