#include "person.h"
#include "ui_person.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>

Person::Person(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Person)
{
    ui->setupUi(this);
}

Person::~Person()
{
    delete ui;
}

void Person::on_Add_clicked()//функция добавления сотрудника
{
    new QListWidgetItem(tr("ФИО: ДР:"),ui->listWidget);
     QString item2Title ("ФИО: ДР: ");
     QListWidgetItem *item2 = new QListWidgetItem;
     item2->setText(item2Title);
     ui->listWidget->addItem(item2);
}


void Person::on_Sort_clicked()//функция сортировки
{
     static Qt::SortOrder order = Qt::AscendingOrder;
     ui->listWidget->sortItems(order);
     if (order == Qt::AscendingOrder) order = Qt::DescendingOrder;
     else order = Qt::AscendingOrder;
}

void Person::on_upgrade_clicked()//функция редактирования
{
    QListWidgetItem *item = ui->listWidget->currentItem();
     if (!item) {
      QMessageBox::warning(this,tr("Ошибка"),tr("Не выбран элемент в списке"));
      return;
     }
     item->setFlags (item->flags () | Qt::ItemIsEditable);
}

void Person::on_Delete_clicked()//функция удаления
{
    QListWidgetItem *item = ui->listWidget->item(ui->listWidget->currentRow());
     if (!item) {
      QMessageBox::warning(this,tr("Ошибка"),tr("Не выбран элемент в списке"));
      return;
     }
     ui->listWidget->takeItem (ui->listWidget->currentRow());
}

void Person::on_clearAll_clicked()//функция очистки списка
{
    ui->listWidget->clear();
}


void Person::on_Save_clicked()//функция сохранения списка
{
    QFile Fperson("person.txt");
     if (!Fperson.open(QFile::WriteOnly | QIODevice::Text)) {
      QMessageBox::critical(this,tr("Ошибка"),tr("Не могу записать в data.txt"));
      return;
     }
     for (int row = 0; row < ui->listWidget->count(); row++) {
      QListWidgetItem *item = ui->listWidget->item(row);
      QTextStream out(&Fperson);
      out << item->text() << "\n";
     }
     Fperson.close();
}


void Person::on_Setup_clicked()//функция загрузки списка из файла
{
    QFile Fperson("person.txt");
     if (!Fperson.open(QIODevice::ReadOnly | QIODevice::Text)) {
      QMessageBox::critical(this,tr("Ошибка"),tr("Не могу прочитать data.txt"));
      return;
     }
     QTextStream in(&Fperson);
     while (!in.atEnd()) {
      QString line = in.readLine();
      QListWidgetItem *item = new QListWidgetItem;
      item->setText(line);
      ui->listWidget->addItem(item);
     }
     Fperson.close();
}


void Person::on_pushButton_clicked() //функция скрытия окна person
{
    hide();
}

