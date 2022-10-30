#include "../include/scalar1.hpp"

Scalar1::Scalar1() : Field1<float>()
{

}

Scalar1::~Scalar1()
{
    delete _toBase;

    for (uint32_t i = 0u; i < _size; i++)
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
    for (uint32_t i = 0u; i < _size; i++)
        *address(i) *= _factor_;
}