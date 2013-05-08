#Spongebob Escapes from Bikini Bottom

##PA6 Additions
  1. High Scores list
    * It saves the past 10 high scores.
    * You can access it from the start, pause, and game over screens.
  2. 3-levels
    * I did not implement this feature.
  3. At least 2 items that are player-aware
    * Every single one of my things are player-aware.
    * They all move in relation to spongebob's movement.


##Game Objects
  1. Platforms
    * Platforms will be what Spongebob jumps on to advance forward towards the surface.
    * As Spongebob moves upward, the platforms move downward when his velocity is positive. Otherwise, they stay in place.
    * ![alt text](https://raw.github.com/usc-csci102-spring2013/game_rstack/master/PA5_Images/1-c-extended.png?login=ryancstack&token=9a85973499c4bf8095df4c40e359c8d7 "Spongebob")
  2. Jellyfish
    * Jellyfish are enemies, and they wobble up and down and are randomly produced based on a probability of appearance.
    * They move along with platforms, so when Spongebob's velocity is positive, jellyfish move downward.
    * ![alt text](https://raw.github.com/usc-csci102-spring2013/game_rstack/master/PA5_Images/5-a-squid.png?login=ryancstack&token=09cd49fa5fdd884b495a6a22beab56e6 "Jellyfish")
  3. Bubbles
    * Bubbles are powerups. When Spongebob hits one, they boost him up in a stream of bubbles for a limited time and boost his velocity.
    * Bubbles will start at the top of the screen and will move slowly down unless Spongebob picks it up or goes off the screen.
    * ![alt text](https://raw.github.com/usc-csci102-spring2013/game_rstack/master/PA5_Images/bubble2.png?login=ryancstack&token=fd37cd44da2e1579aaa4dc9dc1dc3075 "Bubble") 
  4. Shield (Pencil)
    * When Spongebob holds the pencil, he is invincible to jellyfish and Patrick Star until he accidentally hits one of them and then the pencil is removed.
    * The pencil moves randomly on screen until it is pushed out of view or Spongebob picks it up.
    * ![alt text](https://raw.github.com/usc-csci102-spring2013/game_rstack/master/PA5_Images/pencil.png?login=ryancstack&token=56c1698273608cefadd60355b6900631 "Pencil")
  5. Patrick Star
    * Patrick Star is the main enemy. He moves slowly back and forth on the screen.
    * He exits the scene when Spongebob moves high enough as he pushes Patrick down or when Spongebob jumps on him.
    * ![alt text](https://raw.github.com/usc-csci102-spring2013/game_rstack/master/PA5_Images/6-a-patrick.png?login=ryancstack&token=c5996542f25aee11253e2a6961fc3205 "Patrick")

##Game Play
  * Gameplay is simple. All it involves is avoiding the enemies and trying to go as far as possible.
  * To move back and forth, all you need to use are the arrow keys and try and bounce on platforms.

###Controls
  * Left-Right arrows move Spongebob back and forth

###Score
  * Score is calculated by how high Spongebob gets. So every y-coord gain increases the score by one (when the platforms are pushed down).
  * You can gain extra points by eliminating enemies.

###Goals and Lives
  * You only have one life, so if you hit an enemy or miss a platform, you die.
  * Your goal is to try and get to the surface and achieve a high score.

##User Interface:
  * There is a front menu that has a name input, a start button, and a quit button.
  * During the game there is a pause button which when pressed displays a resume, reset, and quit button. Other than that there is a display that shows the name and score of the current game.


