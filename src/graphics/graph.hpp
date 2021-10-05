#ifndef _GRAPH_HPP_INCLUDED
#define _GRAPH_HPP_INCLUDED

#include "../math/vector2.hpp"
#include "renderer.hpp"
#include "coordinate_system.hpp"
#include "../list/list.hpp"

class Graph
{
public:
    Graph(size_t max_num_points) : max_num_points_(max_num_points) {}
    ~Graph() {}

    void AddPoint(const Vec2<float>& point, CoordinateSystem* system, float dt);
    void Draw(Renderer* renderer, CoordinateSystem* system, uint32_t color = kGraphColor);

private:
    List<Vec2<float>> points_;
    size_t max_num_points_;
};

#endif /* _GRAPH_HPP_INCLUDED */