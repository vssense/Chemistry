#ifndef _CIRCLE_HPP_INCLUDED
#define _CIRCLE_HPP_INCLUDED

#include "../math/vector2.hpp"
#include "shape.hpp"

class Circle : public Shape
{
public:
    Circle(Vec2<float> center, float radius, Vec2<float> speed = Vec2<float>(0, 0), uint32_t color = kBlue, int weight = 1) :
           Shape(CircleType, center, radius, speed, color, weight) {}
    ~Circle() {}

    virtual void Draw(Renderer* renderer, CoordinateSystem* system) override;
    virtual void CollideFrame(CoordinateSystem* system) override;
    virtual void Move(float dt) override;
};

#endif /* _CIRCLE_HPP_INCLUDED */