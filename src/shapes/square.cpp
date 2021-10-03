#include "square.hpp"
#include "../graphics/renderer.hpp"
#include "../graphics/coordinate_system.hpp"

void Square::Draw(Renderer* renderer, CoordinateSystem* system)
{
    assert(renderer);
    assert(system);

    float half_of_side = radius_;

    renderer->SetColor(color_);

    renderer->FillRect({ system->ConvertXCoordinate(center_.x - half_of_side),
                         system->ConvertYCoordinate(center_.y + half_of_side),
                         system->ConvertXProjection(2 * half_of_side),
                         system->ConvertXProjection(2 * half_of_side) });
}

void Square::CollideFrame(CoordinateSystem* system)
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

void Square::Move(float dt)
{
    center_ += dt * speed_;
}
