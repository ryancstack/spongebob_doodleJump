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
#include "RSObject.h"

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class RSSpongebob;

class RSPlatform : RSObject
{
public:
	RSPlatform(QPixmap *pic, MainWindow *window, int xloc, int yloc, int xV, int yV);
	void move();
	void setVelocity(int spongebobVelocity);
};

#endif /* defined(____RSPlatform__) */
