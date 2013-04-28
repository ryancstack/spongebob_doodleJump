//
//  RSSquid.h
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#ifndef ____RSSquid__
#define ____RSSquid__

#include <iostream>
#include "RSSpongebob.h"
#include "RSObject.h"

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class RSSpongebob;

class RSSquid : public RSObject
{
public:
	RSSquid(RSSpongebob *spongebob, QPixmap *squid1, QPixmap *squid2, QPixmap *squid3, QPixmap *squid4, QPixmap *squid5, QPixmap *squid6, QPixmap *hit, MainWindow *window, int xloc, int yloc);
	void move();
	void hit();
private:
	double time;
	float first;
	float second;
	RSSpongebob *spongebob_;
	QPixmap *squid1_;
	QPixmap *squid2_;
	QPixmap *squid3_;
	QPixmap *squid4_;
	QPixmap *squid5_;
	QPixmap *squid6_;
	QPixmap *hit_;
	int pictureSwitcher;
};

#endif /* defined(____RSSquid__) */
