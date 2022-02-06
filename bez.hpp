#ifndef BEZ_HPP
#define BEZ_HPP
#include <iostream>

typedef struct
{
    int x;
    int y;
}plot_type;


class Bezje_curve
{
    plot_type* reper_points;
    plot_type* path_;
    int path_length;
    int quarter;
    int bezje_height;
    
    void set_reper_points(const plot_type& start_point); 
    void make_path();
    public:
    Bezje_curve(int length, int height, const plot_type& start_point);
    ~Bezje_curve();
    Bezje_curve(const Bezje_curve& ) {}
    plot_type* GetPath() {return path_;}
    int GetPathLength() const {return path_length;}
    

};



#endif
