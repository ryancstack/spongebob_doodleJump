


//
//  RSGUI.h
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#ifndef ____RSGUI__
#define ____RSGUI__

#include <iostream>
#include "RSObject.h"

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class MainWindow;

class RSGUI : public RSObject
{
public:
	RSGUI(QPixmap *pic, MainWindow *window, int xloc, int yloc);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void move();
};
#endif /* defined(____RSGUI__) */
