#include "../include/scalar1.hpp"

Scalar1::Scalar1() : Field1<float>()
{

}

Scalar1::~Scalar1()
{
    uint32_t  tempSize = size();
    delete _toBase;

    for (uint32_t i = 0u; i < tempSize; i++)
        delete address(i);
}

Scalar1::Scalar1(Base _base_) : Field1<float>(_base_)
{

}

Scalar1::Scalar1(Base* _toBase_) : Field1<float>(_toBase_)
{

}

void Scalar1::scale(float _factor_)
{
    uint32_t  tempSize = size();

    for (uint32_t i = 0u; i < tempSize; i++)
        *address(i) *= _factor_;
}