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

Edycja_klient::Edycja_klient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edycja_klient)
{
    ui->setupUi(this);
    MainWindow Lacznik;
    this->setWindowTitle("Edycja klientów");
}

Edycja_klient::~Edycja_klient()
{
    delete ui;
}

void Edycja_klient::on_pushButton_2_clicked()        //ZALADUJ TABELE
{
    MainWindow Lacznik;
    QSqlQueryModel * modal=new QSqlQueryModel();

    Lacznik.Otworz();
    QSqlQuery* query=new QSqlQuery(Lacznik.servi);

    query->prepare("select imie,nazwisko,telefon,k_mail,adres from klient order by nazwisko");
    query->exec();
    modal->setQuery(*query);
    ui->tableView3->setModel(modal);
    Lacznik.Zamknij();
    qDebug() << (modal->rowCount());
}

void Edycja_klient::on_tableView3_activated(const QModelIndex &index)   //DANE DO FORMULARZY
{
    QString val=ui->tableView3->model()->data(index).toString();
    MainWindow Lacznik;;

    if(!Lacznik.Otworz())
    {
        qDebug()<<"Bład";
        return;
    }

    Lacznik.Otworz();
    QSqlQuery query;
    query.prepare("select * from klient where imie='"+val+"' or nazwisko ='"+val+"' or telefon ='"+val+"' or k_mail ='"+val+"' or adres ='"+val+"'");
    if(query.exec())
    {
        while (query.next())
        {
            ui->k_id_label->setText(query.value(0).toString());
            ui->k_name->setText(query.value(1).toString());
            ui->k_surname->setText(query.value(2).toString());
            ui->k_tel->setText(query.value(3).toString());
            ui->k_mail->setText(query.value(4).toString());
            ui->k_adres->setText(query.value(5).toString());

        }
        Lacznik.Zamknij();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }
}

void Edycja_klient::on_pushButton_5_clicked()          //DODAWANIE KLIENTOW DO BAZY
{
    MainWindow Lacznik;
    QString  imie, nazwisko, telefon, k_mail, adres;
    imie=ui->k_name->text();
    nazwisko=ui->k_surname->text();
    telefon=ui->k_tel->text();
    k_mail=ui->k_mail->text();
    adres=ui->k_adres->text();

    if(!Lacznik.Otworz())
    {
        QString windowTitle("Aktualizacja bazy klientów");
        qDebug()<<"Błąd łączena z bazą";
        this->setWindowTitle(windowTitle);
        return;
    }

    if(imie.isEmpty() || nazwisko.isEmpty() || telefon.isEmpty() || k_mail.isEmpty() || adres.isEmpty())
    {
        QMessageBox::critical(this,tr("Nie zapisano"),tr("Błąd podczas dodawania!"));
        return;
    }
    else
    {

    Lacznik.Otworz();
    QSqlQuery query;
    query.prepare("insert into klient (imie,nazwisko,telefon,k_mail,adres) values ('"+imie+"','"+nazwisko+"','"+telefon+"','"+k_mail+"','"+adres+"')");         //wprowadzania danych do SQLite

        if(query.exec())
    {
        QMessageBox::information(this,tr("Zapisano"),tr("Dodano klienta do bazy!"));
        Lacznik.Zamknij();
    }
        else
    {
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }
    }
}

void Edycja_klient::on_pushButton_6_clicked()      //EDYCJA DANEGO WIERSZA
{
    MainWindow Lacznik;
    QString k_id,imie, nazwisko, telefon, k_mail, adres;
    k_id=ui->k_id_label->text();
    imie=ui->k_name->text();
    nazwisko=ui->k_surname->text();
    telefon=ui->k_tel->text();
    k_mail=ui->k_mail->text();
    adres=ui->k_adres->text();

    if(!Lacznik.Otworz())
    {
        qDebug()<<"Błąd łączena z bazą";
        return;
    }

    Lacznik.Otworz();
    QSqlQuery query;
    query.prepare("update klient set imie='"+imie+"', nazwisko='"+nazwisko+"', telefon='"+telefon+"', k_mail='"+k_mail+"', adres='"+adres+"' where k_id='"+k_id+"'");

        if(query.exec())
    {
        QMessageBox::information(this,tr("Edytowanie"),tr("Poprawiono informacje o kliencie!"));
        Lacznik.Zamknij();
    }
        else
    {
        QMessageBox::critical(this,tr("Nie zapisano"),tr("Błąd podczas edytowania!"));
    }

}


void Edycja_klient::on_pushButton_7_clicked()             //USUWANIE KLIENTA Z BAZY
{
    {
        MainWindow Lacznik;
        QString k_id,imie, nazwisko, telefon, k_mail, adres;
        k_id=ui->k_id_label->text();
        imie=ui->k_name->text();
        nazwisko=ui->k_surname->text();
        telefon=ui->k_tel->text();
        k_mail=ui->k_mail->text();
        adres=ui->k_adres->text();


        if(!Lacznik.Otworz())
        {
            QString windowTitle("Usuwanie klienta");       // ??? nie dziala
            qDebug()<<"Błąd łączena z bazą";
            this->setWindowTitle(windowTitle);
            return;
        }


        Lacznik.Otworz();
        QSqlQuery query;
        query.prepare("delete from klient where k_id='"+k_id+"'");

            if(query.exec())
        {
            QMessageBox::information(this,tr("Usuwanie"),tr("Usunięto dane klienta!"));
            Lacznik.Zamknij();
        }
            else
        {
            QMessageBox::critical(this,tr("Błąd"),tr("Błąd podczas usuwania!"));
        }
    }
}
