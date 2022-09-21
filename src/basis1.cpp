#include "../include/basis1.hpp"

template<unsigned int N>
Basis1<N>::Basis1()
{
    _vertices = new Vertex1<float>[N];
}

template<unsigned int N>
Basis1<N>::~Basis1()
{

}

template<unsigned int N>
Basis1<N>::Basis1(Vertex1<float>* input_vertices[N])
{
    _vertices = new Vertex1<float>[N];
}

template class Basis1<1>;
template class Basis1<2>;
template class Basis1<3>;
template class Basis1<4>;