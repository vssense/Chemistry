#include "coordinate_system.hpp"

float CoordinateSystem::ConvertXCoordinate(float x)
{
    return rect_.x0 + (rect_.w * (x - x_axis_range_.min) /
                      (x_axis_range_.max - x_axis_range_.min));
}

float CoordinateSystem::ConvertYCoordinate(float y)
{
    return rect_.y0 + (rect_.h * (y_axis_range_.max - y) /
                      (y_axis_range_.max - y_axis_range_.min));
}

float CoordinateSystem::ConvertXProjection(float x)
{
    return (rect_.w * x) / (x_axis_range_.max - x_axis_range_.min);
}

float CoordinateSystem::ConvertYProjection(float y)
{
    return - (rect_.h * y) / (y_axis_range_.max - y_axis_range_.min);
}
