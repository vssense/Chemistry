#include "shape_collide.hpp"

void Collide(Circle* lhs, Circle* rhs)
{
    assert(lhs);
    assert(rhs);

    Vec2<float> centers_vec = rhs->center_ - lhs->center_;

    if (centers_vec.GetLength() > rhs->radius_ + lhs->radius_)
    {
        return;
    }

    Swap(rhs->speed_, lhs->speed_);
}
