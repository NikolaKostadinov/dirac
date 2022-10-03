#pragma once

#include "complex.hpp"
#include <string>

class Spinor2
{
    public:

        Spinor2();
        virtual ~Spinor2();

        Spinor2(Complex _up_, Complex _down_);

        void scale(float _factor_);

        Spinor2 operator+();
        Spinor2 operator-();

        Spinor2 operator+(Spinor2 _other_);
        Spinor2 operator-(Spinor2 _other_);
        Spinor2 operator*(Spinor2 _other_);
        Spinor2 operator/(Spinor2 _other_);

        Complex up  ();
        Complex down();
        float   prob();

        std::string string();

    protected:

        Complex _up;
        Complex _down;
};