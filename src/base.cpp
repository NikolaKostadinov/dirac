#include "../include/base.hpp"

Base::Base()
{
    _size  = 0u;
    _start = 0u;
    _end   = 0u;
}

Base::~Base()
{

}

Base::Base(float _start_, uint32_t _size_,  float _end_)
{
    if (_size_  == 0u  ) throw INF_DX;
    if (_start_ < _end_)
    {
        _size  = _size_ ;
        _start = _start_;
        _end   = _end_  ;
    }
    else if (_start_ > _end_)
    {
        _size  = _size_ ;
        _start = _end_  ;
        _end   = _start_;
    }
    else throw INF_DX;
}

float Base::operator()(uint32_t _index_) const
{
    return x(_index_);
}

uint32_t Base::size() const
{
    return _size;
}

float Base::start() const
{
    return _start;
}

float Base::end() const
{
    return _end;
}

float Base::length() const
{
    return _end - _start;
}

float Base::dx() const
{
    return (_end - _start) / (float) (_size - 1u);
}

float Base::x(uint32_t _index_) const
{
    if   (_index_ < _size) return _start + _index_ * dx();
    else                   throw OUT_OF_BOUNDS           ;
}