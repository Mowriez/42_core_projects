The fractol project is a programming exercise from School 42.

It teaches students how to use complex numbers and graphics programming to render fractals in real-time. 
The task is to write a program that allows users to select and explore different fractals, using the arrow keys and mouse to navigate and zoom in and out of the fractal.

This project was usefull to practice important concepts in mathematics, graphics programming, and user interface design. It also helped develop problem-solving skills and creativity, as I could experiment with different fractals and rendering techniques to create stunning visual effects.

Prerequisites: Cocoa of MacOSX (AppKit) and OpenGL.

Compilation: Run "make" to compile. Ignore the warnings that MiniLibX produces, it's trying its best.

Execution: ./fractol "img_width" "fractal-set" 
Where 800 < img_width < 1920 and fractal-set = Mandelbrot || Julia || BS

Input:
Move with arrow keys, change resolution with +/-, change colors with 1/2/3/4/5/6. Reset view with r.
