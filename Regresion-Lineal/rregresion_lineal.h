#ifndef RREGRESION_LINEAL_H
#define RREGRESION_LINEAL_H

#include <QMainWindow>

namespace Ui {
class Rregresion_Lineal;
}

class Rregresion_Lineal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Rregresion_Lineal(QWidget *parent = 0);
    ~Rregresion_Lineal();
     double funcion(double x);

private:
    Ui::Rregresion_Lineal *ui;

public slots:
    void metodo();
    void borrar();
};

#endif // RREGRESION_LINEAL_H
