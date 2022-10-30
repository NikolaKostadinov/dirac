#pragma once

#include "engineparams.h"
#include "exceptions.h"
#include "complex.hpp"

class WaveFunc
{
    public:

        WaveFunc();
        virtual ~WaveFunc();

        void      setNorm(float _norm_ = DEFAULT_NORM);
        void      setMass(float _mass_ = DEFAULT_MASS);
        void    checkNorm(                           );
        void    checkMass(                           );

        bool    isNormValid();
        bool    isMassValid();
        
        float   norm       ();
        float   mass       ();
        float   ampFactor  ();
        Complex cmpFactor  ();
        float   prbFactor  ();

        virtual float prob(bool _isNormed_ = DEFAULT_IS_NORMED);

    protected:

        float _norm;
        float _mass;
};