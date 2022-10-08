#include "../include/scalar1.hpp"

Scalar1::Scalar1()
{
    _size          = 0u       ;
    _toBase        = new Base ;
    _originAddress = new float;
}

Scalar1::~Scalar1()
{
    delete   _toBase       ;
    delete[] _originAddress;
}

Scalar1::Scalar1(Base _base_)
{
    _size          =  _base_.size();
    _toBase        = &_base_       ;
    _originAddress =  new float    ;
}

Scalar1::Scalar1(Base* _toBase_)
{
    _size          = _toBase_->size();
    _toBase        = _toBase_        ;
    _originAddress = new float       ;
}

void Scalar1::scale(float _factor_)
{
    for (uint32_t i = 0U; i < _size; i++)
        (*address(i)) *= _factor_;
}