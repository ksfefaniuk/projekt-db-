#include "edycja_naprawa.h"
#include "ui_edycja_naprawa.h"
#include "edycja_klient.h"
#include "ui_edycja_klient.h"
#include "rejestracja.h"
#include "ui_rejestracja.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include "zalogowany.h"
#include "ui_zalogowany.h"
#include "edycja_urzadzenie.h"
#include "ui_edycja_urzadzenie.h"

edycja_naprawa::edycja_naprawa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edycja_naprawa)
{
    ui->setupUi(this);
}

edycja_naprawa::~edycja_naprawa()
{
    delete ui;
}

void edycja_naprawa::on_pushButton_clicked()      //LADOWANIE TABELI
{
    MainWindow Lacznik;
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQueryModel * modal2=new QSqlQueryModel();

    Lacznik.Otworz();
    QSqlQuery* query=new QSqlQuery(Lacznik.servi);
    QSqlQuery* query2=new QSqlQuery(Lacznik.servi);

    query->prepare("select u_name,marka,model,data1,opis from naprawa join uzytkownik on us_id2=us_id join urzadzenie on u_id2=u_id order by data1;");
    query->exec();
   // query2->prepare("select k_id from klient order by k_id;");
   // query2->exec();
    modal->setQuery(*query);modal->setQuery(*query);
   // modal2->setQuery(*query2);modal->setQuery(*query);

    ui->tableView3->setModel(modal);
    Lacznik.Zamknij();
    qDebug() << (modal->rowCount());
}

void edycja_naprawa::on_tableView3_activated(const QModelIndex &index)         // DO FORMUALRZY
{
    QString val1=ui->tableView3->model()->data(index).toString();
    MainWindow Lacznik;;

    if(!Lacznik.Otworz())
    {
        qDebug()<<"Bład";
        return;
    }

    Lacznik.Otworz();
    QSqlQuery query;
    query.prepare("select data1,opis,s_id from naprawa,urzadzenie where data1='"+val1+"' or opis='"+val1+"'");


    if(query.exec())
    {
        while (query.next())
        {
            ui->s_data->setText(query.value(0).toString());
            ui->s_opis->setText(query.value(1).toString());
            ui->s_idd->setText(query.value(2).toString());
        }

    }
    else
    {
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }
}

void edycja_naprawa::on_pushButton_3_clicked()        //EDYCJA OPISU
{
    MainWindow Lacznik;
    QString  s_data,s_opis,s_id;
    s_id=ui->s_idd->text();
    s_data=ui->s_data->text();
    s_opis=ui->s_opis->text();
   // u_marka=ui->u_marka->text();

    if(s_data.isEmpty() || s_opis.isEmpty())
    {
        QMessageBox::critical(this,tr("Nie zapisano"),tr("Błąd podczas edytowania!"));
        return;
    }

    Lacznik.Otworz();
    QSqlQuery query;
    query.prepare("update naprawa set data1='"+s_data+"', opis='"+s_opis+"' where s_id='"+s_id+"'");



        if(query.exec())
    {
        QMessageBox::information(this,tr("Edytowanie"),tr("Poprawiono informacje o urzadzeniu!"));
        Lacznik.Zamknij();
    }
        else
        {
            QMessageBox::critical(this,tr("error::"),query.lastError().text());
        }
}

void edycja_naprawa::on_pushButton_2_clicked()   // DODAWANIE <<nie mozliwe>>
{
            QMessageBox::critical(this,tr("Dodawanie"),tr("Brak opcji dodawania!"));
}

void edycja_naprawa::on_pushButton_4_clicked()
{
    {
        MainWindow Lacznik;
        QString u_id,marka,model;
        u_id=ui->s_idd->text();

        if(!Lacznik.Otworz())
        {
            QString windowTitle("Usuwanie danych");
            qDebug()<<"Błąd łączena z bazą";
            this->setWindowTitle(windowTitle);
            return;
        }


        Lacznik.Otworz();
        QSqlQuery query;
        query.prepare("delete from naprawa where s_id='"+u_id+"'");

            if(query.exec())
        {
            QMessageBox::information(this,tr("Usuwanie"),tr("Usunięto dane informacje!"));
            Lacznik.Zamknij();
        }
            else
        {
            QMessageBox::critical(this,tr("Błąd"),tr("Nie można usunąć przypisanego urządzenia"));
        }
    }
}
