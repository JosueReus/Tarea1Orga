#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
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

    ofstream myfile ("students.data",ios::in | ios::out | ios::binary | ios::app );



    myfile<<"Numero de cuenta: "<<cuenta<<"\n";
    myfile<<"Nombre: "<<nombre<<"\n";
    myfile<<"Carrera: "<<carrera<<"\n";
    myfile<<"Fecha de Nacimento: "<<fecha<<"\n";
    myfile<<"Universidad: "<<universidad<<"\n";
    myfile<<"\n";
    myfile.flush();
    myfile.close();



    cout<<nombre.compare("hola")<<endl;


    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
}

void Dialog::on_pushButton_3_clicked()
{
    ui->listWidget->clear();

    ifstream read("students.data");

    string line;

    if (read.is_open()){

      while (!read.eof()){
        getline (read,line);
        cout << line << endl;
        QString qstr = QString::fromStdString(line);
        ui->listWidget->addItem(qstr);
      }

      read.close();

    }

}

void Dialog::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    ifstream read("students.data",ios::in|ios::ate|ios::binary);
    QString num="Numero de cuenta: "+ui->lineEdit_6->text();

    if(read.is_open()){
    read.seekg(0);
    string line;
    QString text;
    while(getline(read,line))
    {
        text=QString::fromStdString(line);
        if(text==num)
        {
            for(int x=0;x<5;x++)
            {
                getline(read,line);
                text=QString::fromStdString(line);
                ui->listWidget->addItem(text);

            }
        }
    }
    read.close();
    ui->lineEdit_6->setText("");
    }
}


