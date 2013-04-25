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
#include <QGraphicsPixmapItem>
#include "RSObject.h"

class RSSpongebob : public RSObject
{
public:
	RSSpongebob(QPixmap *pic, MainWindow *window, int xloc, int yloc, int xV, int yV);
	void move();
};

#endif /* defined(____RSSpongebob__) */
