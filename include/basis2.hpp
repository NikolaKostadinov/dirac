#pragma once

#include "vertex.h"

template <unsigned int NX, unsigned int NY>
class Basis2
{
    public:

        Basis2();
        ~Basis2();

        Basis2(Vertex2<float> input_vertices[][NY]);

    private:

        Vertex2<float>* _vertices[NX][NY];
};