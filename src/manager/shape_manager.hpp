#ifndef _SHAPE_MANAGER_HPP_INCLUDED
#define _SHAPE_MANAGER_HPP_INCLUDED

#include "../shapes/shape.hpp"
#include "../list/list.hpp"

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

private:
    Renderer* renderer_;
    CoordinateSystem* system_;
    List<Shape*> shapes;
};

#endif /* _SHAPE_MANAGER_HPP_INCLUDED */