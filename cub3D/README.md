# cub3D
> Wolfenstein3D reimagination except 30 years later it's way less impressive.
# Project Overview
Cub3D is a project that focuses on raycasting, a technique used to render 3D environments in a 2D space. The project involves creating a simple 3D game engine that can read a map from a file and render it using raycasting techniques. The player can navigate through the environment, and the walls are textured to provide a more immersive experience.

# Description

## Features

- Raycasting Engine: Utilizes the raycasting technique to render a 3D environment.<br>
- Map Parsing: Reads a simple map from a provided file to generate the game world.<br>
- Textured Walls: Renders textured walls to enhance the visual experience.<br>
- Player Movement: Allows the player to move within the 3D space and rotate the view.<br>

## Dependencies

- MinilibX: A simple X Window System library for graphics.

## Build and run the project

1. Clone the repository and compile it with 'make'

2. Run the following command from the terminal to start the game with a specific map file

        ./cub3D map/subjectmap.cub
    (other mapfiles available in map-directory)

- Controls

        W/A/S/D: Move forward/left/backward/right.
        Arrow keys: Rotate the view.
        ESC: Exit the game.
