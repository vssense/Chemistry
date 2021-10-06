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

    return !IsEqual(centers_vec.GetLength(), rhs->GetRadius() + lhs->GetRadius());
}

void ResponseCollisionCC(ShapeManager* manager, Circle* first, Circle* second)
{
    assert(first);
    assert(second);

    Vec2<float> speed = first->GetSpeed() + second->GetSpeed();
    speed.Normalize();

    speed *= sqrt(first ->GetSpeed() * first ->GetSpeed() / 2 +
                  second->GetSpeed() * second->GetSpeed() / 2);

    manager->AddShape<Square>((first->GetCenter() + second->GetCenter()) / 2,
                               first->GetRadius() + second->GetRadius(),
                               speed,
                               kLightYellow,
                               first->GetWeight() + second->GetWeight());

    first->Delete();
    second->Delete();
}

void ResponseCollisionCS(ShapeManager* manager, Circle* circle, Square* square)
{
    assert(circle);
    assert(square);

    int m = square->GetWeight();
    Vec2<float> v1 = circle->GetSpeed();
    Vec2<float> v2 = square->GetSpeed();
 
    Vec2<float> v = square->GetSpeed() + circle->GetSpeed() / (square->GetWeight());
    v.Normalize();
    v *= sqrt((v1  * v1 + m * v2 * v2) / (m + 1));
    square->SetSpeed(v);
 
    square->SetWeight(circle->GetWeight() + square->GetWeight());
    square->SetRadius(square->GetWeight());

    circle->Delete();
}

void ResponseCollisionSC(ShapeManager* manager, Square* square, Circle* circle)
{
    assert(square);
    assert(circle);

    ResponseCollisionCS(manager, circle, square);
}

void ResponseCollisionSS(ShapeManager* manager, Square* first, Square* second)
{   
    assert(first);
    assert(second);

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
        manager->AddShape<Circle>(manager->GetCoordinateSystem()->CrossOver(center + distance_from_center), 1, speed);
        distance_from_center.Rotate(alpha);
        speed.Rotate(alpha);
    }

    first->Delete();
    second->Delete();
}