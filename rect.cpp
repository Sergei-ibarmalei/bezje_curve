#include "rect.hpp"

Rect_::Rect_(const plot_type& c)
{
    center = c;
    set_upleftcorner();
    rect = new SDL_Rect {upleftcorner.x, upleftcorner.y, RECT_SIDE, RECT_SIDE};
    bezcurve = new Bezje_curve {BEZ_LENGHT, BEZ_HEIGHT, center};


}

Rect_::~Rect_()
{
    delete rect;
    delete bezcurve;
    rect = nullptr;
    bezcurve = nullptr;
}

void Rect_::set_upleftcorner()
{
    upleftcorner.x = center.x - RECT_SIDE/2;
    upleftcorner.y = center.y - RECT_SIDE/2;
}

void Rect_::SetCenter(const plot_type& newc)
{
    center = newc;
    set_upleftcorner();
    rect->x = upleftcorner.x;
    rect->y = upleftcorner.y;
    rect->w = rect->h = RECT_SIDE;

}

