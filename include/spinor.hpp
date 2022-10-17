#pragma once

#include "complex.hpp"
#include <string>

class Spinor
{
    public:

        Spinor();
        virtual ~Spinor();

        Spinor(Complex _up_, Complex _down_);

        void scale(float _factor_);

        Spinor operator+();
        Spinor operator-();

        Spinor operator+(Spinor _other_);
        Spinor operator-(Spinor _other_);
        Spinor operator*(Spinor _other_);
        Spinor operator/(Spinor _other_);

        Complex up  ();
        Complex down();
        float   prob();

        std::string string();

    protected:

        Complex _up  ;
        Complex _down;
};