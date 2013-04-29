//
//  RSSquid.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#include "RSSpongebob.h"
#include "RSSquid.h"
//#include <math.h>
#include <cmath>

using namespace std;

RSSquid::RSSquid(RSSpongebob *spongebob, QPixmap *squid1, QPixmap *squid2, QPixmap *squid3, QPixmap *squid4, QPixmap *squid5, QPixmap *squid6, QPixmap *hit,  MainWindow *window, int xloc, int yloc) : RSObject(squid1, window, xloc, yloc) 
{
	time = 0;
	spongebob_ = spongebob;
	squid2_ = squid2;
	squid3_ = squid3;
	squid4_ = squid4;
	squid5_ = squid5;
	squid6_ = squid6;
	hit_ = hit;
	pictureSwitcher = 0;
	first = 0;
	second = 0;
	name_ = "squid";
}

void RSSquid::move()
{
	pictureSwitcher++;
	 if(spongebob_->getY() < WINDOW_MAX_Y/2 && spongebob_->getVelocityY() < 0) {  
	    y_ -= spongebob_->getVelocityY();
	    velocityY_ += spongebob_->getVelocityY();
	}
	//not working
	//floor functions for doubles to integers. if it's .8 it goes to 0, and if it's -.8 it goes to -1
	first = 10*sin(time);
	time += .1;
	second = 10*sin(time);
	
	if((first-second) > 0) 
		y_ += ceil(first-second);
	else 
		y_ += (first-second);
    velocityY_ += first-second;
    
    //need to do setPos not moveby
    setPos(x_, y_);
    
    if(pictureSwitcher%40 == 0) QGraphicsPixmapItem::setPixmap(*picture_);
    else if(pictureSwitcher%40 == 4 || pictureSwitcher%40 == 36) QGraphicsPixmapItem::setPixmap(*squid2_);
    else if(pictureSwitcher%40 == 8 || pictureSwitcher%40 == 32) QGraphicsPixmapItem::setPixmap(*squid3_);
    else if(pictureSwitcher%40 == 12 || pictureSwitcher%40 == 28) QGraphicsPixmapItem::setPixmap(*squid4_);
    else if(pictureSwitcher%40 == 16 || pictureSwitcher%40 == 24) QGraphicsPixmapItem::setPixmap(*squid5_);
    else if(pictureSwitcher%40 == 20) QGraphicsPixmapItem::setPixmap(*squid6_);
}

void RSSquid::hit()
{
	QGraphicsPixmapItem::setPixmap(*hit_);
}

std::string RSSquid::getName()
{
	return name_;
}
