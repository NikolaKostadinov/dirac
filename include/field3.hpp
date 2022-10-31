#pragma once

#include "engine_exceptions.h"
#include "base.hpp"
#include "basis3.hpp"
#include "complex.hpp"

#include <vector>

template <class T>
class Field3
{
    public:

        Field3();
        virtual ~Field3();

        Field3(Basis3    _basis_);
        Field3(Basis3* _toBasis_);

        void     setValues(T* _address_);

        uint32_t  size  ();
        uint32_t xSize  ();
        uint32_t ySize  ();
        uint32_t zSize  ();
        Basis3*  toBasis();
        Basis3   basis  ();
        
        T*       address(uint32_t _index_ = 0u, uint32_t _jndex_ = 0u, uint32_t _kindex_ = 0u);
        T        value  (uint32_t _index_     , uint32_t _jndex_     , uint32_t _kindex_     );

    protected:

        uint32_t _xSize        ;
        uint32_t _ySize        ;
        uint32_t _zSize        ;
        Basis3*  _toBasis      ;
        T*       _originAddress;
};