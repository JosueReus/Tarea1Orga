#include "tarea3.h"
#include "ui_tarea3.h"
#include <fstream>
#include<string>
#include<sstream>
#include<QGraphicsTextItem>
#include<string.h>
#include <bitset>
#include<iostream>

#define CLEARBIT(a,pos) (a^(1<<pos) )

using namespace std;
std::bitset<32> b;

int foo [3] = { 1, 2, 3 };



Tarea3::Tarea3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tarea3)
{
    ui->setupUi(this);

}

Tarea3::~Tarea3()
{
    delete ui;
}

void Tarea3::on_pushButton_clicked()
{
    ui->listWidget->clear();
    texto=ui->lineEdit->text();
    toBit=texto.toInt();
    std::bitset<32> b(toBit);
    std::cout << "Your number in binary is " <<  b << std::endl;


    string mystring = b.to_string<char,char_traits<char>,allocator<char> >();

    QString show=QString::fromStdString(mystring);

     ui->listWidget->addItem(show);
     ofstream myfile2 ("bits",ios::out);
     myfile2<<mystring<<"$";

     myfile2.close();
}

void Tarea3::on_pushButton_2_clicked()
{


    QString hey=ui->lineEdit_2->text();



    ifstream read2("bits");
    string line2;
    string numero;
    if(read2.is_open())
    {
        while (getline (read2,line2,'$').good())
        {
               QString ind=QString::fromStdString(line2);
               numero=ind.toStdString();
        }

    }
    read2.close();



    int indice=hey.toInt();
    std::bitset<32> b(numero);

    b.flip(indice-1);






    string mystring = b.to_string<char,char_traits<char>,allocator<char> >();
    QString show=QString::fromStdString(mystring);

     ui->listWidget->addItem(show);

     ofstream myfile2 ("bits",ios::out);
     std::cout<<mystring<<endl;
     myfile2<<mystring<<"$";

     myfile2.close();



//        in_use = in_use ^ 1<<toBit;



}
