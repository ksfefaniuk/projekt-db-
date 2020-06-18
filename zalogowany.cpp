#include "zalogowany.h"
#include "ui_zalogowany.h"

Zalogowany::Zalogowany(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Zalogowany)
{
    ui->setupUi(this);

}

Zalogowany::~Zalogowany()
{
    delete ui;
}
