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
#include "edycja_serwisowanie.h"
#include "edycja_naprawa.h"

edycja_urzadzenie::edycja_urzadzenie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edycja_urzadzenie)
{
    ui->setupUi(this);
    MainWindow Lacznik;
}

edycja_urzadzenie::~edycja_urzadzenie()
{
    delete ui;
}

void edycja_urzadzenie::on_pushButton_clicked()                   //laduj tabele
{
    MainWindow Lacznik;
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQueryModel * modal2=new QSqlQueryModel();

    Lacznik.Otworz();
    QSqlQuery* query=new QSqlQuery(Lacznik.servi);
    QSqlQuery* query2=new QSqlQuery(Lacznik.servi);

    query->prepare("select k_id1,marka,model from urzadzenie;");
    query->exec();
    query2->prepare("select k_id from klient order by k_id;");
    query2->exec();
    modal->setQuery(*query);modal->setQuery(*query);
    modal2->setQuery(*query2);modal->setQuery(*query);

    ui->tableView4->setModel(modal);
    ui->combo1->setModel(modal2);
    Lacznik.Zamknij();
    qDebug() << (modal->rowCount());
}

void edycja_urzadzenie::on_pushButton_2_clicked()              //DODAWANIE
{

    MainWindow Lacznik;
    QString  k_id,u_model,u_marka;
    //k_id=ui->k_idd->text();
    u_model=ui->u_model->text();
    u_marka=ui->u_marka->text();


    if(!Lacznik.Otworz())
    {
        QString windowTitle("Aktualizacja bazy klientów");
        qDebug()<<"Błąd łączena z bazą";
        this->setWindowTitle(windowTitle);
        return;
    }

    if(u_model.isEmpty() || u_marka.isEmpty())
    {
        QMessageBox::critical(this,tr("Nie zapisano"),tr("Błąd podczas dodawania!"));
        return;
    }
    else
    {

    Lacznik.Otworz();
    QSqlQuery query;
    query.prepare("insert into urzadzenie (model,marka) values ('"+u_model+"','"+u_marka+"')");         //wprowadzania danych do SQLite

        if(query.exec())
    {
        QMessageBox::information(this,tr("Zapisano"),tr("Dodano nowe urządzenie!"));
        Lacznik.Zamknij();
    }
        else
    {
        QMessageBox::critical(this,tr("error::"),tr("Dodawanie nie możliwe!"));
    }
    }
}

void edycja_urzadzenie::on_pushButton_3_clicked()      //EDYTOWANIEW
{
    MainWindow Lacznik;
    QString  u_id,u_model,u_marka;
    //u_id=ui->u_id_info->text();
    u_id=ui->id_load->text();
    u_model=ui->u_model->text();
    u_marka=ui->u_marka->text();

    if(u_model.isEmpty() || u_marka.isEmpty())
    {
        QMessageBox::critical(this,tr("Nie zapisano"),tr("Błąd podczas edytowania!"));
        return;
    }

    Lacznik.Otworz();
    QSqlQuery query;
    query.prepare("update urzadzenie set marka='"+u_marka+"', model='"+u_model+"' where u_id='"+u_id+"'");



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

void edycja_urzadzenie::on_tableView4_activated(const QModelIndex &index)          //do formow
{
    QString val1=ui->tableView4->model()->data(index).toString();
    MainWindow Lacznik;;

    if(!Lacznik.Otworz())
    {
        qDebug()<<"Bład";
        return;
    }

    Lacznik.Otworz();
    QSqlQuery query;
    query.prepare("select * from urzadzenie where k_id1='"+val1+"' or marka='"+val1+"' or model ='"+val1+"'");


    if(query.exec())
    {
        while (query.next())
        {
            ui->id_load->setText(query.value(0).toString());
            //ui->k_idd->setText(query.value(1).toString());
            ui->u_marka->setText(query.value(2).toString());
            ui->u_model->setText(query.value(3).toString());

        }

    }
    else
    {
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }
}


void edycja_urzadzenie::on_pushButton_4_clicked()   //usuwanie
{
    {
        MainWindow Lacznik;
        QString u_id,marka,model;
        u_id=ui->id_load->text();
        marka=ui->u_marka->text();
        model=ui->u_model->text();



        if(!Lacznik.Otworz())
        {
            QString windowTitle("Usuwanie urządzenia");
            qDebug()<<"Błąd łączena z bazą";
            this->setWindowTitle(windowTitle);
            return;
        }


        Lacznik.Otworz();
        QSqlQuery query;
        query.prepare("delete from urzadzenie where u_id='"+u_id+"'");

            if(query.exec())
        {
            QMessageBox::information(this,tr("Usuwanie"),tr("Usunięto dane urządzenie!"));
            Lacznik.Zamknij();
        }
            else
        {
            QMessageBox::critical(this,tr("Błąd"),tr("Nie można usunąć przypisanego urządzenia"));
        }
    }
}



void edycja_urzadzenie::on_pushButton_5_clicked()
{
    MainWindow Lacznik;
    QString  k_id,u_id;
    k_id=ui->combo1->currentText();
    u_id=ui->id_load->text();


    Lacznik.Otworz();
    QSqlQuery query;
    query.prepare("update urzadzenie set k_id1='"+k_id+"' where u_id='"+u_id+"'");


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

