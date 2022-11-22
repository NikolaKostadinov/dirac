#pragma once

#include "complex.hpp"

#include <string>

class Spinor
{
    public:

        Spinor();
        virtual ~Spinor();

        Spinor(Complex _up_, Complex _down_);

        void    scale(float _factor_);

        Spinor  operator+() const;
        Spinor  operator-() const;

        Spinor  operator+ ( const Spinor _other_);
        Spinor  operator- ( const Spinor _other_);
        Spinor  operator* ( const Spinor _other_);
        Spinor  operator/ ( const Spinor _other_);
        Spinor  operator==( const Spinor _other_);
        Spinor& operator+=( const Spinor _other_);

        Complex up  ()      const;
        Complex down()      const;
        float   prob()      const;

        std::string string();

    protected:

        Complex _up  ;
        Complex _down;
};