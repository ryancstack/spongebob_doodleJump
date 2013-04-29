//
//  RSPencil.h
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

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
	RSPencil(RSSpongebob *spongebob, QPixmap *pic, MainWindow *window, int xloc, int yloc);
	void move();
	std::string getName();
private:
	RSSpongebob *spongebob_;
	std::string name_;
};
#endif /* defined(____RSPencil__) */
