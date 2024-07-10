#include "common.h"

common::common(int y):bird_y(y)
{
//    bird_x=170;
    //bird_y=202;
    bird_y_change(202);
//    bird_x_change(170);
}

void common:: drop()
{
    if(bird_y+2<=403)
    bird_y=bird_y+2;
    else bird_y=403;

    bird_y_change(bird_y);
}


void common:: fly()
{
    if(bird_y-40>=0)
    bird_y=bird_y-40;
    else bird_y=0;
    bird_y_change(bird_y);
}

