#pragma once

#include "engine_params.h"
#include "engine_exceptions.h"
#include "complex.hpp"
#include "base.hpp"
#include "field1.hpp"
#include "wavefunc.hpp"
#include "scalar1.hpp"

#include <string>

class WaveFunc1 : public Field1<Complex>, public WaveFunc
{
    public:

        WaveFunc1();
        virtual ~WaveFunc1();

        WaveFunc1(Base    _basis_);
        WaveFunc1(Base* _toBasis_);


        void     evolve   (float _dt_   = DEFAULT_DT            );
        void     evolve   (float _dt_   , Scalar1    _potential_);
        void     evolve   (float _dt_   , Scalar1* _toPotential_);

        Complex  probAmp  (uint32_t _index_, bool _isNormed_ = DEFAULT_IS_NORMED);
        float    prob     (uint32_t _index_, bool _isNormed_ = DEFAULT_IS_NORMED);
        float    prob     (                  bool _isNormed_ = DEFAULT_IS_NORMED);

        Complex  ddx      (uint32_t _index_, bool _isNormed_ = DEFAULT_IS_NORMED);
        Complex  d2dx2    (uint32_t _index_, bool _isNormed_ = DEFAULT_IS_NORMED);

        float    prob     (uint32_t _start_,
                           uint32_t _end_  , bool _isNormed_ = DEFAULT_IS_NORMED);

        Complex    maxAmp(                   bool _isNormed_ = DEFAULT_IS_NORMED);
        Complex* toMaxAmp(                                                      );
        float    maxProb (                   bool _isNormed_ = DEFAULT_IS_NORMED);

        float expcIndex();
        float excpX    ();

        std::string string();
};