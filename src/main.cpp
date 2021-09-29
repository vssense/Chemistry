#include "graphics/window.hpp"
#include "graphics/renderer.hpp"
#include "graphics/coordinate_system.hpp"
#include "shapes/circle.hpp"
#include "shapes/square.hpp"
#include "manager/shape_manager.hpp"

const float kCoordinateSystemWidth  = 100;
const float kCoordinateSystemHeight = 100;

int main()
{
    Window window{};
    Renderer renderer(&window);

    CoordinateSystem system({ 0, kCoordinateSystemWidth },
                            { 0, kCoordinateSystemHeight },
                            { 50, 50, kWindowWidth - 100, kWindowHeight - 100 });

    ShapeManager manager(&renderer, &system);

    manager.AddShape<Circle>(Point(50.0, 50.0), 5);
    manager.AddShape<Square>(Point(10, 10), 9 * sqrt(2));

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

        // clock_t start = clock();

        renderer.Clear();

        manager.DrawFrame();
        manager.DrawShapes();

        renderer.Present();

        // window.SetTitleFPS(CLOCKS_PER_SEC / (clock() - start + 1));
    }

    SDL_Quit();
    return 0;
}