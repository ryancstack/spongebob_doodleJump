//
//  MainWindow.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#include "MainWindow.h"

void MainWindow::show() {
   view->show();
}

MainWindow::MainWindow()
{
	scene = new QGraphicsScene();
    view = new QGraphicsView( scene );
	view->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );
}
