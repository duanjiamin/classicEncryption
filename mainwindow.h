#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include<QApplication>

#include<QDialog>

#include<QPushButton>

#include<QLineEdit>

#include<QLabel>

class ClassicEncrypt:public QDialog

{

Q_OBJECT

protected:
QLabel *label_0;

QLabel *label_1;

QLabel *label_2;

QLineEdit *lineEditor_0;

QLineEdit *lineEditor_1;

QLineEdit *lineEditor_2;

QPushButton *button_0;

QPushButton *button_1;

QPushButton *button_2;

QPushButton *button_3;

QPushButton *button_4;

QPushButton *button_5;

QPushButton *button_6;

QPushButton *button_7;



QString p;

QString c;
public:

ClassicEncrypt();

private slots:

void button_0_clicked();

void button_1_clicked();

void button_2_clicked();

void button_3_clicked();

void button_4_clicked();

void button_5_clicked();

void button_6_clicked();

void button_7_clicked();



};

#endif // MAINWINDOW_H
