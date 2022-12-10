#pragma once

#include "engine_params.h"
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
        Base(
            float    _start_,
            float    _end_  ,
            uint32_t _size_
        );

        float    operator()   (uint32_t _index_)                                                   const;

        uint32_t size         (                )                                                   const;
        float    start        (                )                                                   const;
        float    end          (                )                                                   const;
        float    delta        (                )                                                   const;
        float    delta2       (                )                                                   const;
        float    length       (                )                                                   const;
        float    coord        (uint32_t _index_)                                                   const;

        bool     isIn         (uint32_t _index_, bool _includes_bounds_ = DEFAULT_INCLUDES_BOUNDS) const;
        bool     isOut        (uint32_t _index_, bool _includes_bounds_ = DEFAULT_INCLUDES_BOUNDS) const;
        bool     isForbidden  (uint32_t _index_)                                                   const;
        bool     isStartCloser(uint32_t _index_)                                                   const;
        bool     isEndCloser  (uint32_t _index_)                                                   const;

    private:

        uint32_t _size ;
        float    _start;
        float    _end  ;
};