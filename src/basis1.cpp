#include "../include/basis1.hpp"

#define BASIS1 template<unsigned int N> Basis1<N>

BASIS1::Basis1()
{
    for (int i = 0; i < N; i++)
        _vertices[i] = new Vertex1<float>;
}

BASIS1::~Basis1()
{

}

BASIS1::Basis1(Vertex1<float> input_vertices[])
{
    for (int i = 0; i < N; i++)
        _vertices[i] = &input_vertices[i];
}

template class Basis1<10>;
template class Basis1<1000>;