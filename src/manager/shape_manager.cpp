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

void ShapeManager::MoveShapes(float dt)
{
    for (auto i = shapes.Begin(); i != shapes.End(); ++i)
    {
        auto j = i;
        ++j;
        for (; j != shapes.End(); ++j)
        {
            collide_func[(*i)->GetType()][(*j)->GetType()](*i, *j);
        }
    }

    for (auto it = shapes.Begin(); it != shapes.End(); ++it)
    {
        (*it)->Move(dt);
        (*it)->CollideFrame(system_);
    }
}

void ShapeManager::DrawFrame()
{
    renderer_->SetColor(kWhite);
    renderer_->FillRect(system_->GetRectangle());
}
