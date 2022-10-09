#pragma once

#include "engineparams.h"
#include "complex.hpp"
#include "basis2.hpp"
#include "field2.hpp"
#include "scalar2.hpp"
#include <string>

class WaveFunc2 : public Field2<Complex>
{
    public:

        WaveFunc2();
        virtual ~WaveFunc2();

        WaveFunc2(Basis2  _basis_  );
        WaveFunc2(Basis2* _toBasis_);

        void setMass      (float    _mass_   );
        void setNormValues(Complex* _address_);

        void normalize (float _norm_ = NORM)                      ;
        void evolveFree(float _deltaTime_  )                      ;
        void evolve    (float _deltaTime_, Scalar2    _potential_);
        void evolve    (float _deltaTime_, Scalar2* _toPotential_);

        Complex probAmp(uint32_t _index_, uint32_t _jndex_);
        float   prob   (uint32_t _index_, uint32_t _jndex_);
        
        float totalProb();

        std::string string();
    
    protected:

        float _mass;
};