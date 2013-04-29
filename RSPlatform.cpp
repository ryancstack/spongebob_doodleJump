//
//  RSPlatform.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#include <QGraphicsPixmapItem>
#include "RSObject.h"
#include "RSSpongebob.h"
#include "RSPlatform.h"

using namespace std;

RSPlatform::RSPlatform(RSSpongebob *spongebob, QPixmap *pic, MainWindow *window, int xloc, int yloc) : RSObject(pic, window, xloc, yloc) 
{
    time = 0;
    spongebob_ = spongebob;
    name_ = "platform";
}

void RSPlatform::move()
{
    if(spongebob_->getY() < WINDOW_MAX_Y/2 && spongebob_->getVelocityY() < 0) {  
	    setPos(x_, y_ - spongebob_->getVelocityY());
	    velocityY_ = spongebob_->getVelocityY();
	    //cout << "PY " << y_ << endl;
	}	
}

std::string RSPlatform::getName()
{
	return name_;
}
