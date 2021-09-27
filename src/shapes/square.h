#ifndef _SQUARE_H_INCLUDED
#define _SQUARE_H_INCLUDED

#include "../math/vector2.h"
#include "../graphics/renderer.h"
#include "../graphics/coordinate_system.h"
#include "shape.h"

class Square : public Shape
{
public:
    Square(Point center, float radius, Vec2<float> speed = Vec2<float>(0, 0)) :
           Shape(SquareType, center, radius, speed) {}
    virtual ~Square() override {}

    virtual void Draw(Renderer* renderer, CoordinateSystem* system) override;
};


#endif /* _SQUARE_H_INCLUDED */