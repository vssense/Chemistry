#ifndef _SHAPE_HPP_INCLUDED
#define _SHAPE_HPP_INCLUDED

#include "../graphics/renderer.hpp"
#include "../math/vector2.hpp"

class Circle;
class Square;

class Shape
{
public:
    enum ShapeType
    {
        CircleType,
        SquareType,

        ShapeNumTypes
    };

    Shape(ShapeType type, Vec2<float> center, float radius, Vec2<float> speed, uint32_t color, int weight) :
          type_(type), center_(center), radius_(radius), speed_(speed), color_(color), weight_(weight)
    {
        is_deleted_ = false;        
    }

    virtual ~Shape() {}
    virtual void Draw(Renderer* renderer, CoordinateSystem* system) = 0;
    virtual void CollideFrame(CoordinateSystem* system) = 0;    
    virtual void Move(float dt) = 0;

    ShapeType GetType  () { return type_  ; }
    float     GetRadius() { return radius_; }
    uint32_t  GetColor () { return color_ ; }
    int       GetWeight() { return weight_; }
    
    const Vec2<float>& GetCenter() { return center_; }
    const Vec2<float>& GetSpeed () { return speed_ ; }

    void SetRadius(float    radius) { radius_ = radius; }
    void SetColor (uint32_t color ) { color_  = color ; }
    void SetWeight(int      weight) { weight_ = weight; }

    void SetCenter(const Vec2<float>& center) { center_ = center; }
    void SetSpeed (const Vec2<float>& speed ) { speed_  = speed ; }

    bool IsDeleted() { return is_deleted_; }
    void Delete() { is_deleted_ = true; }

protected:
    ShapeType type_;
    Vec2<float> center_;
    float radius_;
    Vec2<float> speed_;
    uint32_t color_;
    int weight_;

    bool is_deleted_;
};

#endif /* _SHAPE_HPP_INCLUDED */