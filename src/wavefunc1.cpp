#include "../include/wavefunc1.hpp"

WaveFunc1::WaveFunc1()
{
    _size          = 0u         ;
    _toBase        = new Base   ;
    _originAddress = new Complex;
    _mass          = 0.0F       ;
}

WaveFunc1::~WaveFunc1()
{
    delete   _toBase       ;
    delete[] _originAddress;
}

WaveFunc1::WaveFunc1(Base _base_)
{
    _size   =  _base_.size()    ;
    _toBase = &_base_           ;
    _originAddress = new Complex;
    _mass          = 0.0F       ;
}

WaveFunc1::WaveFunc1(Base* _toBase_)
{
    _size   = _toBase_->size()  ;
    _toBase = _toBase_          ;
    _originAddress = new Complex;
    _mass          = 0.0F       ;
}

void WaveFunc1::setMass(float _mass_)
{
    _mass = _mass_;
}

void WaveFunc1::setNormValues(Complex* _address_)
{
    setValues(_address_);
    normalize(         );
}

void WaveFunc1::normalize(float _norm_)
{
    float prob   = totalProb()        ;
    float factor = sqrt(_norm_ / prob);

    for (uint32_t i = 0U; i < _size; i++)
        (*address(i)).scale(factor);
}

void WaveFunc1::evolveFree(float _deltaTime_)
{
    float dx      = _toBase->dx()      ;
    float ifactor = HBAR * _deltaTime_ ;
    ifactor      /= 2 * _mass * dx * dx;

    Complex factor = Complex(0, ifactor);
    Complex two    = Complex(2)         ;

    for (uint32_t i = 1U; i < _size - 1; i++)
        *address(i) = factor * (value(i+1) - two * value(i) + value(i-1)) + value(i);

    normalize();
}

void WaveFunc1::evolve(float _deltaTime_, Scalar1 _potential_)
{
    if (_potential_.toBase() == _toBase)
    {

    }
    else throw BASE_NOT_SAME;
}

void WaveFunc1::evolve(float _deltaTime_, Scalar1* _toPotential_)
{
    if (_toPotential_->toBase() == _toBase)
    {

    }
    else throw BASE_NOT_SAME;
}

Complex WaveFunc1::probAmp(uint32_t _index_)
{
    return value(_index_);
}

float WaveFunc1::prob(uint32_t _index_)
{
    return value(_index_).conjSq();
}

float WaveFunc1::prob(uint32_t _start_, uint32_t _end_)
{
    float prob = 0;
    for (uint32_t i = _start_; i <= _end_; i++)
        prob += value(i).conjSq();
    
    return prob;
}

float WaveFunc1::totalProb()
{
    float prob = 0;
    for (uint32_t i = 0U; i < _size; i++)
        prob += value(i).conjSq();
    
    return prob;
}

std::string WaveFunc1::string()
{
    std::string result = "[ ";
    if (_size <= MAX_STR_SIZE_WIDTH)
    {
        for (uint32_t i = 0U; i < _size - 1; i++)
        {
            result += value(i).string();
            result += ", ";
        }
        result += value(_size - 1).string();
    }
    else
    {
        for (uint32_t i = 0U; i < MAX_STR_SIZE_WIDTH - 2; i++)
        {
            result += value(i).string();
            result += ", ";
        }
        result += value(MAX_STR_SIZE_WIDTH - 2).string();
        result += ", ... ";
        result += value(_size - 1).string();
    }
    
    result += " ]";
    return result;
}