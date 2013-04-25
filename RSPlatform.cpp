//
//  RSPlatform.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#include <QGraphicsPixmapItem>
#include "RSObject.h"
#include "RSPlatform.h"

using namespace std;

RSPlatform::RSPlatform(QPixmap *pic, MainWindow *window, int xloc, int yloc, int xV, int yV) : RSObject(pic, window, xloc, yloc, xV, yV) 
{
    time = 0;
}

void RSPlatform::moveOther(int spongebobVelocity, int spongebobY)
{
    if(spongebobY < WINDOW_MAX_Y/2 && spongebobVelocity < 0) { 
        y_ = y_ - spongebobVelocity;  
	    setPos(x_, y_);
	    velocityY_ = spongebobVelocity;
	    //cout << "PY " << y_ << endl;
	}	
}

void RSPlatform::move() {}
