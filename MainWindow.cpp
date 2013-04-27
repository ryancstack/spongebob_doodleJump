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
#include <QDir>

using namespace std;

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
	pause->setGeometry(WINDOW_MAX_X-91,5,90,30);
	scene->addWidget(pause);
	pause->setVisible(false);
	
	scoreDisplay = new QGraphicsSimpleTextItem();
	scene->addItem(scoreDisplay);
	scoreDisplay->setPos(10,12);
	scoreDisplay->setVisible(false);
	scoreDisplay->setZValue(101);
	
	
	
	
	topLayout->addWidget(view);
	QWidget::setFocus();
	
	
	
	background.setBrush(view->backgroundRole(), QBrush(QPixmap(QDir::currentPath() +"/PA5_Images/background.png")));
	view->setPalette(background);
	
	
	
	spongebob_crouched = new QPixmap(QDir::currentPath() + "/PA5_Images/1-a-crouched.png");
	spongebob_half_crouched = new QPixmap(QDir::currentPath() +"/PA5_Images/1-b-half_crouched.png");
	spongebob_extended = new QPixmap(QDir::currentPath() +"/PA5_Images/1-c-extended.png");
	spongebob_p_crouched = new QPixmap(QDir::currentPath() +"/PA5_Images/3-a-pencil_crouched.png");
	spongebob_p_half_crouched = new QPixmap(QDir::currentPath() +"/PA5_Images/3-b-pencil_half_crouched.png");
	spongebob_p_extended = new QPixmap(QDir::currentPath() +"/PA5_Images/3-c-pencil_extened");
	
	spongebob = new RSSpongebob(spongebob_crouched, spongebob_half_crouched, spongebob_extended,spongebob_p_crouched,spongebob_p_half_crouched,  spongebob_p_extended,  this, WINDOW_MAX_X/2-20, WINDOW_MAX_Y-62);
	scene->addItem(spongebob);
	spongebob->setVisible(false);
	activeObjects.push_back(spongebob);
	spongebob->setZValue(100);
	
	platformPic = new QPixmap(QDir::currentPath() +"/PA5_Images/platform.png");
	
	
	timer = new QTimer(this);
	timer->setInterval(30);
	connect(timer, SIGNAL(timeout()), this, SLOT(timerAnimation()));
	connect(start, SIGNAL(clicked()), this, SLOT(startPressed()));
	connect(pause, SIGNAL(clicked()), this, SLOT(pausePressed()));
	srand(time(NULL));
	
	frequencyCounter = 4;
	counter = 0;
	
}

MainWindow::~MainWindow()
{
	delete start;
	delete scene;
	delete view;
	//delete topLayout;
}

void MainWindow::show() {
    QWidget::show();	
    view->show();
}

void MainWindow::populateInitialPlatforms()
{
	
	for(int i = 0; i < 20; i++) {
		randY =  rand()%(WINDOW_MAX_Y -18) +1 ;
		randX = rand()%(WINDOW_MAX_X -51) +1;
		goodLoc = true;
		for(unsigned int i = 1; i < activeObjects.size(); i++)
		{
			if(abs(randX - activeObjects[i]->getX()) <= 51 && abs(randY - activeObjects[i]->getY()) <= 18)
				goodLoc = false;
		}
		if(goodLoc) {
			platform = new RSPlatform(spongebob, platformPic, this, randX, randY);
			activeObjects.push_back(platform);
			scene->addItem(platform);
		}
	}

}

void MainWindow::populateFrequencyPlatforms()
{
	//when a specific counter is reached - no clue how to do this yet
	for(int i = 0; i < frequencyCounter; i++) {
		randY =  -rand()%(WINDOW_MAX_Y/5 +18) +1 ;
		randX = rand()%(-WINDOW_MAX_X +51) +1;
		goodLoc = true;
		//cout << activeObjects.size() << endl;
		for(unsigned int i = 1; i < activeObjects.size(); i++)
		{
			if(abs(randX - activeObjects[i]->getX()) <= 51 && abs(randY - activeObjects[i]->getY()) <= 18)
				goodLoc = false;
		}
		if(goodLoc) {
			platform = new RSPlatform(spongebob, platformPic, this, randX, randY);
			activeObjects.push_back(platform);
			scene->addItem(platform);
		}
	}
	
}

void MainWindow::populateSquids()
{

}
void MainWindow::populateBubbles()
{

}

void MainWindow::populatePatricks()
{

}

void MainWindow::startPressed()
{
	start->setVisible(false);
	pause->setVisible(true);
	spongebob->score = 0;
	scoreDisplay->setVisible(true);
	
	//start gameplay here
	
	spongebob->setVisible(true);
	//platform->setVisible(true);
	populateInitialPlatforms();
	populateFrequencyPlatforms();
	
	//activeObjects.push_back(platform);
	
	
	timer->start();
	QWidget::setFocus();
}

void MainWindow::pausePressed()
{
    QWidget::setFocus();
        timer->stop();
}

void MainWindow::timerAnimation()
{
	if(spongebob->differenceScore < 500) {
		populateFrequencyPlatforms();
		spongebob->differenceScore = 0;
		spongebob->previousScore = 0;
	}
    QWidget::setFocus();
    spongebob->move();
    for(unsigned int i = 1; i < activeObjects.size(); i++) {
    	if(activeObjects[i]->getY() > WINDOW_MAX_Y ) {
    		delete activeObjects[i];
    		activeObjects.erase(activeObjects.begin() + i);
    		i--;
    	}	
    	else activeObjects[i]->move();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{	
	//cout << "key pressed" << endl;
	if(e->key() == Qt::Key_Left) {
		if(spongebob->getX() - 20 > 0) {
			spongebob->moveBy(- 20, 0);
	     	spongebob->setX(spongebob->getX() - 20);
		}
		else {
			spongebob->moveBy(- spongebob->getX(), 0);
	     	spongebob->setX(0);
	     }
		
	}
	else if(e->key() == Qt::Key_Right) {
		if(spongebob->getX() + 20 < WINDOW_MAX_X -25) {
	     	spongebob->moveBy(20, 0);
	     	spongebob->setX(spongebob->getX() + 20);
	     }
	}
}


