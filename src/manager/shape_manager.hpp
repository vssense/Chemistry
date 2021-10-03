#ifndef _SHAPE_MANAGER_HPP_INCLUDED
#define _SHAPE_MANAGER_HPP_INCLUDED

#include "../shapes/shape.hpp"
#include "../list/list.hpp"
#include "../math/swap.hpp"
#include "../shapes/circle.hpp"

typedef void (*CollideFunc)(Shape*, Shape*);

#include "shape_collide.hpp"

class ShapeManager
{
public:
    ShapeManager(Renderer* renderer, CoordinateSystem* system) :
                 renderer_(renderer), system_(system) {}
    ~ShapeManager();

    template <class ShapeType, class... Args>
    Shape* AddShape(Args... args)
    {
        Shape* shape = new ShapeType(args...);
        shapes.PushBack(shape);
        return shape;
    }

    void DrawShapes();
    void DrawFrame();
    void MoveShapes(float dt);

private:
    const CollideFunc collide[Shape::ShapeNumTypes][Shape::ShapeNumTypes] =
    {
        { (CollideFunc)Collide, (CollideFunc)Collide },
        { (CollideFunc)Collide, (CollideFunc)Collide }
    };

    Renderer* renderer_;
    CoordinateSystem* system_;
    List<Shape*> shapes;
};

#endif /* _SHAPE_MANAGER_HPP_INCLUDED */