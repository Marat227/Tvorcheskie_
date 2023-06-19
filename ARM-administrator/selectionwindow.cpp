#include "selectionwindow.h"
#include "ui_selectionwindow.h"
#include "person.h"
#include "tovar.h"

selectionWindow::selectionWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::selectionWindow)
{
    ui->setupUi(this);
}

selectionWindow::~selectionWindow()
{
    delete ui;
}


void selectionWindow::on_pushButton_clicked()
{
    Person *infoDialog = new Person(this); // Создание объекта класса Person
    infoDialog->show(); // Отображение диалогового окна
}

void selectionWindow::on_pushButton_2_clicked()
{
    Tovar *infoDialog = new Tovar(this); // Создание объекта класса Tovar
    infoDialog->show(); // Отображение диалогового окна
}

