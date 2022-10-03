#pragma once

#include "complex.hpp"
#include "spinor2.hpp"
#include <string>

class Spinor4
{
    public:

        Spinor4();
        virtual ~Spinor4();

        Spinor4(Spinor2 _positive_, Spinor2 _negative_);

        void scale(float _factor_);

        Spinor4 operator+();
        Spinor4 operator-();

        Spinor4 operator+(Spinor4 _other_);
        Spinor4 operator-(Spinor4 _other_);
        Spinor4 operator*(Spinor4 _other_);
        Spinor4 operator/(Spinor4 _other_);

        Spinor2 positive();
        Spinor2 negative();
        Complex posUp   ();
        Complex posDown ();
        Complex negUp   ();
        Complex negDown ();
        float   prob    ();

        std::string string();

    protected:

        Spinor2 _positive;
        Spinor2 _negative;
};