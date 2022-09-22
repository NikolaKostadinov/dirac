#pragma once

#include "vertex.h"

template <unsigned int N>
class Basis1
{
    public:

        Basis1();
        ~Basis1();

        Basis1(Vertex1<float> vertices[]);

    private:

        Vertex1<float>* _vertices[N];
};