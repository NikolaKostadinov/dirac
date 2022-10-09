#include "../include/scalar2.hpp"

Scalar2::Scalar2()
{
    _xSize         = 0u        ;
    _ySize         = 0u        ;
    _toBasis       = new Basis2;
    _originAddress = new float ;
}

Scalar2::~Scalar2()
{
    delete _toBasis;

    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            delete address(i, j);
}

Scalar2::Scalar2(Basis2 _basis_)
{
    _xSize         =  _basis_.xSize();
    _ySize         =  _basis_.ySize();
    _toBasis       = &_basis_        ;
    _originAddress =  new float      ;
}

Scalar2::Scalar2(Basis2* _toBase_)
{
    _xSize         = _toBase_->xSize();
    _ySize         = _toBase_->ySize();
    _toBasis       = _toBase_         ;
    _originAddress = new float        ;
}

void Scalar2::scale(float _factor_)
{
    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            *address(i, j) *= _factor_;
}