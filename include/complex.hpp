#pragma once

#include "engineparams.h"
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

class Complex
{
    public:

        Complex();
        ~Complex();

        Complex(float _real_, float _imag_ = 0.0F);

        void scale(float _factor_);

        Complex operator+();
        Complex operator-();
        
        Complex operator+ (Complex _other_);
        Complex operator- (Complex _other_);
        Complex operator* (Complex _other_);
        Complex operator/ (Complex _other_);
        Complex operator==(Complex _other_);

        float real();
        float imag();
        float mod ();
        float arg ();

        Complex     sq();
        Complex conj  ();
        float   conjSq();

        std::string string();

    private:

        float _real;
        float _imag;
};

Complex cis (float   _arg_    );
Complex sqrt(Complex _complex_);
Complex exp (Complex _complex_);
Complex ln  (Complex _complex_);