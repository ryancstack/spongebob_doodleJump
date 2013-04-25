//
//  RSSpongebob.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//
#include <QGraphicsPixmapItem>
#include "RSObject.h"
#include "RSSpongebob.h"

using namespace std;

RSSpongebob::RSSpongebob(QPixmap *crouched, QPixmap *halfCrouched, QPixmap *extended, QPixmap *pCrouched, QPixmap *pHalfCrouched, QPixmap *pExtended, QPixmap *fallingA, QPixmap *fallingB, MainWindow *window, int xloc, int yloc, int xV, int yV) : RSObject(crouched, window, xloc, yloc, xV, yV) 
{
	time = 0;
	crouched_ = crouched;
	halfCrouched_ = halfCrouched;
	extended_ = extended;
	pCrouched_ = pCrouched;
	pHalfCrouched_ = pHalfCrouched;
	pExtended_ = pExtended;
	fallingA_ = fallingA;
	fallingB_ = fallingB;
}

void RSSpongebob::move()
{
	//this is for the basic jump - set time to 0 if it hits something
	if(time >= 22.5) {
		time = 0;
	}
	
	double first = 45*time - 2*time*time;
	time += .5;
	double second = 45*time - 2*time*time;
	
	if(y_ > WINDOW_MAX_Y/2) {   
	    setPos(x_, y_);
	}
	y_ = y_ + (first-second);
	velocityY_ = first-second;
	
	if(abs(velocityY_) >= 19 && abs(velocityY_) <= 22) QGraphicsPixmapItem::setPixmap(*crouched_);
	else if(abs(velocityY_) < 16) QGraphicsPixmapItem::setPixmap(*extended_);
	else if(abs(velocityY_) >17) QGraphicsPixmapItem::setPixmap(*halfCrouched_);

}
