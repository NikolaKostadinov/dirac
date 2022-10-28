#pragma once

#include "engineparams.h"
#include "exceptions.h"
#include "complex.hpp"
#include "base.hpp"
#include "field1.hpp"
#include "scalar1.hpp"

#include <string>

class WaveFunc1 : public Field1<Complex>
{
    public:

        WaveFunc1();
        virtual ~WaveFunc1();

        WaveFunc1(Base    _basis_);
        WaveFunc1(Base* _toBasis_);

        void      setNorm(float _norm_ = NORM               );
        void      setMass(float _mass_ = 1.0f               );
        void    checkNorm(                                  );
        void    checkMass(                                  );
        void    evolve   (float _dt_                        );
        void    evolve   (float _dt_, Scalar1    _potential_);
        void    evolve   (float _dt_, Scalar1* _toPotential_);

        bool    isNormValid();
        bool    isMassValid();

        float   mass   (                );
        float   norm   (                );
        Complex probAmp(uint32_t _index_);
        float   prob   (uint32_t _index_);
        float   prob   (                );
        float   sumSqr (                );

        Complex ddx    (uint32_t _index_);
        Complex d2dx2  (uint32_t _index_);

        float   prob   (uint32_t _start_, uint32_t _end_);

        float expcIndex();
        float excpX    ();

        std::string string();

    protected:

        float _norm;
        float _mass;
};