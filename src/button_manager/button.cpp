#include "button.hpp"
#include <assert.h>

void Button::OnClick(Vec2<int> point)
{
    if (IsInsideRectangle(rect_, Vec2<float>(point.x, point.y)))
    {
        functor_->Execute();
    }
}

void Button::Draw(Renderer* renderer)
{
    assert(renderer);

    renderer->SetColor(color_);
    renderer->FillRect(rect_);

    renderer->SetColor(kBlack);
    renderer->DrawRect(rect_);
}