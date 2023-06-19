#ifndef TOVAR_H
#define TOVAR_H

#include <QDialog>

namespace Ui {
class Tovar;
}

class Tovar : public QDialog
{
    Q_OBJECT

public:
    explicit Tovar(QWidget *parent = nullptr);
    ~Tovar();

private slots:
    void on_Add_clicked();

    void on_upgrade_clicked();

    void on_Delete_clicked();

    void on_Sort_clicked();

    void on_Save_clicked();

    void on_Setup_clicked();

    void on_clearAll_clicked();

    void on_Add_2_clicked();

    void on_upgrade_2_clicked();

    void on_Delete_2_clicked();

    void on_Sort_2_clicked();

    void on_Save_2_clicked();

    void on_Setup_2_clicked();

    void on_clearAll_2_clicked();

    void on_Comeback_clicked();

    void on_Comeback_2_clicked();

private:
    Ui::Tovar *ui;
};

#endif // TOVAR_H
