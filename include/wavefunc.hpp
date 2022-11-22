#pragma once

#include "engine_params.h"
#include "engine_exceptions.h"
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

        bool    isNormValid()                                          const;
        bool    isMassValid()                                          const;
        
        float   norm       ()                                          const;
        float   mass       ()                                          const;
        float   ampFactor  ()                                          const;
        Complex cmpFactor  ()                                          const;
        float   prbFactor  ()                                          const;

        virtual float       prob (bool _isNormed_ = DEFAULT_IS_NORMED) const;
        virtual Complex* toMaxAmp(                                   ) const;
        virtual Complex* toMinAmp(                                   ) const;
        virtual Complex    maxAmp(bool _isNormed_ = DEFAULT_IS_NORMED) const;
        virtual Complex    minAmp(bool _isNormed_ = DEFAULT_IS_NORMED) const;
        virtual float    maxProb (bool _isNormed_ = DEFAULT_IS_NORMED) const;
        virtual float    minProb (bool _isNormed_ = DEFAULT_IS_NORMED) const;

    protected:

        float _norm;
        float _mass;
};