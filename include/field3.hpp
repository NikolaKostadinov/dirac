#pragma once

#include "engine_exceptions.h"
#include "base.hpp"
#include "basis3.hpp"
#include "complex.hpp"
#include "vector2.hpp"
#include "vector3.hpp"

#include <vector>

template <class T>
class Field3
{
    public:

        Field3();
        virtual ~Field3();

        Field3(Basis3    _basis_);
        Field3(Basis3* _toBasis_);

        void     setValues(T*      _address_);
        void     setBasis (Basis2* _toBasis_);

        uint32_t  size  ()                                                                     const;
        uint32_t xSize  ()                                                                     const;
        uint32_t ySize  ()                                                                     const;
        uint32_t zSize  ()                                                                     const;
        Basis3*  toBasis()                                                                     const;
        Basis3   basis  ()                                                                     const;
        
        T*       address(uint32_t _index_ = 0u, uint32_t _jndex_ = 0u, uint32_t _kindex_ = 0u) const;
        T        value  (uint32_t _index_     , uint32_t _jndex_     , uint32_t _kindex_     ) const;

    protected:

        Basis3*  _toBasis      ;
        T*       _originAddress;
};