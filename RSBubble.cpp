//
//  RSBubble.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#include "RSSpongebob.h"
#include "RSBubble.h"


RSBubble::RSBubble(RSSpongebob *spongebob, QPixmap *pic, MainWindow *window, int xloc, int yloc) : RSObject(pic, window, xloc, yloc)
{
	spongebob_ = spongebob;
	velocityY_ = 3;
	name_ = "bubble";
}

void RSBubble::move()
{
	if(spongebob_->getY() < WINDOW_MAX_Y/2 && spongebob_->getVelocityY() < 0) {  
	    y_ -= spongebob_->getVelocityY();
	    velocityY_ -= spongebob_->getVelocityY();
	}
	else {
    	velocityY_ = 3;
   		y_ += velocityY_;
   	}
    
    setPos(x_, y_);
}

std::string RSBubble::getName()
{
	return name_;
}
