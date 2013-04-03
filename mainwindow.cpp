#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    relogio = new QTimer(this);
    relogio->setInterval(100);
    relogio->start();
    this->connect(relogio,SIGNAL(timeout()),this,SLOT(update()));
    this->connect(ui->BtnAplicar,SIGNAL(clicked()),this,SLOT(clicado()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    if(ui->BtnRodar->isChecked())
    {
        paletaColorida.updateCor();
        ui->colorFrame->setStyleSheet(QString("background-color: %1").arg(paletaColorida.cor->name()));
    }
}

void MainWindow::clicado()
{
    double v1 = ui->value1->value();
    double v2 = ui->value2->value();
    double v3 = ui->value3->value();
    paletaColorida.updatePorcentagem((v2-v1)/(v3-v1));
    ui->colorFrame->setStyleSheet(QString("background-color: %1").arg(paletaColorida.cor->name()));
}
