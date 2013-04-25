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

class MainWindow;


class RSObject : public QGraphicsPixmapItem
{
public:	
   RSObject(QPixmap *pic, MainWindow *window, int xloc, int yloc, int xV, int yV);
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
   int time_;
   QPixmap *picture_;
   MainWindow *window_;
};




#endif
