#ifndef ZALOGOWANY_H
#define ZALOGOWANY_H

#include <QDialog>

namespace Ui {
class Zalogowany;
}

class Zalogowany : public QDialog
{
    Q_OBJECT

public:
    explicit Zalogowany(QWidget *parent = nullptr);
    ~Zalogowany();

private:
    Ui::Zalogowany *ui;
};

#endif // ZALOGOWANY_H
