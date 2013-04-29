//
//  MainWindow.h
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#ifndef ____MainWindow__
#define ____MainWindow__

#include <iostream>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QLineEdit>
#include <QVBoxLayout>
#include <vector>
#include "RSGUI.h"
#include "RSBubble.h"
#include "RSPatrick.h"
#include "RSSquid.h"
#include "RSPencil.h"
#include "RSPlatform.h"
#include "RSObject.h"
#include "RSSpongebob.h"


#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class MainWindow : public QWidget {
   Q_OBJECT
   
public:
   explicit MainWindow();
   ~MainWindow();
   void show();
   //void restart();
   void populateInitialPlatforms();
   void populateFrequencyPlatforms();
   void populateSquids();
   void populateBubbles();
   void populatePatricks();
   void populatePencils();
   void restartPressed();
   void startPressed();
   void pausePressed();
   void resumePressed();
   bool probabilityCreator(int percentenge);
   
private:
   QTimer *timer;
   QGraphicsScene *scene;
   QGraphicsView *view;
   QVBoxLayout *topLayout;
   
   //GUI
   RSGUI *title;
   RSGUI *pause;
   RSGUI *start;
   RSGUI *enterNamePic;
   RSGUI *nameBG;
   RSGUI *scoreBG;
   RSGUI *pauseSplash;
   RSGUI *resume;
   RSGUI *quit_;
   RSGUI *restart;
   QLineEdit *playerName;
   QGraphicsSimpleTextItem *playerDisplay;
	
   QPixmap *titlePic;	
   QPixmap *pauseBG;
   QPixmap *startButton;
   QPixmap *pauseButton;
   QPixmap *resumeButton;
   QPixmap *restartButton;
   QPixmap *quitButton;
   QPixmap *enterName;
   QPixmap *textBG;
   
   //spongebob
   RSSpongebob *spongebob;
   QPixmap *spongebob_crouched;
   QPixmap *spongebob_half_crouched;
   QPixmap *spongebob_extended;
   QPixmap *spongebob_p_crouched;
   QPixmap *spongebob_p_half_crouched;
   QPixmap *spongebob_p_extended;
   QPixmap *bubble_up1;
   QPixmap *bubble_up2;
   
   //patrick
   RSPatrick *patrick; //dynamically allocate this later
   QPixmap *patrick1;
   QPixmap *patrick2;
   QPixmap *patrick3;
   QPixmap *patrick4;
   
   //squid
   RSSquid *squid; //dynamically allocate this later
   QPixmap *squid1;
   QPixmap *squid2;
   QPixmap *squid3;
   QPixmap *squid4;
   QPixmap *squid5;
   QPixmap *squid6;
   QPixmap *squidHit;
   
   //bubble
   RSBubble *bubble;
   QPixmap *bubblePic;
   
   //pencil
   RSPencil *pencil;
   QPixmap *pencilPic;
   
   
   
   QPalette background;
   
   
   //platform
   RSPlatform *platform;
   QPixmap *platformPic;
   
   int frequencyCounter;
   int randY;
   int randX;
   bool goodLoc;
   
   
   int badItemCounter;
   int goodItemCounter;
   
   
   

public:
   std::vector<RSObject*> activeObjects;
   QGraphicsSimpleTextItem *scoreDisplay;
   int counter;
   bool squidActive;
   bool bubbleActive;
   bool patrickActive;
   bool pencilActive;
   
 
protected:
   void keyPressEvent(QKeyEvent *e);
   

public slots:
   
   void timerAnimation();
};


#endif /* defined(____MainWindow__) */
