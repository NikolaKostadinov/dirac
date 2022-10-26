#pragma once

#include "base.hpp"
#include "basis2.hpp"
#include "exceptions.h"

class Basis3 : public Basis2
{
    public:

        Basis3();
        virtual ~Basis3();

        Basis3(Base    _xBase_, Base    _yBase_, Base    _zBase_);
        Basis3(Base* _toXBase_, Base* _toYBase_, Base* _toZBase_);

        uint32_t  size();
        uint32_t zSize();

        float zStart();
        float zEnd  ();

        float dz();

        float zLength();

        float z(uint32_t _index_);

    protected:

        Base* _toZ;
};

Basis3 CubeBasis3(Base    _base);
Basis3 CubeBasis3(Base* _toBase);