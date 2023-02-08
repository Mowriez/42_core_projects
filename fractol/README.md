# fractol
Summary: A program that visualizes different fractals. Right now it can display the Mandelbrot, Julia, and
burning ships sets. Uses a basic graphics library (MiniLibX) for the image/window handling part. 
This library is contained in inc-directory.

Scope: Written for MacOS. MiniLibX requires Cocoa of MacOSX (AppKit) and OpenGL.
Possible extension to Linux if I feel bored one day.

Prerequisites: Cocoa of MacOSX (AppKit) and OpenGL.

Compilation: Run "make" to compile. Ignore the warnings that MiniLibX produces, it's trying its best.

Execution: ./fractol "img_width" "fractal-set" 
Where 800 < img_width < 1920 and fractal-set = Mandelbrot || Julia || BS

Input:
Move with arrow keys, change resolution with +/-, change colors with 1/2/3/4/5/6. Reset view with r.
