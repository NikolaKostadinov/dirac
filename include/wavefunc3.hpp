#pragma once

#include "engine_params.h"
#include "engine_exceptions.h"
#include "complex.hpp"
#include "basis3.hpp"
#include "field3.hpp"
#include "wavefunc.hpp"
#include "scalar3.hpp"

#include <string>

class WaveFunc3 : public Field3<Complex>, public WaveFunc
{
    public:

        WaveFunc3();
        virtual ~WaveFunc3();

        WaveFunc3(Basis3  _basis_  );
        WaveFunc3(Basis3* _toBasis_);

        void    evolve (float _dt_ = DEFAULT_DT            );
        void    evolve (float _dt_,  Scalar3    _potential_);
        void    evolve (float _dt_,  Scalar3* _toPotential_);

        Complex probAmp(uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;
        float   prob   (uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;
        float   prob   (                                                      bool _isNormed_ = DEFAULT_IS_NORMED) const;

        Complex ddx    (uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;
        Complex ddy    (uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;
        Complex ddz    (uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;
        Complex grad   (uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;
        Complex d2dx2  (uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;
        Complex d2dy2  (uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;
        Complex d2dz2  (uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;
        Complex laplace(uint32_t _index_, uint32_t _jndex_, uint32_t _kndex_, bool _isNormed_ = DEFAULT_IS_NORMED) const;

        std::string string();
};