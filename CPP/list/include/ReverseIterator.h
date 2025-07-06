#pragma once

namespace bit
{
    template <class Iterator, class Ref, class Ptr>
    struct ReverseIterator
    {
        typedef ReverseIterator<Iterator, Ref, Ptr> Self;
        Iterator _it;

        ReverseIterator(Iterator it) : _it(it) {}

        Ref operator*()
        {
            Iterator tmp = _it;
            return *(--tmp); // 庫中對於反向迭代器的做法是鏡像對稱正向迭代器，因此需要先做前置--後再解引用
        }
        Ptr operator->()
        {
            return &(operator * ());
        }
        Self &operator++()
        {
            --_it;
            return *this;
        }
        Self &operator--()
        {
            ++_it;
            return *this;
        }

        bool operator!=(const Self &s) const
        {
            return _it != s._it;
        }
    };

}