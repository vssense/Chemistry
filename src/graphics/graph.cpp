#include "graph.hpp"

void Graph::AddPoint(const Vec2<float>& point, CoordinateSystem* system, float dt)
{
    points_.PushBack(point);
    if (points_.Size() > max_num_points_)
    {
        auto it = points_.Begin();
        points_.Erase(it);
        system->MoveXAxisRange(dt);
    }
}

void Graph::Draw(Renderer* renderer, CoordinateSystem* system, uint32_t color)
{
    assert(renderer);
    assert(system);

    renderer->SetColor(color);

    for (auto it = points_.Begin(); it != points_.End(); ++it)
    {
        auto next = it;
        ++next;

        if (next != points_.End())
        {
            renderer->DrawLineCS(system, (*it).x, (*it).y, (*next).x, (*next).y);
        }
    }
}
