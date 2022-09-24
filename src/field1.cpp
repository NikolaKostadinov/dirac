#include "../include/field1.hpp"

template <class T, unsigned int N>
Field1<T, N>::Field1()
{
    _toBasis = new Basis1;
}

template <class T, unsigned int N>
Field1<T, N>::~Field1()
{

}

template <class T, unsigned int N>
Field1<T, N>::Field1(Basis1 _basis_)
{
    _toBasis = &_basis_;
}

template <class T, unsigned int N>
Field1<T, N>::Field1(Basis1* _toBasis_)
{
    _toBasis = _toBasis_;
}

template <class T, unsigned int N>
void Field1<T, N>::setValues(T _values_[N])
{
    for (int i = 0; i < N; i++)
        _values[i] = _values_[i];
}

template <class T, unsigned int N>
void Field1<T, N>::setValues(T* _toValues_[N])
{
    for (int i = 0; i < N; i++)
        _values[i] = *_toValues_[i];
}

template <class T, unsigned int N>
void Field1<T, N>::getValue(T& reference, int _index_)
{
    reference = _values[_index_];
}

template <class T, unsigned int N>
void Field1<T, N>::getValue(T*& toReference, int _index_)
{
    toReference = &_values[_index_];
}

template <class T, unsigned int N>
T* Field1<T, N>::address(int _index_)
{
    return &_values[_index_];
}

template class Field1<float, 10>;
template class Field1<float, 1000>;
template class Field1<float, 10000>;