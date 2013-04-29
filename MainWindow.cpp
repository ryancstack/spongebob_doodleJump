//
//  MainWindow.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//
#include <QPixmap>
#include <QKeyEvent>
#include <QDir>
#include <QApplication>
#include "MainWindow.h"

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
	
	textBG = new QPixmap(QDir::currentPath() + "/PA5_Images/nameBG.png");
	
	//name display
	nameBG = new RSGUI(textBG, this, 3, 3);
	scene->addItem(nameBG);
	nameBG->setVisible(false);
	nameBG->setZValue(200);
	
	playerDisplay = new QGraphicsSimpleTextItem();
	playerDisplay->setPos(10,12);
	playerDisplay->setVisible(false);
	scene->addItem(playerDisplay);
	playerDisplay->setZValue(201);
	
	//score display	
	scoreBG = new RSGUI(textBG, this, 125, 3);
	scene->addItem(scoreBG);
	scoreBG->setVisible(false);
	scoreBG->setZValue(200);
	
	scoreDisplay = new QGraphicsSimpleTextItem();
	scene->addItem(scoreDisplay);
	scoreDisplay->setPos(130,12);
	scoreDisplay->setVisible(false);
	scoreDisplay->setZValue(201);
	
	//pause display //qApp::quit()
	pauseBG = new QPixmap(QDir::currentPath() + "/PA5_Images/pause-background.png");
	pauseSplash = new RSGUI(pauseBG, this, 0,0);
	scene->addItem(pauseSplash);
	pauseSplash->setVisible(false);
	pauseSplash->setZValue(300);
	
	quitButton = new QPixmap(QDir::currentPath() + "/PA5_Images/quit.png");
	quit_ = new RSGUI(quitButton, this, WINDOW_MAX_X/2-75, WINDOW_MAX_Y/2 +30);
	scene->addItem(quit_);
	quit_->setVisible(true);
	quit_->setZValue(301);
	
	
	resumeButton = new QPixmap(QDir::currentPath() + "/PA5_Images/resume.png");
	resume = new RSGUI(resumeButton, this, WINDOW_MAX_X/2-75, WINDOW_MAX_Y/2-70);
	scene->addItem(resume);
	resume->setVisible(false);
	resume->setZValue(301);
	
	restartButton = new QPixmap(QDir::currentPath() + "/PA5_Images/restart.png");
	restart = new RSGUI(restartButton, this, WINDOW_MAX_X/2-75, WINDOW_MAX_Y/2-20);
	scene->addItem(restart);
	restart->setVisible(false);
	restart->setZValue(301);
	
	
	
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
	pencilPic = new QPixmap(QDir::currentPath() +"/PA5_Images/pencil.png");
	pencil = new RSPencil(spongebob, pencilPic, this, 100, 300);
	scene->addItem(pencil);
	pencil->setVisible(false);
	activeObjects.push_back(pencil);
	pencil->setZValue(100);
	
	
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

void MainWindow::restartPressed()
{
	for(unsigned int i = 0; i < activeObjects.size(); i++)
	{
		delete activeObjects[i];
	}
	activeObjects.clear();
	
	
	spongebob = new RSSpongebob(spongebob_crouched, spongebob_half_crouched, spongebob_extended,spongebob_p_crouched,spongebob_p_half_crouched,  spongebob_p_extended,  this, WINDOW_MAX_X/2-20, WINDOW_MAX_Y-62);
	activeObjects.push_back(spongebob);
	spongebob->setZValue(100);
	scene->addItem(spongebob);
	
	populateInitialPlatforms();
	//populate the rest here
	
	spongebob->score = 0;
	resumePressed();
}

void MainWindow::startPressed()
{
	
	if(playerName->text() == "") playerName->setPlaceholderText("enter name");
	else {
		start->setVisible(false);
		pause->setVisible(true);
		spongebob->score = 0;
		scoreDisplay->setVisible(true);
		playerName->setVisible(false);
		playerDisplay->setText(playerName->text());
		playerDisplay->setVisible(true);
		enterNamePic->setVisible(false);
		nameBG->setVisible(true);
		scoreBG->setVisible(true);
		quit_->setVisible(false);
		
		//start gameplay here
		spongebob->setVisible(true);
		patrick->setVisible(true);
		squid->setVisible(true);
		bubble->setVisible(true);
		pencil->setVisible(true);
		populateInitialPlatforms();
		//populateFrequencyPlatforms();
		
		timer->start();
		QWidget::setFocus();
	}
}

void MainWindow::pausePressed()
{
    QWidget::setFocus();
    timer->stop();
    pause->setVisible(false);
    nameBG->setVisible(false);
    scoreBG->setVisible(false);
    playerDisplay->setVisible(false);
    scoreDisplay->setVisible(false);
    
    pauseSplash->setVisible(true);
    quit_->setVisible(true);
    resume->setVisible(true);
    restart->setVisible(true);
    
    
}

void MainWindow::resumePressed()
{
	QWidget::setFocus();
    timer->start();
    pause->setVisible(true);
    nameBG->setVisible(true);
    scoreBG->setVisible(true);
    playerDisplay->setVisible(true);
    scoreDisplay->setVisible(true);
    
    pauseSplash->setVisible(false);
    quit_->setVisible(false);
    resume->setVisible(false);
    restart->setVisible(false);
}

void MainWindow::quitPressed()
{
	//emit quitButtonEmit();
	qApp->quit();
}

void MainWindow::timerAnimation()
{
	counter++;
	if(spongebob->differenceScore < 500) {
		//populateFrequencyPlatforms();
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
