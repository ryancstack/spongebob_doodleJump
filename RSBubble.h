//
//  RSBubble.h
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#ifndef ____RSBubble__
#define ____RSBubble__

#include <iostream>
#include "RSObject.h"

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class RSSpongebob;

class RSBubble : RSObject
{
public:
	RSBubble(QPixmap *pic, MainWindow *window, int xloc, int yloc, int xV, int yV);
};
#endif /* defined(____RSBubble__) */
