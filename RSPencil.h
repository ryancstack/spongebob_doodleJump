/**
 * @author Ryan Stack
 * @date April 29, 2013
 */

#ifndef ____RSPencil__
#define ____RSPencil__

#include <iostream>
#include <string>
#include "RSSpongebob.h"
#include "RSObject.h"

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class RSSpongebob;
class MainWindow;

class RSPencil : public RSObject
{
public:
   /**
    * Constructor for an RSPencil object. It uses the RSObject as
    * the superclass constructor for most parameters.
    * @param spongebob Spongebob to reference velocity and y location
    * @param pic Picture for pencil
    * @param window Window the object is in to access variables
    * @param xloc X-coordinate for the object
    * @param yloc Y-coordinate for the object
    */
	RSPencil(RSSpongebob *spongebob, QPixmap *pic, MainWindow *window, int xloc, int yloc);
   /**
    * Moves the pencil randomly around until spongebob 
    * pushes it off the screen
    */
	void move();
   /**
    * @return name of object
    */
	std::string getName();
private:
   /** Pointer to a spongebob object */
	RSSpongebob *spongebob_;
   /** Name of object */
	std::string name_;
};
#endif /* defined(____RSPencil__) */
