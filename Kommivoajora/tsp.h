#ifndef TSP_H
#define TSP_H

#include <QMainWindow>
#include "glwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TSP; }
QT_END_NAMESPACE

class TSP : public QMainWindow
{
    Q_OBJECT

public:
    TSP(QWidget *parent = nullptr);
    ~TSP();
    GlWidget* openGlW;

private slots:
    void on_Create_vertex_clicked();

    void on_Delete_vertex_clicked();

    void on_Clear_graph_clicked();

    void on_Create_edge_clicked();

    void on_Optimal_rout_clicked();

private:
    Ui::TSP *ui;

};
#endif // TSP_H
