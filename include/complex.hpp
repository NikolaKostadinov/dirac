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

        Complex  operator+ (                     ) const;
        Complex  operator- (                     ) const;
        Complex  operator+ (const Complex _other_) const;
        Complex  operator- (const Complex _other_) const;
        Complex  operator* (const Complex _other_) const;
        Complex  operator/ (const Complex _other_) const;
        Complex& operator+=(const Complex _other_)      ;
        Complex& operator-=(const Complex _other_)      ;
        Complex& operator*=(const Complex _other_)      ;
        Complex& operator/=(const Complex _other_)      ;
        bool     operator==(const Complex _other_) const;
        bool     operator> (const Complex _other_) const;
        bool     operator< (const Complex _other_) const;
        bool     operator>=(const Complex _other_) const;
        bool     operator<=(const Complex _other_) const;

        float   real()      const;
        float   imag()      const;
        float   mod ()      const;
        float   arg ()      const;

        Complex     sq()    const;
        Complex conj  ()    const;
        float   conjSq()    const;
        
        Complex recip ()    const;

        std::string string();

    private:

        float _real;
        float _imag;
};

Complex Real(float   _real_   );
Complex Imag(float   _imag_   );

Complex cis (float   _arg_    );
Complex sqrt(Complex _complex_, bool _isPositive_ = true);
Complex exp (Complex _complex_);
Complex ln  (Complex _complex_, int _rotNumber_ = 0);

bool    areEqual(Complex _left_, Complex _right_);