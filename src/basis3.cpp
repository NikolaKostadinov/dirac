#include "../include/basis3.hpp"

template <unsigned int NX, unsigned int NY, unsigned int NZ>
Basis3<NX, NY, NZ>::Basis3()
{
    for (int i = 0; i < NX; i++)
        for (int j = 0; j < NY; j++)
            for (int k = 0; k < NZ; k++)
                _toMesh[k][j][i] = new Vertex3<float>;
}

template <unsigned int NX, unsigned int NY, unsigned int NZ>
Basis3<NX, NY, NZ>::~Basis3()
{
    for (int i = 0; i < NX; i++)
            for (int j = 0; j < NY; j++)
                for (int k = 0; k < NZ; k++)
                    delete _toMesh[k][j][i];
}

template <unsigned int NX, unsigned int NY, unsigned int NZ>
Basis3<NX, NY, NZ>::Basis3(Vertex3<float> _mesh_[NX][NY][NZ])
{
    for (int i = 0; i < NX; i++)
        for (int j = 0; j < NY; j++)
            for (int k = 0; k < NZ; k++)
                _toMesh[k][j][i] = &_mesh_[k][j][i];
}

template <unsigned int NX, unsigned int NY, unsigned int NZ>
Basis3<NX, NY, NZ>::Basis3(Vertex3<float>* _toMesh_[NX][NY][NZ])
{
    for (int i = 0; i < NX; i++)
        for (int j = 0; j < NY; j++)
            for (int k = 0; k < NZ; k++)
                _toMesh[k][j][i] = _toMesh_[k][j][i];
}

template class Basis3<10, 10, 10>;