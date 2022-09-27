#pragma once

#include "base.hpp"
#include "basis.hpp"
#include "exceptions.h"

class Basis2 : Basis
{
    public:

        Basis2();
        virtual ~Basis2();

        Basis2(Base _xBase_, Base _yBase_);
        Basis2(Base* _toXBase_, Base* _toYBase_);

        unsigned int size();
        unsigned int xSize();
        unsigned int ySize();
        unsigned int zSize();
        
        float xStart();
        float yStart();
        float zStart();
        float xEnd();
        float yEnd();
        float zEnd();

        float dx();
        float dy();
        float dz();

        float xLength();
        float yLength();
        float zLength();

    private:

        Base* _toX;
        Base* _toY;
};