#include <stdio.h>
#include <stdlib.h>
#include "robot.h"
#include "setup.h"
#include "graphics.h"
#include <time.h>

int main(int argc, char **argv){
    int initialX = 6;
    int initialY = 5;
    char *initialDirection = "north";
    if (argc == 4) 
    {
    initialX = atoi(argv[1]); 
    initialY = atoi(argv[2]); 
    initialDirection = argv[3];
    }
    srand(time(NULL));

    /*setting coordinates for the robot, home, blocks and markers. The Blocks and Markers have random location 
    using the ransompos() from setup.c*/
    coordinates robot = {initialX, initialY, false};
    coordinates homeloc = {initialX,initialY};
    coordinates blockloc1 = randompos(); //block1
    coordinates blockloc2 = randompos(); //block2
    coordinates blockloc3 = randompos(); //block3
    coordinates blockloc4 = randompos(); //block4
    coordinates markerloc1 = randompos(); //marker1
    coordinates markerloc2 = randompos(); //marker2
    coordinates markerloc3 = randompos(); //marker3

    //drawing the grid and home
    grid();
    home(homeloc);
    //these while loops check if a marker is on the same location as another marker or the home, if it is then the marker loction is randomised again until it finds a location that is free.
    while((markerloc1.x == homeloc.x && markerloc1.y == homeloc.y) || (markerloc1.x == markerloc2.x && markerloc1.y == markerloc2.y) || (markerloc1.x == markerloc3.x && markerloc1.y == markerloc3.y))
    {
      markerloc1 = randompos();
    }
    while((markerloc2.x == homeloc.x && markerloc2.y == homeloc.y) || (markerloc2.x == markerloc1.x && markerloc2.y == markerloc1.y) || (markerloc2.x == markerloc3.x && markerloc2.y == markerloc3.y))
    {
      markerloc2 = randompos();
    }
    while((markerloc3.x == homeloc.x && markerloc3.y == homeloc.y) || (markerloc3.x == markerloc1.x && markerloc3.y == markerloc1.y) || (markerloc3.x == markerloc2.x && markerloc3.y == markerloc2.y))
    {
      markerloc3 = randompos();
    }
    //these while loops check if a block is on the same location as another block or the home or a marker, if it is then the block location is randomised again until it finds a location that is free.
    while((blockloc1.x == homeloc.x && blockloc1.y == homeloc.y) || (blockloc1.x == markerloc1.x && blockloc1.y == markerloc1.y) || (blockloc1.x == markerloc2.x && blockloc1.y == markerloc2.y) || (blockloc1.x == markerloc3.x && blockloc1.y == markerloc3.y) || (blockloc1.x == blockloc2.x && blockloc1.y == blockloc2.y) || (blockloc1.x == blockloc3.x && blockloc1.y == blockloc3.y) || (blockloc1.x == blockloc4.x && blockloc1.y == blockloc4.y))
    {
      blockloc1 = randompos();
    }
    while((blockloc2.x == homeloc.x && blockloc2.y == homeloc.y) || (blockloc2.x == markerloc1.x && blockloc2.y == markerloc1.y) || (blockloc2.x == markerloc2.x && blockloc2.y == markerloc2.y) || (blockloc2.x == markerloc3.x && blockloc2.y == markerloc3.y) || (blockloc2.x == blockloc1.x && blockloc2.y == blockloc1.y) || (blockloc2.x == blockloc3.x && blockloc2.y == blockloc3.y) || (blockloc2.x == blockloc4.x && blockloc2.y == blockloc4.y))
    {
      blockloc2 = randompos();
    }
    while((blockloc3.x == homeloc.x && blockloc3.y == homeloc.y) || (blockloc3.x == markerloc1.x && blockloc3.y == markerloc1.y) || (blockloc3.x == markerloc2.x && blockloc3.y == markerloc2.y) || (blockloc3.x == markerloc3.x && blockloc3.y == markerloc3.y) || (blockloc3.x == blockloc1.x && blockloc3.y == blockloc1.y) || (blockloc3.x == blockloc2.x && blockloc3.y == blockloc2.y) || (blockloc3.x == blockloc4.x && blockloc3.y == blockloc4.y))
    {
      blockloc3 = randompos();
    }
    while((blockloc4.x == homeloc.x && blockloc4.y == homeloc.y) || (blockloc4.x == markerloc1.x && blockloc4.y == markerloc1.y) || (blockloc4.x == markerloc2.x && blockloc4.y == markerloc2.y) || (blockloc4.x == markerloc3.x && blockloc4.y == markerloc3.y) || (blockloc4.x == blockloc1.x && blockloc4.y == blockloc1.y) || (blockloc4.x == blockloc2.x && blockloc4.y == blockloc2.y) || (blockloc4.x == blockloc3.x && blockloc4.y == blockloc3.y))
    {
      blockloc4 = randompos();
    }
    //drawing the blocks and markers
    block(blockloc1);
    block(blockloc2);
    block(blockloc3);
    block(blockloc4);
    marker(markerloc1);
    marker(markerloc2);
    marker(markerloc3);
    
    int dir = convertDtoN(initialDirection);
    drawrobot(robot, dir);
    
    char moves[9999] = {};
    int no_of_moves = 0;
    int state = 1;
    for(int counter = 0; counter < 3; counter++) //for loop runs 3 times as there are 3 markers.
    {
      while(state == 1)
      {
        if(atMarker(robot, markerloc1))
        { //if robot locates marker1 this code is run
          robot.carryingmarker = pickupmarker(robot);
          //the next 2 lines sets the location of the marker outside the grid
          markerloc1.x = 11;
          markerloc1.y = 11;
          wayback(robot, dir, moves, no_of_moves, markerloc2, markerloc3, homeloc, blockloc1, blockloc2, blockloc3, blockloc4);
          robot.carryingmarker= dropMarker(robot);
          //this now resets the robot to its original start position
          robot.x = homeloc.x;
          robot.y = homeloc.y;
          dir = convertDtoN(initialDirection);
          state = 0;//the while loop breaks here.
        }
        else if(atMarker(robot,markerloc2))
        { //if robot locates marker2 this code is run
          robot.carryingmarker = pickupmarker(robot);
          markerloc2.x = 11;
          markerloc2.y = 11;
          wayback(robot, dir, moves, no_of_moves, markerloc1, markerloc3, homeloc, blockloc1, blockloc2, blockloc3, blockloc4);
          robot.carryingmarker= dropMarker(robot);
          robot.x = homeloc.x;
          robot.y = homeloc.y;
          dir = convertDtoN(initialDirection);        
          state = 0;
        }
        else if(atMarker(robot,markerloc3))
        { //if robot locates marker3 this code is run
          robot.carryingmarker = pickupmarker(robot);
          markerloc3.x = 11;
          markerloc3.y = 11;
          wayback(robot, dir, moves, no_of_moves, markerloc1, markerloc2, homeloc, blockloc1, blockloc2, blockloc3, blockloc4);
          robot.carryingmarker= dropMarker(robot);
          robot.x = homeloc.x;
          robot.y = homeloc.y;
          dir = convertDtoN(initialDirection);        
          state = 0;
        }
        else{ /*if robot locates a box with no markers this code is run. This part generates a random number and the move is
                randomized with forward having 0.8 probability and right and left having 0.1 probability each*/                  
          int random = rand() % 10;       
          if(random < 7 && canMoveForward(robot, dir, blockloc1, blockloc2, blockloc3, blockloc4))
          {        
            robot = forward(robot, dir);
            moves[no_of_moves] = 'f'; //saves f as an element of the array to use it for backtracting.
            no_of_moves = no_of_moves + 1;
          }
          else if (random == 8)
          {     
            dir = right(robot,dir);
            moves[no_of_moves] = 'r'; //saves r as an element of the array to use it for backtracting.
            no_of_moves = no_of_moves + 1; 
          }
          else if (random == 9)
          {
            dir = left(robot,dir);
            moves[no_of_moves] = 'l'; //saves l as an element of the array to use it for backtracting.
            no_of_moves = no_of_moves + 1;
          }              
        }
      }
      no_of_moves = 0; //reset to 0 for the path to the next marker 
      state = 1; //reset to 1 to let the while loop be initiated 
    }
    //once all 3 markers are returned this code will run.
    setColour(black);
    drawString("FINISH!!", 100, 90);
    return 0;
}
