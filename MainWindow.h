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

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class MainWindow : public QWidget {
   Q_OBJECT
   
public:
   explicit MainWindow();
   ~MainWindow();
   void show();
   //void restart();
   
private:
   //QTimer *timer;
   QGraphicsScene *scene;
   QGraphicsView *view;
   QPushButton *start;
   QVBoxLayout *topLayout;
   //QPushButton *pause;

public slots:
   void startPressed();

};


#endif /* defined(____MainWindow__) */
