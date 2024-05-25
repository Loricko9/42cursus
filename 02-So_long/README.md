# So_long

[![fr](https://img.shields.io/badge/Langue-fr-blue)](README.fr.md)

<p align="center"><img src="https://i.imgur.com/oxsa34o.jpg" alt="drawing" width="400"/></p>

$$\color{darkgreen}{{\Huge \mathbf {120/100 ✅}}}$$

## The goal

Create a 2D game in C with the MiniLibX, a simplified  library, coded by 42 school and derived from X11 librairy.
The program must take in arguments a map with this folowing character :
| CHAR |	OBJECT   |
| --------- | ---------- |
| 1         |   Plot   |
| C	        | Jerican |
| E	        |   Exit  |
| P         |   Car  |      
| 0         |   Road     |

You can deplace the car with the arrow and you need to get all the collectible before go to the exit and win the game.
For bonues, a counter of move must be display on the windows.

## Requirements

This project needed specific librairy to compile the Minilibx.

You can install it with this command :

````sh
sudo apt update
sudo apt install libx11-dev
````

After install this package, compiation of the MiniLIbX is automatic when you execute `make` command.

## Execution

You need to put in argument the path map in format `.ber` of a valid with, at least : 
- only one E (for exit)
- only one P (for player)
- one or more C (for collectibles)
- A valid path between P and E
- Wall (1 character) all arond the map

Some maps are availble in `maps/` directory.
At the end you will have something like this for the execution :
````sh
./so_long maps/map1.ber
````
