#pragma once

#include "engine_exceptions.h"
#include "base.hpp"
#include "basis2.hpp"
#include "complex.hpp"

#include <vector>

template <class T>
class Field2
{
    public:

        Field2();
        virtual ~Field2();

        Field2(Basis2    _basis_);
        Field2(Basis2* _toBasis_);

        void     setValues(T* _address_);

        uint32_t  size  ();
        uint32_t xSize  ();
        uint32_t ySize  ();
        Basis2*  toBasis();
        Basis2   basis  ();
        
        T*       address(uint32_t _index_ = 0u, uint32_t _jndex_ = 0u);
        T        value  (uint32_t _index_     , uint32_t _jndex_     );

    protected:

        uint32_t _xSize        ;
        uint32_t _ySize        ;
        Basis2*  _toBasis      ;
        T*       _originAddress;
};