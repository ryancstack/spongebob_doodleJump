//
//  RSPencil.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#include "RSSpongebob.h"
#include "RSPencil.h"

RSPencil::RSPencil(RSSpongebob *spongebob, QPixmap *pic, MainWindow *window, int xloc, int yloc) : RSObject(pic, window, xloc, yloc)
{
	spongebob_ = spongebob;
}

void RSPencil::move()
{

}
