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
    delete _toBase;
    
    for (uint32_t i = 0u; i < _size; i++)
        delete address(i);
}

WaveFunc1::WaveFunc1(Base _base_)
{
    _size          =  _base_.size();
    _toBase        = &_base_       ;
    _originAddress =  new Complex  ;
    _mass          =  0.0F         ;
}

WaveFunc1::WaveFunc1(Base* _toBase_)
{
    _size          = _toBase_->size();
    _toBase        = _toBase_        ;
    _originAddress = new Complex     ;
    _mass          = 0.0F            ;
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
    /*Scalar1* nullPtntl = new Scalar1(_toBase);

    for (uint32_t i = 0u; i < _size; i++)
        *nullPtntl->address(i) = 0.0f;

    evolve(_deltaTime_, nullPtntl);

    delete nullPtntl;*/
}

void WaveFunc1::evolve(float _deltaTime_, Scalar1 _potential_)
{
    evolve(_deltaTime_, &_potential_);
}

void WaveFunc1::evolve(float _deltaTime_, Scalar1* _toPotential_)
{
    if (_toPotential_->toBase() == _toBase)
    {
        float dx = _toBase->dx();

        float   ifactor = 0.5f * HBAR * _deltaTime_ / _mass;                                // inverted triangle factor
        Complex  factor = Complex(0, ifactor)              ;                                // welcome to wonderland
        Complex  two    = Complex(2)                       ;                                // god's number

        for (uint32_t i = 1u; i < _size - 1u; i++)
        {
            Complex thisAmp = value(i)                                 ;
            Complex d2dx2   = value(i+1u) - two * thisAmp + value(i-1u);                    // inverse triangle
            d2dx2.scale(dx  * dx)                                      ;

            *address(i) = factor * d2dx2 + thisAmp;                                         // cat equation
        }

        Complex fstAmp = value(      0u);                                                   // easy boundary conditions
        Complex lstAmp = value(_size-1u);
        *address(      0u) = factor * (value(      1u) - two * fstAmp)/(dx * dx) + fstAmp;
        *address(_size-1u) = factor * (value(_size-2u) - two * lstAmp)/(dx * dx) + lstAmp;

        normalize();                                                                        // just in case
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
    float prob = 0.0F;
    for (uint32_t i = _start_; i <= _end_; i++)
        prob += value(i).conjSq();
    
    return prob;
}

float WaveFunc1::totalProb()
{
    float prob = 0.0F;
    for (uint32_t i = 0u; i < _size; i++)
        prob += value(i).conjSq();
    
    return prob;
}

std::string WaveFunc1::string()
{
    std::string result = "[ ";
    if (_size <= MAX_STR_SIZE_WIDTH)
    {
        for (uint32_t i = 0u; i < _size - 1u; i++)
        {
            result += value(i).string();
            result += ", ";
        }
        result += value(_size - 1u).string();
    }
    else
    {
        for (uint32_t i = 0u; i < MAX_STR_SIZE_WIDTH - 2u; i++)
        {
            result += value(i).string();
            result += ", ";
        }
        result += value(MAX_STR_SIZE_WIDTH - 2u).string();
        result += ", ... ";
        result += value(_size - 1u).string();
    }
    
    result += " ]";
    return result;
}