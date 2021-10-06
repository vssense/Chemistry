#include "renderer.hpp"
#include "coordinate_system.hpp"

uint8_t  GetB(uint32_t color);
uint8_t  GetG(uint32_t color);
uint8_t  GetR(uint32_t color);
uint8_t  GetA(uint32_t color);

Renderer::Renderer(Window* window)
{
    assert(window);

    renderer_ = SDL_CreateRenderer(window->GetWindow(), -1, 0);
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer_);
}

void Renderer::DrawLine(float x1, float y1, float x2, float y2)
{
    assert(!SDL_RenderDrawLineF(renderer_, x1, y1, x2, y2));
}

void Renderer::DrawLineCS(CoordinateSystem* system, float x1, float y1, float x2, float y2)
{
    assert(system);

    DrawLine(system->ConvertXCoordinate(x1),
             system->ConvertYCoordinate(y1),
             system->ConvertXCoordinate(x2),
             system->ConvertYCoordinate(y2));
}

void Renderer::DrawCircle(Vec2<float> center, float radius)
{
    assert(radius >= 0);

    float radius_squared = radius * radius;

    for (float x = - radius; x <= radius; x++)
    {
        float y_lenght = sqrt(radius_squared - x * x);
        for (float y = -y_lenght; y <= y_lenght; y++)
        {
            SetPixel(x + center.x, y + center.y);
            SetPixel(x + center.x, -y + center.y);
        }
    }
}

void Renderer::SetColor(uint32_t color)
{
    assert(!SDL_SetRenderDrawColor(renderer_, GetR(color), GetG(color), GetB(color), GetA(color)));
}

void Renderer::SetPixel(float x, float y)
{
    assert(!SDL_RenderDrawPointF(renderer_, x, y));
}

void Renderer::Clear()
{
    SetColor(kWhite);
    assert(!SDL_RenderClear(renderer_));
}

void Renderer::Present()
{
    SDL_RenderPresent(renderer_);
}

void Renderer::DrawVector(float x0, float y0, float pr_x, float pr_y, uint32_t color)
{
    SetColor(color);

    float end_x = x0 + pr_x;
    float end_y = y0 + pr_y;

    DrawLine(x0, y0, end_x, end_y);

    float dx = (pr_x * cos(kEdgesAngle) - pr_y * sin(kEdgesAngle)) / -kEdgesNormalising;
    float dy = (pr_y * cos(kEdgesAngle) + pr_x * sin(kEdgesAngle)) / -kEdgesNormalising;

    DrawLine(end_x, end_y, end_x + dx, end_y + dy);

    dx = (pr_x * cos(kEdgesAngle) + pr_y * sin(kEdgesAngle)) / -kEdgesNormalising;
    dy = (pr_y * cos(kEdgesAngle) - pr_x * sin(kEdgesAngle)) / -kEdgesNormalising;
    
    DrawLine(end_x, end_y, end_x + dx, end_y + dy);

}

void Renderer::FillRect(const Rectangle& rect)
{
    SDL_Rect rectangle = { (int)rect.x0, (int)rect.y0, (int)rect.w, (int)rect.h };
    assert(!SDL_RenderFillRect(renderer_, &rectangle));
}

void Renderer::DrawRect(const Rectangle& rect)
{
    float x0 = rect.x0;
    float y0 = rect.y0;
    float x1 = rect.x0 + rect.w;
    float y1 = rect.y0 + rect.h;
    DrawLine(x0, y0, x1, y0);
    DrawLine(x0, y0, x0, y1);
    DrawLine(x1, y1, x1, y0);
    DrawLine(x1, y1, x0, y1);
}

void Renderer::DrawCoordinateSystem(CoordinateSystem* system)
{
    assert(system);

    DrawBackground(system);
    DrawAuxiliaryLines(system);
    DrawAxes(system);
}

void Renderer::DrawBackground(CoordinateSystem* system)
{
    SetColor(kBackGroundColor);
    FillRect(system->GetRectangle());
}

void Renderer::DrawAuxiliaryLines(CoordinateSystem* system)
{
    assert(system);

    SetColor(kAuxLinesColor);

    const Range& x_axis_range = system->GetXAxisRange();
    const Range& y_axis_range = system->GetYAxisRange();

    for (int x = int(x_axis_range.min); x <= (int)x_axis_range.max; ++x)
    {
        DrawLine(system->ConvertXCoordinate(x),
                 system->ConvertYCoordinate(y_axis_range.min),
                 system->ConvertXCoordinate(x),
                 system->ConvertYCoordinate(y_axis_range.max));
    }

    for (int y = int(y_axis_range.min); y <= (int)y_axis_range.max; ++y)
    {
        DrawLine(system->ConvertXCoordinate(x_axis_range.min),
                 system->ConvertYCoordinate(y),
                 system->ConvertXCoordinate(x_axis_range.max),
                 system->ConvertYCoordinate(y));
    }
}

void Renderer::DrawAxes(CoordinateSystem* system)
{
    assert(system);

    const Range& x_axis_range = system->GetXAxisRange();
    const Range& y_axis_range = system->GetYAxisRange();

    DrawVector(system->ConvertXCoordinate(x_axis_range.min),
               system->ConvertYCoordinate(0),
               system->ConvertXProjection(x_axis_range.max - x_axis_range.min),
               system->ConvertYProjection(0), kAxesColor);

    DrawVector(system->ConvertXCoordinate(0),
               system->ConvertYCoordinate(y_axis_range.min),
               system->ConvertXProjection(0),
               system->ConvertYProjection(y_axis_range.max - y_axis_range.min), kAxesColor);
}

uint8_t GetB(uint32_t color)
{
    return color & 0xFF;
}

uint8_t GetG(uint32_t color)
{
    return (color >> kByteSize) & 0xFF;
}

uint8_t GetR(uint32_t color)
{
    return (color >> (2 * kByteSize)) & 0xFF;
}

uint8_t GetA(uint32_t color)
{
    return (color >> (3 * kByteSize)) & 0xFF;
}
