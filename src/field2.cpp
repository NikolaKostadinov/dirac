#include "../include/field2.hpp"

template <class T>
Field2<T>::Field2()
{
    _xSize = 0U;
    _ySize = 0U;
    _toBasis = new Basis2;
    _originAddress = new T;
}

template <class T>
Field2<T>::~Field2()
{
    delete _toBasis;
    //delete[] _originAddress;
}

template <class T>
Field2<T>::Field2(Basis2* _toBasis_)
{
    _xSize = _toBasis_->xSize();
    _ySize = _toBasis_->ySize();
    _toBasis = _toBasis_;
    _originAddress = new T;
}

template <class T>
Field2<T>::Field2(Basis2 _basis_)
{
    _xSize = _basis_.xSize();
    _ySize = _basis_.ySize();
    _toBasis = &_basis_;
    _originAddress = new T;
}

template <class T>
void Field2<T>::setValues(T* _address_)
{
    _originAddress = _address_;
}

template <class T>
unsigned int Field2<T>::size()
{
    return _toBasis->size();
}

template <class T>
unsigned int Field2<T>::xSize()
{
    return _toBasis->xSize();
}

template <class T>
unsigned int Field2<T>::ySize()
{
    return _toBasis->ySize();
}

template <class T>
Basis2* Field2<T>::toBasis()
{
    return _toBasis;
}

template <class T>
Basis2 Field2<T>::basis()
{
    return *_toBasis;
}

template <class T>
T* Field2<T>::address(unsigned int _index_, unsigned int _jndex_)
{
    unsigned int upperArea = _jndex_ * xSize();
    return _originAddress + _index_ + upperArea;
}

template class Field2<   float   >;
template class Field2<   double  >;
template class Field2<long double>;
template class Field2<  Complex  >;