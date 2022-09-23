#pragma once

#include <string>
#include <cmath>

#define ROOTHALF 0.70710678118F

class Complex
{
    public:

        Complex();
        ~Complex();

        Complex(float real, float imag = 0);

        Complex operator+(Complex other);
        Complex operator-();
        Complex operator-(Complex other);
        Complex operator*(Complex other);
        Complex operator/(Complex other);

        Complex operator==(Complex other);

        Complex sq();

        float real();
        float imag();
        float mod();
        float arg();

        Complex conj();
        float conjSq();

        std::string toString();

    private:

        float _real;
        float _imag;
};

Complex cis(float arg);
Complex sqrt(Complex complex);
Complex exp(Complex complex);
Complex ln(Complex complex);