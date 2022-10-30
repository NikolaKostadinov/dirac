#include "../include/scalar3.hpp"

Scalar3::Scalar3() : Field3<float>()
{

}

Scalar3::~Scalar3()
{
    delete _toBasis;

    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            for (uint32_t k = 0u; k < _zSize; k++)
                delete address(i, j, k);
}

Scalar3::Scalar3(Basis3 _basis_) : Field3<float>(_basis_)
{

}

Scalar3::Scalar3(Basis3* _toBase_) : Field3<float>(_toBase_)
{

}

void Scalar3::scale(float _factor_)
{
    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            for (uint32_t k = 0u; k < _zSize; k++)
                *address(i, j, k) *= _factor_;
}