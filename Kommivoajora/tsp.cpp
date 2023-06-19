#include "tsp.h"
#include "ui_tsp.h"
#include "vertex.h"
#include "edge.h"

#include <QPainter>
#include <QtMath>
#include <QIntValidator>
#include <QMessageBox>


const int move_x = 250;
const int move_y = 250;
const double pi = 3.1415;

extern QVector<Vertex> vertexs;
extern QVector<EDGE> edges;
extern QVector<QVector<int>> map;

const int max_num_vertexs = 8;
bool flag[max_num_vertexs] = {0, 0, 0, 0, 0, 0, 0, 0};
int num_vertexs = 0;


TSP::TSP(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TSP)
{
    ui->setupUi(this);
    openGlW = new GlWidget(this);
    ui->verticalLayout->addWidget(openGlW, 0, 0);
    ui->ScreenDeleteVertex->setValidator(new QIntValidator(1,8,this));
    ui->ScreenEdge1->setValidator(new QIntValidator(1,8,this));
    ui->ScreenEdge2->setValidator(new QIntValidator(1,8,this));
    ui->ScreenWeight->setValidator(new QIntValidator(1,99,this));
}

TSP::~TSP()
{
    delete ui;
}

void TSP::on_Create_vertex_clicked()
{
    ui->Route_result->clear();
    ui->Length_route->clear();
    if(num_vertexs != max_num_vertexs)
    {
        int num = 0;
        while(flag[num] != 0 && num < 7)
        {
            num++;
        }
        flag[num] = 1;
        double angel = pi * 3/2 + pi * 2 / max_num_vertexs * num;
        const int radius = 200;
        int num_x = cos(angel) * radius + move_x;
        int num_y = sin(angel) * radius + move_y;

        Vertex vertex(num_x, num_y, num);
        vertexs.push_back(vertex);
        num_vertexs++;

        QVector<int> row(num_vertexs);
        row.fill(0);
        map.append(row);

        for(int i = 0; i < num_vertexs - 1; i++)
        {
            map[i].append(0);
        }

        openGlW->updatedraw();
    }
}



void TSP::on_Delete_vertex_clicked()
{
    ui->Route_result->clear();
    ui->Length_route->clear();
    if(num_vertexs != 0)
    {
        QString del = ui->ScreenDeleteVertex->text();
        int del_index = del.toInt()-1;
        if(del_index == -1)
        {
            QMessageBox::warning(this, "Ошибка", "Заполните пустые поля");
        }
        else if(del_index+1>num_vertexs)
        {
            QMessageBox::warning(this, "Ошибка", "Введенной вершины в графе нет");
        }
        else
        {
            Vertex del_vertex = vertexs[del_index];
            flag[del_vertex.point] = 0;
            vertexs.erase(vertexs.begin() + del_index);
            QVector <EDGE> new_edges;
            for(int i = 0; i < edges.size(); i++)
            {
                if(!(edges[i].from_x == del_vertex.x && edges[i].from_y == del_vertex.y) && !(edges[i].to_x == del_vertex.x && edges[i].to_y == del_vertex.y))
                {
                    new_edges.push_back(edges[i]);
                }
            }
            edges=new_edges;
            for(int i = 0; i < num_vertexs; i++)
            {
                map[i].erase(map[i].begin() + del_index);
            }
            map.erase(map.begin() + del_index);
            num_vertexs--;
            openGlW->updatedraw();
        }
    }
    ui->ScreenDeleteVertex->clear();
}


void TSP::on_Clear_graph_clicked()
{
    num_vertexs=0;
    vertexs.clear();
    edges.clear();
    map.clear();


    vertexs.squeeze();
    edges.squeeze();
    map.squeeze();


    for(int i = 0; i < num_vertexs; i++)
    {
        flag[i]=0;
    }
    ui->ScreenDeleteVertex->clear();
    ui->ScreenEdge1->clear();
    ui->ScreenEdge2->clear();
    ui->ScreenWeight->clear();
    ui->Route_result->clear();
    ui->Length_route->clear();
    openGlW->updatedraw();
    QMessageBox::warning(this, "", "Очистка прошла успешно");
}


void TSP::on_Create_edge_clicked()
{
    ui->Route_result->clear();
    ui->Length_route->clear();
    if(vertexs.size()>1)
    {
        QString new_edge = ui->ScreenEdge1->text();
        int first = new_edge.toInt()-1;
        new_edge = ui->ScreenEdge2->text();
        int second = new_edge.toInt()-1;
        new_edge = ui->ScreenWeight->text();
        int weight = new_edge.toInt();

        if(first == -1 || second == -1 || weight == 0)
        {
            QMessageBox::warning(this, "Ошибка", "Заполните пустые поля");
        }
        else if(first + 1 >num_vertexs || second + 1 > num_vertexs)
        {
            QMessageBox::warning(this, "Ошибка", "Вершина не обнаружена");
        }
        else {
            EDGE edge(vertexs[first].x, vertexs[first].y, vertexs[second].x, vertexs[second].y, weight, 0);
            edges.push_back(edge);
            map[first][second] = weight;
            map[second][first] = weight;
            openGlW->updatedraw();
        }
    }
    ui->ScreenEdge1->clear();
    ui->ScreenEdge2->clear();
    ui->ScreenWeight->clear();
}

void TSP::on_Optimal_rout_clicked()
{
    ui->Route_result->clear();
    ui->Length_route->clear();
    try
    {
        int X = 1000;
        QVector<QVector<int>> matrix = map;
        for(int i = 0; i < num_vertexs; i++)
        {
            for(int j=0; j < num_vertexs; j++)
            {
                if(i==j || matrix[i][j]==0)
                {
                    matrix[i][j] = X;
                }
            }

        }
        QVector<int> first, second;
        bool optimal_rout = true;
        int sum = 0;
        while(optimal_rout)
        {
            for(int i = 0; i < num_vertexs; i++)
            {
                int row_min = X;
                for(int j = 0; j < num_vertexs; j++)
                {
                    row_min=qMin(row_min, matrix[i][j]);
                }
                for(int j = 0; j < num_vertexs; j++)
                {
                    if(row_min != X && matrix[i][j] != X)
                    {
                        matrix[i][j] -= row_min;
                    }
                }
            }
            for(int i = 0; i < num_vertexs; i++)
            {
                int col_min = X;
                for(int j = 0; j < num_vertexs; j++)
                {
                    col_min=qMin(col_min, matrix[j][i]);
                }
                for(int j = 0; j < num_vertexs; j++)
                {
                    if(col_min != X && matrix[j][i] != X)
                    {
                        matrix[j][i] -= col_min;
                    }
                }
            }
            int max = -1;
            int max_x, max_y;
            for(int i = 0; i < num_vertexs; i++)
            {
                for (int j = 0; j < num_vertexs; j++)
                {
                    if(matrix[i][j] == 0)
                    {
                        int row_min = X;
                        for(int k = 0; k < num_vertexs; k++)
                        {
                            if(k != j)
                            {
                                row_min = qMin(row_min, matrix[i][k]);
                            }
                        }
                        int col_min = X;
                        for(int k = 0; k < num_vertexs; k++)
                        {
                            if(k != i)
                            {
                                col_min = qMin(col_min, matrix[k][j]);
                            }
                        }
                        if(row_min + col_min > max)
                        {
                            max = row_min + col_min;
                            max_x = i;
                            max_y = j;
                        }
                    }
                }
            }
            sum += map[max_x][max_y];
            matrix[max_y][max_x] = X;
            for(int i = 0; i < num_vertexs; i++)
            {
                matrix[max_x][i] = X;
                matrix[i][max_y] = X;
            }
            first.push_back(max_x + 1);
            second.push_back(max_y + 1);

            optimal_rout = false;
            for(int i = 0; i < num_vertexs; i++)
            {
                for(int j=0; j < num_vertexs; j++)
                {
                    if(matrix[i][j] != X)
                    {
                        optimal_rout = true;
                    }
                }
            }
        }
        QString path = QString::number(first[0]) + " -> " + QString::number(second[0]);
        int new_first = second[0];
        first.erase(first.begin());
        second.erase(second.begin());
        while(first.size() != 0)
        {
            for(int i = 0; i < first.size(); i++)
            {
                if(first[i] == new_first)
                {
                    path += " -> " + QString::number(second[i]);
                    new_first = second[i];
                    first.erase(first.begin() + i);
                    second.erase(second.begin() + i);
                }
            }
        }
        ui->Route_result->setText(path);
        QString result = "Длина кратчайшего пути = ";
        result += QString::number(sum);
        ui->Length_route->setText(result);
    }
    catch(...)
    {
        QMessageBox::warning(this, "Ошибка", "Невозможно вычислить оптимальный маршрут");
    }
    ui->ScreenDeleteVertex->clear();
    ui->ScreenEdge1->clear();
    ui->ScreenEdge2->clear();
    ui->ScreenWeight->clear();
}

