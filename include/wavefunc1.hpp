#pragma once

#include "complex.hpp"
#include "field1.hpp"

class WaveFunc1 : public Field1<Complex>
{
    public:

        WaveFunc1();
        virtual ~WaveFunc1();

        WaveFunc1(Base  _basis_  );
        WaveFunc1(Base* _toBasis_);

        void normalize();

        Complex probAmp(unsigned int _index_);
        float   prob   (unsigned int _index_);
        
        float prob();
        Field1<float> probDensity();
};