#include "../include/scalar3.hpp"

Scalar3::Scalar3() : Field3<float>()
{

}

Scalar3::~Scalar3()
{
    uint32_t  tempXSize = xSize();
    uint32_t  tempYSize = ySize();
    uint32_t  tempZSize = zSize();
    delete   _toBasis;

    for (uint32_t i = 0u; i < tempXSize; i++)
        for (uint32_t j = 0u; j < tempYSize; j++)
            for (uint32_t k = 0u; k < tempZSize; k++)
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
    uint32_t  tempXSize = xSize();
    uint32_t  tempYSize = ySize();
    uint32_t  tempZSize = zSize();

    for (uint32_t i = 0u; i < tempXSize; i++)
        for (uint32_t j = 0u; j < tempYSize; j++)
            for (uint32_t k = 0u; k < tempZSize; k++)
                *address(i, j, k) *= _factor_;
}