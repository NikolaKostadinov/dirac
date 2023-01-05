#pragma once

#include "engine_params.h"
#include "engine_exceptions.h"
#include "complex.hpp"

class WaveFunc
{
    public:

        WaveFunc();
        virtual ~WaveFunc();

        void      setNorm  (float _norm_      = DEFAULT_NORM       )        ;
        void      setMass  (float _mass_      = DEFAULT_MASS       )        ;
        void    checkNorm  (                                       )   const;
        void    checkMass  (bool _isMassless_ = DEFAULT_IS_MASSLESS)   const;

        bool    isNormValid(                                       )   const;
        bool    isMassValid(bool _isMassless_ = DEFAULT_IS_MASSLESS)   const;
        
        float   norm       ()                                          const;
        float   mass       ()                                          const;
        float   ampFactor  ()                                          const;   // probability amplitude normalization factor
        Complex cmpFactor  ()                                          const;   // probability amplitude normalization factor as a complex number
        float   prbFactor  ()                                          const;   // probability           normalization factor

        virtual float       prob (bool _isNormed_ = DEFAULT_IS_NORMED) const;

    protected:

        float _norm;
        float _mass;
};