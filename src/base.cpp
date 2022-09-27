#include "../include/base.hpp"

Base::Base()
{
    _size = 0U;
    _start = 0U;
    _end = 0U;
}

Base::~Base()
{

}

Base::Base(float _start_, float _end_, unsigned int _size_)
{
    if (_size_ == 0) throw INF_DX;
    if (_start_ < _end_)
    {
        _size = _size_;
        _start = _start_;
        _end = _end_;
    }
    else if (_start_ > _end_)
    {
        _size = _size_;
        _start = _end_;
        _end = _start_;
    }
    else throw INF_DX;
}

unsigned int Base::size()
{
    return _size;
}

float Base::start()
{
    return _start;
}

float Base::end()
{
    return _end;
}

float Base::length()
{
    return _end - _start;
}

float Base::dx()
{
    return _end - _start / (float) _size;
}