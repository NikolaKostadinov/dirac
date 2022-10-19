#pragma once

#include "engineparams.h"
#include "complex.hpp"
#include "basis3.hpp"
#include "field3.hpp"
#include "scalar3.hpp"
#include <string>

class WaveFunc3 : public Field3<Complex>
{
    public:

        WaveFunc3();
        virtual ~WaveFunc3();

        WaveFunc3(Basis3  _basis_  );
        WaveFunc3(Basis3* _toBasis_);

        void setMass      (float    _mass_   );
        void setNormValues(Complex* _address_);

        void normalize (float _norm_ = NORM)                      ;
        void evolveFree(float _deltaTime_  )                      ;
        void evolve    (float _deltaTime_, Scalar3    _potential_);
        void evolve    (float _deltaTime_, Scalar3* _toPotential_);

        Complex probAmp(uint32_t _index_, uint32_t _jndex_, uint32_t _kindex_);
        float   prob   (uint32_t _index_, uint32_t _jndex_, uint32_t _kindex_);
        
        float totalProb();

        std::string string();
    
    protected:

        float _mass;
};