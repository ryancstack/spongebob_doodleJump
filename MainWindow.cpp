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
	
	//title
	titlePic = new QPixmap(QDir::currentPath() + "/PA5_Images/title.png");
	title = new RSGUI(titlePic, this, 0, 0);
	scene->addItem(title);
	
	
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
	enterNamePic = new RSGUI(enterName, this, WINDOW_MAX_X/2-95, 140);
	scene->addItem(enterNamePic);
	
	playerName = new QLineEdit();
	playerName->setGeometry(WINDOW_MAX_X/2-50, WINDOW_MAX_Y/2 - 85, 100, 30);
	playerName->setMaxLength(11);
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
	
	//squid
	squid1 = new QPixmap(QDir::currentPath() +"/PA5_Images/5-a-squid.png");
   	squid2 = new QPixmap(QDir::currentPath() +"/PA5_Images/5-b-squid.png");
   	squid3 = new QPixmap(QDir::currentPath() +"/PA5_Images/5-c-squid.png");
  	squid4 = new QPixmap(QDir::currentPath() +"/PA5_Images/5-d-squid.png");
   	squid5 = new QPixmap(QDir::currentPath() +"/PA5_Images/5-e-squid.png");
   	squid6 = new QPixmap(QDir::currentPath() +"/PA5_Images/5-f-squid.png");
   	squidHit = new QPixmap(QDir::currentPath() +"/PA5_Images/4-a-squid_hit.png");
	
	//bubble
	bubblePic = new QPixmap(QDir::currentPath() +"/PA5_Images/bubble2.png");
	
	//pencil
	pencilPic = new QPixmap(QDir::currentPath() +"/PA5_Images/pencil.png");
	
	
	timer = new QTimer(this);
	timer->setInterval(30);
	connect(timer, SIGNAL(timeout()), this, SLOT(timerAnimation()));
	srand(time(NULL));
	
	frequencyCounter = 4;
	counter = 0;
	
	squidActive = false;
	bubbleActive = false;
	patrickActive = false;
	pencilActive = false;
	
	badItemCounter = 0;
	goodItemCounter = 0;
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
	if(probabilityCreator(300 + badItemCounter) && !squidActive) {
		randY =  -rand()%(WINDOW_MAX_Y +54) +1 ;
		randX = rand()%(-WINDOW_MAX_X +56) +1;
		squid = new RSSquid(spongebob, squid1, squid2, squid3, squid4, squid5, squid6, squidHit, this, randX, randY);
		activeObjects.push_back(squid);
		scene->addItem(squid);
		squidActive = true;
		if(badItemCounter < 500)badItemCounter++;
		squid->setZValue(100);
	}
}

void MainWindow::populateBubbles()
{
	if(probabilityCreator(150 + goodItemCounter) && !bubbleActive) {
		randX = rand()%(-WINDOW_MAX_X +33) +1;
		bubble = new RSBubble(spongebob, bubblePic, this, randX, 0);
		activeObjects.push_back(bubble);
		scene->addItem(bubble);
		bubbleActive = true;
		if(goodItemCounter>5)goodItemCounter--;
		bubble->setZValue(100);
	}		
}

void MainWindow::populatePatricks()
{
	if(probabilityCreator(100+badItemCounter) && !patrickActive) {
		randY =  -rand()%(WINDOW_MAX_Y +52) +1 ;
		randX = rand()%(-WINDOW_MAX_X +50) +1;
		patrick = new RSPatrick(spongebob, patrick1, patrick2, patrick3, patrick4, this, randX, randY);
		activeObjects.push_back(patrick);
		scene->addItem(patrick);
		patrickActive = true;
		if(badItemCounter < 500)badItemCounter++;
		patrick->setZValue(100);
	}
}

void MainWindow::populatePencils()
{
	if(probabilityCreator(250+goodItemCounter) && !pencilActive) {
		randY =  -rand()%(WINDOW_MAX_Y/5 +47) +1 ;
		randX = rand()%(-WINDOW_MAX_X +5) +1;
		pencil = new RSPencil(spongebob, pencilPic, this, randX, randY);
		activeObjects.push_back(pencil);
		scene->addItem(pencil);
		pencilActive = true;
		if(goodItemCounter>5)goodItemCounter--;
		pencil->setZValue(100);
	}

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
		title->setVisible(false);
		
		//start gameplay here
		spongebob->setVisible(true);
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

bool MainWindow::probabilityCreator(int percentage)
{
	int randPer = rand()%1000;
	if(randPer < percentage) return true;
	else return false;
}

void MainWindow::timerAnimation()
{
	cout << "pencil " << pencilActive << endl;
	cout << "squid " << squidActive << endl;
	cout << "patrick " << patrickActive << endl;
	cout << "bubble " << bubbleActive << endl;
	
	counter++;
	if(spongebob->itrScore > 120) {
		populateFrequencyPlatforms();
		populateSquids();
   		populatePatricks();
   		populatePencils();
    	populateBubbles();
		spongebob->itrScore = 0;
	}
    QWidget::setFocus();
    spongebob->move();
    for(unsigned int i = 1; i < activeObjects.size(); i++) {
    	if(activeObjects[i]->getY() > WINDOW_MAX_Y ) {
    		if(activeObjects[i]->getName() == "pencil") pencilActive = false;
    		else if(activeObjects[i]->getName() == "squid") squidActive = false;
    		else if(activeObjects[i]->getName() == "bubble") bubbleActive = false;
    		else if(activeObjects[i]->getName() == "patrick") patrickActive = false;
    		delete activeObjects[i];
    		activeObjects.erase(activeObjects.begin() + i);
    		i--;
    		
    	}	
    	else activeObjects[i]->move();
    }
    
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{	
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
