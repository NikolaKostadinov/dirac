#pragma once

#include "vertex.h"

template <unsigned int NX, unsigned int NY, unsigned int NZ>
class Basis3
{
    public:

        Basis3();
        ~Basis3();

        Basis3(Vertex3<float> _mesh_[NX][NY][NZ]);
        Basis3(Vertex3<float>* _toMesh_[NX][NY][NZ]);

    private:

        Vertex3<float>* _mesh[NX][NY][NZ];
};