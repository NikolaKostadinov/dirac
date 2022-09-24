#pragma once

#include "vertex.h"
#include "exceptions.h"

class Basis3
{
    public:

        Basis3();
        virtual ~Basis3();

        Basis3(
            Vertex3<float>* _toXOrigin_,
            Vertex3<float>* _toYOrigin_,
            Vertex3<float>* _toZOrigin_,
            unsigned int _nx_,
            unsigned int _ny_,
            unsigned int _nz_
        );

        unsigned int xSize();
        unsigned int ySize();
        unsigned int zSize();

    private:

        unsigned int _nx;
        unsigned int _ny;
        unsigned int _nz;
        Vertex3<float>* _toXOrigin;
        Vertex3<float>* _toYOrigin;
        Vertex3<float>* _toZOrigin;
};