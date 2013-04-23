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

class MainWindow : public QWidget {
   Q_OBJECT
   
public:
   explicit MainWindow();
   ~MainWindow();
   void show();
   void restart();
   
private:
   QTimer *timer;
   QGraphicsScene *scene;
   QGraphicsView *view;
   QPushButton *start;
   QPushButton *pause;

public slots:
   void startPressed();
   void cheatPressed();

};


#endif /* defined(____MainWindow__) */
