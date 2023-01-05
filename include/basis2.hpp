#pragma once

#include "engine_exceptions.h"
#include "base.hpp"
#include "vector2.hpp"

class Basis2
{
    public:

        Basis2();
        virtual ~Basis2();

        Basis2(Base    _xBase_, Base    _yBase_);
        Basis2(Base* _toXBase_, Base* _toYBase_);

        virtual
        Vector2 operator()(uint32_t _index_,
                           uint32_t _jndex_)    const final;

        uint32_t  size()                        const      ;
        uint32_t xSize()                        const      ;
        uint32_t ySize()                        const      ;
        uint32_t zSize()                        const      ;

        float    xStart()                       const      ;
        float    yStart()                       const      ;
        float    zStart()                       const      ;
        float    xEnd  ()                       const      ;
        float    yEnd  ()                       const      ;
        float    zEnd  ()                       const      ;

        float    xDelta ()                      const      ;
        float    yDelta ()                      const      ;
        float    zDelta ()                      const      ;
        float    xDelta2()                      const      ;
        float    yDelta2()                      const      ;
        float    zDelta2()                      const      ;

        float    xLength()                      const      ;
        float    yLength()                      const      ;
        float    zLength()                      const      ;

        float    xCoord(uint32_t _index_)       const      ;
        float    yCoord(uint32_t _jndex_)       const      ;
        float    zCoord(uint32_t _kndex_)       const      ;

        virtual
        Vector2   coord(uint32_t _index_,
                        uint32_t _jndex_)       const final;

    protected:

        Base* _toX;
        Base* _toY;
};