//
//  RSObject.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#include "RSObject.h"
#include "MainWindow.h"

RSObject::RSObject(QPixmap *pic, MainWindow *window, int xloc, int yloc, int xV, int yV)
{
	picture_ = pic;
	window_ = window;
	x_ = xloc;
	y_ = yloc;
	velocityX_ = xV;
	velocityY_ = yV;
	
	QGraphicsPixmapItem::setPixmap( *pic);
	
	QGraphicsPixmapItem::setPos(xloc, yloc);
}

void RSObject::setX(int x)
{
	x_ = x;
}

void RSObject::setY(int y)
{
	y_ = y;
}

void RSObject::setVelocityX(int vX)
{
	velocityX_ = vX;
}

void RSObject::setVelocityY(int vY)
{
	velocityY_ = vY;
}

int RSObject::getX()
{
	return x_;
}

int RSObject::getY()
{
	return y_;
}

int RSObject::getVelocityX()
{
	return velocityX_;
}

int RSObject::getVelocityY()
{
	return velocityY_;
}

void RSObject::setPixmap(QPixmap *pic)
{
	picture_ = pic;
}

void RSObject::setPos(int x, int y)
{
	QGraphicsPixmapItem::setPos(x, y);
}
