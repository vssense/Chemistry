#include "circle.hpp"

void Circle::Draw(Renderer* renderer, CoordinateSystem* system)
{
    assert(renderer);
    assert(system);

    renderer->SetColor(kBlue);

    renderer->DrawCircle({ system->ConvertXCoordinate(center_.x),
                           system->ConvertYCoordinate(center_.y) }, 
                           system->ConvertXProjection(radius_));
}
