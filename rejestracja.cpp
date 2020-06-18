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

    query->prepare("select u_name from Uzytkownik");
    query->exec();
    modal->setQuery(*query);
    ui->tableView2->setModel(modal);
    Lacznik.Zamknij();
    qDebug() << (modal->rowCount());
}
