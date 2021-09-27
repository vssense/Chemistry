#ifndef _COORDINATE_SYSTEM_H_INCLUDED
#define _COORDINATE_SYSTEM_H_INCLUDED

#include <math.h>

#include "renderer.h"

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
    const Range&     GetXAxisRange() const { return x_axis_range_; }
    const Range&     GetYAxisRange() const { return y_axis_range_; }

private:
    Rectangle rect_;
    Range x_axis_range_;
    Range y_axis_range_;
};

#endif /* _COORDINATE_SYSTEM_H_INCLUDED */