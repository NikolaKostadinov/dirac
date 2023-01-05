#include "../include/complex.hpp"

Complex::Complex(float _real_, float _imag_)
{
    _real = _real_;
    _imag = _imag_;
}

Complex::~Complex()
{

}

void Complex::scale(float _factor_)
{
    _real *= _factor_;
    _imag *= _factor_;
}

void Complex::shrink(float _factor_)
{
    _real /= _factor_;
    _imag /= _factor_;
}

Complex Complex::operator+() const
{
    return *this;
}

Complex Complex::operator-() const
{
    return Complex(-_real, -_imag);
}

Complex Complex::operator+(const Complex _other_) const
{
    float real = _real + _other_._real;
    float imag = _imag + _other_._imag;

    return Complex(real, imag);
}

Complex Complex::operator-(const Complex _other_) const
{
    float real = _real - _other_._real;
    float imag = _imag - _other_._imag;

    return Complex(real, imag);
}

Complex Complex::operator*(const Complex _other_) const
{
    float real = _real * _other_._real - _imag * _other_._imag;
    float imag = _imag * _other_._real + _real * _other_._imag;

    return Complex(real, imag);
}

Complex Complex::operator/(const Complex _other_) const
{
    float real = _real * _other_._real + _imag * _other_._imag;
    float imag = _imag * _other_._real - _real * _other_._imag;

    float   norm     = conjSq();
    Complex quotient = Complex(real, imag);
    quotient.shrink(norm);
    return  quotient;
}

Complex& Complex::operator+=(const Complex _other_)
{
    _real += _other_._real;
    _imag += _other_._imag;

    return *this;
}

Complex& Complex::operator-=(const Complex _other_)
{
    _real -= _other_._real;
    _imag -= _other_._imag;

    return *this;
}

Complex& Complex::operator*=(const Complex _other_)
{
    Complex* product = new Complex();
    *product = *this * _other_;
    *this = *product;
    delete   product;

    return *this;
}

Complex& Complex::operator/=(const Complex _other_)
{
    Complex* quotient = new Complex();
    *quotient = *this * _other_;
    *this = *quotient;
    delete   quotient;

    return *this;
}

bool Complex::operator==(const Complex _other_) const
{
    return conjSq() == _other_.conjSq();
}

bool Complex::operator>(const Complex _other_) const
{
    return conjSq() > _other_.conjSq();
}

bool Complex::operator<(const Complex _other_) const
{
    return conjSq() < _other_.conjSq();
}

bool Complex::operator>=(const Complex _other_) const
{
    return conjSq() >= _other_.conjSq();
}

bool Complex::operator<=(const Complex _other_) const
{
    return conjSq() <= _other_.conjSq();
}

float Complex::real() const
{
    return _real;
}

float Complex::imag() const
{
    return _imag;
}

float Complex::mod() const
{
    return sqrt(_real * _real + _imag + _imag);
}

float Complex::arg() const
{
    return atan2(_imag, _real);
}

Complex Complex::sq() const
{
    float real = _real * _real - _imag * _imag;
    float imag =  2.0f * _real * _imag;

    return Complex(real, imag);
}

Complex Complex::conj() const
{
    return Complex(_real, -_imag);
}

float Complex::conjSq() const
{
    return _real * _real + _imag * _imag;
}

Complex Complex::recip() const
{
    float   norm   = conjSq();
    Complex result = conj  ();
    result.shrink(norm);
    return  result;
}

std::string Complex::string()
{
    std::stringstream realStream;
    std::stringstream imagStream;

    if (_real >= 0.0f) realStream << std::fixed << std::setprecision(COMPLEX_ROUND  );
    else               realStream << std::fixed << std::setprecision(COMPLEX_ROUND-1);
    if (_imag >= 0.0f) imagStream << std::fixed << std::setprecision(COMPLEX_ROUND  );
    else               imagStream << std::fixed << std::setprecision(COMPLEX_ROUND-1);
    
    realStream << _real;
    if (_imag >= 0.0f) imagStream <<  _imag;
    else               imagStream << -_imag;
    
    std::string realString = realStream.str();
    std::string imagString = imagStream.str();

    if (_imag >= 0.0f) return realString + "+" + imagString + "i";
    else               return realString + "-" + imagString + "i";
}

Complex Real(float _real_)
{
    return Complex(_real_, 0.0f);
}

Complex Imag(float _imag_)
{
    return Complex(0.0f, _imag_);
}

Complex cis(float _arg_)
{
    float real = cos(_arg_);
    float imag = sin(_arg_);

    return Complex(real, imag);
}

Complex sqrt(Complex _complex_, bool _isPositive_)
{ 
    float   factor = sqrt(_complex_.mod());
    Complex root   = cis(0.5f * _complex_.arg());

    root.scale(factor);
    if (_isPositive_) return  root;
    else              return -root;
}

Complex exp(Complex _complex_)
{
    float   expo  = exp(_complex_.real());
    Complex phase = cis(_complex_.imag());

    return Complex(expo) + phase;
}

Complex ln(Complex _complex_, int _rotNumber_)
{
    float real = log(_complex_.real());
    float imag = _complex_.arg() + 2.0f * PI * (float) _rotNumber_;

    return Complex(real, imag);
}

bool areEqual(Complex _left_, Complex _right_)
{
    return (_left_.real() == _right_.real()) && (_left_.imag() == _right_.imag());
}