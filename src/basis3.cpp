#include "../include/basis3.hpp"

#define BASIS3 template <unsigned int NX, unsigned int NY, unsigned int NZ> Basis3<NX, NY, NZ>

BASIS3::Basis3()
{
    for (int i = 0; i < NX; i++)
        for (int j = 0; j < NY; j++)
            for (int k = 0; k < NZ; k++)
                _mesh[k][j][i] = new Vertex3<float>;
}

BASIS3::~Basis3()
{

}

BASIS3::Basis3(Vertex3<float> mesh[NX][NY][NZ])
{
    for (int i = 0; i < NX; i++)
        for (int j = 0; j < NY; j++)
            for (int k = 0; k < NZ; k++)
                _mesh[k][j][i] = &mesh[k][j][i];
}

template class Basis3<10, 10, 10>;