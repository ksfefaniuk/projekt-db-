#ifndef EDYCJA_KLIENT_H
#define EDYCJA_KLIENT_H

#include <QDialog>

namespace Ui {
class Edycja_klient;
}

class Edycja_klient : public QDialog
{
    Q_OBJECT

public:
    explicit Edycja_klient(QWidget *parent = nullptr);
    ~Edycja_klient();

private slots:
    void on_pushButton_2_clicked();

    void on_tableView3_activated(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Edycja_klient *ui;
};

#endif // EDYCJA_KLIENT_H
