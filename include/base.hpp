#pragma once

#include "exceptions.h"

class Base
{
    public:

        Base();
        virtual ~Base();

        Base(
            float        _start_,
            unsigned int _size_,
            float        _end_
        );

        unsigned int size();

        float start ();
        float end   ();
        float dx    ();
        float length();

        float x(unsigned int _index_);

    private:

        unsigned int _size;
        float _start;
        float _end;
};