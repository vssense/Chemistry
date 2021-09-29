#ifndef _COORDINATE_SYSTEM_HPP_INCLUDED
#define _COORDINATE_SYSTEM_HPP_INCLUDED

#include <math.h>

#include "renderer.hpp"

const float kStep = 0.01;

struct Range
{
    float min;
    float max;
};

class CoordinateSystem
{
public:
    CoordinateSystem(Range x_axis_range, Range y_axis_range, Rectangle rect) :
                     rect_(rect), x_axis_range_(x_axis_range), y_axis_range_(y_axis_range) {}
    ~CoordinateSystem() {}
    float ConvertXCoordinate(float x);
    float ConvertYCoordinate(float y);
    float ConvertXProjection(float x);
    float ConvertYProjection(float x);

    const Rectangle& GetRectangle () const { return rect_; }

private:
    Rectangle rect_;
    Range x_axis_range_;
    Range y_axis_range_;
};

#endif /* _COORDINATE_SYSTEM_HPP_INCLUDED */