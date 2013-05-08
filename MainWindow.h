/**
 * @author Ryan Stack
 * @date April 29, 2013
 */

#ifndef ____MainWindow__
#define ____MainWindow__

#include <iostream>
#include <algorithm>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QListView>
#include <QStringListModel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <vector>
#include "RSGUI.h"
#include "RSBubble.h"
#include "RSPatrick.h"
#include "RSSquid.h"
#include "RSPencil.h"
#include "RSPlatform.h"
#include "RSObject.h"
#include "RSSpongebob.h"


#define WINDOW_MAX_X 320
#define WINDOW_MAX_Y 568

struct Score {
  int personalScore;
  std::string personalName;
  bool operator() (Score* lhs, Score* rhs)
  { 
  	return lhs->personalScore < rhs->personalScore; 
  }
};

class MainWindow : public QWidget {
   Q_OBJECT
   
public:
   /**
    * Default constructor that creates a QVBoxLayout that
    * holds a View to display the scene and the gameplay.
    */
   explicit MainWindow();
   /**
    * Deletes all dynamically allocated QObjects,
    * QGraphics objects, and the timer.
    */
   ~MainWindow();
   /**
    * Displays the view and all the items set up for viewing.
    */
   void show();
   /**
    * Populates from -50 to the max window size with a number
    * of platforms to initially create a playable game.
    */
   void populateInitialPlatforms();
   /**
    * Populates a variable number of platforms that decreases
    * every 1000 points gained.
    */
   void populateFrequencyPlatforms();
   /**
    * Populates a squid 30% of the time and increases as
    * score increases.
    */
   void populateSquids();
   /**
    * Populates a bubble 2% of the time and decreases as
    * score increases.
    */
   void populateBubbles();
   /**
    * Populates a patrick 10% of the time and increases as
    * score increases.
    */
   void populatePatricks();
   /**
    * Populates a squid 30% of the time and increases as
    * score increases.
    */
   void populatePencils();
   /**
    * Restarts the game and re-populates the screen.
    */
   void restartPressed();
   /**
    * Starts the game and populates the screen with platforms
    * and spongebob.
    */
   void startPressed();
   /**
    * Pauses the game by stopping the timer and displaying
    * a screen with three buttons: Quit, Resume, Restart.
    */
   void pausePressed();
   /**
    * Resumes the game by removing the pause screen and
    * starting the timer.
    */
   void resumePressed();
   /**
    * Determines whether whoever calls this function appears or not.
    * @param percentage The desired percentage for things to appear
    * @return true if it appears, false if it isn't
    */
   bool probabilityCreator(int percentenge);
   
   void closeEvent(QCloseEvent *e);
   
   void quitPressed();
   
   void highScoresPressed();
   
   void backPressed();
   
private:
   /** The timer that serves as the clockwork for animation */
   QTimer *timer;
   /** The scene that displays the game */
   QGraphicsScene *scene;
   /** The view that displays the scene */
   QGraphicsView *view;
   /** The layout that holds the view and scene */
   QVBoxLayout *topLayout;
   
   /** Title picture */
   RSGUI *title;
   /** Pause button */
   RSGUI *pause;
   /** Start button */
   RSGUI *start;
   /** Picture that prompts user to enter name */
   RSGUI *enterNamePic;
   /** Background circle for name */
   RSGUI *nameBG;
   /** Background circle for score */
   RSGUI *scoreBG;
   /** Pause screen background */
   RSGUI *pauseSplash;
   /** Game over screen background*/
   RSGUI *gameoverSplash;
   /** Resume button */
   RSGUI *resume;
   /** Quit button */
   RSGUI *quit_;
   /** Restart button */
   RSGUI *restart;
   /** Text box for player name*/
   QLineEdit *playerName;
   /** Display for player name */
   QGraphicsSimpleTextItem *playerDisplay;
	
   /** PNG for title */
   QPixmap *titlePic;
	/** PNG for pause background */
   QPixmap *pauseBG;
   /** PNG for start button */
   QPixmap *startButton;
   /** PNG for pause button */
   QPixmap *pauseButton;
   /** PNG for resume button */
   QPixmap *resumeButton;
   /** PNG for restart button */
   QPixmap *restartButton;
   /** PNG for quit button */
   QPixmap *quitButton;
   /** PNG for the enter name picture*/
   QPixmap *enterName;
   /** PNG for backgrounds of name and score */
   QPixmap *textBG;
   /** PNG for gameover background */
   QPixmap *gameoverBG;
   
   RSGUI *highScoresSplash;
   QPixmap *highScoresBG;
   
   RSGUI *backButton;
   QPixmap *backButtonPic;
   
   RSGUI *highScoresButton;
   QPixmap *highScoresButtonPic;
   
	QGraphicsTextItem *scoresList;

   
   //spongebob
   /** Pointer to a spongebob object*/
   RSSpongebob *spongebob;
   /** Spongebob crouched PNG */
   QPixmap *spongebob_crouched;
   /** Spongebob half crouched PNG */
   QPixmap *spongebob_half_crouched;
   /** Spongebob extended PNG */
   QPixmap *spongebob_extended;
   /** Spongebob pencil crouched PNG */
   QPixmap *spongebob_p_crouched;
   /** Spongebob pencil half crouched PNG */
   QPixmap *spongebob_p_half_crouched;
   /** Spongebob pencil extended PNG */
   QPixmap *spongebob_p_extended;
   /** Spongebob bubble 1 PNG */
   QPixmap *spongebob_bubble1;
   /** Spongebob bubble 2 PNG */
   QPixmap *spongebob_bubble2;
   
   //patrick
   /** Pointer to a patrick object */
   RSPatrick *patrick;
   /** Patrick animation 1 PNG */
   QPixmap *patrick1;
   /** Patrick animation 2 PNG */
   QPixmap *patrick2;
   /** Patrick animation 3 PNG */
   QPixmap *patrick3;
   /** Patrick animation 4 PNG */
   QPixmap *patrick4;
   
   //squid
   /** Pointer to a squid object */
   RSSquid *squid;
   /** Squid animation 1 PNG */
   QPixmap *squid1;
   /** Squid animation 2 PNG */
   QPixmap *squid2;
   /** Squid animation 3 PNG */
   QPixmap *squid3;
   /** Squid animation 4 PNG */
   QPixmap *squid4;
   /** Squid animation 5 PNG */
   QPixmap *squid5;
   /** Squid animation 6 PNG */
   QPixmap *squid6;
   /** Squid animation 7 PNG */
   QPixmap *squidHit;
   
   //bubble
   /** Pointer to a bubble object */
   RSBubble *bubble;
   /** Bubble PNG */
   QPixmap *bubblePic;
   
   //pencil
   /** Pointer to a pencil object */
   RSPencil *pencil;
   /** Pencil PNG */
   QPixmap *pencilPic;
   
   
   /** Sets background to Bikini Bottom */
   QPalette background;
   
   
   //platform
   /** Pointer to a platform object */
   RSPlatform *platform;
   /** Platform PNG */
   QPixmap *platformPic;
   
   /** Random y location */
   int randY;
   /** Random x location */
   int randX;
   /** Boolean that describes whether a location is good to place an object */
   bool goodLoc;
   
   /** Frequency iterator for bad items */
   int badItemCounter;
   /** Frequency iterator for good items */
   int goodItemCounter;
   /** Score object to keep track of high scores */
   Score *highScore;
   
   
   

public:
   /** A vector of active objects on the screen */
   std::vector<RSObject*> activeObjects;
   /** Text to display the score */
   QGraphicsSimpleTextItem *scoreDisplay;
   /** Determines how many boards to be placed */
   int frequencyCounter;
   /** Iterator that increases every timer fire */
   int counter;
   /** Boolean that describes whether a squid is on screen or not */
   bool squidActive;
   /** Boolean that describes whether a bubble is on screen or not */
   bool bubbleActive;
   /** Boolean that describes whether a patrick is on screen or not */
   bool patrickActive;
   /** Boolean that describes whether a pencil is on screen or not */
   bool pencilActive;
   /**A vector of high scores **/
   std::vector<Score*> highScores;
   
 
protected:
   /** 
    * Controls when the left are right keys are pressed and moves
    * spongebob back and forth accordingly
    * @param e The key being pressed
    */
   void keyPressEvent(QKeyEvent *e);

   

public slots:
   /**
    * Moves everything, populates items, and removes items
    * that are off screen.
    */
   void timerAnimation();
};


#endif /* defined(____MainWindow__) */
