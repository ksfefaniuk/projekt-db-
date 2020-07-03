#include "edycja_serwisowanie.h"
#include "ui_edycja_serwisowanie.h"
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

edycja_serwisowanie::edycja_serwisowanie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edycja_serwisowanie)
{
    ui->setupUi(this);
    MainWindow Lacznik;
}

edycja_serwisowanie::~edycja_serwisowanie()
{
    delete ui;
}

void edycja_serwisowanie::on_pushButton_clicked()         //LADUJ TABELE
{
    MainWindow Lacznik;
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQueryModel * modal2=new QSqlQueryModel();
    QSqlQueryModel * modal3=new QSqlQueryModel();
  //  QSqlQueryModel * modal4=new QSqlQueryModel();
  //  QSqlQueryModel * modal5=new QSqlQueryModel();

    Lacznik.Otworz();
    QSqlQuery* query=new QSqlQuery(Lacznik.servi);
    QSqlQuery* query2=new QSqlQuery(Lacznik.servi);
    QSqlQuery* query3=new QSqlQuery(Lacznik.servi);
 //   QSqlQuery* query4=new QSqlQuery(Lacznik.servi);
   // QSqlQuery* query5=new QSqlQuery(Lacznik.servi);


    query->prepare("select us_id1,marka,model from serwisowanie join urzadzenie on u_id1=u_id join uzytkownik on us_id1=us_id;");        //DO FORMOW
    query->exec();
    query2->prepare("select us_id from uzytkownik order by us_id;");      //DO DROPA
    query2->exec();
    query3->prepare("select us_id,u_name from uzytkownik order by us_id;");      //DO 2 table view
    query3->exec();
   /* query4->prepare("select us_id,u_name from uzytkownik order by us_id;");      //DO 2 table view
    query4->exec();
    query5->prepare("select us_id,u_name from uzytkownik order by us_id;");      //DO 2 table view
    query5->exec(); */
    modal->setQuery(*query);modal->setQuery(*query);
    modal2->setQuery(*query2);modal->setQuery(*query);
    modal3->setQuery(*query3);modal->setQuery(*query);
  //  modal4->setQuery(*query3);modal->setQuery(*query);
   // modal5->setQuery(*query3);modal->setQuery(*query);

    ui->tableView3->setModel(modal);
    ui->combo1->setModel(modal2);
    ui->tableView4->setModel(modal3);

    Lacznik.Zamknij();
    qDebug() << (modal->rowCount());
}


void edycja_serwisowanie::on_pushButton_5_clicked()               //EDYCJA SERWISANTA
{

    MainWindow Lacznik;
    QString  u_name,us_id;
    u_name=ui->combo1->currentText();
    us_id=ui->id_load->text();


    Lacznik.Otworz();
    QSqlQuery query;
    query.prepare("update serwisowanie set us_id1='"+us_id+"' where ser_id='"+us_id+"'");



        if(query.exec())
    {
        QMessageBox::information(this,tr("Edytowanie"),tr("Poprawiono informacje o serwisie!"));
        Lacznik.Zamknij();
    }
        else
        {
            QMessageBox::critical(this,tr("error::"),query.lastError().text());
        }

}

void edycja_serwisowanie::on_tableView3_activated(const QModelIndex &index)         //LOAD TO INDEX
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
    query.prepare("select ser_id,marka,model from serwisowanie join  urzadzenie on u_id1=u_id where marka='"+val1+"' or model ='"+val1+"'");


    if(query.exec())
    {
        while (query.next())
        {
            ui->id_load->setText(query.value(0).toString());
            //ui->k_idd->setText(query.value(1).toString());
            ui->u_marka->setText(query.value(1).toString());
            ui->u_model->setText(query.value(2).toString());

        }

    }
    else
    {
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }
}

void edycja_serwisowanie::on_pushButton_2_clicked()       //DODAWANIE    <<nie mozliwe>>
{
    MainWindow Lacznik;

    QString  k_id,u_model,u_marka;
    //k_id=ui->k_idd->text();
    //u_model=ui->u_model->text();
   // u_marka=ui->u_marka->text();
    //ui->combo1->setModel(modal);
    //ui->combo1->setModel(modal2);


    if(!Lacznik.Otworz())
    {
        QString windowTitle("Aktualizacja bazy klientów");
        qDebug()<<"Błąd łączena z bazą";
        this->setWindowTitle(windowTitle);
        return;
    }

    if(u_model.isEmpty() || u_marka.isEmpty())
    {
        QMessageBox::critical(this,tr("Nie zapisano"),tr("Dodawanie nie możliwe!"));
        return;
    }
    else
    {

    Lacznik.Otworz();
    QSqlQuery query;
    query.prepare("insert into serwisowanie (u_id1,us_id1) values ('"+u_model+"','"+u_marka+"')");         //wprowadzania danych do SQLite

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

void edycja_serwisowanie::on_pushButton_3_clicked()      //EDYCJA  <<nie mozliwa>>
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
    query.prepare("update serwisowanie set marka='"+u_marka+"', model='"+u_model+"' where ser_id='"+u_id+"'");



        if(query.exec())
    {
        QMessageBox::information(this,tr("Edytowanie"),tr("Poprawiono informacje o serwisie!"));
        Lacznik.Zamknij();
    }
        else
        {
            QMessageBox::critical(this,tr("Edytowanie"),tr("Nie mozna edytowac"));
        }

}

void edycja_serwisowanie::on_pushButton_4_clicked()       //USUWANIE
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
        query.prepare("delete from serwisowanie where ser_id='"+u_id+"'");

            if(query.exec())
        {
            QMessageBox::information(this,tr("Usuwanie"),tr("Usunięto dane urządzenie!"));
            Lacznik.Zamknij();
        }
            else
        {
            QMessageBox::critical(this,tr("Błąd"),tr("Nie można usunąć przypisanego serwisu"));
        }
    }
}
