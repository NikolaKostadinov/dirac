#pragma once

#include <string>

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

        float real();
        float imag();
        float mod();
        float arg();

        Complex conj();
        float conjSq();    // z* z

        std::string toString();

    private:

        float _real;
        float _imag;
};

Complex sqrt(Complex complex);