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

class RSSquid : RSObject
{
public:
	RSSquid(RSSpongebob *spongebob, QPixmap *pic, MainWindow *window, int xloc, int yloc, int xV, int yV);
};

#endif /* defined(____RSSquid__) */
