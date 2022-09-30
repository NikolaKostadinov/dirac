#include "../include/field1.hpp"

template <class T>
Field1<T>::Field1()
{
    _size = 0U;
    _toBase = new Base;
    _originAddress = new T;
}

template <class T>
Field1<T>::~Field1()
{
    delete _toBase;
    delete[] _originAddress;
}

template <class T>
Field1<T>::Field1(Base _base_)
{
    _size = _base_.size();
    _toBase = &_base_;
}

template <class T>
Field1<T>::Field1(Base* _toBase_)
{
    _size = _toBase_->size();
    _toBase = _toBase_;
}

template <class T>
void Field1<T>::setValues(T* _address_)
{
    _originAddress = _address_;
}

template <class T>
void Field1<T>::setValue(T _value_, unsigned int _index_)
{
    *(_originAddress + _index_) = _value_;
}

template <class T>
unsigned int Field1<T>::size()
{
    return _size;
}

template <class T>
Base* Field1<T>::toBase()
{
    return _toBase;
}

template <class T>
T* Field1<T>::address(unsigned int _index_)
{
    return _originAddress + _index_;
}

template <class T>
T Field1<T>::value(unsigned int _index_)
{
    return *(_originAddress + _index_);
}

template class Field1<   float   >;
template class Field1<   double  >;
template class Field1<long double>;
template class Field1<  Complex  >;