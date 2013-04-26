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
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <vector>
//#include "RSBubble.h"
//#include "RSPatrick.h"
//#include "RSSquid.h"
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
   
private:
   QTimer *timer;
   QGraphicsScene *scene;
   QGraphicsView *view;
   QPushButton *start;
   QVBoxLayout *topLayout;
   QPushButton *pause;
   
   
   RSSpongebob *spongebob;
   QPixmap *spongebob_crouched;
   QPixmap *spongebob_half_crouched;
   QPixmap *spongebob_extended;
   QPixmap *spongebob_p_crouched;
   QPixmap *spongebob_p_half_crouched;
   QPixmap *spongebob_p_extended;
   QPalette background;
   
   
   RSPlatform *platform;
   QPixmap *platformPic;
   

public:
   std::vector<RSObject*> activeObjects;
   
 
protected:
   void keyPressEvent(QKeyEvent *e);
   

public slots:
   void startPressed();
   void pausePressed();
   void timerAnimation();
};


#endif /* defined(____MainWindow__) */
