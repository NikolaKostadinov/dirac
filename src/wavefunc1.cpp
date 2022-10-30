#include "../include/wavefunc1.hpp"

WaveFunc1::WaveFunc1()
{
    _size          = 0u         ;
    _toBase        = new Base   ;
    _originAddress = new Complex;
    _norm          = 0.0f       ;
    _mass          = 0.0f       ;
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
    _norm          =  0.0f         ;
    _mass          =  0.0f         ;
}

WaveFunc1::WaveFunc1(Base* _toBase_)
{
    _size          = _toBase_->size();
    _toBase        = _toBase_        ;
    _originAddress = new Complex     ;
    _norm          = 0.0f            ;
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
    evolve(        _dt_, nullField);
}

void WaveFunc1::evolve(float _dt_, Scalar1 _potential_)
{
    evolve(_dt_, &_potential_);
}

void WaveFunc1::evolve(float _dt_, Scalar1* _toPotential_)
{
    if (_toPotential_->toBase() == _toBase)
    {
        checkNorm();
        checkMass();

        float   ifactor  = 0.5f * HBAR * _dt_ / _mass;              // inverted triangle factor
        Complex  factor  = Imag(ifactor)             ;              // welcome to wonderland
        Complex  thisAmp                             ;
        Complex    d2Amp                             ;

        for (uint32_t i = 0u; i < _size; i++)
        {
            thisAmp = value(i       );
            d2Amp   = d2dx2(i, false);

            *address(i) = factor * d2Amp + thisAmp;                 // cat equation (NO POTENTIAL)
        }
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

float WaveFunc1::norm()
{
    return _norm;
}

float WaveFunc1::mass()
{
    return _mass;
}

float WaveFunc1::ampFactor()
{
    return _norm / sqrt( prob(false) );                             // 0x5f3759df
}

Complex WaveFunc1::cmpFactor()
{
    return Real(ampFactor());
}

float WaveFunc1::prbFactor()
{
    return prob() / prob(false);
}

Complex WaveFunc1::probAmp(uint32_t _index_, bool _isNormed_)
{
    if   (_isNormed_) return cmpFactor() * value(_index_);
    else              return               value(_index_);
}

float WaveFunc1::prob(uint32_t _index_, bool _isNormed_)
{
    if   (_isNormed_) return prbFactor() * value(_index_).conjSq();
    else              return               value(_index_).conjSq();
    
}

float WaveFunc1::prob(bool _isNormed_)
{
    if   (_isNormed_) return _norm * _norm;
    else
    {
        float sum = 0.0f;
        for (uint32_t i = 0u; i < _size; i++)
            sum += value(i).conjSq();
    
        return sum;
    }
}

Complex WaveFunc1::ddx(uint32_t _index_, bool _isNormed_)
{
    float   dx   = _toBase->dx();
    Complex dAmp                ;

    if      (_index_ ==       0u) dAmp = value(_index_+1u)   /*     NULL    */;
    else if (_index_ == _size-1u) dAmp = /*     NULL    */ - value(_index_-1u);
    else                          dAmp = value(_index_+1u) - value(_index_-1u);

    dAmp.shrink(2.0f * dx);

    if (_isNormed_) dAmp.scale(ampFactor());

    return dAmp;
}

Complex WaveFunc1::d2dx2(uint32_t _index_, bool _isNormed_)
{
    float   dx      = _toBase->dx( );
    Complex thisAmp = value(_index_);
    Complex two     = Real(2.0f)    ;
    Complex d2Amp                   ;

    if      (_index_ ==       0u) d2Amp = value(_index_+1u) - two * thisAmp   /*     NULL    */;
    else if (_index_ == _size-1u) d2Amp = /*     NULL    */ - two * thisAmp + value(_index_-1u);
    else                          d2Amp = value(_index_+1u) - two * thisAmp + value(_index_-1u);

    d2Amp.shrink(dx * dx);

    if (_isNormed_) d2Amp.scale(ampFactor());

    return d2Amp;
}

float WaveFunc1::prob(uint32_t _start_, uint32_t _end_, bool _isNormed_)
{
    float sum = 0.0f;
    for (uint32_t i = _start_; i <= _end_; i++)
        sum += value(i).conjSq();
    
    if   (_isNormed_) return prbFactor() * sum;
    else              return               sum;
}

std::string WaveFunc1::string()
{
    std::string result = "[ ";
    if (_size <= MAX_STR_SIZE_WIDTH)
    {
        for (uint32_t i = 0u; i < _size - 1u; i++)
        {
            result += probAmp(i).string();
            result += ", ";
        }
        result += probAmp(_size - 1u).string();
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
        result += probAmp(_size - 1u).string();
    }
    
    result += " ]";
    return result;
}