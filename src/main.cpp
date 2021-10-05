#include "graphics/window.hpp"
#include "graphics/renderer.hpp"
#include "graphics/coordinate_system.hpp"
#include "shapes/circle.hpp"
#include "shapes/square.hpp"
#include "manager/shape_manager.hpp"
#include "graphics/graph.hpp"

const float kCoordinateSystemWidth  = 100;
const float kCoordinateSystemHeight = 100;
// TODO: 1. add chemical reactions +
//       2. add event manager
//       3. add buttons
//       4. add graphics +
//       5. ShapeManager : public Shape
int main()
{
    Window window{};
    Renderer renderer(&window);

    CoordinateSystem manager_system({0, kCoordinateSystemWidth}, {0, kCoordinateSystemHeight},
                                    {10, 10, kWindowWidth / 2 - 20, kWindowHeight - 20});

    ShapeManager manager(&renderer, &manager_system);

    manager.AddShape<Square>(Vec2<float>(10, 10), 7, Vec2<float>(5, 5), kLightYellow, 14);
    manager.AddShape<Square>(Vec2<float>(90, 90), 7, Vec2<float>(-5, -5), kLightYellow, 14);

    float time = 0;
    float dt = 0.01;

    CoordinateSystem graph_system({-1, 30}, {-1, 100},
                                  {kWindowWidth / 2 + 10, 10, kWindowWidth / 2 - 20, kWindowHeight / 2 - 20});
    
    Graph graph((graph_system.GetXAxisRange().max - graph_system.GetXAxisRange().min) / dt);

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
        manager.MoveShapes(dt);
        time += dt;
        renderer.DrawCoordinateSystem(&graph_system);
        graph.AddPoint(Vec2<float>(time, manager.CalculateKineticEnergy() / 10), &graph_system, dt);
        graph.Draw(&renderer, &graph_system);

        renderer.Present();
        // window.SetTitleFPS(CLOCKS_PER_SEC / (clock() - start + 1));
    }

    SDL_Quit();
    return 0;
}