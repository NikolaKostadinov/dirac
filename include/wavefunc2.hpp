#pragma once

#include "engineparams.h"
#include "exceptions.h"
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

        void    setMass      (float    _mass_   );
        void    setNormValues(Complex* _address_);
        void    checkMass    (                  );

        void    normalize(float _norm_ = NORM               );
        void    evolve   (float _dt_                        );
        void    evolve   (float _dt_, Scalar2    _potential_);
        void    evolve   (float _dt_, Scalar2* _toPotential_);

        bool    isMassValid();

        float   mass   (                                  );
        Complex probAmp(uint32_t _index_, uint32_t _jndex_);
        float   prob   (uint32_t _index_, uint32_t _jndex_);
        float   prob   (                                  );

        Complex ddx    (uint32_t _index_, uint32_t _jndex_);
        Complex ddy    (uint32_t _index_, uint32_t _jndex_);
        Complex grad   (uint32_t _index_, uint32_t _jndex_);
        Complex d2dx2  (uint32_t _index_, uint32_t _jndex_);
        Complex d2dy2  (uint32_t _index_, uint32_t _jndex_);
        Complex laplace(uint32_t _index_, uint32_t _jndex_);

        float   expcIndex();
        float   expcJndex();
        float   excpX    ();
        float   excpY    ();

        std::string string();
    
    protected:

        float _mass;
};