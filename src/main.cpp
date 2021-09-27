#include "graphics/window.h"
#include "graphics/renderer.h"
#include "graphics/coordinate_system.h"
#include "shapes/circle.h"

const float kCoordinateSystemWidth  = 100;
const float kCoordinateSystemHeight = 100;

int main()
{
    Window window{};
    Renderer renderer(&window);

    CoordinateSystem system({ 0, kCoordinateSystemWidth },
                            { 0, kCoordinateSystemHeight },
                            { 50, 50, kWindowWidth - 100, kWindowHeight - 100 });
    Circle molecule({ 50, 50 }, 5);
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
        molecule.Draw(&renderer, &system);

        renderer.Present();

        // window.SetTitleFPS(CLOCKS_PER_SEC / (clock() - start + 1));
    }

    SDL_Quit();
    return 0;
}