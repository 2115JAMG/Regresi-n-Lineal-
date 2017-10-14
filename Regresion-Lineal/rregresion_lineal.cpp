#include "rregresion_lineal.h"
#include "ui_rregresion_lineal.h"
#include <QString>
#include <qmath.h>
#include <cmath>
#include <qmessagebox.h>

Rregresion_Lineal::Rregresion_Lineal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Rregresion_Lineal)
{
    ui->setupUi(this);//The interface connections to the program are created
    connect(ui->Metodo,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->limpiar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->salir,SIGNAL(clicked()),this,SLOT(close()));
}

Rregresion_Lineal::~Rregresion_Lineal()
{
    delete ui;
}

void Rregresion_Lineal::metodo(){
    QString temp,temp2,temp3,temp4,temp5;
    double x1=ui->x1->value();
    double x2=ui->x2->value();
    double x3=ui->x3->value();
    double x4=ui->x4->value();
    double x5=ui->x5->value();
    double x6=ui->x6->value();
    double x7=ui->x7->value();
    double y1=ui->y1->value();
    double y2=ui->y2->value();
    double y3=ui->y3->value();
    double y4=ui->y4->value();
    double y5=ui->y5->value();
    double y6=ui->y6->value();
    double y7=ui->y7->value();
    double n,SumX,SumY,SumXY,SumXX,X,Y,A0,A1,r,SumYY,a,b,c;

    if(x1==0,x2==0){
        QMessageBox msgBox;
        msgBox.setText("Usted ingreso pocos valores para realizar el método, por favor ingrese 3 o más valores (tanto en X como en Y) para que el programa corra.");//suggests entering more than 3 value in X0 and X1 to start the method
        msgBox.exec();//show a window of warning for entering few values
        }

    n=7;//n value
    SumX=x1+x2+x3+x4+x5+x6+x7;//sum of X
    SumY=y1+y2+y3+y4+y5+y6+y7;//sum of Y
    SumXY=(x1*y1)+(x2*y2)+(x3*y3)+(x4*y4)+(x5*y5)+(x6*y6)+(x7*y7);//sum of the X and Y multiplication
    SumXX=(x1*x1)+(x2*x2)+(x3*x3)+(x4*x4)+(x5*x5)+(x6*x6)+(x7*x7);//sum of X squared
    SumYY=(y1*y1)+(y2*y2)+(y3*y3)+(y4*y4)+(y5*y5)+(y6*y6)+(y7*y7);//sum of Y squared

    X=(SumX/n);//obtaining of X
    Y=(SumY/n);//obtaining of Y

    A1=((n*SumXY)-(SumX*SumY))/((n*SumXX)-(SumX*SumX));//Obtaining A1 to perform the following operations
    A0=(Y-(A1*X));//obtaining A0 to perform the following operations

   // RES=(A0+A1x);//result of the line fuction that is not shown because it would be added

    //SR=((y1-A0-(A1*X))*(y1-A0-(A1*X)))+((y2-A0-(A1*X))*(y2-A0-(A1*X)))+((y3-A0-(A1*X))*(y3-A0-(A1*X)))+((y4-A0-(A1*X))*(y4-A0-A1*X))+((y5-A0-(A1*X))*(y5-A0-(A1*X)))+((y6-A0-(A1*X))*(y6-A0-(A1*X)))+((y7-A0-(A1*X))*(y7-A0-(A1*X)));
    //sum of the values square for S

   // S=(sqrt(SR/(n-2)));//estimated standard error

    r=(((n*SumXY)-(SumX*SumY))/(((sqrt((n*SumXX)-(SumX*SumX))))*((sqrt((n*SumYY)-(SumY*SumY))))));//estimated standard error
    a=1-r;//obtaining the percentage that does not ocucupy points of the graph
    b=r*100;//multiplication by 100 to get the percentage in the coincidence of points
    c=a*100;//multiplication by 100 to get the percentage in the points that there are no matches


temp.append("Ecuación de la linea:\n\t ").append(temp2.setNum(A0)).append(" + ").append(temp3.setNum(A1)).append("x").append("\n\nCoincidencia de los puntos:\n\t ").append(temp4.setNum(b)).append("%").append("\n\nNo existe coincidencia de puntos:\n\t ").append(temp5.setNum(c)).append("%");
ui->textEdit->setText(temp);//Displays the text in the window and the lineal ecuation
}

void Rregresion_Lineal::borrar(){//the spinbox and the text window are cleaned
    ui->x1->setValue(0.0);
    ui->x2->setValue(0.0);
    ui->x3->setValue(0.0);
    ui->x4->setValue(0.0);
    ui->x5->setValue(0.0);
    ui->x6->setValue(0.0);
    ui->x7->setValue(0.0);
    ui->y1->setValue(0.0);
    ui->y2->setValue(0.0);
    ui->y3->setValue(0.0);
    ui->y4->setValue(0.0);
    ui->y5->setValue(0.0);
    ui->y6->setValue(0.0);
    ui->y7->setValue(0.0);
    ui->textEdit->clear();
}





