#pragma once

#include "field1.hpp"

class Scalar1 : public Field1<float>
{
    public:

        Scalar1();
        virtual ~Scalar1();

        Scalar1(Base    _base_);
        Scalar1(Base* _toBase_);

        void scale(float _factor_);
};