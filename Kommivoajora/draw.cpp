#include "draw.h"
#include "vertex.h"
#include "edge.h"

#include <QPainter>
#include <QPaintEvent>
#include <QtMath>

const double pi = 3.1415;
const int size_text = 35;
const int radius = 34;

#include "draw.h"
#include "vertex.h"
#include "edge.h"

#include <QPainter>
#include <QPaintEvent>
#include <QtMath>

Draw::Draw()
{
    shape = QBrush(QColor(250, 250, 250));
    background = QBrush(QColor(250, 250, 250));
    textP = QPen(QColor(0, 0, 0));
    font.setPixelSize(size_text);
}

void Draw::draw(QPainter *draw, QPaintEvent *event)
{
    draw->fillRect(event->rect(),background);
    draw->setBrush(shape);
    draw->setPen(textP);
    draw->setFont(font);

    extern QVector <Vertex> vertexs;
    extern QVector <EDGE> edges;
    for (int i = 0; i < vertexs.size(); i++)
    {
        draw_vertex(vertexs[i].x, vertexs[i].y, draw, QString::number(i+1));
    }
    for (int i = 0; i < edges.size(); i++)
    {
        draw_edge(edges[i].from_x, edges[i].from_y, edges[i].to_x, edges[i].to_y, draw, edges[i].weight, edges[i].type);
    }
}

void Draw::draw_vertex(int x, int y, QPainter *draw, QString name)
{
    draw->drawEllipse(QRectF(x - radius, y - radius, 2 * radius, 2 * radius));
    int text_x = x - radius / 2;
    int text_y = y - size_text / 2;
    draw->drawText(QRect(text_x, text_y, radius, size_text), Qt::AlignCenter, name);
}

void Draw::draw_edge(int x1, int y1, int x2, int y2, QPainter *draw, int weight, int type)
{
    double line_edge = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    int P_x1 = (x2 - x1) / line_edge * radius + x1;
    int P_y1 = (y2 - y1) / line_edge * radius + y1;
    int P_x2 = x2 - (x2 - x1) / line_edge * radius;
    int P_y2 = y2 - (y2 - y1) / line_edge * radius;

    const int LengthEdge = 15;
    const double AngleEdge=pi/8;

    draw->drawLine(P_x1, P_y1, P_x2, P_y2);
    if(type == 1)
    {
        double Point;
        if (x2==P_x2 && P_y2 < y2) {Point = pi * 3 / 2;}

        else if (x2==P_x2 && P_y2>y2) {Point = pi/2;}

        else if (y2==P_y2 && P_x2<x2) {Point = pi;}

        else if (y2==P_y2 && P_x2<x2) {Point = 0;}

        else if (y2<P_y2 && P_x2<x2) {Point = atan(1.0 * (y2-P_y2)/(x2-P_x2)) + pi;}

        else if (y2>P_y2 && P_x2<x2) {Point = atan(1.0 * (y2-P_y2)/(x2-P_x2)) + pi;}

        else if (y2<P_y2 && P_x2>x2) {Point = atan(1.0 * (y2-P_y2)/(x2-P_x2)) + 2 * pi;}

        else if (y2>P_y2 && P_x2>x2) {Point = atan(1.0 * (y2-P_y2)/(x2-P_x2));}

        int a_x1 = cos(Point + AngleEdge) * LengthEdge + P_x2;
        int a_x2 = cos(Point - AngleEdge) * LengthEdge + P_x2;

        int a_y1 = sin(Point + AngleEdge) * LengthEdge + P_y2;
        int a_y2 = sin(Point - AngleEdge) * LengthEdge + P_y2;

        draw->drawLine(P_x2, P_y2, a_x1, a_y1);
        draw->drawLine(P_x2, P_y2, a_x2, a_y2);
    }
    int text_x = (P_x2 + P_x1) / 2 - radius / 2;
    int text_y = (P_y2 + P_y1) / 2 - size_text / 2;
    draw->drawRect(QRectF(text_x, text_y, radius, size_text));
    draw->drawText(QRect(text_x, text_y, radius, size_text), Qt::AlignCenter, QString::number(weight));
}

