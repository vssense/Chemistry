#ifndef _SHAPE_H_INCLUDED
#define _SHAPE_H_INCLUDED

#include "../graphics/renderer.hpp"
#include "../math/vector2.hpp"

class Shape
{
public:
    enum ShapeType
    {
        CircleType,
        SquareType,

        ShapeNumTypes
    };

    Shape(ShapeType type, Vec2<float> center, float radius, Vec2<float> speed, uint32_t color) :
          type_(type), center_(center), radius_(radius), speed_(speed), color_(color) {}

    virtual ~Shape() {}
    virtual void Draw(Renderer* renderer, CoordinateSystem* system) = 0;
    virtual void CollideFrame(CoordinateSystem* system) = 0;    
    virtual void Move(float dt) = 0;

    ShapeType GetType  () { return type_; }

protected:
    ShapeType type_;
    Vec2<float> center_;
    float radius_;
    Vec2<float> speed_;
    uint32_t color_;
};

#endif /* _SHAPE_H_INCLUDED */