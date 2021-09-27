#ifndef _MOLECULE_H_INCLUDED
#define _MOLECULE_H_INCLUDED

#include "../math/vector2.h"
#include "../graphics/renderer.h"
#include "../graphics/coordinate_system.h"
#include "shape.h"

class Circle : public Shape
{
public:
    Circle(Point center, float radius, Vec2<float> speed = Vec2<float>(0, 0)) :
           Shape(CircleType, center, radius, speed) {}
    virtual ~Circle() override {}

    virtual void Draw(Renderer* renderer, CoordinateSystem* system) override;
};

#endif /* _MOLECULE_H_INCLUDED */