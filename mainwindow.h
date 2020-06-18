#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include"zalogowany.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase servi;
    void Zamknij()                     //zamykanie polaczenia z servi danych
    {
        servi.close();
        servi.removeDatabase(QSqlDatabase::defaultConnection);
    }


    bool Otworz()                 //otwieranie polaczenia z servi danych
    {
        servi=QSqlDatabase::addDatabase("QSQLITE");
        servi.setDatabaseName("C:/Qt/projekty/db-project/baza2.db");;
        if(!servi.open())
        {
            qDebug()<<("Błąd otwierania!");
            return false;
        }
        else
            qDebug()<<("Połączono!");
            return true;
    }

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
