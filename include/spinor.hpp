#pragma once

#include "complex.hpp"

class Spinor2
{
    public:

        Spinor2();
        virtual ~Spinor2();

        Spinor2 operator+();
        Spinor2 operator-();

        Spinor2 operator+(Spinor2 _other_);
        Spinor2 operator-(Spinor2 _other_);
        Spinor2 operator*(Spinor2 _other_);
        Spinor2 operator/(Spinor2 _other_);

        bool operator==(Spinor2 _other_);

        Complex up  ();
        Complex down();
        float   prob();

    protected:

        Complex _up;
        Complex _down;
};