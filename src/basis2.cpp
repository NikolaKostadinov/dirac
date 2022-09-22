#include "../include/basis2.hpp"

#define BASIS2 template <unsigned int NX, unsigned int NY> Basis2<NX, NY>

BASIS2::Basis2()
{
    for (int i = 0; i < NX; i++)
        for (int j = 0; j < NY; j++)
            _mesh[j][i] = new Vertex2<float>;
}

BASIS2::~Basis2()
{

}

BASIS2::Basis2(Vertex2<float> input_mesh[NX][NY])
{
    for (int i = 0; i < NX; i++)
        for (int j = 0; j < NY; j++)
            _mesh[j][i] = &input_mesh[j][i];
}

template class Basis2<10, 10>;
template class Basis2<100, 10>;