#ifndef _BUTTON_HPP_INCLUDED
#define _BUTTON_HPP_INCLUDED

#include "functor.hpp"
#include "../math/rectangle.hpp"
#include "../graphics/renderer.hpp"

class Button
{
public:
    Button(const Rectangle& rect, IFunctor* functor, uint32_t color = kGray) :
            rect_(rect), functor_(functor), color_(color) {}
    ~Button() {}

    void OnClick(Vec2<int> point);
    void Draw(Renderer* renderer);
private:
    Rectangle rect_;
    IFunctor* functor_;
    uint32_t color_;
};

#endif /* _BUTTON_HPP_INCLUDED */
