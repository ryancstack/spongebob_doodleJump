//
//  MainWindow.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#include "MainWindow.h"
#include <QPixmap>
#include <QKeyEvent>

using namespace std;

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
	QWidget::setFocus();
	
	
	spongebob_crouched = new QPixmap("/home/cs102/game_rstack/PA5_Images/1-a-crouched.png");
	spongebob_half_crouched = new QPixmap("/home/cs102/game_rstack/PA5_Images/1-b-half_crouched.png");
	spongebob_extended = new QPixmap("/home/cs102/game_rstack/PA5_Images/1-c-extended.png");
	spongebob_p_crouched = new QPixmap("/home/cs102/game_rstack/PA5_Images/3-a-pencil_crouched.png");
	spongebob_p_half_crouched = new QPixmap("/home/cs102/game_rstack/PA5_Images/3-b-pencil_half_crouched.png");
	spongebob_p_extended = new QPixmap("/home/cs102/game_rstack/PA5_Images/3-c-pencil_extened");
	spongebob_falling_a = new QPixmap("/home/cs102/game_rstack/PA5_Images/2-a-falling_split");
	spongebob_falling_b = new QPixmap("/home/cs102/game_rstack/PA5_Images/2-b-half_split.png");
	
	spongebob = new RSSpongebob(spongebob_crouched, spongebob_half_crouched, spongebob_extended,spongebob_p_crouched,spongebob_p_half_crouched,  spongebob_p_extended, spongebob_falling_a, spongebob_falling_b,  this, WINDOW_MAX_X/2-20, WINDOW_MAX_Y-62, 0, 0);
	scene->addItem(spongebob);
	spongebob->setVisible(false);
	
	platformPic = new QPixmap("/home/cs102/game_rstack/PA5_Images/platform.png");
	
	
	//dynamically allocate this randomly in the timer function
	platform = new RSPlatform(platformPic, this, 30, 30, 0, 0);
	scene->addItem(platform);
	platform->setVisible(false);
	
	
	
	
	timer = new QTimer(this);
	timer->setInterval(30);
	connect(timer, SIGNAL(timeout()), this, SLOT(timerAnimation()));
	connect(start, SIGNAL(clicked()), this, SLOT(startPressed()));
	connect(pause, SIGNAL(clicked()), this, SLOT(pausePressed()));
	
}

MainWindow::~MainWindow()
{
	delete start;
	delete scene;
	delete view;
	//delete topLayout;
}

void MainWindow::startPressed()
{
	start->setVisible(false);
	pause->setVisible(true);
	//start gameplay here
	spongebob->setVisible(true);
	platform->setVisible(true);
	
	activeObjects.push_back(platform);
	
	
	timer->start();
	QWidget::setFocus();
}

void MainWindow::pausePressed()
{
	if(timer->isActive() == true) {
        timer->stop();
    }
    else {
        timer->start();
    }
}

void MainWindow::timerAnimation()
{
   QWidget::setFocus();
   spongebob->move();
   platform->moveOther(spongebob->getVelocityY(), spongebob->getY());
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{	
	cout << "key pressed" << endl;
	if(e->key() == Qt::Key_Left) {
	     spongebob->moveBy(-10,0);
	     spongebob->setX(spongebob->getX() - 10);
	}
	else if(e->key() == Qt::Key_Right) {
	     spongebob->moveBy(10,0);
	     spongebob->setX(spongebob->getX() + 10);
	}
}


