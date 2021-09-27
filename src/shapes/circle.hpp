#ifndef _CIRCLE_HPP_INCLUDED
#define _CIRCLE_HPP_INCLUDED

#include "../math/vector2.hpp"
#include "../graphics/renderer.hpp"
#include "../graphics/coordinate_system.hpp"
#include "shape.hpp"

class Circle : public Shape
{
public:
    Circle(Point center, float radius, Vec2<float> speed = Vec2<float>(0, 0)) :
           Shape(CircleType, center, radius, speed) {}
    virtual ~Circle() override {}

    virtual void Draw(Renderer* renderer, CoordinateSystem* system) override;
};

#endif /* _CIRCLE_HPP_INCLUDED */