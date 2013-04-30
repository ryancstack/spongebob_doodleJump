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
	itrScore = 0;
	name_ = "spongebob";
	isShielded = false;
	isBubbling = false;
	isDead = false;
}

void RSSpongebob::move()
{

	//fix for when his velocity is positive and runs into the stuff
	if(!isDead) {
		for (unsigned int i = 1; i < window_->activeObjects.size(); i++ ) {
			if(window_->activeObjects[0]->collidesWithItem(window_->activeObjects[i]) && y_+ 40  <= window_->activeObjects[i]->getY() && velocityY_ > 0) { 
				if(window_->activeObjects[i]->getName() == "platform") {
					time = 0;
        			velocityY_ = 0;
        		}
				else if(window_->activeObjects[i]->getName() == "squid" || window_->activeObjects[i]->getName() == "patrick") {
        			time = 0;
        			velocityY_ = 0;
        			score +=50;
        			n = score/4;
  					n=sprintf (number_,"%d", n);
					QString qScore(number_);
					window_->scoreDisplay->setText(qScore);
					if(window_->activeObjects[i]->getName() == "squid") window_->squidActive = false;
					else window_->patrickActive = false;
        			delete window_->activeObjects[i];
    				window_->activeObjects.erase(window_->activeObjects.begin() + i);
    				i--;
    			}
    			else if(window_->activeObjects[i]->getName() == "pencil") {
    				isShielded = true;
    				window_->pencilActive = false;
        			delete window_->activeObjects[i];
    				window_->activeObjects.erase(window_->activeObjects.begin() + i);
    				i--;
    			}
    			else if(window_->activeObjects[i]->getName() == "bubble") {
    				isBubbling = true;
    				window_->bubbleActive = false;
        			delete window_->activeObjects[i];
    				window_->activeObjects.erase(window_->activeObjects.begin() + i);
    				i--;
    			}
       		}
    	}
		if(!isBubbling) {
			first = 28*time - time*time;
			time += .7;
			second = 28*time - time*time;

			if(y_ >= WINDOW_MAX_Y/2 - 25 || velocityY_ > 0) {   
			    setPos(x_, y_ += first-second);
			}
			else if (velocityY_ < 0) {
				score -= (first-second);
				itrScore -= first-second;
  				n = score/4;
  				n=sprintf (number_,"%d", n);
				QString qScore(number_);
				window_->scoreDisplay->setText(qScore);
			}
   			velocityY_ = first-second;
   	 	
			if(!isShielded) {
				if(time < 1) QGraphicsPixmapItem::setPixmap(*crouched_);
				else if(abs(velocityY_) >= 15) QGraphicsPixmapItem::setPixmap(*halfCrouched_);
				else if(abs(velocityY_) < 15) QGraphicsPixmapItem::setPixmap(*extended_);
			}
			else {
			//set shield stuff here
			}
		}
		else {
	
		//set velocity to LOTS and change pixmap to bubbles
	
	
		}
	}
}
