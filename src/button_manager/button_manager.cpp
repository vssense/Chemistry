#include "button_manager.hpp"

ButtonManager::ButtonManager(Renderer* renderer) : renderer_(renderer) {}

ButtonManager::~ButtonManager()
{
    for (auto it = buttons_.Begin(); it != buttons_.End(); ++it)
    {
        delete *it;
    }
}

Button* ButtonManager::AddButton(const Rectangle& rect, IFunctor* functor, uint32_t color)
{
    assert(functor);

    Button* button = new Button(rect, functor, color);
    buttons_.PushBack(button);

    return button;
}

void ButtonManager::OnClick(Vec2<int> point)
{
    for (auto it = buttons_.Begin(); it != buttons_.End(); ++it)
    {
        (*it)->OnClick(point);
    }
}

void ButtonManager::DrawButtons()
{
    for (auto it = buttons_.Begin(); it != buttons_.End(); ++it)
    {
        (*it)->Draw(renderer_);
    }
}
