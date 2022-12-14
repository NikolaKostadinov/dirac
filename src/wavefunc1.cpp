#include "../include/wavefunc1.hpp"

WaveFunc1::WaveFunc1() : Field1<Complex>(), WaveFunc()
{

}

WaveFunc1::~WaveFunc1()
{
    uint32_t  tempSize = size();
    delete    _toBase;
    
    for (uint32_t i = 0u; i < tempSize; i++)
        delete address(i);
}

WaveFunc1::WaveFunc1(Base _base_) : Field1<Complex>(_base_), WaveFunc()
{

}

WaveFunc1::WaveFunc1(Base* _toBase_) : Field1<Complex>(_toBase_), WaveFunc()
{

}

void WaveFunc1::evolve(float _dt_)
{
    uint32_t  tempSize  =     size();
    float*    nullArray = new float  [tempSize];
    Scalar1*  nullField = new Scalar1( _toBase);

    for (uint32_t i  = 0u  ; i < tempSize; i++)
        nullArray[i] = 0.0f;

    nullField->setValues(nullArray);
    evolve(        _dt_, nullField);

    free(nullArray);
    free(nullField);
}

void WaveFunc1::evolve(float _dt_, Scalar1 _potential_)
{
    evolve(_dt_, &_potential_);
}

void WaveFunc1::evolve(float _dt_, Scalar1* _toPotential_)
{
    if (_toPotential_->toBase() == _toBase)
    {
        checkMass(false);

        uint32_t  tempSize =            size();
        float     dx2      = _toBase->delta2();
        
        Complex   thisAmp;
        Complex   lastAmp;
        Complex   laplAmp;

        float    iwingCoef = 0.5f * HBAR * _dt_ / _mass;                // inverted triangle factor
        Complex   wingCoef = Imag(iwingCoef)           ;                // welcome to wonderland
        Complex   two      = Real(2.0f)                ;                // god's number

        for (uint32_t i = 0u; i < tempSize; i++)
        {
            thisAmp = value(i   , false);
            laplAmp = value(i+1u, true ) + lastAmp - two * thisAmp;
            laplAmp.shrink(dx2);

            float   potential = _toPotential_->value(i, true);          // unleash your full potential
            float  icoreCoef  = -  potential * _dt_ / HBAR   ;
            Complex coreCoef  = Complex(1, icoreCoef)        ;

            lastAmp     = wingCoef * laplAmp + coreCoef * thisAmp;      // cat equation
            *address(i) = lastAmp;
        }
    }
    else throw BASE_NOT_SAME;
}

Complex WaveFunc1::probAmp(uint32_t _index_, bool _isNormed_) const
{
    if   (_isNormed_) return cmpFactor() * value(_index_);
    else              return               value(_index_);
}

float WaveFunc1::prob(uint32_t _index_, bool _isNormed_) const
{
    if   (_isNormed_) return prbFactor() * value(_index_).conjSq();
    else              return               value(_index_).conjSq();
    
}

float WaveFunc1::prob(bool _isNormed_) const
{
    if   (_isNormed_) return _norm * _norm;
    else
    {
        uint32_t tempSize = size();
        float    sum      = 0.0f  ;

        for (uint32_t i = 0u; i < tempSize; i++)
            sum += value(i).conjSq();
    
        return sum;
    }
}

Complex WaveFunc1::ddx(uint32_t _index_, bool _isNormed_) const
{
    float dx = _toBase->delta();

    Complex dAmp = value(_index_+1u, false) - value(_index_-1u, false);
    
    dAmp.shrink(2.0f * dx);
    if (_isNormed_) dAmp.scale(ampFactor());

    return dAmp;
}

Complex WaveFunc1::d2dx2(uint32_t _index_, bool _isNormed_) const
{
    float   dx2     = _toBase->delta2();
    Complex thisAmp =    value(_index_);
    Complex two     =        Real(2.0f);

   Complex d2Amp = value(_index_+1u, false) - two * thisAmp + value(_index_-1u, false);

    d2Amp.shrink(dx2);
    if (_isNormed_) d2Amp.scale(ampFactor());

    return d2Amp;
}

float WaveFunc1::prob(uint32_t _start_, uint32_t _end_, bool _isNormed_) const
{
    float sum = 0.0f;
    for (uint32_t i = _start_; i <= _end_; i++)
        sum += value(i).conjSq();
    
    if   (_isNormed_) return prbFactor() * sum;
    else              return               sum;
}

std::string WaveFunc1::string()
{
    uint32_t    tempSize = size();
    std::string result   = "[ "  ;
    if (tempSize <= MAX_STR_SIZE_WIDTH)
    {
        for (uint32_t i = 0u; i < tempSize - 1u; i++)
        {
            result += probAmp(i).string();
            result += ", ";
        }
        result += probAmp(tempSize - 1u).string();
    }
    else
    {
        for (uint32_t i = 0u; i < MAX_STR_SIZE_WIDTH - 2u; i++)
        {
            result += probAmp(i).string();
            result += ", ";
        }
        result += probAmp(MAX_STR_SIZE_WIDTH - 2u).string();
        result += ", ... ";
        result += probAmp(tempSize - 1u).string();
    }
    
    result += " ]";
    return result;
}