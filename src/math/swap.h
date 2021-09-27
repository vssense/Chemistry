template<typename T>
void Swap(T* lhs, T* rhs)
{
    assert(lhs);
    assert(rhs);

    T tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}