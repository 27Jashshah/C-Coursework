
# C Coursework

This is my submission for the C Coursework for COMP0002. Our tasks involved coding a flawless algorithm for a robot to find the markers on a grid.

## Introduction

My program is set to have 3 markers and 4 blocks at random locations and the home location has to be entered by the user while executing the prgoram. The robot, not knowing where the markers are located, has to find the markers and return them to the home. If there is a block in front of the robot, the robot cannot move forward.

This is an example of the grid-

![Example Photo of my Grid](<Example Photo of my Grid.png>)

The green Triangle is the robot, the black square is home, the blue squares are the markers and the red squares are the blocks.

## Contents

My submission contains 5 main files: main.c, setup.c, setup.h, robot.c and robot.h.

The main.c file contains the main function that runs when the program is executed. This function contains the animation of the robot and the algorithms I have used.

The setup.c file contains the functions that are required to draw the grid, markers, home and blocks. This file also contains a function that takes in coordinates as an argument and converts it into pixels as per my grid's measurements. This file also has a function that converts the direction into an integer so that when the robot takes turns, it can easily add or subtract 1 to change its direction.

The robot.c file contains all the functions related to the robot like its movements, logics, dropping and picking up markers, backtracking etc.

## Compiling And Running The Program

To compile the file you can use: gcc -o [name of executable file] main.c graphics.c robot.c setup.c

Example: gcc -o test main.c graphics.c robot.c setup.c

To run the file you can use: ./[name of executable file].exe [x coord] [y coord] [direction] | java -jar drawapp-3.0.jar

Where x coord and y coord are the coordinates of the starting point of the robot, i.e., the location of the home. The coordinates range from 1 to 10 with the bottom left box of the grid being 1,1. The direction is the starting direction of the robot.

Example: ./test.exe 4 8 south | java -jar drawapp-3.0.jar

## Algorithms

The algorithms that I have used include a random movement for the robot, where if the robot does not have a wall or a block in front of it, the probability of the robot moving forward is 0.8. The probability of the robot turning left or right is 0.1 each. This causes the robot to move around the grid without mapping the grid and knowing where the markers are on the grid. If the robot reaches a marker then it turns 180 degrees and then uses my Backtracking algorithm to get back to home.

My Backtracking algorithm simply contains an array that stores each and every movement of the robot before it reaches a marker. It then goes through the array backwards and reverses the movements it took to reach the marker , i.e., right -> left, left -> right and forward stays forward. The Backtracking algorithm works until the robot reaches back home.

