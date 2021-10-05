#include "shape_collision.hpp"
#include "../graphics/coordinate_system.hpp"

bool IsEqual(float lhs, float rhs)
{
    return rhs - lhs < FLT_EPSILON;
}

bool DetectCollisionCC(Circle* lhs, Circle* rhs)
{
    assert(lhs);
    assert(rhs);

    Vec2<float> centers_vec = rhs->GetCenter() - lhs->GetCenter();

    return centers_vec.GetLength() <= rhs->GetRadius() + lhs->GetRadius();
}

void ResponseCollisionCC(CollisionInfo& info)
{
    Circle* first  = dynamic_cast<Circle*>(*info.first);
    Circle* second = dynamic_cast<Circle*>(*info.second);

    Vec2<float> speed = first->GetSpeed() + second->GetSpeed();
    speed.Normalize();

    speed *= sqrt(first->GetSpeed() * first->GetSpeed() / 2 + second->GetSpeed() * second->GetSpeed() / 2);

    info.manager->AddShape<Square>((first->GetCenter() + second->GetCenter()) / 2,
                                   (first->GetRadius() + second->GetRadius()),
                                    speed,
                                    kLightYellow,
                                    first->GetWeight() + second->GetWeight());

    info.manager->GetShapes().Erase(info.first);
    info.manager->GetShapes().Erase(info.second);
}

void ResponseCollisionCS(CollisionInfo& info)
{
    Circle* circle  = dynamic_cast<Circle*>(*info.first);
    Square* square = dynamic_cast<Square*>(*info.second);

    int m = square->GetWeight();
    Vec2<float> v1 = circle->GetSpeed();
    Vec2<float> v2 = square->GetSpeed();
    Vec2<float> v = square->GetSpeed() + circle->GetSpeed() / (square->GetWeight());
    v.Normalize();
    v *= sqrt((v1  * v1 + m * v2 * v2) / (m + 1));
    square->SetSpeed(v);
    square->SetWeight(circle->GetWeight() + square->GetWeight());
    square->SetRadius(square->GetWeight());

    info.manager->GetShapes().Erase(info.first);
}

void ResponseCollisionSC(CollisionInfo& info)
{
    Swap(info.first, info.second);
    ResponseCollisionCS(info);
}

void ResponseCollisionSS(CollisionInfo& info)
{
    Square* first  = dynamic_cast<Square*>(*info.first);
    Square* second = dynamic_cast<Square*>(*info.second);
    
    int m1 = first->GetWeight();
    int m2 = second->GetWeight();
    Vec2<float> v1 = first->GetSpeed();
    Vec2<float> v2 = second->GetSpeed();

    Vec2<float> speed(sqrt((m1 * v1 * v1 + m2 * v2 * v2) / (m1 + m2)), 0);

    Vec2<float> center = (first->GetCenter() + second->GetCenter()) / 2;

    int weight = m1 + m2;
    float alpha = 2 * M_PI / weight;
    Vec2<float> distance_from_center(1 / sin(M_PI / (weight + 1)), 0);

    for (int i = 0; i < weight; ++i)
    {
        info.manager->AddShape<Circle>(info.manager->GetCoordinateSystem()->CrossOver(center + distance_from_center), 1, speed);
        distance_from_center.Rotate(alpha);
        speed.Rotate(alpha);
    }

    info.manager->GetShapes().Erase(info.first);
    info.manager->GetShapes().Erase(info.second);
}