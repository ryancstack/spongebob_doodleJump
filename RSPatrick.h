//
//  RSPatrick.h
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#ifndef ____RSPatrick__
#define ____RSPatrick__

#include <iostream>
#include "RSSpongebob.h"
#include "RSObject.h"

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class RSSpongebob;

class RSPatrick : public RSObject
{
public:
	RSPatrick(RSSpongebob *spongebob, QPixmap *patrick1, QPixmap *patrick2, QPixmap *patrick3, QPixmap *patrick4, MainWindow *window, int xloc, int yloc);
	void move();
private:
	RSSpongebob *spongebob_;
	QPixmap *patrick2_;
	QPixmap *patrick3_;
	QPixmap *patrick4_;
	int pictureSwitcher;
};

#endif /* defined(____RSPatrick__) */
