//
//  RSSpongebob.h
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#ifndef ____RSSpongebob__
#define ____RSSpongebob__

#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "RSObject.h"

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class MainWindow;

class RSSpongebob : public RSObject
{
public:
	RSSpongebob(QPixmap *crouched, QPixmap *halfCrouched, QPixmap *extended, QPixmap *pCrouched, QPixmap *pHalfCrouched, QPixmap *pExtended, QPixmap *fallingA, QPixmap *fallingB, MainWindow *window, int xloc, int yloc, int xV, int yV);
	void move();
public:
	double time;
	QPixmap *crouched_;
	QPixmap *halfCrouched_;
	QPixmap *extended_;
	QPixmap *pCrouched_;
	QPixmap *pHalfCrouched_;
	QPixmap *pExtended_;
	QPixmap *fallingA_;
	QPixmap *fallingB_;
	bool hasJumped;
	int score;
};

#endif /* defined(____RSSpongebob__) */
