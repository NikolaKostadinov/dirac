#pragma once

#include "vertex.h"
#include <stdexcept>

class Basis1
{
    public:

        Basis1();
        ~Basis1();

        Basis1(Vertex1<float>* _toOrigin_, unsigned int _n_);

        unsigned int size();

        Vertex1<float> origin();
        Vertex1<float> end();
        Vertex1<float> vertex(unsigned int _index_);

        Vertex1<float>* toOrigin();
        Vertex1<float>* toEnd();
        Vertex1<float>* toVertex(unsigned int _index_);

    private:

        unsigned int _n;
        Vertex1<float>* _toOrigin;
};