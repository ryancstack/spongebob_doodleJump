//
//  MainWindow.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#include "MainWindow.h"
#include <QPixmap>

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
	
	//make pause button a pause icon in future
	pause = new QPushButton("Pause");
	pause->setGeometry(WINDOW_MAX_X-91,2,90,30);
	scene->addWidget(pause);
	pause->setVisible(false);
	
	
	
	
	topLayout->addWidget(view);
	view->setFocus();
	
	
	spongebob_crouched = new QPixmap("/home/cs102/game_rstack/PA5_Images/1-a-crouched.png");
	spongebob_half_crouched = new QPixmap("/home/cs102/game_rstack/PA5_Images/1-b-half_crouched.png");
	spongebob_extended = new QPixmap("/home/cs102/game_rstack/PA5_Images/1-c-extended.png");
	spongebob = new RSSpongebob(spongebob_extended, this, WINDOW_MAX_X/2-20, WINDOW_MAX_Y-62, 0, 0);
	
	
	
	
	
	
	
	connect(start, SIGNAL(clicked()), this, SLOT(startPressed()));
	connect(pause, SIGNAL(clicked()), this, SLOT(pausePressed()));
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
	pause->setVisible(true);
	//start gameplay here
	
	scene->addItem(spongebob);
}

void MainWindow::pausePressed()
{
	//stop gameplay here
}


