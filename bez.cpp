#include "bez.hpp"

static double get_t(int power, const double t_bezje);

Bezje_curve::Bezje_curve(int length, int height, const plot_type& start_p)
{
    path_length = 2 * length;
    path_ = new plot_type[path_length];
    reper_points = new plot_type[4];
    quarter = length / 4;
    bezje_height = height;
    set_reper_points(start_p);
    make_path();

}

void Bezje_curve::set_reper_points(const plot_type& start_p)
{
    reper_points[0] = start_p;
    reper_points[1].x = reper_points[0].x - quarter;
    reper_points[1].y = reper_points[0].y - bezje_height;
    reper_points[2].x = reper_points[0].x - 3 * quarter;
    reper_points[2].y = reper_points[0].y + bezje_height;
    reper_points[3].x = reper_points[0].x - path_length / 2;
    reper_points[3].y = reper_points[0].y;
}

void Bezje_curve::make_path()
{
    double t_bezje {0.0};
    auto ptr = &path_[0];
    int half_path {path_length /2 };
    for(;;ptr++)
    {
        if(ptr == &path_[half_path]) break;
        ptr->x = get_t(3, t_bezje) * reper_points[0].x + 
                3 *  t_bezje * (get_t(2, t_bezje)) * reper_points[1].x + 
                3 * t_bezje * t_bezje * (1 - t_bezje) * reper_points[2].x + 
                t_bezje * t_bezje * t_bezje * reper_points[3].x;
        ptr->y = get_t(3, t_bezje) * reper_points[0].y + 
                3 * t_bezje * (get_t(2, t_bezje)) * reper_points[1].y +
                3 * t_bezje * t_bezje * (1 - t_bezje) * reper_points[2].y +
                t_bezje * t_bezje * t_bezje * reper_points[3].y;
        t_bezje += (1.0 / half_path);
    }
    t_bezje = 0.0;
    ptr = &path_[half_path];
    for(;;ptr++)
    {
        if(ptr == &path_[path_length]) break;
        ptr->x = get_t(3, t_bezje) * reper_points[3].x +
                3 * t_bezje * (get_t(2, t_bezje)) * reper_points[2].x + 
                3 * t_bezje * t_bezje * (1 - t_bezje) * reper_points[1].x +
                t_bezje * t_bezje * t_bezje * reper_points[0].x;
        ptr->y = get_t(3, t_bezje) * reper_points[3].y +
                3 * t_bezje * (get_t(2, t_bezje)) * reper_points[1].y +
                3 * t_bezje * t_bezje * (1 - t_bezje) * reper_points[2].y +
                t_bezje * t_bezje * t_bezje * reper_points[3].y;
        t_bezje += (1.0 / half_path);
    }

}

Bezje_curve::~Bezje_curve()
{
    delete[] reper_points;
    delete[] path_;
    reper_points = nullptr;
    path_ = nullptr;
}

double get_t(int power, const double t_bezje)
{
    if (power == 0) return 1;
    else 
    {
        power -= 1;
        return (1 - t_bezje) * (get_t(power, t_bezje));
    }
}

