#ifndef RECT_HPP
#define RECT_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "bez.hpp"
#include "consts.hpp"


class Rect_
{
    plot_type center;
    plot_type upleftcorner;
    
    SDL_Rect* rect;
    Bezje_curve* bezcurve = nullptr;
    void set_upleftcorner();

    public:
    Rect_(const plot_type& c);
    Rect_(const Rect_& ) {}
    ~Rect_();
    void SetCenter(const plot_type& newc);
    SDL_Rect& GetRect() {return *rect;}
    plot_type* Get_path() {return bezcurve->GetPath();}
    int Get_path_length() const {return bezcurve->GetPathLength();}
};


#endif