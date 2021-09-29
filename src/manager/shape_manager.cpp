#include "shape_manager.hpp"
#include "../graphics/renderer.hpp"
#include "../graphics/coordinate_system.hpp"

ShapeManager::~ShapeManager()
{
    for (auto it = shapes.Begin(); it != shapes.End(); ++it)
    {
        delete *it;
    }
}

void ShapeManager::DrawShapes()
{
    for (auto it = shapes.Begin(); it != shapes.End(); ++it)
    {
        (*it)->Draw(renderer_, system_);
    }
}

void ShapeManager::DrawFrame()
{
    renderer_->SetColor(kWhite);
    renderer_->FillRect(system_->GetRectangle());
}
