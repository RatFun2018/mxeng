# Microcontroller Project - Curtin University S12024
Source code for the robots and controllers being programmed in Microcontroller Project.

## Project Structure
The project is broken down into individual labs and individual tasks within those labs.
The code for each lab is in `src/Lab *` and is split between `Robot.c` and `Controller.c`
If the lab has only 1 task, the main function will be put in `Robot.c` or `Controller.c`, but if the lab has more than 1 task, the code will be split into separate C files which the `Robot.c` or `Controller.c` will `#include`.

Any files written as general purpose helper files will be put in the `lib` directory.

## Required Extensions
This project is designed to be written using the Visual Studio Code editor, along with the following extensions
 - C/C++
 - C/C++ Extension pack
 - CMake
 - PlatformIO IDE
 - Serial Monitor

## Building and uploading
To upload the code to the robot or controller, first configure the platformio.ini file to include the source files from the respective lab. Then using the platformio tab in VSCode choose either Controller or Robot and press upload
