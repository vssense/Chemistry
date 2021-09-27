#ifndef _SHAPE_H_INCLUDED
#define _SHAPE_H_INCLUDED

class Shape
{
protected:
    enum ShapeType
    {
        CircleType,
        SquareType,
        TriangleType
    };

    Shape(ShapeType type, Point center, float radius, Vec2<float> speed) :
          type_(type), center_(center), radius_(radius), speed_(speed) {}
    virtual ~Shape() {}
public:
    virtual void Draw(Renderer* renderer, CoordinateSystem* system) = 0;
    // virtual void Move();

    // ShapeType GetType  () const { return type_; }

protected:
    ShapeType type_;
    Point center_;
    float radius_;
    Vec2<float> speed_;
};

#endif /* _SHAPE_H_INCLUDED */