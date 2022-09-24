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

        Vertex3<float> xOrigin();
        Vertex3<float> yOrigin();
        Vertex3<float> zOrigin();
        Vertex3<float> xEnd();
        Vertex3<float> yEnd();
        Vertex3<float> zEnd();
        Vertex3<float> xAxisAt(unsigned int _index_);
        Vertex3<float> yAxisAt(unsigned int _index_);
        Vertex3<float> zAxisAt(unsigned int _index_);

        Vertex3<float>* toXOrigin();
        Vertex3<float>* toYOrigin();
        Vertex3<float>* toZOrigin();
        Vertex3<float>* toXEnd();
        Vertex3<float>* toYEnd();
        Vertex3<float>* toZEnd();
        Vertex3<float>* toXAxisAt(unsigned int _index_);
        Vertex3<float>* toYAxisAt(unsigned int _index_);
        Vertex3<float>* toZAxisAt(unsigned int _index_);

    private:

        unsigned int _nx;
        unsigned int _ny;
        unsigned int _nz;
        Vertex3<float>* _toXOrigin;
        Vertex3<float>* _toYOrigin;
        Vertex3<float>* _toZOrigin;
};