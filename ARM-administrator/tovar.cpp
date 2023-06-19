#include "tovar.h"
#include "ui_tovar.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>

Tovar::Tovar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tovar)
{
    ui->setupUi(this);
}

Tovar::~Tovar()
{
    delete ui;
}

void Tovar::on_Add_clicked()
{
    new QListWidgetItem(tr("Название: Цена:"),ui->listWidget);
     QString person2Title ("Название: Цена:");
     QListWidgetItem *person2 = new QListWidgetItem;
     person2->setText(person2Title);
     ui->listWidget->addItem(person2);
}


void Tovar::on_upgrade_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
     if (!item) {
      QMessageBox::warning(this,tr("Ошибка"),tr("Не выбран элемент в списке"));
      return;
     }
     item->setFlags (item->flags () | Qt::ItemIsEditable);
}


void Tovar::on_Delete_clicked()
{
    QListWidgetItem *item = ui->listWidget->item(ui->listWidget->currentRow());
     if (!item) {
      QMessageBox::warning(this,tr("Ошибка"),tr("Не выбран элемент в списке"));
      return;
     }
     ui->listWidget->takeItem (ui->listWidget->currentRow());
}


void Tovar::on_Sort_clicked()
{
    static Qt::SortOrder order = Qt::AscendingOrder;
    ui->listWidget->sortItems(order);
    if (order == Qt::AscendingOrder) order = Qt::DescendingOrder;
    else order = Qt::AscendingOrder;
}


void Tovar::on_Save_clicked()
{
    QFile FTovarElectro("TovarElectro.txt");
     if (!FTovarElectro.open(QFile::WriteOnly | QIODevice::Text)) {
      QMessageBox::critical(this,tr("Ошибка"),tr("Не могу записать в TovarElectro.txt"));
      return;
     }
     for (int row = 0; row < ui->listWidget->count(); row++) {
      QListWidgetItem *item = ui->listWidget->item(row);
      QTextStream out(&FTovarElectro);
      out << item->text() << "\n";
     }
     FTovarElectro.close();
}


void Tovar::on_Setup_clicked()
{
    QFile FTovarElectro("TovarElectro.txt");
     if (!FTovarElectro.open(QIODevice::ReadOnly | QIODevice::Text)) {
      QMessageBox::critical(this,tr("Ошибка"),tr("Не могу прочитать TovarElectro.txt"));
      return;
     }
     QTextStream in(&FTovarElectro);
     while (!in.atEnd()) {
      QString line = in.readLine();
      QListWidgetItem *item = new QListWidgetItem;
      item->setText(line);
      ui->listWidget->addItem(item);
     }
     FTovarElectro.close();
}


void Tovar::on_clearAll_clicked()
{
    ui->listWidget->clear();
}

void Tovar::on_Comeback_clicked()
{
    hide();
}

/*********************************************************/

void Tovar::on_Add_2_clicked()
{
    new QListWidgetItem(tr("Название: Цена:"),ui->listWidget_2);
     QString tovar2Title ("Название: Цена:");
     QListWidgetItem *tovar2 = new QListWidgetItem;
     tovar2->setText(tovar2Title);
     ui->listWidget_2->addItem(tovar2);
}


void Tovar::on_upgrade_2_clicked()
{
    QListWidgetItem *item = ui->listWidget_2->currentItem();
     if (!item) {
      QMessageBox::warning(this,tr("Ошибка"),tr("Не выбран элемент в списке"));
      return;
     }
     item->setFlags (item->flags () | Qt::ItemIsEditable);
}


void Tovar::on_Delete_2_clicked()
{
    QListWidgetItem *item = ui->listWidget_2->item(ui->listWidget_2->currentRow());
     if (!item) {
      QMessageBox::warning(this,tr("Ошибка"),tr("Не выбран элемент в списке"));
      return;
     }
     ui->listWidget_2->takeItem (ui->listWidget_2->currentRow());
}


void Tovar::on_Sort_2_clicked()
{
    static Qt::SortOrder order = Qt::AscendingOrder;
    ui->listWidget_2->sortItems(order);
    if (order == Qt::AscendingOrder) order = Qt::DescendingOrder;
    else order = Qt::AscendingOrder;
}


void Tovar::on_Save_2_clicked()
{
    QFile FTovarTechnika("TovarBT.txt");
     if (!FTovarTechnika.open(QFile::WriteOnly | QIODevice::Text)) {
      QMessageBox::critical(this,tr("Ошибка"),tr("Не могу записать в TovarBT.txt"));
      return;
     }
     for (int row = 0; row < ui->listWidget_2->count(); row++) {
      QListWidgetItem *item = ui->listWidget_2->item(row);
      QTextStream out(&FTovarTechnika);
      out << item->text() << "\n";
     }
     FTovarTechnika.close();
}


void Tovar::on_Setup_2_clicked()
{
    QFile FTovarTechnika("TovarBT.txt");
     if (!FTovarTechnika.open(QIODevice::ReadOnly | QIODevice::Text)) {
      QMessageBox::critical(this,tr("Ошибка"),tr("Не могу прочитать TovarBT.txt"));
      return;
     }
     QTextStream in(&FTovarTechnika);
     while (!in.atEnd()) {
      QString line = in.readLine();
      QListWidgetItem *item = new QListWidgetItem;
      item->setText(line);
      ui->listWidget_2->addItem(item);
     }
     FTovarTechnika.close();
}


void Tovar::on_clearAll_2_clicked()
{
    ui->listWidget_2->clear();
}

void Tovar::on_Comeback_2_clicked()
{
    hide();
}

