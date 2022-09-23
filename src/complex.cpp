#include "../include/complex.hpp"

Complex::Complex()
{
    _real = 0;
    _imag = 0;
}

Complex::~Complex()
{

}

Complex::Complex(float real, float imag)
{
    _real = real;
    _imag = imag;
}

Complex Complex::operator+(Complex other)
{
    float real = _real + other._real;
    float imag = _imag + other._imag;

    return Complex(real, imag);
}

Complex Complex::operator-()
{
    return Complex(-_real, -_imag);
}

Complex Complex::operator-(Complex other)
{
    float real = _real - other._real;
    float imag = _imag - other._imag;

    return Complex(real, imag);
}

Complex Complex::operator*(Complex other)
{
    float real = _real * other._real - _imag * other._imag;
    float imag = _imag * other._real + _real * other._imag;

    return Complex(real, imag);
}

Complex Complex::operator/(Complex other)
{
    float real = _real * other._real + _imag * other._imag;
    float imag = _imag * other._real - _real * other._imag;

    float factor = 1 / (other._real * other._real + other._imag * other._imag);
    real *= factor;
    imag *= factor;

    return Complex(real, imag);
}

Complex Complex::operator==(Complex other)
{
    return (_real == other._real) && (_imag == other._imag);
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
    return _real * _real + _imag + _imag;
}

std::string Complex::toString()
{
    return std::to_string(_real) + " + " + std::to_string(_imag) + "i";
}

Complex cis(float arg)
{
    float real = cos(arg);
    float imag = sin(arg);

    return Complex(real, imag);
}

Complex sqrt(Complex complex)
{

}

Complex exp(Complex complex)
{
    float expo = exp(complex.real());
    Complex phase = cis(complex.imag());

    return Complex(expo) + phase;
}

Complex ln(Complex complex)
{
    float real = log(complex.real());
    float imag = complex.arg();

    return Complex(real, imag);
}