/**
 * @author Ryan Stack
 * @date April 29, 2013
 */

#ifndef _RSObject_h
#define _RSObject_h

#include <QGraphicsPixmapItem>

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class MainWindow;


class RSObject : public QGraphicsPixmapItem
{
public:
   /**
    * Constructor for an RSObject object. This is the super class
    * that determines the velocity, and location, and pixmap. It 
    * also has all the accessor and setter methods to change all these
    * @param pic Picture for object
    * @param window Window the object is in to access variables
    * @param xloc X-coordinate for the object
    * @param yloc Y-coordinate for the object
    */
   RSObject(QPixmap *pic, MainWindow *window, int xloc, int yloc);
   /**
    * @param x X location to be set
    */
   void setX(int x);
   /**
    * @param y Y location to be set
    */
   void setY(int y);
   /**
    * @param vX Velocity in the x direction to be set
    */
   void setVelocityX(int vX);
   /**
    * @param vY Velocity in the y direction to be set
    */
   void setVelocityY(int vY);
   /**
    * @return x location
    */
   int getX();
   /**
    * @return y location
    */
   int getY();
   /**
    * @return x-velocity
    */
   int getVelocityX();
   /**
    * @return y-velocity
    */
   int getVelocityY();
   /**
    * @param pic Picture to set as the objects image
    */
   void setPixmap(QPixmap *pic);
   /**
    * @param x X location to be set
    * @param y Y location to be set
    */
   void setPos(int x, int y);
   /**
    * @return name of the object
    */
   virtual std::string getName();
   /**
    * Pure virtual function to implement move function in subclasses
    */
   virtual void move() = 0;
protected:
   /** x location */
   int x_;
   /** y location */
   int y_;
   /** x velocity */
   int velocityX_;
   /** y velocity */
   int velocityY_;
   /** picture for object */
   QPixmap *picture_;
   /** window to access public variables*/
   MainWindow *window_;
   /** name of object */
   std::string name_;
};




#endif
