#pragma once

#include "engine_exceptions.h"
#include "base.hpp"
#include "basis2.hpp"
#include "vector3.hpp"

class Basis3 : public Basis2
{
    public:

        Basis3();
        virtual ~Basis3();

        Basis3(Base    _xBase_, Base    _yBase_, Base    _zBase_);
        Basis3(Base* _toXBase_, Base* _toYBase_, Base* _toZBase_);

        Vector3  operator()(uint32_t _index_,
                            uint32_t _jndex_,
                            uint32_t _kndex_) const;

        uint32_t  size()                      const;
        uint32_t zSize()                      const;

        float    zStart()                     const;
        float    zEnd  ()                     const;

        float    dz()                         const;

        float    zLength()                    const;

        float    z(uint32_t _kndex_)          const;

    protected:

        Base* _toZ;
};

Basis3 CubeBasis3(Base    _base);
Basis3 CubeBasis3(Base* _toBase);