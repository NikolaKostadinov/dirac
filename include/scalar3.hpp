#pragma once

#include "field3.hpp"

class Scalar3 : public Field3<float>
{
    public:

        Scalar3();
        virtual ~Scalar3();

        Scalar3(Basis3    _basis_);
        Scalar3(Basis3* _toBasis_);

        void scale(float _factor_);
};