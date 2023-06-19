#include "edge.h"

EDGE::EDGE()
{
    /*
    from_x = 0;
    from_y = 0;
    to_x = 0;
    to_y = 0;
    weight = 0;
    type = 0;
    */
}

EDGE::EDGE(int from_X, int from_Y, int to_X, int to_Y, int Weight, int Type)
{
    from_x = from_X;
    from_y = from_Y;
    to_x = to_X;
    to_y = to_Y;
    weight = Weight;
    type = Type;
}
