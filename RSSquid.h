/**
 * @author Ryan Stack
 * @date April 29, 2013
 */

#ifndef ____RSSquid__
#define ____RSSquid__

#include <iostream>
#include <string>
#include "RSSpongebob.h"
#include "RSObject.h"

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class RSSpongebob;

class RSSquid : public RSObject
{
public:
   /**
    * Constructor for an RSSquid object. It has all the
    * accessor and setter methods to change all these
    * @param squid1 Picture for squid animation 1
    * @param squid2 Picture for squid animation 2
    * @param squid3 Picture for squid animation 3
    * @param squid4 Picture for squid animation 4
    * @param squid5 Picture for squid animation 5
    * @param squid6 Picture for squid animation 6
    * @param hit Picture for squid animation hit
    * @param window Window the object is in to access variables
    * @param xloc X-coordinate for the object
    * @param yloc Y-coordinate for the object
    */
	RSSquid(RSSpongebob *spongebob, QPixmap *squid1, QPixmap *squid2, QPixmap *squid3, QPixmap *squid4, QPixmap *squid5, QPixmap *squid6, QPixmap *hit, MainWindow *window, int xloc, int yloc);
   /**
    * Moves up and down in a sine curve
    */
	void move();
   /**
    * Does the animation for when he is hit
    */
	void hit();
   /**
    * @return name of object
    */
	std::string getName();
private:
   /** time for sine curve*/
	double time;
   /** first time for sine curve */
	float first;
   /** second time for sine curve*/
	float second;
   /** Pointer to a spongebob object*/
	RSSpongebob *spongebob_;
   /** PNG for squid animation 1 */
	QPixmap *squid1_;
   /** PNG for squid animation 2 */
	QPixmap *squid2_;
   /** PNG for squid animation 3 */
	QPixmap *squid3_;
   /** PNG for squid animation 4 */
	QPixmap *squid4_;
   /** PNG for squid animation 5 */
	QPixmap *squid5_;
   /** PNG for squid animation 6 */
	QPixmap *squid6_;
   /** PNG for squid animation hit */
	QPixmap *hit_;
   /** picture switcher iterator */
	int pictureSwitcher;
   /** name of object */
	std::string name_;
};

#endif /* defined(____RSSquid__) */
