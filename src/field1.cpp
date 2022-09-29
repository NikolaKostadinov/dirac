#include "../include/field1.hpp"

template <class T>
Field1<T>::Field1()
{
    _size = 0U;
    _toBase = new Base;
    _toOriginValue = new T;
}

template <class T>
Field1<T>::~Field1()
{
    delete _toBase;
    delete[] _toOriginValue;
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
    _toOriginValue = _address_;
}

template <class T>
void Field1<T>::setValue(T _value_, unsigned int _index_)
{
    *(_toOriginValue + _index_) = _value_;
}

template <class T>
void Field1<T>::scale(float _factor_)
{
    for (unsigned int i = 0U; i < _size; i++)
    {
        *(_toOriginValue + i) *= _factor_;
    }
}

template <class T>
Field1<T> Field1<T>::operator+()
{
    return *this;
}

template <class T>
Field1<T> Field1<T>::operator-()
{
    Field1<T> result(_toBase);
    T* address = _toOriginValue;
    for (unsigned int i = 0U; i < _size; i++)
    {
        T value = *address;
        result.setValue(-value);
        address++;
    }
}

// OPERATORS

template <class T>
unsigned int Field1<T>::size()
{
    return _size;
}

template <class T>
T* Field1<T>::address(unsigned int _index_)
{
    return _toOriginValue + _index_;
}

template <class T>
T Field1<T>::value(unsigned int _index_)
{
    return *(_toOriginValue + _index_);
}