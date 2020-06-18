#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QLabel>
#include<QFileDialog>
#include "rejestracja.h"
#include "edycja_urzadzenie.h"
#include "ui_edycja_urzadzenie.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QString windowTitle("Logowanie");
    ui->setupUi(this);

    if(!Otworz())
        ui->Status->setText("Błąd otwierania!");                //laczenie z baza danych
    else
        ui->Status->setText("Połączono z bazą danych!");
    this->setWindowTitle(windowTitle);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()       //LOGOWANIE
    {
    QString u_name,u_pass;
    u_name=ui->lineEdit_login->text();
    u_pass=ui->lineEdit_haslo->text();

        if(!Otworz())
        {
            qDebug()<<"Błąd łączena z bazą";
            return;
        }


        Otworz();
        QSqlQuery query;
        if(query.exec("SELECT * FROM Uzytkownik WHERE u_name='"+u_name +"' AND u_pass='"+u_pass+"'"))
        {
            int ile=0;
            while(query.next())
            {
                ile++;
            }
            if(ile==1)
            {
                ui->Status->setText("Logowanie udane!");
                this->hide();
                Zalogowany zalogowany;
                zalogowany.setModal(true);
                zalogowany.exec();

            }
            if(ile<1)
                ui->Status->setText("Logowanie nie udane!");
            if(ile>1)
                ui->Status->setText("Logowanie nie udane!");

        }



    }

void MainWindow::on_pushButton_2_clicked()
{
    QString windowTitle("Rejestracja");
    Rejestracja rejestracja;
    rejestracja.setModal(true);
    rejestracja.exec();
}
