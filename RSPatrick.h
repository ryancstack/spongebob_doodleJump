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
#include "RSObject.h"

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class RSSpongebob;

class RSPatrick : RSObject
{
public:
	RSPatrick(QPixmap *pic, MainWindow *window, int xloc, int yloc, int xV, int yV);
};

#endif /* defined(____RSPatrick__) */