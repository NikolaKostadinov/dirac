#pragma once

#include "field1.hpp"

class Scalar1 : public Field1<float>
{
    public:

        Scalar1();
        virtual ~Scalar1();

        Scalar1(Base    _basis_);
        Scalar1(Base* _toBasis_);

        void scale(float _factor_);
};