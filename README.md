# Wolf3d
This project is inspired by the world-famous eponymous 90’s game, which was the first FPS ever.


## Description 

In this project we followed the footsteps of brillant programmer John Carmack and write our own version of Wolfenstein 3D !

Not re-write the ENTIRE Wolfenstein 3D but a 3D representation of a maze in which a player can find his/her way, using the ray casting technique.

This is the introduction to the final project : Doom Nukem.

![](wolf3d.gif)

## Features

I had to remove multiple feature to keep the minimum like teleportation and items wich had some issues.

However there is :
- texture mode : press p to see / unsee the textures on the wall
- door inside blocs
- press e to open door only close to the door

## Installation 

You need to install sdl2 
```
brew sdl2
```
Then simply
```
make
```
or 
```
make re
```
## Usage 
```
./Wolf3d maps/first_map.txt
```
You can also edit the map in maps/first_map.txt, as long as it is a rectangle with walls all around the map.

Each bloc is composed with 5 ints example (1100,1,2,1,1)

- 1100 for walls, 1 for empty, 1001 vertical door, 1000 horizontal door
- must be 1, removed feature
- must be 2, removed feature
- must be 1, removed feature
- player spawn and direction (between 2 and 5)

