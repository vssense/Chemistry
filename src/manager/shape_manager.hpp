#ifndef _SHAPE_MANAGER_HPP_INCLUDED
#define _SHAPE_MANAGER_HPP_INCLUDED

#include "../shapes/shape.hpp"
#include "../list/list.hpp"
#include "../math/swap.hpp"
#include "../shapes/circle.hpp"
#include "../shapes/square.hpp"

class ShapeManager;

struct CollisionInfo
{
    ShapeManager* manager;
    List<Shape*>::Iterator first;
    List<Shape*>::Iterator second;
};

typedef bool (*DetectCollisionFunc)(Shape*, Shape*);
typedef void (*ResponseCollisionFunc)(CollisionInfo&);

#include "shape_collision.hpp"

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
        shapes_.PushBack(shape);
        return shape;
    }

    void DrawShapes();
    void DrawFrame();
    void MoveShapes(float dt);
    List<Shape*>& GetShapes() { return shapes_; }
    CoordinateSystem* GetCoordinateSystem() { return system_; }

private:
    const DetectCollisionFunc DetectCollision[Shape::ShapeNumTypes][Shape::ShapeNumTypes] =
    {
        {(DetectCollisionFunc)DetectCollisionCC, (DetectCollisionFunc)DetectCollisionCC},
        {(DetectCollisionFunc)DetectCollisionCC, (DetectCollisionFunc)DetectCollisionCC}
    };

    const ResponseCollisionFunc ResponseCollision[Shape::ShapeNumTypes][Shape::ShapeNumTypes] =
    {
        {(ResponseCollisionFunc)ResponseCollisionCC, (ResponseCollisionFunc)ResponseCollisionCS},
        {(ResponseCollisionFunc)ResponseCollisionSC, (ResponseCollisionFunc)ResponseCollisionSS}
    };

    Renderer* renderer_;
    CoordinateSystem* system_;
    List<Shape*> shapes_;
};

#endif /* _SHAPE_MANAGER_HPP_INCLUDED */