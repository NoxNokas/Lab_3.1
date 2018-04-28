#include "mainwindow.h"
#include <QApplication>
#include <tchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "array.h"


#define max(a, b) ( ( (a) > (b) ) ? (a) : (b) )
#define min(a, b) ( ( (a) < (b) ) ? (a) : (b) )


#include "integrator.h"
#include "custom.h"



/*	Аргумент маятника	*/
int mode = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

  /*  delete Model_MathPendulum_ideal;
    delete Integrator_MathPendulum_ideal;

    delete Model_MathPendulum_real;
    delete Integrator_MathPendulum_real;

    delete Model_SpringPendulum_ideal;
    delete Integrator_SpringPendulum_ideal;

    delete Model_SpringPendulum_real_ViscousFriction;
    delete Integrator_SpringPendulum_real_ViscousFriction;

    delete Model_SpringPendulum_real_FrictionSliding;
    delete Integrator_SpringPendulum_real_FrictionSliding;               */


    return a.exec();
}
