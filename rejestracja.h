#ifndef REJESTRACJA_H
#define REJESTRACJA_H

#include <QDialog>

namespace Ui {
class Rejestracja;
}

class Rejestracja : public QDialog
{
    Q_OBJECT

public:
    explicit Rejestracja(QWidget *parent = nullptr);
    ~Rejestracja();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView2_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

private:
    Ui::Rejestracja *ui;
};

#endif // REJESTRACJA_H
