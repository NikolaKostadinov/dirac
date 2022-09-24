#pragma once

#include "vertex.h"

class Basis2
{
    public:

        Basis2();
        virtual ~Basis2();

        Basis2(
            Vertex2<float>* _toOriginX_,
            Vertex2<float>* _toOriginY_,
            unsigned int _nx_,
            unsigned int _ny_
        );

        unsigned int xSize();
        unsigned int ySize();

        Vertex2<float> xOrigin();
        Vertex2<float> yOrigin();

        Vertex2<float> xEnd();
        Vertex2<float> yEnd();

    private:

        unsigned int _nx;
        unsigned int _ny;
        Vertex2<float>* _toOriginX;
        Vertex2<float>* _toOriginY;
};