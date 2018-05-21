#include "mainwindow.h"
#include "ui_mainwindow.h"


extern int pendulum_mod;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void showResult(TModel* model);

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    pendulum_mod = 1;
    TModel* Model = new MathPendulum();
    MainWindow::showResult(Model);
    delete Model;

}

void MainWindow::on_pushButton_2_clicked()
{
    pendulum_mod = 2;
    TModel* Model = new MathPendulum();
    MainWindow::showResult(Model);
    delete Model;
}

void MainWindow::on_pushButton_3_clicked()
{
    pendulum_mod = 3;
    TModel* Model = new SpringPendulum();
    MainWindow::showResult(Model);
    delete Model;
}

void MainWindow::on_pushButton_4_clicked()
{
    pendulum_mod = 4;
    TModel* Model = new SpringPendulum();
    MainWindow::showResult(Model);
    delete Model;
}

void MainWindow::on_pushButton_5_clicked()
{
    pendulum_mod = 5;
    TModel* Model = new SpringPendulum();
    MainWindow::showResult(Model);
    delete Model;
}

void MainWindow::showResult(TModel* model){

    TIntegrator* Integrator = new TDormandPrinceIntegrator();
        Integrator->setPrecision(1e-5);
        Integrator->Run( model );

    TMatrix Result = model->getResult();

    QVector<double> t(Result.rowCount()), phi(Result.rowCount());

    for (int i=0; i<Result.rowCount(); i++)
    {
        for (int j=0; j<Result.colCount(); j++)
        {
            if (j == 0) { t[i] = Result(i,j);   }
            if (j == 1) { phi[i] = Result(i,j); }
        }
    }

    ui->Graph->clearGraphs();     //Если нужно, то очищаем все графики
    ui->Graph->addGraph();        //Добавляем один график в Graph
    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
    ui->Graph->graph(0)->setData(t, phi);
    ui->Graph->graph(0)->setPen(QColor(0, 0, 255, 255));   //Цвет линии

    //Подписываем оси Ox и Oy
    ui->Graph->xAxis->setLabel("t");
    ui->Graph->yAxis->setLabel("phi");

    ui->Graph->xAxis->setRange(0, 40);        // Область графика по X
    ui->Graph->yAxis->setRange(-2.5, 2.5);    // Область графика по Y

    ui->Graph->replot();              // Обновляет график

        delete Integrator;
}
