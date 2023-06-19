#ifndef PERSON_H
#define PERSON_H

#include <QDialog>

namespace Ui {
class Person;
}

class Person : public QDialog
{
    Q_OBJECT

public:
    explicit Person(QWidget *parent = nullptr);
    ~Person();

private slots:

    void on_Add_clicked();

    void on_Sort_clicked();

    void on_upgrade_clicked();

    void on_Delete_clicked();

    void on_clearAll_clicked();

    void on_Save_clicked();

    void on_Setup_clicked();

    void on_pushButton_clicked();

private:
    Ui::Person *ui;
};

#endif // PERSON_H
