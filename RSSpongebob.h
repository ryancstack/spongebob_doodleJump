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
#include <string>
#include <QGraphicsPixmapItem>
#include "RSObject.h"

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class MainWindow;

class RSSpongebob : public RSObject
{
public:
	RSSpongebob(QPixmap *crouched, QPixmap *halfCrouched, QPixmap *extended, QPixmap *pCrouched, QPixmap *pHalfCrouched, QPixmap *pExtended, MainWindow *window, int xloc, int yloc);
	void move();
	std::string getName();
public:
	double time;
	QPixmap *crouched_;
	QPixmap *halfCrouched_;
	QPixmap *extended_;
	QPixmap *pCrouched_;
	QPixmap *pHalfCrouched_;
	QPixmap *pExtended_;
	int score;
	int itrScore;
	bool hasHitBadGuy;
	bool isShielded;
	bool isBubbling;
	bool isDead;
private:
	double first;
	double second;
	char number_ [11];
	int n;
	std::string name_;
	int tempY_;
	int tempVY_;
	
};

#endif /* defined(____RSSpongebob__) */
