#include "graphics/window.hpp"
#include "graphics/renderer.hpp"
#include "graphics/coordinate_system.hpp"
#include "shapes/circle.hpp"
#include "shapes/square.hpp"
#include "manager/shape_manager.hpp"

const float kCoordinateSystemWidth  = 100;
const float kCoordinateSystemHeight = 100;
// TODO: 1. add chemical reactions
//       2. add event manager
//       3. add buttons
//       4. add graphics
//       5. ShapeManeger : public Shape
int main()
{
    Window window{};
    Renderer renderer(&window);

    CoordinateSystem system({ 0, kCoordinateSystemWidth },
                            { 0, kCoordinateSystemHeight },
                            { 0, 0, kWindowWidth, kWindowHeight });

    ShapeManager manager(&renderer, &system);

    manager.AddShape<Circle>(Vec2<float>(50, 50), 5, Vec2<float>(1, 2), kLightPurple);
    manager.AddShape<Circle>(Vec2<float>(40, 60), 5, Vec2<float>(1, 1.1));
    manager.AddShape<Square>(Vec2<float>(10, 10), 9, Vec2<float>(2, 1));

    bool is_running = true;

    while (is_running)
    {
        SDL_Event event = {};                                    //TODO: EventManager
        while (SDL_PollEvent(&event))
        {
            if ((event.type == SDL_QUIT) || (event.type == SDL_KEYDOWN && event.key.keysym.scancode == 20))
            {
                is_running = false;
            }
        }

        clock_t start = clock();

        renderer.Clear();

        manager.DrawFrame();
        manager.DrawShapes();
        manager.MoveShapes(0.05);

        renderer.Present();

        window.SetTitleFPS(CLOCKS_PER_SEC / (clock() - start + 1));
    }

    SDL_Quit();
    return 0;
}