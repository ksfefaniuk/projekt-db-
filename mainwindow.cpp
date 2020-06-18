#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    servi = QSqlDatabase::addDatabase("QSQLITE");
    servi.setDatabaseName("C:/Qt/projekty/db-project/baza.db");

    if(!servi.open())
        ui->label1->setText("Fail");
    else
        ui->label1->setText("Good");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString u_name,u_pass;
    u_name=ui->lineEdit_login->text();
    u_pass=ui->lineEdit_password->text();

    if(!servi.isOpen()) {
        qDebug()<<"Błąd otwierania!";
        return;
    }

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
            ui->label1->setText("Logowanie udane!");
            this->hide();
            Zalogowany zalogowany;
            zalogowany.setModal(true);
            zalogowany.exec();

        }
        if(ile<1)
            ui->label1->setText("Logowanie nie udane!");
        if(ile>1)
            ui->label1->setText("Logowanie nie udane!");

    }



}
