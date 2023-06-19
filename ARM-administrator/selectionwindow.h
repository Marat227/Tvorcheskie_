#ifndef SELECTIONWINDOW_H
#define SELECTIONWINDOW_H

#include <QMainWindow>
#include "person.h"
#include "tovar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class selectionWindow; }
QT_END_NAMESPACE

class selectionWindow : public QMainWindow
{
    Q_OBJECT

public:
    selectionWindow(QWidget *parent = nullptr);
    ~selectionWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::selectionWindow *ui;
};
#endif // SELECTIONWINDOW_H
