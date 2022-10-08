#pragma once

#include "base.hpp"
#include "exceptions.h"

class Basis2
{
    public:

        Basis2();
        virtual ~Basis2();

        Basis2(Base    _xBase_, Base    _yBase_);
        Basis2(Base* _toXBase_, Base* _toYBase_);

        uint32_t  size();
        uint32_t xSize();
        uint32_t ySize();
        uint32_t zSize();
        
        float xStart();
        float yStart();
        float zStart();
        float xEnd  ();
        float yEnd  ();
        float zEnd  ();

        float dx();
        float dy();
        float dz();

        float xLength();
        float yLength();
        float zLength();

        float x(uint32_t _index_);
        float y(uint32_t _index_);
        float z(uint32_t _index_);

    protected:

        Base* _toX;
        Base* _toY;
};