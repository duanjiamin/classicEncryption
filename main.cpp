#include "mainwindow.h"
#include <QApplication>



int main(int argc,char *argv[])

{

QApplication app(argc,argv);

ClassicEncrypt cal;

cal.show();

return app.exec();

}


