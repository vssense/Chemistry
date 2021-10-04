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

    info.manager->AddShape<Square>((first->GetCenter() + second->GetCenter()) / 2,
                                   (first->GetRadius() + second->GetRadius()),
                                   (first->GetSpeed () + second->GetSpeed ()) / 2,
                                    kLightYellow,
                                    first->GetWeight() + second->GetWeight());

    info.manager->GetShapes().Erase(info.first);
    info.manager->GetShapes().Erase(info.second);
}

void ResponseCollisionCS(CollisionInfo& info)
{
    return;
    Circle* circle  = dynamic_cast<Circle*>(*info.first);
    Square* square = dynamic_cast<Square*>(*info.second);

    square->SetWeight(circle->GetWeight() + square->GetWeight());
    square->SetRadius(circle->GetRadius() + square->GetRadius());
    square->SetSpeed(((square->GetWeight() - 1.0) / square->GetWeight()) * square->GetSpeed() + circle->GetSpeed() / (square->GetWeight()));
    
    info.manager->GetShapes().Erase(info.first);
}

void ResponseCollisionSC(CollisionInfo& info)
{
    return;
    Swap(info.first, info.second);
    ResponseCollisionCS(info);
}

void ResponseCollisionSS(CollisionInfo& info)
{
    Square* first  = dynamic_cast<Square*>(*info.first);
    Square* second = dynamic_cast<Square*>(*info.second);
    
    int weight = first->GetWeight() + second->GetWeight();
    float alpha = 2 * M_PI / weight;

    Vec2<float> speed(sqrt(first->GetSpeed() * first->GetSpeed() + second->GetSpeed() * second->GetSpeed()), 0);
    Vec2<float> center = (first->GetCenter() + second->GetCenter()) / 2;
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