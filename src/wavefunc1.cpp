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
    _mass          =  0.0f         ;
}

WaveFunc1::WaveFunc1(Base* _toBase_)
{
    _size          = _toBase_->size();
    _toBase        = _toBase_        ;
    _originAddress = new Complex     ;
    _mass          = 0.0f            ;
}

void WaveFunc1::setNorm(float _norm_)
{
    _norm =  _norm_;
    checkNorm(    );
}

void WaveFunc1::setMass(float _mass_)
{
    _mass =  _mass_;
    checkMass(    );
}

void WaveFunc1::checkNorm()
{
    if      (_norm == 0.0f) throw     ZERO_NORM;
    else if (_norm <  0.0f) throw NEGATIVE_NORM;
}

void WaveFunc1::checkMass()
{
    if      (_mass == 0.0f) throw     ZERO_MASS;
    else if (_mass <  0.0f) throw NEGATIVE_MASS;
}

void WaveFunc1::evolve(float _dt_)
{
    float*   nullArray = new float  [_size  ];
    Scalar1* nullField = new Scalar1(_toBase);

    for (uint32_t i  = 0u  ; i < _size; i++)
        nullArray[i] = 0.0f;

    nullField->setValues(nullArray);
    evolve(   _dt_,      nullField);
}

void WaveFunc1::evolve(float _dt_, Scalar1 _potential_)
{
    evolve(_dt_, &_potential_);
}

void WaveFunc1::evolve(float _dt_, Scalar1* _toPotential_)
{
    if (_toPotential_->toBase() == _toBase)
    {
        checkMass();

        float dx = _toBase->dx();

        float   ifactor = 0.5f * HBAR * _dt_ / _mass;                                       // inverted triangle factor
        Complex  factor = Complex(0, ifactor)       ;                                       // welcome to wonderland
        Complex  two    = Complex(2)                ;                                       // god's number

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
    }
    else throw BASE_NOT_SAME;
}

bool WaveFunc1::isNormValid()
{
    if   (_norm <= 0.0f) return false;
    else                 return true ;
}

bool WaveFunc1::isMassValid()
{
    if   (_mass <= 0.0f) return false;
    else                 return true ;
}

Complex WaveFunc1::probAmp(uint32_t _index_)
{
    float  sumsqr = sumSqr()            ;
    float  factor = _norm / sqrt(sumsqr);
    return Real(factor) * value(_index_);
}

float WaveFunc1::prob(uint32_t _index_)
{
    float  sumsqr = sumSqr()               ;
    float  sqrlen = prob()                 ;
    float  factor = sqrlen / sumsqr        ;
    return factor * value(_index_).conjSq();
}

float WaveFunc1::prob()
{
    return _norm * _norm;
}

float WaveFunc1::prob(uint32_t _start_, uint32_t _end_)
{
    float sum = 0.0f;
    for (uint32_t i = _start_; i <= _end_; i++)
        sum += prob(i);
    
    return sum;
}

float WaveFunc1::sumSqr()
{
    float sum = 0.0f;
    for (uint32_t i = 0u; i < _size; i++)
        sum += value(i).conjSq();
    
    return sum;
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