#ifndef TAREA2_H
#define TAREA2_H
#include<iostream>
using namespace std;

#include <QDialog>

namespace Ui {
class Tarea2;
}

class Tarea2 : public QDialog
{
    Q_OBJECT

public:
    explicit Tarea2(QWidget *parent = 0);
    ~Tarea2();
    bool matriculado;
    string cuenta;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    int tellIndex(int index);

    void indexRead();


    void on_pushButton_4_clicked();

private:
    Ui::Tarea2 *ui;
};

#endif // TAREA2_H
