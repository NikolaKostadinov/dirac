#pragma once

#include "engineparams.h"
#include "complex.hpp"
#include "basis2.hpp"
#include "field2.hpp"
#include <string>

class WaveFunc2 : public Field2<Complex>
{
    public:

        WaveFunc2();
        virtual ~WaveFunc2();

        WaveFunc2(Basis2  _basis_  );
        WaveFunc2(Basis2* _toBasis_);

        void normalize(float _norm_ = NORM);
        void evolve   (float _deltaTime_  );

        Complex probAmp(unsigned int _index_, unsigned int _jndex_);
        float   prob   (unsigned int _index_, unsigned int _jndex_);
        
        float totalProb();

        std::string string();
};