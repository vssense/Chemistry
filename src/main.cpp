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

    manager.AddShape<Square>(Vec2<float>(10, 10), 7, Vec2<float>(1, 1), kLightYellow, 14);
    manager.AddShape<Square>(Vec2<float>(80, 80), 6, Vec2<float>(-1, -1), kLightYellow, 12);

    // for (int i = 0; i < 15; ++i)
    // {
    //     manager.AddShape<Circle>(Vec2<float>(10 + 4 * i, 10 + 4 * i), 1, Vec2<float>((rand() % 3) - 1, (rand() % 3) - 1));
    // }

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
        manager.MoveShapes(0.005);

        renderer.Present();
        // window.SetTitleFPS(CLOCKS_PER_SEC / (clock() - start + 1));
    }

    SDL_Quit();
    return 0;
}