#include "circle.hpp"
#include "../graphics/renderer.hpp"
#include "../graphics/coordinate_system.hpp"

void Circle::Draw(Renderer* renderer, CoordinateSystem* system)
{
    assert(renderer);
    assert(system);

    renderer->SetColor(color_);

    renderer->DrawCircle({system->ConvertXCoordinate(center_.x),
                          system->ConvertYCoordinate(center_.y)}, 
                          system->ConvertXProjection(radius_));
}

void Circle::CollideFrame(CoordinateSystem* system)
{
    assert(system);

    if (system->GetXAxisRange().min >= center_.x - radius_ && speed_.x < 0)
    {
        speed_.x = -speed_.x;
    }

    if (system->GetXAxisRange().max <= center_.x + radius_ && speed_.x > 0)
    {
        speed_.x = -speed_.x;
    }

    if (system->GetYAxisRange().min >= center_.y - radius_ && speed_.y < 0)
    {
        speed_.y = -speed_.y;
    }

    if (system->GetYAxisRange().max <= center_.y + radius_  && speed_.y > 0)
    {
        speed_.y = -speed_.y;
    }
}

void Circle::Move(float dt)
{
    center_ += dt * speed_;
}
