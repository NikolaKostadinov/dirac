#pragma once

#include "complex.hpp"
#include "field1.hpp"
#include <string>

#define MAX_STR 8

class WaveFunc1 : public Field1<Complex>
{
    public:

        WaveFunc1();
        virtual ~WaveFunc1();

        WaveFunc1(Base  _basis_  );
        WaveFunc1(Base* _toBasis_);

        void normalize(float _norm_ = 1.0F);

        Complex probAmp(unsigned int _index_);
        float   prob   (unsigned int _index_);
        float   prob   (unsigned int _start_, unsigned int _end_);
        
        float totalProb();
        Field1<float> probDensity();

        std::string string();
};