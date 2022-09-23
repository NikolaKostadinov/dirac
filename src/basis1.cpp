#include "../include/basis1.hpp"

template<unsigned int N>
Basis1<N>::Basis1()
{
    for (int i = 0; i < N; i++)
        _vertices[i] = new Vertex1<float>;
}

template<unsigned int N>
Basis1<N>::~Basis1()
{
    for (int i = 0; i < N; i++)
        delete _vertices[i];
}

template<unsigned int N>
Basis1<N>::Basis1(Vertex1<float> _vertices_[])
{
    for (int i = 0; i < N; i++)
        _vertices[i] = &_vertices_[i];
}

template<unsigned int N>
Basis1<N>::Basis1(Vertex1<float>* _toVertices_[])
{
    for (int i = 0; i < N; i++)
        _vertices[i] = _toVertices_[i];
}

template class Basis1<10>;
template class Basis1<1000>;
template class Basis1<10000>;