#ifndef EDYCJA_NAPRAWA_H
#define EDYCJA_NAPRAWA_H

#include <QDialog>

namespace Ui {
class edycja_naprawa;
}

class edycja_naprawa : public QDialog
{
    Q_OBJECT

public:
    explicit edycja_naprawa(QWidget *parent = nullptr);
    ~edycja_naprawa();

private slots:
    void on_pushButton_clicked();

    void on_tableView3_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::edycja_naprawa *ui;
};

#endif // EDYCJA_NAPRAWA_H
