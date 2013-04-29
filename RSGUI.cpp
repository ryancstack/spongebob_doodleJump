//
//  RSGUI.cpp
//  
//
//  Created by Ryan Stack on 4/22/13.
//
//

#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include "MainWindow.h"
#include "RSGUI.h"


RSGUI::RSGUI(QPixmap *pic, MainWindow *window, int xloc, int yloc) : RSObject(pic, window, xloc, yloc) {}

void RSGUI::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if(event->button() == Qt::LeftButton) {
		if(x_ == WINDOW_MAX_X-39 && y_ == 2 )
			window_->pausePressed();
		else if(x_ == WINDOW_MAX_X/2-75 && y_ == WINDOW_MAX_Y/2-37)
			window_->startPressed();
		else if(x_ == WINDOW_MAX_X/2-75 && y_ ==WINDOW_MAX_Y/2 +30)
			qApp->quit();
		else if(x_ == WINDOW_MAX_X/2-75 && y_ == WINDOW_MAX_Y/2-20)
			window_->restartPressed();
		else if(x_ == WINDOW_MAX_X/2-75 && y_ == WINDOW_MAX_Y/2-70)
			window_->resumePressed();
	}
		
}

void RSGUI::move() {}
