//
//  RSSpongebob.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//
#include <stdio.h>
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
	score = 0;
	previousScore = 0;
	differenceScore = 0;
	name_ = "spongebob";
	isMoving = true;
}

void RSSpongebob::move()
{
	for (unsigned int i = 1; i < window_->activeObjects.size(); i++ ) {
		if(window_->activeObjects[0]->collidesWithItem(window_->activeObjects[i]) && y_  <= window_->activeObjects[i]->getY() && velocityY_ > 0) { 
        //if (x_ > window_->activeObjects[i]->getX() && x_ < window_->activeObjects[i]->getX()+50) {
          //  if(abs(y_ + 65 - window_->activeObjects[i]->getY()) <= velocityY_) {
            	//y_ = window_->activeObjects[i]->getY();  
                //setPos(x_, y_);
                time = 0;
                velocityY_ = 0;
            //}
        }
    }
	
	first = 28*time - time*time;
	time += .7;
	second = 28*time - time*time;

	if(y_ >= WINDOW_MAX_Y/2 - 25 || velocityY_ > 0) {   
	    setPos(x_, y_ += first-second);
	}

	else if (velocityY_ < 0) {
		score -= (first-second);
		previousScore -= first-second;
  		n = score/4;
  		n=sprintf (number_,"%d", n);
		QString qScore(number_);
		window_->scoreDisplay->setText(qScore);
	}
    velocityY_ = first-second;
    differenceScore = abs(previousScore - WINDOW_MAX_Y);
	
	
	
	
	differenceScore = abs(previousScore - WINDOW_MAX_Y);
	
	
	if(time < 1) QGraphicsPixmapItem::setPixmap(*crouched_);
	else if(abs(velocityY_) >= 17) QGraphicsPixmapItem::setPixmap(*halfCrouched_);
	else if(abs(velocityY_) < 17) QGraphicsPixmapItem::setPixmap(*extended_);
}

std::string RSSpongebob::getName()
{
	return name_;
}
