#include "../include/scalar3.hpp"

Scalar3::Scalar3()
{
    _xSize         = 0u        ;
    _ySize         = 0u        ;
    _zSize         = 0u        ;
    _toBasis       = new Basis3;
    _originAddress = new float ;
}

Scalar3::~Scalar3()
{
    delete _toBasis;

    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            for (uint32_t k = 0u; k < _zSize; k++)
                delete address(i, j, k);
}

Scalar3::Scalar3(Basis3 _basis_)
{
    _xSize         =  _basis_.xSize();
    _ySize         =  _basis_.ySize();
    _zSize         =  _basis_.zSize();
    _toBasis       = &_basis_        ;
    _originAddress =  new float      ;
}

Scalar3::Scalar3(Basis3* _toBase_)
{
    _xSize         = _toBase_->xSize();
    _ySize         = _toBase_->ySize();
    _zSize         = _toBase_->zSize();
    _toBasis       = _toBase_         ;
    _originAddress = new float        ;
}

void Scalar3::scale(float _factor_)
{
    for (uint32_t i = 0u; i < _xSize; i++)
        for (uint32_t j = 0u; j < _ySize; j++)
            for (uint32_t k = 0u; k < _zSize; k++)
                *address(i, j, k) *= _factor_;
}