#include "tarea2.h"
#include "ui_tarea2.h"
#include <fstream>
#include<iostream>
#include <sstream>
#include <string>

using namespace std;

Tarea2::Tarea2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tarea2)
{
    ui->setupUi(this);
}

Tarea2::~Tarea2()
{
    delete ui;
}

void Tarea2::on_pushButton_clicked()
{
    if(ui->checkBox->isChecked())
        matriculado=true;
    else{
        matriculado=false;
    }

    QString name=ui->lineEdit->text();
    int account=ui->lineEdit_2->text().toInt();
    QString major=ui->lineEdit_3->text();
    QString birth=ui->lineEdit_4->text();
    QString College=ui->lineEdit_5->text();

    string nombre=name.toStdString();
    int cuenta=account;
    string carrera=major.toStdString();
    string fecha=birth.toStdString();
    string universidad=College.toStdString();

    ofstream myfile ("students2.data",ios::in | ios::out | ios::binary | ios::app );

    ifstream read("students2.data",ios::in|ios::ate|ios::binary);
    int size=read.tellg();
    read.close();

    ofstream myfile2 ("students2Indexes.data",ios::in | ios::out | ios::binary | ios::app );
    myfile2<<size<<"$";



    myfile<<cuenta<<" ";
    myfile<<nombre<<" ";
    myfile<<carrera<<" ";
    myfile<<fecha<<" ";
    myfile<<universidad<<" ";
    myfile<<matriculado<<" ";
    myfile<<"$";
    myfile.flush();
    myfile.close();

    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->checkBox->setChecked(false);


}

void Tarea2::on_pushButton_2_clicked()
{
    ui->listWidget->clear();


    ifstream read("students2.data");
    ifstream read2("students2Indexes.data");
    string line2;
    if(read2.is_open())
    {

        while (getline (read2,line2,'$').good()){
          cout << line2 << endl;
        }
        read2.close();
    }

    string line;

    if (read.is_open()){

        while (getline (read,line,'$').good()){
          cout << line << endl;
          QString qstr = QString::fromStdString(line);
         ui->listWidget->addItem(qstr);
        }

        read.close();

    }
}

void Tarea2::on_pushButton_3_clicked()
{
    ui->listWidget->clear();
    ifstream in("students2.data",ios::in|ios::ate|ios::binary);

    QString num=ui->lineEdit_6->text();

    in.seekg(0);
    int test=1;

    string li;
    QString qstr;


    while (getline (in,li,' ').good())
    {
      qstr = QString::fromStdString(li);


    if(num==qstr)
    {
        in.seekg(tellIndex(test));
        string line;
                while (getline (in,line,'$').good())
                {
                  QString qstr = QString::fromStdString(line);
                 ui->listWidget->addItem(qstr);
                 break;
                }
                break;
    }

        test++;
        in.seekg(tellIndex(test));


   }








    in.close();
    ui->lineEdit_6->setText("");

}


int Tarea2::tellIndex(int index)
{
    ifstream read2("students2Indexes.data");
    string line2;
    int indice=0;
    if(read2.is_open())
    {
        while (getline (read2,line2,'$').good())
        {
            indice++;

            if(indice==index)
            {

                QString ind=QString::fromStdString(line2);
                int indexToReturn =ind.toInt();
                cout << indexToReturn << endl;
                return indexToReturn;
            }

        }

    }

    read2.close();

return 0;
}

void Tarea2::on_pushButton_4_clicked()
{
    tellIndex(2);
}

void Tarea2::indexRead()
{

}
