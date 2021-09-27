#ifndef _SWAP_HPP_INCLUDED
#define _SWAP_HPP_INCLUDED

template<typename T>
void Swap(T* lhs, T* rhs)
{
    assert(lhs);
    assert(rhs);

    T tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

#endif /* _SWAP_HPP_INCLUDED */