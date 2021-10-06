#ifndef _BUTTON_MANAGER_HPP_INCLUDED
#define _BUTTON_MANAGER_HPP_INCLUDED

#include "button.hpp"
#include "../list/list.hpp"
#include "../graphics/renderer.hpp"
#include "../math/vector2.hpp"

class ButtonManager
{
public:
    explicit ButtonManager(Renderer* renderer);
    ~ButtonManager();

    Button* AddButton(const Rectangle& rect, IFunctor* functor, uint32_t color = kGray);
    void OnClick(Vec2<int> point);
    void DrawButtons();
private:
    List<Button*> buttons_;
    Renderer* renderer_;
};

#endif /* _BUTTON_MANAGER_HPP_INCLUDED */
