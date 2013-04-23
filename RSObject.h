//
//  RSObject.h
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#ifndef _RSObject_h
#define _RSObject_h

class RSObject
{
public:
   virtual void setX(int x) = 0;
   virtual void setY(int x) = 0;
   virtual void setVelocityX(int vX) = 0;
   virtual void setVelocityY(int vY) = 0;
   virtual void getX() = 0;
   virtual void getY() = 0;
   virtual void move() = 0;
private:
   int x;
   int y;
   int width;
   int height;
   int velocityX;
   int velocityY;
}




#endif
