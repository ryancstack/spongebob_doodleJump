/**
 * @author Ryan Stack
 * @date April 29, 2013
 */

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
   /**
    * Constructor for an RSGUI object. The object is simply a
    * way to add picture, button, or background
    * @param pic Picture for graphics item
    * @param window Window the bubble is in to access variables
    * @param xloc X-coordinate for the object
    * @param yloc Y-coordinate for the object
    */
	RSGUI(QPixmap *pic, MainWindow *window, int xloc, int yloc);
   /**
    * Handles when a button is pressed
    * @param event Mouse click event to make these act like buttons
    */
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
   /**
    * Isn't implemented but if the button wants to move there is the
    * possibility of it moving.
    */
	void move();
};
#endif /* defined(____RSGUI__) */
