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
Basis1<N>::Basis1(Vertex1<float>* input_vertices[])
{
    _vertices = new Vertex1<float>[N];

    /*for (int i = 0; i < N; i++)
    {
        float x = input_vertices[i]->x;
        _vertices[i] = new Vertex1<float>(x);
    }*/
}

template class Basis1<4>;