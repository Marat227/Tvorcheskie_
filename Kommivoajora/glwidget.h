#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include "draw.h"

class GlWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    GlWidget(QWidget *parent);
    void paintEvent(QPaintEvent* event) override;
    void updatedraw();

private:
   Draw* mydraw;

};

#endif // MYGLWIDGET_H
