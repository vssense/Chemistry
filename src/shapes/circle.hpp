#ifndef _CIRCLE_HPP_INCLUDED
#define _CIRCLE_HPP_INCLUDED

#include "../math/vector2.hpp"
#include "shape.hpp"

class Circle : public Shape
{
public:
    Circle(Vec2<float> center, float radius, Vec2<float> speed = Vec2<float>(0, 0), uint32_t color = kBlue) :
           Shape(CircleType, center, radius, speed, color) {}
    ~Circle() {}

    virtual void Draw(Renderer* renderer, CoordinateSystem* system) override;
    virtual void CollideFrame(CoordinateSystem* system) override;
    virtual void Move(float dt) override;

    friend void Collide(Circle* lhs, Circle* rhs);
};

#endif /* _CIRCLE_HPP_INCLUDED */