#include "mainwindow.h"

#include<QLayout>

#include<QHBoxLayout>

#include<QVBoxLayout>

#include<QLineEdit>

#include"hill.h"
#include"playfair.h"
#include"vigenere.h"
#include"caesar.h"



ClassicEncrypt::ClassicEncrypt()

{

label_0=new QLabel("INPUT KEY HERE:");
label_1=new QLabel("INPUT TEXT HERE:");
label_2=new QLabel("RESULT COMES HERE:");
lineEditor_0=new QLineEdit;
lineEditor_1=new QLineEdit;
lineEditor_2=new QLineEdit;

p="";

c="";

button_0=new QPushButton("caesar encrypt");

button_1=new QPushButton("caesar decrypt");

button_2=new QPushButton("playfair encrypt");

button_3=new QPushButton("playfair decrypt");

button_4=new QPushButton("hill encrypt");

button_5=new QPushButton("hill decrypt");

button_6=new QPushButton("vigenere encrypt");

button_7=new QPushButton("vigenere decrypt");



QHBoxLayout *Hl1=new QHBoxLayout;

QHBoxLayout *Hl2=new QHBoxLayout;

QHBoxLayout *Hl3=new QHBoxLayout;

QHBoxLayout *Hl4=new QHBoxLayout;

QHBoxLayout *Hl5=new QHBoxLayout;

Hl1->addWidget(button_0);

Hl1->addWidget(button_2);

Hl1->addWidget(button_4);

Hl1->addWidget(button_6);

Hl2->addWidget(button_1);

Hl2->addWidget(button_3);

Hl2->addWidget(button_5);

Hl2->addWidget(button_7);

Hl3->addWidget(label_0);

Hl3->addWidget(lineEditor_0);

Hl4->addWidget(label_1);

Hl4->addWidget(lineEditor_1);

Hl5->addWidget(label_2);

Hl5->addWidget(lineEditor_2);



QVBoxLayout *V1=new QVBoxLayout;

V1->addLayout(Hl3);

V1->addLayout(Hl4);

V1->addLayout(Hl5);

V1->addLayout(Hl1);

V1->addLayout(Hl2);

connect(button_0,SIGNAL(clicked()),this,SLOT(button_0_clicked()));

connect(button_1,SIGNAL(clicked()),this,SLOT(button_1_clicked()));

connect(button_2,SIGNAL(clicked()),this,SLOT(button_2_clicked()));

connect(button_3,SIGNAL(clicked()),this,SLOT(button_3_clicked()));

connect(button_4,SIGNAL(clicked()),this,SLOT(button_4_clicked()));

connect(button_5,SIGNAL(clicked()),this,SLOT(button_5_clicked()));

connect(button_6,SIGNAL(clicked()),this,SLOT(button_6_clicked()));

connect(button_7,SIGNAL(clicked()),this,SLOT(button_7_clicked()));



setLayout(V1);

}

void ClassicEncrypt::button_0_clicked(){

    QString qkey=lineEditor_0->text();
    QString qtext=lineEditor_1->text();
    std::string stdtext=qtext.toStdString();
    std::string stdkey=qkey.toStdString();
    caesar*p=new caesar;
    p->key=stdkey[0]-'a';
    p->encrypt(stdtext);
    lineEditor_2->setText(QString::fromStdString(p->cipher));
}

void ClassicEncrypt::button_1_clicked(){

    QString qkey=lineEditor_0->text();
    QString qtext=lineEditor_1->text();
    std::string stdtext=qtext.toStdString();
    std::string stdkey=qkey.toStdString();
    caesar*p=new caesar;
    p->key=stdkey[0]-'a';
    p->decrypt(stdtext);
    lineEditor_2->setText(QString::fromStdString(p->plain));


}

void ClassicEncrypt::button_2_clicked(){

    QString qkey=lineEditor_0->text();
    QString qtext=lineEditor_1->text();
    std::string stdkey=qkey.toStdString();
    std::string stdtext=qtext.toStdString();
    playfair*p=new playfair;
    p->makekey(stdkey);
    p->encrypt(stdtext);
    lineEditor_2->setText(QString::fromStdString(p->cipher));

}

void ClassicEncrypt::button_3_clicked(){

    QString qkey=lineEditor_0->text();
    QString qtext=lineEditor_1->text();
    std::string stdkey=qkey.toStdString();
    std::string stdtext=qtext.toStdString();
    playfair*p=new playfair;
    p->makekey(stdkey);
    p->decrypt(stdtext);
    lineEditor_2->setText(QString::fromStdString(p->plain));
}

void ClassicEncrypt::button_4_clicked(){

    QString qkey=lineEditor_0->text();
    QString qtext=lineEditor_1->text();
    std::string stdkey=qkey.toStdString();
    std::string stdtext=qtext.toStdString();
    hill*p=new hill;
    p->makekey(stdkey);
    p->encrypt(stdtext);
    lineEditor_2->setText(QString::fromStdString(p->cipher));
}

void ClassicEncrypt::button_5_clicked(){

    QString qkey=lineEditor_0->text();
    QString qtext=lineEditor_1->text();
    std::string stdkey=qkey.toStdString();
    std::string stdtext=qtext.toStdString();
    hill*p=new hill;
    p->makekey(stdkey);
    p->decrypt(stdtext);
    lineEditor_2->setText(QString::fromStdString(p->plain));
}

void ClassicEncrypt::button_6_clicked(){

    QString qkey=lineEditor_0->text();
    QString qtext=lineEditor_1->text();
    std::string stdkey=qkey.toStdString();
    std::string stdtext=qtext.toStdString();
    vigenere*p=new vigenere;
    p->makekey(stdkey);
    p->encrypt(stdtext);
    lineEditor_2->setText(QString::fromStdString(p->cipher));

}

void ClassicEncrypt::button_7_clicked(){
    QString qkey=lineEditor_0->text();
    QString qtext=lineEditor_1->text();
    std::string stdkey=qkey.toStdString();
    std::string stdtext=qtext.toStdString();
    vigenere*p=new vigenere;
    p->makekey(stdkey);
    p->decrypt(stdtext);
    lineEditor_2->setText(QString::fromStdString(p->plain));

}


