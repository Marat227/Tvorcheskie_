#ifndef EDGE_H
#define EDGE_H


class EDGE
{
public:
    EDGE();
    EDGE(int from_X, int from_Y, int to_X, int to_Y, int Weight, int Type);

public:
    int to_x;
    int to_y;

    int from_x;
    int from_y;

    int weight;
    int type;
};

#endif // EDGE_H
