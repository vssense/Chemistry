#ifndef _SQUARE_HPP_INCLUDED
#define _SQUARE_HPP_INCLUDED

#include "../math/vector2.hpp"
#include "shape.hpp"

class Square : public Shape
{
public:
    Square(Vec2<float> center, float radius, Vec2<float> speed = Vec2<float>(0, 0), uint32_t color = kLightYellow) :
           Shape(SquareType, center, radius, speed, color) {}
    ~Square() {}

    virtual void Draw(Renderer* renderer, CoordinateSystem* system) override;
    virtual void CollideFrame(CoordinateSystem* system) override;
    virtual void Move(float dt) override;
};

#endif /* _SQUARE_HPP_INCLUDED */