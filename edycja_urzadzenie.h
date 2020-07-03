#ifndef EDYCJA_URZADZENIE_H
#define EDYCJA_URZADZENIE_H

#include <QDialog>

namespace Ui {
class edycja_urzadzenie;
}

class edycja_urzadzenie : public QDialog
{
    Q_OBJECT

public:
    explicit edycja_urzadzenie(QWidget *parent = nullptr);
    ~edycja_urzadzenie();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableView4_activated(const QModelIndex &index);


    void on_pushButton_4_clicked();


    void on_pushButton_5_clicked();



private:
    Ui::edycja_urzadzenie *ui;
};

#endif // EDYCJA_URZADZENIE_H
