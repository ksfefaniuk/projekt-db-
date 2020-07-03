#include "rejestracja.h"
#include "ui_rejestracja.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include "zalogowany.h"
#include "ui_zalogowany.h"

Rejestracja::Rejestracja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rejestracja)
{
    ui->setupUi(this);
    MainWindow Lacznik;
    this->setWindowTitle("Rejestracja");
}

Rejestracja::~Rejestracja()
{
    delete ui;
}

void Rejestracja::on_pushButton_clicked()
{
    MainWindow Lacznik;
    QString u_name,u_pass,u_mail;

    u_name=ui->lineEdit_name->text();                        //wprowadzanie nowych klientow
    u_pass=ui->lineEdit_pass->text();  //
    u_mail=ui->lineEdit_mail->text();

    if(!Lacznik.Otworz())
    {
        qDebug()<<"Błąd łączena z bazą";
        return;
    }


    Lacznik.Otworz();
    QSqlQuery query;
    query.prepare("insert into Uzytkownik (u_name,u_pass,u_mail) values ('"+u_name+"','"+u_pass+"','"+u_mail+"')");         //wprowadzania danych do SQLite

        if(query.exec())
    {
        QMessageBox::information(this,tr("Zapisano"),tr("Dodano nowego użytkownika!"));
        Lacznik.Zamknij();
    }
        else
    {
        QMessageBox::critical(this,tr("Nie zapisano"),tr("Błąd podczas dodawania!"));
    }
}

void Rejestracja::on_pushButton_2_clicked()
{
    MainWindow Lacznik;
    QSqlQueryModel * modal=new QSqlQueryModel();

    Lacznik.Otworz();
    QSqlQuery* query=new QSqlQuery(Lacznik.servi);

    query->prepare("select u_name,u_mail from Uzytkownik order by u_name");
    query->exec();
    modal->setQuery(*query);
    ui->tableView2->setModel(modal);
    Lacznik.Zamknij();
    qDebug() << (modal->rowCount());
}

void Rejestracja::on_tableView2_activated(const QModelIndex &index)          //DO TABELI
{
    QString val=ui->tableView2->model()->data(index).toString();
    MainWindow Lacznik;;

    if(!Lacznik.Otworz())
    {
        qDebug()<<"Bład";
        return;
    }

    Lacznik.Otworz();
    QSqlQuery query;
    query.prepare("select * from uzytkownik where u_name='"+val+"' or u_pass ='"+val+"' or u_mail ='"+val+"'");
    if(query.exec())
    {
        while (query.next())
        {
            ui->us_id->setText(query.value(0).toString());
            ui->lineEdit_name->setText(query.value(1).toString());
            ui->lineEdit_pass->setText(query.value(2).toString());
            ui->lineEdit_mail->setText(query.value(3).toString());


        }
        Lacznik.Zamknij();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }
}

void Rejestracja::on_pushButton_3_clicked()           //EDYCJAAAAAA
{
    MainWindow Lacznik;
    QString u_id,u_name,u_pass,u_mail;
    u_id=ui->us_id->text();
    u_name=ui->lineEdit_name->text();
    u_pass=ui->lineEdit_pass->text();
    u_mail=ui->lineEdit_mail->text();


    if(!Lacznik.Otworz())
    {
        qDebug()<<"Błąd łączena z bazą";
        return;
    }

    Lacznik.Otworz();
    QSqlQuery query;
    query.prepare("update uzytkownik set u_name='"+u_name+"', u_pass='"+u_pass+"', u_mail='"+u_mail+"' where us_id='"+u_id+"'");

        if(query.exec())
    {
        QMessageBox::information(this,tr("Edytowanie"),tr("Poprawiono informacje o użytkowniku!"));
        Lacznik.Zamknij();
    }
        else
    {
        QMessageBox::critical(this,tr("Nie zapisano"),tr("Błąd podczas edytowania!"));
    }
}
