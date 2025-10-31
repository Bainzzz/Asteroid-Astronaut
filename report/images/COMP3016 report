[3019 Report]{.c0}

[Asteroid Astronaut ]{.c15 .c18}

[]{.c0}

[Gameplay ]{.c7}

[The game asteroid astronaut runs in the terminal and uses ASCII
formatting to make up the graphics. The game is influenced by classic
asteroid shooter games and follows early mobile/browser flash game
principles remaining simple but difficult. The player must move the
spaceship ( \> ) around the stage destroying as many asteroids ( @ )
while ensuring none of them hit the player otherwise they will lose a
life, the game starts off simple but becomes overwhelming after some
time. The goal of the game is to obtain the highest score possible with
the game tracking and ordering the highest 5 scores while displaying
them at all times. ]{.c0}

[]{.c0}

[Dependencies]{.c7}

[Asteroid Astronaut utilises standard C++ libraries ]{.c0}

- [\<iostream\>  - console input/output and rendering ]{.c0}
- [\<vector\> -managing collections]{.c0}
- [\<]{.c15}[cctype]{.c15}[\> -case insensitive input handling ]{.c0}
- [\<conio.h\>]{.c0}
- [\<windows.h\>]{.c0}
- [\<algorithm\> -for vector operations ]{.c0}
- [\<]{.c15}[iomanip]{.c15}[\> -text alignment ]{.c0}
- [\<]{.c15}[fstream]{.c15}[\> -reading/writing highscores ]{.c0}

[]{.c0}

[AI implementation]{.c15 .c19}[ ]{.c0}

[AI (Grok) was used as an assistive tool throughout development. AI was
used to provide code assistance, particularly for debugging one scenario
where AI accelerated the debugging process by trying to get the
highscores system working. The implementation of this system took a
while and I made plenty of simple mistakes doing this ranging from file
loading errors to simple display errors using
'\<]{.c15}[iomanip]{.c15}[\>'. Using AI, I was able to find these errors
much quicker and get the Highscore system implemented at a much faster
rate.]{.c0}

[]{.c0}

[Beyond debugging I used AI as a mentor for C++ and OOP practices and
used it when I was ever stuck or unsure. I often shared code sections
for review and received suggestions; however, all prompts were never
applied blindly and I ensured any recommendations aligned with my
original design goals and I understood how I was applying any snippets
of code.]{.c0}

[]{.c0}

[In summary: ]{.c0}

- [Ai accelerated debugging ]{.c0}
- [Deepened C++ understanding ]{.c0}
- [I remained the lead developer and didn\'t follow AI blindly ]{.c0}
- [Final implementation is my own with AI serving as a tool ]{.c0}

[]{.c0}

[]{.c7}

[]{.c7}

[]{.c7}

[]{.c7}

[]{.c7}

[Testing ]{.c7}

[]{.c0}

+----------------+--------------+----------------+----------------+---------------+
| [Test Cases    | [Description | [Expected      | [Actual        | [Pass?]{.c14} |
| ]{.c14}        | ]{.c14}      | ]{.c14}        | ]{.c14}        |               |
+----------------+--------------+----------------+----------------+---------------+
| [Movement      | [Pressing    | [Player moves  | [Player moves  | [Yes ]{.c0}   |
| ]{.c0}         | WASD ]{.c0}  | Up (W)]{.c0}   | Up (W)]{.c0}   |               |
|                |              |                |                |               |
|                |              | [Down          | [Down          |               |
|                |              | (S)]{.c0}      | (S)]{.c0}      |               |
|                |              |                |                |               |
|                |              | [Left (A)      | [Left (A)      |               |
|                |              | ]{.c0}         | ]{.c0}         |               |
|                |              |                |                |               |
|                |              | [Right         | [Right         |               |
|                |              | (D)]{.c0}      | (D)]{.c0}      |               |
+----------------+--------------+----------------+----------------+---------------+
| [Shooting      | [Pressing    | [A bullet is   | [A bullet is   | [Yes ]{.c0}   |
| ]{.c0}         | Space ]{.c0} | created at x + | created at x + |               |
|                |              | 1 of the       | 1 of the       |               |
|                |              | player and     | player and     |               |
|                |              | travels right  | travels right  |               |
|                |              | ]{.c0}         | ]{.c0}         |               |
+----------------+--------------+----------------+----------------+---------------+
| [Boundary      | [Move player | [Player stays  | [Player stays  | [Yes ]{.c0}   |
| (player)]{.c0} | to x=0 and   | at x=0]{.c0}   | at x=0]{.c0}   |               |
|                | press A      |                |                |               |
|                | ]{.c0}       |                |                |               |
+----------------+--------------+----------------+----------------+---------------+
| [Boundary      | [Let bullet  | [Bullet or     | [Bullet or     | [Yes ]{.c0}   |
| ]{.c0}         | and asteroid | asteroid       | asteroid       |               |
|                | leave the    | erased ]{.c0}  | erased]{.c0}   |               |
| [(asteroid,    | screen       |                |                |               |
| bullet)]{.c0}  | ]{.c0}       |                |                |               |
+----------------+--------------+----------------+----------------+---------------+
| [Asteroid hit  | [Let         | [Asteroid      | [Asteroid      | [Yes ]{.c0}   |
| player ]{.c0}  | asteroid hit | destroyed and  | destroyed and  |               |
|                | player       | life -1 ]{.c0} | life -1 ]{.c0} |               |
|                | ]{.c0}       |                |                |               |
+----------------+--------------+----------------+----------------+---------------+
| [Close game    | [Press Q     | [Game stops    | [Game stops    | [Yes ]{.c0}   |
| ]{.c0}         | ]{.c0}       | running ]{.c0} | running ]{.c0} |               |
+----------------+--------------+----------------+----------------+---------------+
| [Bullet hit    | [Press space | [Both          | [In some cases | [No ]{.c0}    |
| asteroid       | and make a   | destroyed and  | bullet passes  |               |
| ]{.c0}         | bullet hit   | +10 score      | through        |               |
|                | asteroid     | ]{.c0}         | asteroid, but  |               |
|                | ]{.c0}       |                | doesn't occur  |               |
|                |              |                | too often      |               |
|                |              |                |  ]{.c0}        |               |
+----------------+--------------+----------------+----------------+---------------+
| [High score    | [End with    | [highscore.txt | [highscore.txt | [Yes ]{.c0}   |
| save/load      | score of     | displays with  | displays with  |               |
| ]{.c0}         | 30]{.c0}     | ]{.c0}         | ]{.c0}         |               |
|                |              |                |                |               |
|                |              | [30 0 0 0 0    | [30 0 0 0 0    |               |
|                |              | ]{.c0}         | ]{.c0}         |               |
|                |              |                |                |               |
|                |              | []{.c0}        | []{.c0}        |               |
|                |              |                |                |               |
|                |              | [When run game | [When run game |               |
|                |              | high score     | high score     |               |
|                |              | reads 30]{.c0} | reads 30]{.c0} |               |
+----------------+--------------+----------------+----------------+---------------+

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[Diagrams/screenshots ]{.c7}

[]{.c0}

[Initial ASCII diagram when generating the idea ]{.c3}

[![](images/image6.png){style="width: 432.50px; height: 238.52px; margin-left: 0.00px; margin-top: 0.00px; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px);"}]{style="overflow: hidden; display: inline-block; margin: 0.00px 0.00px; border: 0.00px solid #000000; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px); width: 432.50px; height: 238.52px;"}

[]{.c0}

[]{.c0}

[Key]{.c7}

- [\> - Spaceship (player)]{.c0}
- [O - Bullets (shot by player)]{.c0}
- [P - PowerUp]{.c0}
- [@ - Asteroids ]{.c0}
- [. - Part of stage]{.c0}

[]{.c0}

[![](images/image4.png){style="width: 392.50px; height: 260.80px; margin-left: 0.00px; margin-top: 0.00px; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px);"}]{style="overflow: hidden; display: inline-block; margin: 0.00px 0.00px; border: 0.00px solid #000000; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px); width: 392.50px; height: 260.80px;"}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[Screenshot of the game in its current state]{.c3}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[![](images/image1.png){style="width: 369.50px; height: 184.23px; margin-left: 0.00px; margin-top: 0.00px; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px);"}]{style="overflow: hidden; display: inline-block; margin: 0.00px 0.00px; border: 0.00px solid #000000; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px); width: 369.50px; height: 184.23px;"}

[]{.c0}

[Vision for game ]{.c3}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[Game mechanics and implementation  ]{.c7}

- [Movement: player movement is controlled with standard WASD controls
  where each input updates player's x/y position by 1(1.0f) and limited
  to constraints of the map ]{.c0}

[]{.c0}

- [Shooting: pressing SpaceBar creates a bullet in front of the player
  that moves right by x += 1, the player can only do this after the
  500ms cooldown has elapsed]{.c0}

[]{.c0}

- [Asteroid spawning/movement: every frame there's a 10% chance of an
  asteroid spawning at the right edge and moves left towards the player
  ]{.c0}[![](images/image3.png){style="width: 416.92px; height: 47.35px; margin-left: 0.00px; margin-top: 0.00px; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px);"}]{style="overflow: hidden; display: inline-block; margin: 0.00px 0.00px; border: 0.00px solid #000000; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px); width: 416.92px; height: 47.35px;"}

[]{.c0}

- [Collisions:nested iterator loop checks collision match ]{.c0}

<!-- -->

- [Bullet:asteroid collisions = erase both and add 10 score ]{.c0}
- [Player:asteroid = minus 1 life and erase asteroid ]{.c0}

[![](images/image8.png){style="width: 305.50px; height: 57.24px; margin-left: 0.00px; margin-top: 0.00px; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px);"}]{style="overflow: hidden; display: inline-block; margin: 0.00px 0.00px; border: 0.00px solid #000000; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px); width: 305.50px; height: 57.24px;"}

- [Lives: levels decrease on asteroid collision but when lives reach 0
  the game ends]{.c0}

[ ]{.c0}

[![](images/image10.png){style="width: 353.50px; height: 62.83px; margin-left: 0.00px; margin-top: 0.00px; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px);"}]{style="overflow: hidden; display: inline-block; margin: 0.00px 0.00px; border: 0.00px solid #000000; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px); width: 353.50px; height: 62.83px;"}

- [Highscores: ]{.c0}

<!-- -->

- [Reads highscores from 'highscores.txt' at the start of the game and
  loads them onto display for player to view
  ]{.c0}[![](images/image5.png){style="width: 155.50px; height: 49.98px; margin-left: 0.00px; margin-top: 0.00px; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px);"}]{style="overflow: hidden; display: inline-block; margin: 0.00px 0.00px; border: 0.00px solid #000000; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px); width: 155.50px; height: 49.98px;"}

[![](images/image9.png){style="width: 278.16px; height: 69.00px; margin-left: 0.00px; margin-top: 0.00px; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px);"}]{style="overflow: hidden; display: inline-block; margin: 0.00px 0.00px; border: 0.00px solid #000000; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px); width: 278.16px; height: 69.00px;"}

[]{.c0}

- [Saves new high scores to 'highscores.txt' whenever player beats their
  previous 5 highest scores
  ]{.c0}[![](images/image7.png){style="width: 316.24px; height: 69.33px; margin-left: 0.00px; margin-top: 0.00px; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px);"}]{style="overflow: hidden; display: inline-block; margin: 0.00px 0.00px; border: 0.00px solid #000000; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px); width: 316.24px; height: 69.33px;"}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[The prototype is a single file C++ console app without C primitives.
The game loop runs at 6.67 FPS. (Sleep(150)  to reduce flashing from
cls).]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[Evaluation ]{.c11}

[All in all Asteroid Astronaut, is an interactive game that tests
player's reactions and creates a small challenge that players can spend
some time on to test their skills. The game is intended for short term
use remaining simple and easy to understand by implementing widely
understood controls (WASD) and mechanics (cooldowns, highscores) but not
be too hard to put down to avoid addictive design. ]{.c0}

[Despite the deliverable fitting part of my vision there's a lot I wish
was implemented. The game does have a few bugs, nothing too
groundbreaking but It would be better if i could've ironed these out
before submission. Another is the graphics, implementation of SDL for
Asteroid Astronaut would really enhance the submission and would make
the game a lot more immersive, unfortunately due to poor time management
i wasn't able to get this implemented. ]{.c0}

[In conclusion I believe the game is a solid prototype that offers some
short term enjoyment for players and even though it didn\'t meet my true
vision the game still has something to offer. ]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[]{.c0}

[![](images/image11.png){style="width: 208.00px; height: 107.31px; margin-left: 0.00px; margin-top: 0.00px; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px);"}]{style="overflow: hidden; display: inline-block; margin: 0.00px 0.00px; border: 0.00px solid #000000; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px); width: 208.00px; height: 107.31px;"}[![](images/image2.png){style="width: 578.79px; height: 823.00px; margin-left: 0.00px; margin-top: 0.00px; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px);"}]{style="overflow: hidden; display: inline-block; margin: 0.00px 0.00px; border: 0.00px solid #000000; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px); width: 578.79px; height: 823.00px;"}

[]{.c0}

[]{.c0}
