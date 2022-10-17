#pragma once

#include "complex.hpp"
#include "spinor.hpp"
#include <string>

class Bispinor
{
    public:

        Bispinor();
        virtual ~Bispinor();

        Bispinor(Spinor _positive_, Spinor _negative_);

        void scale(float _factor_);

        Bispinor operator+();
        Bispinor operator-();

        Bispinor operator+(Bispinor _other_);
        Bispinor operator-(Bispinor _other_);
        Bispinor operator*(Bispinor _other_);
        Bispinor operator/(Bispinor _other_);

        Spinor  positive();
        Spinor  negative();
        Complex posUp   ();
        Complex posDown ();
        Complex negUp   ();
        Complex negDown ();
        float   prob    ();

        std::string string();

    protected:

        Spinor _positive;
        Spinor _negative;
};