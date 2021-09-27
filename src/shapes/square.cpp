#include "square.hpp"

void Square::Draw(Renderer* renderer, CoordinateSystem* system)
{
    assert(renderer);
    assert(system);

    float half_of_side = radius_ / sqrt(2);

    renderer->SetColor(kBlue);

    renderer->FillRect({ system->ConvertXCoordinate(center_.x - half_of_side),
                         system->ConvertYCoordinate(center_.y + half_of_side),
                         system->ConvertXProjection(2 * half_of_side),
                         system->ConvertXProjection(2 * half_of_side) });
}
