#Spongebob Escapes from Bikini Bottom

##Game Objects
  1. Platforms
    * Platforms will be what Spongebob jumps on to advance forward towards the surface.
    * As Spongebob moves upward, the platforms move downward when his velocity is positive. Otherwise, they stay in place.
    * ![alt text](https://raw.github.com/usc-csci102-spring2013/game_rstack/master/PA5_Images/1-c-extended.png?login=ryancstack&token=9a85973499c4bf8095df4c40e359c8d7 "Spongebob")
  2. Jellyfish
    * Jellyfish are enemies, and they sit on platforms and wobble back and forth.
    * They move along with platforms, so when Spongebob's velocity is positive, jellyfish move downward.
    * ![alt text](https://raw.github.com/usc-csci102-spring2013/game_rstack/master/PA5_Images/5-a-squid.png?login=ryancstack&token=09cd49fa5fdd884b495a6a22beab56e6 "Jellyfish")
  3. Bubbles
    * Bubbles are powerups. When Spongebob hits one, they boost him up in a stream of bubbles for a limited time and boost his velocity.
  *Bubbles will either sit on platforms or move back and forth across the screen until Spongebob hits it or moves off the screen.
  *![alt text](https://raw.github.com/usc-csci102-spring2013/game_rstack/master/PA5_Images/bubble2.png?login=ryancstack&token=fd37cd44da2e1579aaa4dc9dc1dc3075 "Bubble") 
  4.Shield (Pencil)
  *When Spongebob holds the pencil, he is invincible to jellyfish and Patrick Star.
  *The pencil sits on top of a platform and moves with the platform.
  *The pencil disappears after a few seconds of activation.
  *![alt text](https://raw.github.com/usc-csci102-spring2013/game_rstack/master/PA5_Images/pencil.png?login=ryancstack&token=56c1698273608cefadd60355b6900631 "Pencil")
  5.Patrick Star
  *Patrick Star is the main enemy. He moves slowly back and forth, up and down in the screen.
  *He exits the scene when Spongebob moves high enough as he pushes Patrick down.
  *![alt text](https://raw.github.com/usc-csci102-spring2013/game_rstack/master/PA5_Images/6-a-patrick.png?login=ryancstack&token=c5996542f25aee11253e2a6961fc3205 "Patrick")

##Game Play
  *Gameplay is simple. All it involves is avoiding the enemies and trying to go as far as possible.
  *Shooting the enemies might be implemented later...

###Controls
  *Left-Right arrows move Spongebob back and forth
  *P pauses the game
  *Spacebar might shoot projectiles from Spongebob in a future version

###Score
  *Score is calculated by how high Spongebob gets. So every y-coord increase increases the score by one.
  *You can gain extra points by eliminating enemies.

###Goals and Lives
  *You only have one life, so if you hit an enemy or miss a platform, you die.
  *Your goal is to try and get to the surface and achieve a high score.

##User Interface:
![alt text](http://i.imgur.com/Cat6bua.png "Layout")


