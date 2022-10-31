#pragma once

#include "engine_params.h"

#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

class Complex
{
    public:

        Complex(
            float _real_ = DEFAULT_REAL,
            float _imag_ = DEFAULT_IMAG
        );
        virtual ~Complex();

        void    scale (float _factor_);
        void    shrink(float _factor_);

        Complex operator+();
        Complex operator-();
        
        Complex operator+ (Complex _other_);
        Complex operator- (Complex _other_);
        Complex operator* (Complex _other_);
        Complex operator/ (Complex _other_);
        Complex operator==(Complex _other_);

        float   real();
        float   imag();
        float   mod ();
        float   arg ();

        Complex     sq();
        Complex conj  ();
        float   conjSq();

        std::string string();

    private:

        float _real;
        float _imag;
};

Complex Real(float   _real_   );
Complex Imag(float   _imag_   );

Complex cis (float   _arg_    );
Complex sqrt(Complex _complex_);
Complex exp (Complex _complex_);
Complex ln  (Complex _complex_);