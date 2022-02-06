#include "rect.hpp"
#include "consts.hpp"
#include "sdl_init.hpp"
#include <iostream>

static mySDL mysdl;
static SDL_Event e;
static plot_type start_point {S_W-60, S_H/2};
static bool begin = true;

void draw_cross(SDL_Renderer* r);
void Draw_one_rect(SDL_Renderer* r, const SDL_Rect& rect);
void draw_path(SDL_Renderer* r, Rect_& rect, bool& begin);


int main(int argc, char* argv[])
{
    if (!init(mysdl, "Test_Bezje_Curve")) return 1;
    bool quit = false;
    Rect_ rect {start_point};

    SDL_SetRenderDrawColor(mysdl.gRenderer, 0x0, 0x0, 0x0, 0xFF);
    SDL_RenderClear(mysdl.gRenderer);

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT) quit = true;
        }


        draw_cross(mysdl.gRenderer);
        Draw_one_rect(mysdl.gRenderer, rect.GetRect());
        if (begin) 
        {

            //std::cout << "Now\n";
            draw_path(mysdl.gRenderer, rect, begin);
        }
        SDL_RenderPresent(mysdl.gRenderer);



    }
    close(mysdl);
    return 0;
}

void draw_cross(SDL_Renderer* r)
{
    SDL_SetRenderDrawColor(r, 0xFF, 0x0, 0x0, 0xFF);
    SDL_RenderDrawLine(r, 0, S_H/2, S_W, S_H/2);
    SDL_RenderDrawLine(r, S_W/2, 0, S_W/2, S_H);
}

void Draw_one_rect(SDL_Renderer* r, const SDL_Rect& rect)
{
    SDL_SetRenderDrawColor(r, 0x0, 0xFF, 0x0, 0xFF);
    SDL_RenderDrawRect(r, &rect);
}

void draw_path(SDL_Renderer* r, Rect_& rect, bool& begin)
{
    auto ptr = &rect.Get_path()[0];
    auto length = rect.Get_path_length();
    for(;;ptr++)
    {
        if (ptr == &rect.Get_path()[length]) break;
        rect.SetCenter(*ptr);
        Draw_one_rect(r, rect.GetRect());
    }
    begin = false;
    
}