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

        Bispinor  operator+() const;
        Bispinor  operator-() const;

        Bispinor  operator+ ( const Bispinor _other_);
        Bispinor  operator- ( const Bispinor _other_);
        Bispinor  operator* ( const Bispinor _other_);
        Bispinor  operator/ ( const Bispinor _other_);
        Bispinor& operator+=( const Bispinor _other_);
        Bispinor& operator-=( const Bispinor _other_);
        Bispinor& operator*=( const Bispinor _other_);
        Bispinor& operator/=( const Bispinor _other_);
        bool      operator==( const Bispinor _other_);

        Spinor    positive()  const;
        Spinor    negative()  const;
        Complex   posUp   ()  const;
        Complex   posDown ()  const;
        Complex   negUp   ()  const;
        Complex   negDown ()  const;
        float     prob    ()  const;

        std::string string();

    protected:

        Spinor _positive;
        Spinor _negative;
};