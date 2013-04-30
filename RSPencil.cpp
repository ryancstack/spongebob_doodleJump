//
//  RSPencil.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#include "RSSpongebob.h"
#include "MainWindow.h"
#include "RSPencil.h"

RSPencil::RSPencil(RSSpongebob *spongebob, QPixmap *pic, MainWindow *window, int xloc, int yloc) : RSObject(pic, window, xloc, yloc)
{
	spongebob_ = spongebob;
	velocityY_ = 0;
	name_ = "pencil";
}

void RSPencil::move()
{
	if(spongebob_->getY() < WINDOW_MAX_Y/2-25 && spongebob_->getVelocityY() < 0) {  
	    y_ -= spongebob_->getVelocityY();
	    velocityY_ -= spongebob_->getVelocityY();
	}
	if(window_->counter%50 ==0) {
		x_ = rand()%WINDOW_MAX_X;
		y_ = rand()%WINDOW_MAX_Y/2 + 50;
	}
    
    setPos(x_, y_);

}
