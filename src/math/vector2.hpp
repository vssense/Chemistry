#ifndef _VECTOR2_HPP_INCLUDED
#define _VECTOR2_HPP_INCLUDED

#include <assert.h>

template <typename T>
struct Vec2
{
    Vec2(T x, T y) : x(x), y(y) {}
    ~Vec2() {}
    
    Vec2& operator+=(const Vec2& vec);
    Vec2& operator-=(const Vec2& vec);
    Vec2& operator*=(float k);
    Vec2& operator/=(float k);

    Vec2 MulByCoords(const Vec2& lhs, const Vec2& rhs);

    float GetLength();
    void Normalize();

    T x;
    T y;
};

template <typename T>
Vec2<T> operator+(Vec2<T> lhs, const Vec2<T>& rhs)
{
    return lhs += rhs;
}

template <typename T>
Vec2<T> operator-(Vec2<T> lhs, const Vec2<T>& rhs)
{
    return lhs -= rhs;
}

template <typename T>
float operator*(const Vec2<T>& lhs, const Vec2<T>& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

template <typename T>
Vec2<T> operator*(float lhs, Vec2<T> rhs)
{
    return rhs *= lhs;
}

template <typename T>
Vec2<T>& Vec2<T>::operator+=(const Vec2& vec)
{
    x += vec.x;
    y += vec.y;

    return *this;
}

template <typename T>
Vec2<T>& Vec2<T>::operator-=(const Vec2& vec)
{
    x -= vec.x;
    y -= vec.y;

    return *this;
}

template <typename T>
Vec2<T>& Vec2<T>::operator*=(float k)
{
    x *= k;
    y *= k;

    return *this;
}

template <typename T>
Vec2<T>& Vec2<T>::operator/=(float k)
{
    assert(k);

    x /= k;
    y /= k;

    return *this;
}

template <typename T>
Vec2<T> Vec2<T>::MulByCoords(const Vec2& lhs, const Vec2& rhs)
{
    return Vec2(lhs.x * rhs.x, lhs.y * rhs.y);
}

template <typename T>
float Vec2<T>::GetLength()
{
    return sqrt(x * x + y * y);
}

template <typename T>
void Vec2<T>::Normalize()
{
    float length = GetLength();

    if (length != 0)
    {
        *this /= length;
    }
}

#endif /* _VECTOR2_HPP_INCLUDED */