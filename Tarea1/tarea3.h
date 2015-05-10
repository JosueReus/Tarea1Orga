#ifndef TAREA3_H
#define TAREA3_H

#include <QDialog>
#include<QGraphicsView>

namespace Ui {
class Tarea3;
}

class Tarea3 : public QDialog
{
    Q_OBJECT

public:
    explicit Tarea3(QWidget *parent = 0);
    ~Tarea3();
   int toBit;
   QString texto;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Tarea3 *ui;
};

#endif // TAREA3_H
