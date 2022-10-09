#pragma once

#include "field2.hpp"

class Scalar2 : public Field2<float>
{
    public:

        Scalar2();
        virtual ~Scalar2();

        Scalar2(Basis2    _basis_);
        Scalar2(Basis2* _toBasis_);

        void scale(float _factor_);
};