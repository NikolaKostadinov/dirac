#include "../include/scalar2.hpp"

Scalar2::Scalar2() : Field2<float>()
{

}

Scalar2::~Scalar2()
{
    uint32_t  tempXSize = xSize();
    uint32_t  tempYSize = ySize();
    delete   _toBasis;

    for (uint32_t i = 0u; i < tempXSize; i++)
        for (uint32_t j = 0u; j < tempYSize; j++)
            delete address(i, j);
}

Scalar2::Scalar2(Basis2 _basis_) : Field2<float>(_basis_)
{

}

Scalar2::Scalar2(Basis2* _toBase_) : Field2<float>(_toBase_)
{

}

void Scalar2::scale(float _factor_)
{
    uint32_t  tempXSize = xSize();
    uint32_t  tempYSize = ySize();
    
    for (uint32_t i = 0u; i < tempXSize; i++)
        for (uint32_t j = 0u; j < tempYSize; j++)
            *address(i, j) *= _factor_;
}