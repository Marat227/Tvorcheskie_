#include "tsp.h"
#include "vertex.h"
#include "edge.h"

#include <QApplication>

QVector <Vertex> vertexs;
QVector <EDGE> edges;
QVector <QVector<int>> map;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TSP w;
    w.show();
    return a.exec();
}
