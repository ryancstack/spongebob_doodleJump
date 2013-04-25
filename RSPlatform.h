//
//  RSPlatform.h
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#ifndef ____RSPlatform__
#define ____RSPlatform__

#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "RSObject.h"

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class RSPlatform : public RSObject
{
public:
	RSPlatform(QPixmap *pic, MainWindow *window, int xloc, int yloc, int xV, int yV);
	void moveOther(int spongebobVelocity, int spongebobY);
	void move();

private:
    double time;
};

#endif /* defined(____RSPlatform__) */
