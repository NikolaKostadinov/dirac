#include "../include/wavefunc3.hpp"

WaveFunc3::WaveFunc3() : Field3<Complex>(), WaveFunc()
{

}

WaveFunc3::~WaveFunc3()
{
    delete _toBasis;
    
    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            for (uint32_t k = 0u; k < _zSize; k++)
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
}

void WaveFunc3::evolve(float _dt_, Scalar3 _potential_)
{
    evolve(_dt_, &_potential_);
}

void WaveFunc3::evolve(float _dt_, Scalar3* _toPotential_)
{
    if (_toPotential_->toBasis() == _toBasis)
    {
        // QUANTUM MAGIC GOES HERE
    }
    else throw BASE_NOT_SAME;
}

Complex WaveFunc3::probAmp(uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_)
{
    return value(_index_, _jndex_, _kndex_);
}

float WaveFunc3::prob(uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_)
{
    return value(_index_, _jndex_, _kndex_).conjSq();
}

/*
float WaveFunc3::totalProb()
{
    float  prob = 0.0F;
    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            for (uint32_t k = 0u; k < _zSize; k++)
                prob += value(i, j, k).conjSq();
    
    return prob;
}
*/

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