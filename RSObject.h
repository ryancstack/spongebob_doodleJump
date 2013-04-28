//
//  RSObject.h
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#ifndef _RSObject_h
#define _RSObject_h

#include <QGraphicsPixmapItem>

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class MainWindow;


class RSObject : public QGraphicsPixmapItem
{
public:	
   RSObject(QPixmap *pic, MainWindow *window, int xloc, int yloc);
   void setX(int x);
   void setY(int x);
   void setVelocityX(int vX);
   void setVelocityY(int vY);
   int getX();
   int getY();
   int getVelocityX();
   int getVelocityY();
   void setPixmap(QPixmap *pic);
   void setPos(int x, int y);
   virtual void move() = 0;
protected:
   int x_;
   int y_;
   int velocityX_;
   int velocityY_;
   QPixmap *picture_;
   MainWindow *window_;
};




#endif
