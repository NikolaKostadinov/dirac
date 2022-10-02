#include "../include/complex.hpp"

Complex::Complex()
{
    _real = 0;
    _imag = 0;
}

Complex::~Complex()
{

}

Complex::Complex(float _real_, float _imag_)
{
    _real = _real_;
    _imag = _imag_;
}

void Complex::scale(float _factor_)
{
    _real *= _factor_;
    _imag *= _factor_;
}

Complex Complex::operator+()
{
    return *this;
}

Complex Complex::operator-()
{
    return Complex(-_real, -_imag);
}

Complex Complex::operator+(Complex _other_)
{
    float real = _real + _other_._real;
    float imag = _imag + _other_._imag;

    return Complex(real, imag);
}

Complex Complex::operator-(Complex _other_)
{
    float real = _real - _other_._real;
    float imag = _imag - _other_._imag;

    return Complex(real, imag);
}

Complex Complex::operator*(Complex _other_)
{
    float real = _real * _other_._real - _imag * _other_._imag;
    float imag = _imag * _other_._real + _real * _other_._imag;

    return Complex(real, imag);
}

Complex Complex::operator/(Complex _other_)
{
    float real = _real * _other_._real + _imag * _other_._imag;
    float imag = _imag * _other_._real - _real * _other_._imag;

    float factor = 1 / (_other_._real * _other_._real +_other_._imag * _other_._imag);
    real *= factor;
    imag *= factor;

    return Complex(real, imag);
}

Complex Complex::operator+=(Complex _other_)
{
    return *this + _other_;
}

Complex Complex::operator==(Complex _other_)
{
    return (_real == _other_._real) && (_imag == _other_._imag);
}

Complex Complex::sq()
{
    float real = _real * _real - _imag * _imag;
    float imag = 2.0F * _real * _imag;

    return Complex(real, imag);
}

float Complex::real()
{
    return _real;
}

float Complex::imag()
{
    return _imag;
}

float Complex::mod()
{
    return sqrt(_real * _real + _imag + _imag);
}

float Complex::arg()
{
    return atan2(_imag, _real);
}

Complex Complex::conj()
{
    return Complex(_real, -_imag);
}

float Complex::conjSq()
{
    return _real * _real + _imag * _imag;
}

std::string Complex::string()
{
    return std::to_string(_real) + " + " + std::to_string(_imag) + "i";
}

Complex cis(float _arg_)
{
    float real = cos(_arg_);
    float imag = sin(_arg_);

    return Complex(real, imag);
}

Complex sqrt(Complex _complex_)
{ 
    float factor = sqrt(_complex_.mod());
    Complex phase = cis(0.5F * _complex_.arg());

    phase.scale(factor);
    return phase;
}

Complex exp(Complex _complex_)
{
    float expo = exp(_complex_.real());
    Complex phase = cis(_complex_.imag());

    return Complex(expo) + phase;
}

Complex ln(Complex _complex_)
{
    float real = log(_complex_.real());
    float imag = _complex_.arg();

    return Complex(real, imag);
}