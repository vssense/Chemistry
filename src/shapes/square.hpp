#ifndef _SQUARE_HPP_INCLUDED
#define _SQUARE_HPP_INCLUDED

#include "../math/vector2.hpp"
#include "../graphics/renderer.hpp"
#include "../graphics/coordinate_system.hpp"
#include "shape.hpp"

class Square : public Shape
{
public:
    Square(Point center, float radius, Vec2<float> speed = Vec2<float>(0, 0)) :
           Shape(SquareType, center, radius, speed) {}
    virtual ~Square() override {}

    virtual void Draw(Renderer* renderer, CoordinateSystem* system) override;
};


#endif /* _SQUARE_HPP_INCLUDED */