#include "zalogowany.h"
#include "ui_zalogowany.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include<QString>
#include "edycja_klient.h"
#include "ui_edycja_klient.h"
#include "edycja_urzadzenie.h"
#include "ui_edycja_urzadzenie.h"
#include "edycja_serwisowanie.h"
#include "edycja_naprawa.h"
#include "edycja_klient.h"



Zalogowany::Zalogowany(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Zalogowany)
{
    ui->setupUi(this);
    MainWindow Lacznik;
//    QPixmap pix("/D:/qt/projekt/urz1.jpg");
//    ui->label_pics->setPixmap(pix);
}

Zalogowany::~Zalogowany()
{
    delete ui;
}

void Zalogowany::on_pushButton_3_clicked()         //otwieranie folderu ze zdjeciami NIEAKTYWNE
{
    /*
    MainWindow Lacznik;
    Lacznik.Otworz();

    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.jpg *.jpeg *. xpm)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Images"),"C:/Qt/projekty/db-project", (tr("Image Files (*.png *.jpg *.jpeg *.xpm)")));
    if(!fileName.isEmpty())
    {
        QImage image(fileName);
        ui->label_pics->setPixmap(QPixmap::fromImage(image));
    }

    Lacznik.Zamknij();
*/
}


void Zalogowany::on_pushButton_4_clicked()         //odpowiada za wlaczenie apki kalendarza NIEAKTYWNE
{
    /*

    MainWindow Lacznik;
    Lacznik.Otworz();

        QProcess *proc = new QProcess;
        QString progName = "C:/Qt/projekty/db-project/kalendarz/myQtCalendar";
        proc->start(progName);
        proc->errorString();
        qDebug()<< " Started the process"<<endl;

    Lacznik.Zamknij();
*/
}


void Zalogowany::on_pushButton_LOAD_clicked() //LADUJE AKTUALNA BAZE DO PROGRAMU
{

    MainWindow Lacznik;
    QSqlQueryModel * modal=new QSqlQueryModel();

    Lacznik.Otworz();
    QSqlQuery* query=new QSqlQuery(Lacznik.servi);

    query->prepare("select k_id,imie,nazwisko,telefon,k_mail,adres from klient");
    query->exec();
    modal->setQuery(*query);
    ui->tableView->setModel(modal);
    Lacznik.Zamknij();
    qDebug() << (modal->rowCount());

}


void Zalogowany::on_pushButton_LOAD_2_clicked()             //POKAZUJE TABELE URZADZENIE
{
    MainWindow Lacznik;
    QSqlQueryModel * modal=new QSqlQueryModel();

    Lacznik.Otworz();
    QSqlQuery* query=new QSqlQuery(Lacznik.servi);

    query->prepare("select distinct imie,nazwisko,marka,model from urzadzenie join klient on k_id1=k_id order by marka");
    query->exec();
    modal->setQuery(*query);
    ui->tableView->setModel(modal);
    Lacznik.Zamknij();
    qDebug() << (modal->rowCount());
}

void Zalogowany::on_pushButton_LOAD_3_clicked()           //POKAZUJE TABELE NAPRAWA
{
    MainWindow Lacznik;
    QSqlQueryModel * modal=new QSqlQueryModel();

    Lacznik.Otworz();
    QSqlQuery* query=new QSqlQuery(Lacznik.servi);

    query->prepare("select u_name,marka,model,data1,opis from naprawa join uzytkownik on us_id2=us_id join urzadzenie on u_id2=u_id order by data1;");
    query->exec();
    modal->setQuery(*query);
    ui->tableView->setModel(modal);
    Lacznik.Zamknij();
    qDebug() << (modal->rowCount());
}

void Zalogowany::on_pushButton_LOAD_4_clicked()                  //POKAZUJE TABELE SERWISOWANIE
{
    MainWindow Lacznik;
    QSqlQueryModel * modal=new QSqlQueryModel();

    Lacznik.Otworz();
    QSqlQuery* query=new QSqlQuery(Lacznik.servi);

    query->prepare("select u_name,marka,model from naprawa left join uzytkownik on us_id2=us_id left join urzadzenie on u_id2=u_id order by u_name;");
    query->exec();
    modal->setQuery(*query);
    ui->tableView->setModel(modal);
    Lacznik.Zamknij();
    qDebug() << (modal->rowCount());
}

void Zalogowany::on_pushButton_LOAD_5_clicked()            //OTWIERA OKNO EDYCJI KLIENTÓW
{

    Edycja_klient edycja;
    edycja.setModal(true);
    edycja.exec();

}


void Zalogowany::on_pushButton_LOAD_6_clicked()  //OTWIERA OKNO EDYCJI URZADZEN
{
    edycja_urzadzenie edycja1;
    edycja1.setModal(true);
    edycja1.exec();
}




void Zalogowany::on_pushButton_LOAD_7_clicked()    //OTWIERA OKNO EDYCJI serwisow
{
    edycja_naprawa edycja2;
    edycja2.setModal(true);
    edycja2.exec();
}

void Zalogowany::on_pushButton_LOAD_8_clicked()
{
    edycja_serwisowanie edycja3;
    edycja3.setModal(true);
    edycja3.exec();
}
