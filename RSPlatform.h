//
//  RSPlatform.h
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#ifndef ____RSPlatform__
#define ____RSPlatform__

#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "RSSpongebob.h"
#include "RSObject.h"

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class RSPlatform : public RSObject
{
public:
	RSPlatform(RSSpongebob *spongebob, QPixmap *pic, MainWindow *window, int xloc, int yloc);
	void move();

private:
	RSSpongebob *spongebob_;
    double time;
};

#endif /* defined(____RSPlatform__) */
