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

Complex Complex::operator+(Complex& other)
{
    float real = _real + other._real;
    float imag = _imag + other._imag;

    return Complex(real, imag);
}

Complex Complex::operator-(Complex& other)
{
    float real = _real - other._real;
    float imag = _imag - other._imag;

    return Complex(real, imag);
}

Complex Complex::operator*(Complex& other)
{
    float real = _real * other._real - _imag * other._imag;
    float imag = _imag * other._real + _real * other._imag;

    return Complex(real, imag);
}

Complex Complex::operator/(Complex& other)
{
    float real = _real * other._real + _imag * other._imag;
    float imag = _imag * other._real - _real * other._imag;

    float factor = 1 / (other._real * other._real + other._imag * other._imag);
    real *= factor;
    imag *= factor;

    return Complex(real, imag);
}

Complex Complex::operator==(Complex& other)
{
    return (_real == other._real) && (_imag == other._imag);
}

Complex Complex::sq()
{
    float real = _real * _real - _imag * _imag;
    float imag =  2.0F * _real * _imag;

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
    std::stringstream realStream;
    std::stringstream imagStream;

    if (_real >= 0) realStream << std::fixed << std::setprecision(COMPLEX_ROUND    );
    else            realStream << std::fixed << std::setprecision(COMPLEX_ROUND - 1);
    if (_imag >= 0) imagStream << std::fixed << std::setprecision(COMPLEX_ROUND    );
    else            imagStream << std::fixed << std::setprecision(COMPLEX_ROUND - 1);
    realStream << _real;
    imagStream << _imag;
    
    std::string realString = realStream.str();
    std::string imagString = imagStream.str();

    return realString + " + " + imagString;
}

Complex cis(float _arg_)
{
    float real = cos(_arg_);
    float imag = sin(_arg_);

    return Complex(real, imag);
}

Complex sqrt(Complex& complex)
{ 
    float   factor = sqrt(complex.mod());
    Complex phase  = cis(0.5F * complex.arg());

    phase.scale(factor);
    return phase;
}

Complex exp(Complex& complex)
{
    float   expo  = exp(complex.real());
    Complex phase = cis(complex.imag());

    return Complex(expo) + phase;
}

Complex ln(Complex& complex)
{
    float real = log(complex.real());
    float imag = complex.arg();

    return Complex(real, imag);
}