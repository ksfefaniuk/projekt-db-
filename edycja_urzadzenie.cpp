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

void edycja_urzadzenie::on_pushButton_clicked()
{
    MainWindow Lacznik;
    QSqlQueryModel * modal=new QSqlQueryModel();

    Lacznik.Otworz();
    QSqlQuery* query=new QSqlQuery(Lacznik.servi);

    query->prepare("select k_id1,marka,model from urzadzenie order by marka;");
    query->exec();
    modal->setQuery(*query);
    ui->tableView4->setModel(modal);
    Lacznik.Zamknij();
    qDebug() << (modal->rowCount());
}

void edycja_urzadzenie::on_pushButton_2_clicked()
{

    MainWindow Lacznik;
    QString  k_id,u_model,u_marka;
    //k_id=ui->k_id->text();
    u_model=ui->u_model->text();
    u_marka=ui->u_marka->text();


    if(!Lacznik.Otworz())
    {
        QString windowTitle("Aktualizacja bazy klientów");
        qDebug()<<"Błąd łączena z bazą";
        this->setWindowTitle(windowTitle);
        return;
    }

    if(u_model.isEmpty() || u_marka.isEmpty()|| k_id.isEmpty())
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
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }
    }
}

void edycja_urzadzenie::on_pushButton_3_clicked()
{
    MainWindow Lacznik;
    QString  k_id1,u_model,u_marka;
    //k_id1=ui->k_id_info->text();
    u_model=ui->u_model->text();
    u_marka=ui->u_marka->text();

    if(!Lacznik.Otworz())
    {
        qDebug()<<"Błąd łączena z bazą";
        return;
    }

    Lacznik.Otworz();
    QSqlQuery query;
    query.prepare("update urzadzenie set marka='"+u_marka+"', model='"+u_model+"' where u_id='"+k_id1+"'");

        if(query.exec())
    {
        QMessageBox::information(this,tr("Edytowanie"),tr("Poprawiono informacje o urzadzeniu!"));
        Lacznik.Zamknij();
    }
        else
    {
        QMessageBox::critical(this,tr("Nie zapisano"),tr("Błąd podczas edytowania!"));
    }

}

void edycja_urzadzenie::on_tableView4_activated(const QModelIndex &index)
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
    query.prepare("select * from urzadzenie where marka='"+val1+"' or model ='"+val1+"'");
    if(query.exec())
    {
        while (query.next())
        {
            //ui->k_id->setText(query.value(1).toString());
            ui->u_marka->setText(query.value(2).toString());
            ui->u_model->setText(query.value(3).toString());

        }
        Lacznik.Zamknij();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }
}
