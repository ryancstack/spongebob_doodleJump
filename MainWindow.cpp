//
//  MainWindow.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#include "MainWindow.h"

void MainWindow::show() {
	QWidget::show();	
   view->show();
}

MainWindow::MainWindow()
{
	topLayout = new QVBoxLayout;
	setLayout(topLayout);
	scene = new QGraphicsScene(0,0,WINDOW_MAX_X, WINDOW_MAX_Y);
    view = new QGraphicsView( scene );
	view->setFixedSize( WINDOW_MAX_X+2, WINDOW_MAX_Y +2);
	
	start = new QPushButton("Start");
	start->setGeometry(WINDOW_MAX_X/2-45,WINDOW_MAX_Y/2-15, 90, 30);
	scene->addWidget(start);
	
	topLayout->addWidget(view);
	
	
	
	
	
	
	
	connect(start, SIGNAL(clicked()), this, SLOT(startPressed()));
}

MainWindow::~MainWindow()
{
	delete start;
	delete scene;
	delete view;
	delete topLayout;
}

void MainWindow::startPressed()
{
	start->setVisible(false);
	//start gameplay here
}


