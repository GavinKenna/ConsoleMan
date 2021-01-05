# ConsoleMan
I was going through some old code I had and came across this unfinished project. I was practising my C back in 2014 and decided to attempt a Pacman clone. I quickly realised I tend to favour OOP quite a lot so the project quickly migrated to C++ without me noticing.

This was also a great project to practise NCurses and the pthread library.

Currently the project stands as unfinished - you can select a new game and move around collecting pellets, which increases your score, but other than that it is incredibly unfinished. I might get around to cleaning it up and finising it, but for now I'm simply storing it online.

The code is untouched since last I modified it, other than the CMake file - I couldn't build the project so I threw together a CMake file (hey I got to do more C Programming!).

Some screenshots:
![MainMenu](/images/mainScreen.png)

![Playing](/images/playing.png)

## Building
You will need cmake, gcc, ncurses and pthread installed. 

To build : 
```
$ cmake .
$ make
```
## Running
```
$./consoleman
```