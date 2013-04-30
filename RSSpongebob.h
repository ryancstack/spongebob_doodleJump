/**
 * @author Ryan Stack
 * @date April 29, 2013
 */

#ifndef ____RSSpongebob__
#define ____RSSpongebob__

#include <iostream>
#include <QPixmap>
#include <string>
#include <QGraphicsPixmapItem>
#include "RSObject.h"

#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

class MainWindow;

class RSSpongebob : public RSObject
{
public:
   /**
    * Constructor for an RSSpongebob object. It has all the
    * accessor and setter methods to change all these
    * @param crouched Picture for crouched spongebob
    * @param halfCrouched Picture for half crouched spongebob
    * @param extended Picture for extended spongebob
    * @param pCrouched Picture for pencil crouched spongebob
    * @param pHalfCrouched Picture for pencil half crouched spongebob
    * @param pExtended Picture for pencil extended spongebob
    * @param bubble1 Picture for bubble animation 1
    * @param bubble2 Picture for bubble animation 2
    * @param window Window the object is in to access variables
    * @param xloc X-coordinate for the object
    * @param yloc Y-coordinate for the object
    */
	RSSpongebob(QPixmap *crouched, QPixmap *halfCrouched, QPixmap *extended, QPixmap *pCrouched, QPixmap *pHalfCrouched, QPixmap *pExtended, QPixmap *bubble1, QPixmap *bubble2, MainWindow *window, int xloc, int yloc);
   /**
    * Extensive move function that determines whether it hits
    * an enemy, a pencil, a bubble, or a platform and performs
    * according to the design document.
    */
	void move();
   /**
    * @return name of object
    */
	std::string getName();
public:
   /** time for quadratic equation*/
	double time;
   /** PNG spongebob crouched */
	QPixmap *crouched_;
   /** PNG spongebob half crouched */
	QPixmap *halfCrouched_;
   /** PNG spongebob extended */
	QPixmap *extended_;
   /** PNG pencil crouched */
	QPixmap *pCrouched_;
   /** PNG pencil half crouched */
	QPixmap *pHalfCrouched_;
   /** PNG pencil extended*/
	QPixmap *pExtended_;
   /** PNG bubble animation 1 */
	QPixmap *bubble1_;
   /** PNG bubble animation 2*/
	QPixmap *bubble2_;
   /** score for how high spongebob goes */
	int score;
   /** score to reset for item frequency */
	int itrScore;
   /** score for platform frequency */
	int frequencyScore;
   /** Boolean that determines whether spongebob has hit a bad guy or not*/
	bool hasHitBadGuy;
   /** Boolean that determines whether shield is activated */
	bool isShielded;
   /** Boolean that determines whether bubble is activated*/
	bool isBubbling;
   /** Boolean that determines if you're dead */
	bool isDead;
private:
   /** first time for quadratic */
	double first;
   /** second time for quadratic */
	double second;
   /** array for converting to qString */
	char number_ [11];
   /** number for converting qString */
	int n;
   /** name of object */
	std::string name_;
   /** temp y location */
	int tempY_;
   /** temp x location */
	int tempVY_;
	
};

#endif /* defined(____RSSpongebob__) */
