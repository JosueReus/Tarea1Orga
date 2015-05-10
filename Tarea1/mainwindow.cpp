#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Dialog windowvn;
    windowvn.setModal(true);
    windowvn.exec();

}

void MainWindow::on_pushButton_2_clicked()
{
    Tarea2 windowShow;
    windowShow.setModal(true);
    windowShow.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    Tarea3 windowS;
    windowS.setModal(true);
    windowS.exec();

}
