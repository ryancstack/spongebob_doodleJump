//
//  RSSpongebob.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//
#include <QGraphicsPixmapItem>
#include <vector>
#include "MainWindow.h"
#include "RSObject.h"
#include "RSSpongebob.h"

using namespace std;

RSSpongebob::RSSpongebob(QPixmap *crouched, QPixmap *halfCrouched, QPixmap *extended, QPixmap *pCrouched, QPixmap *pHalfCrouched, QPixmap *pExtended, MainWindow *window, int xloc, int yloc) : RSObject(crouched, window, xloc, yloc) 
{
	time = 0;
	crouched_ = crouched;
	halfCrouched_ = halfCrouched;
	extended_ = extended;
	pCrouched_ = pCrouched;
	pHalfCrouched_ = pHalfCrouched;
	pExtended_ = pExtended;
	hasJumped = false;
	score = 0;
}

void RSSpongebob::move()
{
    //you need to map if his velocity +61 equals the location of the platform - set his location to the platform and then set time to 0
	//this is for the basic jump - set time to 0 if it hits something
	if(time >= 22.5 && hasJumped == false) {
		time = 0;
	}
	
	for (unsigned int i = 0; i < window_->activeObjects.size(); i++ ) { 
        if (x_ > window_->activeObjects[i]->getX() && x_ < window_->activeObjects[i]->getX()+50) {
            if(abs(y_ + 65 - window_->activeObjects[i]->getY()) <= velocityY_) {
            	y_ = window_->activeObjects[i]->getY();  
                setPos(x_, y_);
                time = 0;
                hasJumped = true;
            }
        }
    }
	
	double first = 45*time - 2*time*time;
	time += .5;
	double second = 45*time - 2*time*time;
	
	if(y_ >= WINDOW_MAX_Y/2 - 50) {   
	    setPos(x_, y_);
	    score += first-second;
	}
	y_ = y_ + (first-second);
    velocityY_ = first-second;
	
	
	if(abs(velocityY_) >= 22) QGraphicsPixmapItem::setPixmap(*crouched_);
	else if(abs(velocityY_) >= 17 && abs(velocityY_) < 22) QGraphicsPixmapItem::setPixmap(*halfCrouched_);
	else if(abs(velocityY_) < 17) QGraphicsPixmapItem::setPixmap(*extended_);
	

}
