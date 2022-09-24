#pragma once

#include "vertex.h"
#include <stdexcept>

#define INDEX_TOO_LARGE std::invalid_argument("index is larger than Basis2.size()")

class Basis2
{
    public:

        Basis2();
        virtual ~Basis2();

        Basis2(
            Vertex2<float>* _toXOrigin_,
            Vertex2<float>* _toYOrigin_,
            unsigned int _nx_,
            unsigned int _ny_
        );

        unsigned int xSize();
        unsigned int ySize();

        Vertex2<float> xOrigin();
        Vertex2<float> yOrigin();
        Vertex2<float> xEnd();
        Vertex2<float> yEnd();
        Vertex2<float> xAxisAt(unsigned int _index_);
        Vertex2<float> yAxisAt(unsigned int _index_);

        Vertex2<float>* toXOrigin();
        Vertex2<float>* toYOrigin();
        Vertex2<float>* toXEnd();
        Vertex2<float>* toYEnd();
        Vertex2<float>* toXAxisAt(unsigned int _index_);
        Vertex2<float>* toYAxisAt(unsigned int _index_);

    private:

        unsigned int _nx;
        unsigned int _ny;
        Vertex2<float>* _toXOrigin;
        Vertex2<float>* _toYOrigin;
};