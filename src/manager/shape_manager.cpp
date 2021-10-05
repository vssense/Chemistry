#include "shape_manager.hpp"
#include "../graphics/renderer.hpp"
#include "../graphics/coordinate_system.hpp"
#include <vector>


ShapeManager::~ShapeManager()
{
    for (auto it = shapes_.Begin(); it != shapes_.End(); ++it)
    {
        delete *it;
    }
}

void ShapeManager::DrawShapes()
{
    for (auto it = shapes_.Begin(); it != shapes_.End(); ++it)
    {
        (*it)->Draw(renderer_, system_);
    }
}

void ShapeManager::MoveShapes(float dt)
{
    for (auto first = shapes_.Begin(); first != shapes_.End(); ++first)
    {
        auto second = first;
        ++second;
        for (; second != shapes_.End(); ++second)
        {
            if (!(*first)->IsDeleted() && !(*second)->IsDeleted())
            {
                Shape* shape1 = *first;
                Shape* shape2 = *second;
                if (DetectCollision[shape1->GetType()][shape2->GetType()](shape1, shape2))
                {
                    ResponseCollision[shape1->GetType()][shape2->GetType()](this, shape1, shape2);
                    break;
                }
            }
        }
    }

    for (auto it = shapes_.Begin(); it != shapes_.End();)
    {
        if ((*it)->IsDeleted())
        {
            auto old_it = it;
            ++it;
            shapes_.Erase(old_it);
        }
        else
        {
            ++it;
        }
    }

    for (auto it = shapes_.Begin(); it != shapes_.End(); ++it)
    {
        (*it)->Move(dt);
        (*it)->CollideFrame(system_);
    }
}

void ShapeManager::DrawFrame()
{
    renderer_->SetColor(kWhite);
    renderer_->FillRect(system_->GetRectangle());

    renderer_->SetColor(kRed);

    renderer_->DrawLineCS(system_, system_->GetXAxisRange().min, system_->GetYAxisRange().min,
                                   system_->GetXAxisRange().min, system_->GetYAxisRange().max);

    renderer_->DrawLineCS(system_, system_->GetXAxisRange().min, system_->GetYAxisRange().min,
                                   system_->GetXAxisRange().max, system_->GetYAxisRange().min);

    renderer_->DrawLineCS(system_, system_->GetXAxisRange().max, system_->GetYAxisRange().max,
                                   system_->GetXAxisRange().max, system_->GetYAxisRange().min);
                        
    renderer_->DrawLineCS(system_, system_->GetXAxisRange().max, system_->GetYAxisRange().max,
                                   system_->GetXAxisRange().min, system_->GetYAxisRange().max);
}

float ShapeManager::CalculateKineticEnergy()
{
    float kinetic_energy = 0;

    for (auto it = shapes_.Begin(); it != shapes_.End(); ++it)
    {
        kinetic_energy += (*it)->GetSpeed() * (*it)->GetSpeed() * (*it)->GetWeight() / 2;
    }

    return kinetic_energy;
}