#pragma once

#include "engine_exceptions.h"

class Base
{
    public:

        Base();
        virtual ~Base();

        Base(
            float    _start_,
            uint32_t _size_ ,
            float    _end_
        );

        uint32_t size  ();
        float    start ();
        float    end   ();
        float    dx    ();
        float    length();

        float    x(uint32_t _index_);

    private:

        uint32_t _size ;
        float    _start;
        float    _end  ;
};