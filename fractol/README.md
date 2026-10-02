# fractol
> Fractal creator and explorer - bring me the (burning ship) horizon!

# Project Overview
Fractal is a project that focuses on creating and exploring fractals, which are complex mathematical shapes that exhibit self-similarity at different scales. The project involves implementing algorithms to generate various types of fractals, such as the Mandelbrot set, Julia set, and Burning Ship fractal. Users can interact with the fractals by zooming in and out, panning across the fractal space, and changing color schemes to enhance the visual experience.

# Description

## Features

- Fractal Generation: Implements algorithms to generate different types of fractals.<br>
- User Interface: Provides a simple and intuitive interface for interacting with the fractals.<br>
- Interactive Exploration: Allows users to zoom, pan, and change color schemes.<br>

## Dependencies

- MinilibX: A simple X Window System library graphical output. The MinilibX library itself is available in the project files, its dependencies can be installed with (linux environment):

        sudo apt update
        sudo apt install -y build-essential libx11-dev libxext-dev libbsd-dev libxrandr-dev

## Build and run the project

1. Clone the repository and compile it with 'make'. <br>
Ignore the warnings that MiniLibX produces, it's trying its best.

2. Run the following command from the terminal to start the fractal explorer with a specific image width and fractal set

        ./fractol "img_width" "fractal-set"
    Where 800 < img_width < 1920 and fractal-set = Mandelbrot || Julia || BS

3. The program will open a window with the specified width and display the chosen fractal set. Users can interact with the fractal using the keyboard and mouse controls.

4. Controls

        Arrow keys: Pan the view up/left/down/right.
        Mouse scroll: Zoom in/out of the fractal.
        1-6: Change color schemes.
        + / - : Increase/decrease maximum iterations for fractal generation.
        ESC: Exit the program.
