#pragma once

#include <string>
#include <cmath>

#define ROOTHALF 0.70710678118F

class Complex
{
    public:

        Complex();
        ~Complex();

        Complex(float _real_, float _imag_ = 0);

        void scale(float _factor_);

        Complex operator+();
        Complex operator-();
        
        Complex operator+(Complex _other_);
        Complex operator-(Complex _other_);
        Complex operator*(Complex _other_);
        Complex operator/(Complex _other_);

        Complex operator==(Complex _other_);

        Complex sq();

        float real();
        float imag();
        float mod();
        float arg();

        Complex conj();
        float conjSq();

        std::string string();

    private:

        float _real;
        float _imag;
};

Complex cis(float _arg_);
Complex sqrt(Complex _complex_);
Complex exp(Complex _complex_);
Complex ln(Complex _complex_);