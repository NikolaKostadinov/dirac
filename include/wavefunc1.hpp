#pragma once

#include "engineparams.h"
#include "complex.hpp"
#include "base.hpp"
#include "field1.hpp"
#include <string>

class WaveFunc1 : public Field1<Complex>
{
    public:

        WaveFunc1();
        virtual ~WaveFunc1();

        WaveFunc1(Base    _basis_);
        WaveFunc1(Base* _toBasis_);

        void setNormValues(Complex* _address_);

        void normalize(float _norm_ = NORM);
        void evolve   (float _deltaTime_  );

        Complex probAmp(uint32_t _index_                );
        float   prob   (uint32_t _index_                );
        float   prob   (uint32_t _start_, uint32_t _end_);
        
        float totalProb();

        std::string string();
};