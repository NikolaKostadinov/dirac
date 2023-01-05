#pragma once

#include "engine_params.h"
#include "engine_exceptions.h"
#include "complex.hpp"
#include "basis2.hpp"
#include "field2.hpp"
#include "wavefunc.hpp"
#include "vector2.hpp"
#include "scalar2.hpp"

#include <string>

class WaveFunc2 : public Field2<Complex>, public WaveFunc
{
    public:

        WaveFunc2();
        virtual ~WaveFunc2();

        WaveFunc2(Basis2    _basis_);
        WaveFunc2(Basis2* _toBasis_);

        void    evolve (float _dt_ = DEFAULT_DT            );
        void    evolve (float _dt_,  Scalar2    _potential_);
        void    evolve (float _dt_,  Scalar2* _toPotential_);

        Complex probAmp(uint32_t _index_, uint32_t _jndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;
        float   prob   (uint32_t _index_, uint32_t _jndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;
        float   prob   (                                    bool _isNormed_ = DEFAULT_IS_NORMED) const;

        Complex ddx    (uint32_t _index_, uint32_t _jndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;
        Complex ddy    (uint32_t _index_, uint32_t _jndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;
        Complex div    (uint32_t _index_, uint32_t _jndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;
        Complex d2dx2  (uint32_t _index_, uint32_t _jndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;
        Complex d2dy2  (uint32_t _index_, uint32_t _jndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;
        Complex laplace(uint32_t _index_, uint32_t _jndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;

        std::string string();
};