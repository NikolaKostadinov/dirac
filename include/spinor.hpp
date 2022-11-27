#pragma once

#include "engine_params.h"
#include "complex.hpp"

#include <string>

class Spinor
{
    public:

        Spinor();
        virtual ~Spinor();

        Spinor(Complex _up_, Complex _down_);

        void    scale    (float _factor_                    );
        void    shrink   (float _factor_                    );
        void    normalize(float _norm_ = DEFAULT_SPINOR_NORM);

        Spinor  operator+ (                    ) const;
        Spinor  operator- (                    ) const;
        Spinor  operator+ (const Spinor _other_) const;
        Spinor  operator- (const Spinor _other_) const;
        Spinor  operator* (const Spinor _other_) const;
        Spinor  operator/ (const Spinor _other_) const;
        Spinor& operator+=(const Spinor _other_)      ;
        Spinor& operator-=(const Spinor _other_)      ;
        Spinor& operator*=(const Spinor _other_)      ;
        Spinor& operator/=(const Spinor _other_)      ;
        bool    operator==(const Spinor _other_) const;

        Complex up  ()     const;
        Complex down()     const;
        float   prob()     const;

        std::string string();

    protected:

        Complex _up  ;
        Complex _down;
};