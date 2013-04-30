/**
 * @author Ryan Stack
 * @date April 29, 2013
 */

#ifndef ____RSPatrick__
#define ____RSPatrick__

#include <iostream>
#include <string>
#include "RSSpongebob.h"
#include "RSObject.h"

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class RSSpongebob;

class RSPatrick : public RSObject
{
public:
   /**
    * Constructor for an RSPatrick object. It uses the RSObject as
    * the superclass constructor for most parameters.
    * @param spongebob Spongebob to reference velocity and y location
    * @param patrick1 Picture for animation 1
    * @param patrick2 Picture for animation 2
    * @param patrick3 Picture for animation 3
    * @param patrick4 Picture for animation 4
    * @param window Window the object is in to access variables
    * @param xloc X-coordinate for the object
    * @param yloc Y-coordinate for the object
    */
	RSPatrick(RSSpongebob *spongebob, QPixmap *patrick1, QPixmap *patrick2, QPixmap *patrick3, QPixmap *patrick4, MainWindow *window, int xloc, int yloc);
   /**
    * The move function moves patrick back and forth and then down when
    * spongebob moves past the half way point on the screen
    */
	void move();
   /**
    * @return name of object
    */
	std::string getName();
private:
   /** Pointer to a spongebob object */
	RSSpongebob *spongebob_;
   /** PNG for animation 2 */
	QPixmap *patrick2_;
   /** PNG for animation 3 */
	QPixmap *patrick3_;
   /** PNG for animation 4 */
	QPixmap *patrick4_;
   /** picture switcher iterator */
	int pictureSwitcher;
   /** name of object */
	std::string name_;
	
};

#endif /* defined(____RSPatrick__) */
