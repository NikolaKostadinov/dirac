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

        void setMass      (float    _mass_   );
        void setNormValues(Complex* _address_);

        void normalize (float _norm_ = NORM)                      ;
        void evolveFree(float _deltaTime_  )                      ;
        void evolve    (float _deltaTime_, Scalar1    _potential_);
        void evolve    (float _deltaTime_, Scalar1* _toPotential_);

        Complex probAmp(uint32_t _index_)                ;
        float   prob   (uint32_t _index_)                ;
        float   prob   (uint32_t _start_, uint32_t _end_);

        float   mass();
        
        float totalProb();

        std::string string();

    protected:

        float _mass;
};