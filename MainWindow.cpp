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
	
	//start button
	startButton = new QPixmap(QDir::currentPath() + "/PA5_Images/start.png");
	start = new RSGUI(startButton, this, WINDOW_MAX_X/2-75, WINDOW_MAX_Y/2-37);
	scene->addItem(start);
	start->setZValue(100);
	
	//pause button
	pauseButton = new QPixmap(QDir::currentPath() + "/PA5_Images/pause.png");
	pause = new RSGUI(pauseButton, this, WINDOW_MAX_X-39, 2);
	scene->addItem(pause);
	pause->setZValue(200);
	pause->setVisible(false);
	
	//text field
	enterName = new QPixmap(QDir::currentPath() + "/PA5_Images/enterName.png");
	enterNamePic = new RSGUI(enterName, this, WINDOW_MAX_X/2-75, 60);
	scene->addItem(enterNamePic);
	
	playerName = new QLineEdit();
	playerName->setGeometry(WINDOW_MAX_X/2-75, WINDOW_MAX_Y/2 - 85, 150, 30);
	scene->addWidget(playerName);
	
	
	//name display
	playerDisplay = new QGraphicsSimpleTextItem();
	playerDisplay->setPos(10,12);
	playerDisplay->setVisible(false);
	scene->addItem(playerDisplay);
	
	//score display
	scoreDisplay = new QGraphicsSimpleTextItem();
	scene->addItem(scoreDisplay);
	scoreDisplay->setPos(80,12);
	scoreDisplay->setVisible(false);
	scoreDisplay->setZValue(101);
	
	//top widget
	topLayout->addWidget(view);
	QWidget::setFocus();
	
	
	
	background.setBrush(view->backgroundRole(), QBrush(QPixmap(QDir::currentPath() +"/PA5_Images/background.png")));
	view->setPalette(background);
	
	
	//spongebob
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
	
	
	//platform
	platformPic = new QPixmap(QDir::currentPath() +"/PA5_Images/platform.png");
	
	//patrick
    patrick1 = new QPixmap(QDir::currentPath() +"/PA5_Images/6-a-patrick.png");
    patrick2 = new QPixmap(QDir::currentPath() +"/PA5_Images/6-b-patrick.png");
    patrick3 = new QPixmap(QDir::currentPath() +"/PA5_Images/6-c-patrick.png");
    patrick4 = new QPixmap(QDir::currentPath() +"/PA5_Images/6-d-patrick.png");
    
    patrick = new RSPatrick(spongebob, patrick1, patrick2, patrick3, patrick4, this, 20, 90);
    
    scene->addItem(patrick);
	patrick->setVisible(false);
	activeObjects.push_back(patrick);
	patrick->setZValue(99);
	
	//squid
	squid1 = new QPixmap(QDir::currentPath() +"/PA5_Images/5-a-squid.png");
   	squid2 = new QPixmap(QDir::currentPath() +"/PA5_Images/5-b-squid.png");
   	squid3 = new QPixmap(QDir::currentPath() +"/PA5_Images/5-c-squid.png");
  	squid4 = new QPixmap(QDir::currentPath() +"/PA5_Images/5-d-squid.png");
   	squid5 = new QPixmap(QDir::currentPath() +"/PA5_Images/5-e-squid.png");
   	squid6 = new QPixmap(QDir::currentPath() +"/PA5_Images/5-f-squid.png");
   	squidHit = new QPixmap(QDir::currentPath() +"/PA5_Images/4-a-squid_hit.png");
   	
   	squid = new RSSquid(spongebob, squid1, squid2, squid3, squid4, squid5, squid6, squidHit, this, 40, 300);
   	scene->addItem(squid);
	squid->setVisible(false);
	activeObjects.push_back(squid);
	squid->setZValue(99);
	
	//bubble
	bubblePic = new QPixmap(QDir::currentPath() +"/PA5_Images/bubble2.png");
	bubble = new RSBubble(spongebob, bubblePic, this, 40, 0);
	scene->addItem(bubble);
	bubble->setVisible(false);
	activeObjects.push_back(bubble);
	bubble->setZValue(98);
	
	//pencil
	
	
	
	timer = new QTimer(this);
	timer->setInterval(30);
	connect(timer, SIGNAL(timeout()), this, SLOT(timerAnimation()));
	srand(time(NULL));
	
	frequencyCounter = 4;
	counter = 0;
	
}

MainWindow::~MainWindow()
{
	delete scene;
	delete view;
	delete topLayout;
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
void MainWindow::populateBubbles()
{
	randY =  -rand()%(WINDOW_MAX_Y/5 +18) +1 ;
	randX = rand()%(-WINDOW_MAX_X +51) +1;
	//platform = new RSPlatform(spongebob, platformPic, this, randX, randY);
	activeObjects.push_back(platform);
	scene->addItem(platform);
}

void MainWindow::populatePatricks()
{
	randY =  -rand()%(WINDOW_MAX_Y/5 +18) +1 ;
	randX = rand()%(-WINDOW_MAX_X +51) +1;
	//platform = new RSPlatform(spongebob, platformPic, this, randX, randY);
	activeObjects.push_back(platform);
	scene->addItem(platform);
}

void MainWindow::populatePencils()
{
	randY =  -rand()%(WINDOW_MAX_Y/5 +18) +1 ;
	randX = rand()%(-WINDOW_MAX_X +51) +1;
	//platform = new RSPlatform(spongebob, platformPic, this, randX, randY);
	activeObjects.push_back(platform);
	scene->addItem(platform);

}

void MainWindow::startPressed()
{
	start->setVisible(false);
	pause->setVisible(true);
	spongebob->score = 0;
	scoreDisplay->setVisible(true);
	playerName->setVisible(false);
	playerDisplay->setText(playerName->text());
	playerDisplay->setVisible(true);
	enterNamePic->setVisible(false);
	
	//start gameplay here
	
	spongebob->setVisible(true);
	patrick->setVisible(true);
	squid->setVisible(true);
	bubble->setVisible(true);
	populateInitialPlatforms();
	//populateFrequencyPlatforms();
	
	
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
	counter++;
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


