#include "app.hpp"

class IncreaseTemperature : public IFunctor
{
public:
    IncreaseTemperature() {}
    ~IncreaseTemperature() {}
    virtual void Execute() override
    {
        printf("Click!\n");
    }
};

void App::operator () ()
{
    Window window{};
    Renderer renderer(&window);

    CoordinateSystem shape_manager_system({0, kCoordinateSystemWidth}, {0, kCoordinateSystemHeight}, kShapeManagerSystem);
    ShapeManager shape_manager(&renderer, &shape_manager_system);

    shape_manager.AddShape<Square>(Vec2<float>(10, 10), 7, Vec2<float>(5, 5), kLightYellow, 14);
    shape_manager.AddShape<Square>(Vec2<float>(80, 80), 7, Vec2<float>(-5, -5), kLightYellow, 14);

    float dt = 0.01;

    ButtonManager button_manager(&renderer);
    IncreaseTemperature red_button_functor;
    button_manager.AddButton(kRedButtonRect, reinterpret_cast<IFunctor*>(&red_button_functor), kRed);

    CoordinateSystem graph_system({-1, 30}, {-1, 1000}, kGraphSystem);
    Graph graph((graph_system.GetXAxisRange().max - graph_system.GetXAxisRange().min) / dt);

    bool is_running = true;

    for (float time = 0; is_running; time += dt)
    {
        Event event;
        while (event.PollEvent())
        {
            if ((event.GetType() == Quit) || (event.GetType() == KeyDown && event.GetValue().scancode == 20))
            {
                is_running = false;
            }
            else if (event.GetType() == MouseClick)
            {
                button_manager.OnClick(event.GetValue().coordinates);
            }
        }

        renderer.Clear();

        shape_manager.DrawFrame();
        shape_manager.DrawShapes();
        shape_manager.MoveShapes(dt);

        renderer.DrawCoordinateSystem(&graph_system);
        graph.AddPoint(Vec2<float>(time, shape_manager.CalculateKineticEnergy()), &graph_system, dt); //FIXME: scaling graph
        graph.Draw(&renderer, &graph_system);

        // button_manager.DrawButtons();

        renderer.Present();
    }
}