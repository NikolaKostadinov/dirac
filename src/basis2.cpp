#include "../include/basis2.hpp"

template <unsigned int NX, unsigned int NY>
Basis2<NX, NY>::Basis2()
{
    for (int i = 0; i < NX; i++)
        for (int j = 0; j < NY; j++)
            _vertices[j][i] = new Vertex2<float>;
}

template <unsigned int NX, unsigned int NY>
Basis2<NX, NY>::~Basis2()
{

}

template <unsigned int NX, unsigned int NY>
Basis2<NX, NY>::Basis2(Vertex2<float> input_vertices[][NY])
{
    for (int i = 0; i < NX; i++)
        for (int j = 0; j < NY; j++)
            _vertices[j][i] = &input_vertices[j][i];
}

template class Basis2<10, 10>;
template class Basis2<100, 10>;