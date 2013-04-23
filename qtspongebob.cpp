//
//  qtspongebob.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#include <QtGui/QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   MainWindow w;
   
   w.show();
   
   return a.exec();
}

