#include "glwidget.h"
#include "vertex.h"
#include "edge.h"

#include <QPainter>

extern QVector<Vertex> vertexs;
extern QVector<EDGE> edges;

GlWidget::GlWidget(QWidget *parent)
    :QOpenGLWidget(parent)
{
    mydraw=new Draw;
}

void GlWidget::paintEvent(QPaintEvent *event)
{
    QPainter draw;
    draw.begin(this);
    mydraw->draw(&draw,event);
    draw.end();
}

void GlWidget::updatedraw()
{
   this->update();
}
