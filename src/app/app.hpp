#ifndef _APP_HPP_INCLUDED
#define _APP_HPP_INCLUDED

#include "../graphics/window.hpp"
#include "../graphics/renderer.hpp"
#include "../graphics/coordinate_system.hpp"
#include "../shapes/circle.hpp"
#include "../shapes/square.hpp"
#include "../shape_manager/shape_manager.hpp"
#include "../graphics/graph.hpp"
#include "../event/event.hpp"
#include "../button_manager/button_manager.hpp"

const float kCoordinateSystemWidth  = 100;
const float kCoordinateSystemHeight = 100;

const Rectangle kShapeManagerSystem = {10, 10, kWindowWidth / 2 - 20, kWindowHeight - 20};
const Rectangle kGraphSystem        = {kWindowWidth / 2 + 10, 10, kWindowWidth / 2 - 20, kWindowHeight / 2 - 20};
const Rectangle kRedButtonRect      = {3 * kWindowWidth / 4, 3 * kWindowHeight / 4, 50, 50};

class App
{
public:
    App() {}
    ~App() {}
    void operator () ();
};

#endif /* _APP_HPP_INCLUDED */