#include "../include/field1.hpp"

template <class T, unsigned int N>
Field1<T, N>::Field1()
{
    _basis = new Basis1<N>;
}

template <class T, unsigned int N>
Field1<T, N>::~Field1()
{

}

template <class T, unsigned int N>
Field1<T, N>::Field1(Basis1<N> basis)
{
    _basis = &basis;
}

template <class T, unsigned int N>
Field1<T, N>::Field1(Basis1<N>* basis)
{
    _basis = basis;
}

template class Field1<float, 10>;