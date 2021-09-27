#include "graphics/window.h"
#include "graphics/renderer.h"
#include "graphics/coordinate_system.h"
#include "shapes/circle.h"
#include "shapes/square.h"

const float kCoordinateSystemWidth  = 100;
const float kCoordinateSystemHeight = 100;

int main()
{
    Window window{};
    Renderer renderer(&window);

    CoordinateSystem system({ 0, kCoordinateSystemWidth },
                            { 0, kCoordinateSystemHeight },
                            { 50, 50, kWindowWidth - 100, kWindowHeight - 100 });
    Circle molecule1({ 50, 50 }, 5);
    Square molecule2({ 10, 10 }, 9 * sqrt(2));
    bool is_running = true;

    while (is_running)
    {
        SDL_Event event = {};
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                is_running = false;
            }
        }

        // clock_t start = clock();

        renderer.Clear();

        renderer.SetColor(kWhite);
        renderer.FillRect(system.GetRectangle());

        molecule1.Draw(&renderer, &system);
        molecule2.Draw(&renderer, &system);

        renderer.Present();

        // window.SetTitleFPS(CLOCKS_PER_SEC / (clock() - start + 1));
    }

    SDL_Quit();
    return 0;
}