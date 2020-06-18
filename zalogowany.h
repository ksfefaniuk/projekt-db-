#pragma once
#ifndef ZALOGOWANY_H
#define ZALOGOWANY_H

#include <QFileDialog>
#include "mainwindow.h"
#include<QString>
#include<QLabel>

namespace Ui {
class Zalogowany;
}

class Zalogowany : public QDialog
{
    Q_OBJECT

public:
    explicit Zalogowany(QWidget *parent = nullptr);
    ~Zalogowany();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_LOAD_clicked();

    void on_pushButton_LOAD_2_clicked();

    void on_pushButton_LOAD_3_clicked();

    void on_pushButton_LOAD_4_clicked();

    void on_pushButton_LOAD_5_clicked();

    void on_pushButton_LOAD_6_clicked();

private:
    Ui::Zalogowany *ui;
};

#endif // ZALOGOWANY_H
