/**
 * @author Ryan Stack
 * @date April 29, 2013
 */

#ifndef ____RSPlatform__
#define ____RSPlatform__

#include <iostream>
#include <string>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "RSSpongebob.h"
#include "RSObject.h"

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class RSPlatform : public RSObject
{
public:
   /**
    * Constructor for an RSPlatform object. It uses the RSObject as
    * the superclass constructor for most parameters.
    * @param spongebob Spongebob to reference velocity and y location
    * @param pic Picture for platform
    * @param window Window the object is in to access variables
    * @param xloc X-coordinate for the object
    * @param yloc Y-coordinate for the object
    */
	RSPlatform(RSSpongebob *spongebob, QPixmap *pic, MainWindow *window, int xloc, int yloc);
   /**
    * Moves the platform down when spongebob goes past the
    * half-way point
    */
	void move();
   /**
    * @return name of object
    */
	std::string getName();
private:
   /** Pointer to a spongebob object */
	RSSpongebob *spongebob_;
   /** name of object */
   std::string name_;
};

#endif /* defined(____RSPlatform__) */
