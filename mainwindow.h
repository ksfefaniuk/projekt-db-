#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "zalogowany.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase servi;

    void Zamknij()                     //zamykanie polaczenia z baza danych
    {
        servi.close();
        servi.removeDatabase(QSqlDatabase::defaultConnection);
    }


    bool Otworz()                 //otwieranie polaczenia z baza danych
    {
        servi=QSqlDatabase::addDatabase("QSQLITE");
        servi.setDatabaseName("C:/Qt/projekty/projekt/project_v.sql");
        if(!servi.open())
        {
            qDebug()<<("Błąd otwierania!");
            return false;
        }
        else
            qDebug()<<("Połączono!");
            return true;
    }
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H








