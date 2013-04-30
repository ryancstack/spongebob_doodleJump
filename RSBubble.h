/**
 * @author Ryan Stack
 * @date April 29, 2013
 */

#ifndef ____RSBubble__
#define ____RSBubble__

#include <iostream>
#include "RSSpongebob.h"
#include "RSObject.h"

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class RSSpongebob;

class RSBubble : public RSObject
{
public:
   /**
    * Constructor for an RSBubble object
    * @param spongebob Spongebob to use his location and velocity
    * @param pic Picture for bubble
    * @param window Window the bubble is in to access variables
    * @param xloc X-coordinate for the object
    * @param yloc Y-coordinate for the object
    */
	RSBubble(RSSpongebob *spongebob, QPixmap *pic, MainWindow *window, int xloc, int yloc);
   /**
    * Moves the bubble down the screen and increases velocity
    * when spongebob moves past the mid location of the screen.
    */
	void move();
   /**
    * Returns the name of the creature
    * @return name of creature
    */
	std::string getName();
private:
   /** Pointer to a spongebob object*/
	RSSpongebob *spongebob_;
   /** Name of the object */
	std::string name_;
};
#endif /* defined(____RSBubble__) */
