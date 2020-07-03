#ifndef EDYCJA_SERWISOWANIE_H
#define EDYCJA_SERWISOWANIE_H

#include <QDialog>

namespace Ui {
class edycja_serwisowanie;
}

class edycja_serwisowanie : public QDialog
{
    Q_OBJECT

public:
    explicit edycja_serwisowanie(QWidget *parent = nullptr);
    ~edycja_serwisowanie();

private slots:
    void on_pushButton_clicked();



    void on_pushButton_5_clicked();

    void on_tableView3_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::edycja_serwisowanie *ui;
};

#endif // EDYCJA_SERWISOWANIE_H
