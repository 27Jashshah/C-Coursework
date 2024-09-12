#include <stdio.h>
#include "graphics.h"
#include "setup.h"
#include "robot.h"

//this function draws the robot(triangle) depending on the coordinates and the direction of the robot which are entered as arguments of the function.
void drawrobot(coordinates robot_c, int direction){
    foreground();
    coordinates robot_p = convertCtoP(robot_c);
    int pointsx[4] = {}, pointsy[4] = {};
    switch(direction){
      case 1: 
        pointsx[0] = robot_p.x + 3;
        pointsx[1] = robot_p.x + 27;
        pointsx[2] = robot_p.x + 15;
        pointsx[3] = robot_p.x + 3;
        pointsy[0] = robot_p.y + 25;
        pointsy[1] = robot_p.y + 25;
        pointsy[2] = robot_p.y + 5;
        pointsy[3] = robot_p.y + 25;
        break;
      case 2: 
        pointsx[0] = robot_p.x + 5;
        pointsx[1] = robot_p.x + 5;
        pointsx[2] = robot_p.x + 25;
        pointsx[3] = robot_p.x + 5;
        pointsy[0] = robot_p.y + 3;
        pointsy[1] = robot_p.y + 27;
        pointsy[2] = robot_p.y + 15;
        pointsy[3] = robot_p.y + 3;
        break;
      case 3: 
        pointsx[0] = robot_p.x + 3;
        pointsx[1] = robot_p.x + 27;
        pointsx[2] = robot_p.x + 15;
        pointsx[3] = robot_p.x + 3;
        pointsy[0] = robot_p.y + 5;
        pointsy[1] = robot_p.y + 5;
        pointsy[2] = robot_p.y + 25;
        pointsy[3] = robot_p.y + 5;
        break;
      case 4: 
        pointsx[0] = robot_p.x + 25;
        pointsx[1] = robot_p.x + 25;
        pointsx[2] = robot_p.x + 5;
        pointsx[3] = robot_p.x + 25;
        pointsy[0] = robot_p.y + 3;
        pointsy[1] = robot_p.y + 27;
        pointsy[2] = robot_p.y + 15;
        pointsy[3] = robot_p.y + 3;
        break;
    }
    if(robot_c.carryingmarker == false){ //this code draws the robot alone if it is not carrying a marker.
      setColour(green);
      fillPolygon(4,pointsx,pointsy);
    }
    else{ //this code draws the robot over a marker if the robot is carrying a marker.
      setColour(blue);
      fillRect(robot_p.x,robot_p.y, 30, 30);
      setColour(green);          
      fillPolygon(4,pointsx,pointsy);      
    }
    sleep(100);
    clear();
}

//this is the function for the robot to move forward in the direction it is pointing towards
coordinates forward(coordinates robot, int direction){
    foreground();
    drawrobot(robot, direction);
    switch(direction){
      case 1: robot.y = robot.y + 1;
        return robot;
        break;
      case 2: robot.x = robot.x + 1;
        return robot;
        break;
      case 3: robot.y = robot.y - 1;
        return robot;
        break;
      case 4: robot.x = robot.x - 1;
        return robot;
        break;  
    }  
}

//this function returns true if the robot does not have the wall or a block in front of it, else it will return false.
bool canMoveForward(coordinates robot_c, int direction, coordinates blockloc1, coordinates blockloc2, coordinates blockloc3, coordinates blockloc4){
  coordinates robot_p;
  robot_p = convertCtoP(robot_c);
  switch(direction){
    case 1: 
        if(robot_p.y > 100) {         
            return !((robot_c.y == (blockloc1.y - 1) && robot_c.x == blockloc1.x) || (robot_c.y == (blockloc2.y - 1) && robot_c.x == blockloc2.x) || (robot_c.y == (blockloc3.y - 1) && robot_c.x == blockloc3.x) || (robot_c.y == (blockloc4.y - 1) && robot_c.x == blockloc4.x));
        } else {
            return false;
        }
        break;
    case 2: 
        if(robot_p.x < 370) {
            return !((robot_c.y == blockloc1.y && robot_c.x == (blockloc1.x - 1)) || (robot_c.y == blockloc2.y && robot_c.x == (blockloc2.x - 1)) || (robot_c.y == blockloc3.y && robot_c.x == (blockloc3.x - 1)) || (robot_c.y == blockloc4.y && robot_c.x == (blockloc4.x - 1)));            
        } else {
            return false;
        }
        break;
    case 3: if(robot_p.y < 370) {
            return !((robot_c.y == (blockloc1.y + 1) && robot_c.x == blockloc1.x) || (robot_c.y == (blockloc2.y + 1) && robot_c.x == blockloc2.x) || (robot_c.y == (blockloc3.y + 1) && robot_c.x == blockloc3.x) || (robot_c.y == (blockloc4.y + 1) && robot_c.x == blockloc4.x));          
        } else {
            return false;
        }
        break;
    case 4: if(robot_p.x > 100){
            return !((robot_c.y == blockloc1.y && robot_c.x == (blockloc1.x + 1)) || (robot_c.y == blockloc2.y && robot_c.x == (blockloc2.x + 1)) || (robot_c.y == blockloc3.y && robot_c.x == (blockloc3.x + 1)) || (robot_c.y == blockloc4.y && robot_c.x == (blockloc4.x + 1)));
        } else {
            return false;
        }
        break;
  } 
}

//this function changes the value of direction to turn right. 
int right(coordinates robot_c, int direction){
  if(direction < 4){
    direction = direction + 1;
  }
  else if(direction == 4){
    direction = 1;
  }
  drawrobot(robot_c, direction);
  return direction;
}

//this function changes the value of direction to turn left.
int left(coordinates robot_c, int direction){
  if(direction > 1){
    direction = direction - 1;
  }
  else if(direction == 1){
    direction = 4;
  }
  drawrobot(robot_c, direction);
  return direction;
}

//this function returns true if the robot is at the marker, else returns false.
bool atMarker(coordinates robot, coordinates markerloc){
  if(robot.x == markerloc.x && robot.y == markerloc.y){
    return true;
  }
  else{
    return false;
  }
}

//this function returns true if the robot is at the home, else returns false.
bool atHome(coordinates robot, coordinates homeloc){
  if(robot.x == homeloc.x && robot.y == homeloc.y){
    return true;
  }
  else{
    return false;
  }
}

//this function changes the 'carryingmarker' to true.
bool pickupmarker(coordinates robot){
  robot.carryingmarker = true;
  background();
  clear();
  return robot.carryingmarker;
}

//this function changes the 'carryingmarker' to false.
bool dropMarker(coordinates robot){
  robot.carryingmarker = false;
  return robot.carryingmarker;
}

//this function returns true if the robot is carrying a marker, else returns false. 
bool iscarryingmarker(coordinates robot){
    if(robot.carryingmarker == true){
        return true;
    }
    else{
        return false;
    }
}

/*this function is the backtracking function. While finding the marker, the movements are saved in an array and this functuion
goes through the array backwards and goes foward if the element is f, takes a right if the element was l and takes a left element was r.*/
void wayback(coordinates robot, int direction, char moves[9999], int no_of_moves, coordinates markerloc1, coordinates markerloc2, coordinates homeloc, coordinates blockloc1, coordinates blockloc2, coordinates blockloc3, coordinates blockloc4)
{   
  grid();
  marker(markerloc1);
  marker(markerloc2);
  home(homeloc);
  block(blockloc1);
  block(blockloc2);
  block(blockloc3);
  block(blockloc4);
  direction = right(robot,direction);
  direction = right(robot,direction);
  for(int counter = no_of_moves - 1; counter >= 0; counter--)
  {
    if(atHome(robot,homeloc))
    {
      direction = right(robot,direction);
      direction = right(robot,direction);
      counter = -1; //if the marker reaches home, the for loop breaks.           
    } 
    else if(moves[counter] == 'f')
    {        
      robot = forward(robot, direction); 
      marker(markerloc1);
      marker(markerloc2);
    }
    else if(moves[counter] == 'r')
    {
      direction = left(robot,direction);
      marker(markerloc1);
      marker(markerloc2);
    }
    else if(moves[counter] == 'l')
    {
      direction = right(robot,direction);
      marker(markerloc1);
      marker(markerloc2);
    }
  }
}