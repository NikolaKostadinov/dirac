#include "../include/basis2.hpp"

template <unsigned int NX, unsigned int NY>
Basis2<NX, NY>::Basis2()
{
    for (int i = 0; i < NX; i++)
        for (int j = 0; j < NY; j++)
            _toMesh[j][i] = new Vertex2<float>;
}

template <unsigned int NX, unsigned int NY>
Basis2<NX, NY>::~Basis2()
{
    for (int i = 0; i < NX; i++)
        for (int j = 0; j < NY; j++)
            delete _toMesh[j][i];
}

template <unsigned int NX, unsigned int NY>
Basis2<NX, NY>::Basis2(Vertex2<float> _mesh_[NX][NY])
{
    for (int i = 0; i < NX; i++)
        for (int j = 0; j < NY; j++)
            _toMesh[j][i] = &_mesh_[j][i];
}

template <unsigned int NX, unsigned int NY>
Basis2<NX, NY>::Basis2(Vertex2<float>* _toMesh_[NX][NY])
{
    for (int i = 0; i < NX; i++)
        for (int j = 0; j < NY; j++)
            _toMesh[j][i] = _toMesh_[j][i];
}

template class Basis2<10, 10>;
template class Basis2<100, 10>;