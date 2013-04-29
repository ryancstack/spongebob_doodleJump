//
//  RSPatrick.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#include <string>
#include "RSSpongebob.h"
#include "RSPatrick.h"

RSPatrick::RSPatrick(RSSpongebob *spongebob, QPixmap *patrick1, QPixmap *patrick2, QPixmap *patrick3, QPixmap *patrick4, MainWindow *window, int xloc, int yloc) : RSObject(patrick1, window, xloc, yloc) 
{
    spongebob_ = spongebob;
    velocityX_ = 5;
    patrick2_ = patrick2;
	patrick3_ = patrick3;
	patrick4_ = patrick4;
	pictureSwitcher = 0;
	name_ = "patrick";
}

void RSPatrick::move()
{
	pictureSwitcher++;
    if(spongebob_->getY() < WINDOW_MAX_Y/2 && spongebob_->getVelocityY() < 0) {  
	    y_ = y_ - spongebob_->getVelocityY();
	    velocityY_ = spongebob_->getVelocityY();
	}	
	if ( x_ < 0 ) {
        velocityX_ = -velocityX_;
        setPos(x_ + velocityX_, y_);
    }
    else if ( (x_+ 50) > WINDOW_MAX_X ) {
         velocityX_ = -velocityX_;
         setPos(x_ + velocityX_, y_);
    }
    else {
    	setPos(x_ + velocityX_, y_);
    }
    
    
    if(pictureSwitcher%16 == 0) QGraphicsPixmapItem::setPixmap(*picture_);
    else if(pictureSwitcher%16 == 4) QGraphicsPixmapItem::setPixmap(*patrick2_);
    else if(pictureSwitcher%16 == 8) QGraphicsPixmapItem::setPixmap(*patrick3_);
    else if(pictureSwitcher%16 == 12) QGraphicsPixmapItem::setPixmap(*patrick4_);
}

std::string RSPatrick::getName()
{
	return name_;
}
