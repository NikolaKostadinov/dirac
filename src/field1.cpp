#include "../include/field1.hpp"

#define FIELD1 template <class T, unsigned int N> Field1<T, N>

FIELD1::Field1()
{
    _basis = new Basis1<N>;
    
    for (int i = 0; i < N; ++i)
        _values[i] = new T;
}

FIELD1::~Field1()
{

}

FIELD1::Field1(Basis1<N> basis)
{
    _basis = &basis;

    for (int i = 0; i < N; ++i)
        _values[i] = new T;
}

FIELD1::Field1(Basis1<N>* basis)
{
    _basis = basis;

    for (int i = 0; i < N; ++i)
        _values[i] = new T;
}

template <class T, unsigned int N>
void Field1<T, N>::setValues(T values[N])
{
    for (int i = 0; i < N; ++i)
        _values[i] = values[i];
}

template <class T, unsigned int N>
void Field1<T, N>::setValues(T* p_values[N])
{
    for (int i = 0; i < N; ++i)
        _values[i] = *p_values[i];
}

template class Field1<float, 10>;