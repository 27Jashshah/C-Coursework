#include <stdio.h>
#include "graphics.h"
#include <string.h>
#include "setup.h"
#include <stdlib.h>


//this function sets the window size and draws the gird with 10 rows and 10 coloumns of 30p x 30p boxes.
void grid(){
    setWindowSize(500,500);    
    background();
    int a, b = 100;
    for (int c = 0; c < 10; c++){
        a = 100;
        for(int d = 0; d < 10; d++){     
           drawRect(a,b,30,30);
           a = a + 30;
        }
        b = b + 30;
    }        
}

//this function converts coordinates of the grid to their equivalent pixels as per my grid size.
coordinates convertCtoP(coordinates coord){
    coordinates pixel;
    switch (coord.x){
        case 1: pixel.x = 100;
            break;
        case 2: pixel.x = 130;
            break;
        case 3: pixel.x = 160;
            break;
        case 4: pixel.x = 190;
            break;
        case 5: pixel.x = 220;
            break;
        case 6: pixel.x = 250;
            break;
        case 7: pixel.x = 280;
            break;
        case 8: pixel.x = 310;
            break;
        case 9: pixel.x = 340;
            break;
        case 10: pixel.x = 370;
            break; 
        default: pixel.x = 550;
            break;    
    }
    switch (coord.y){
        case 1: pixel.y = 370;
            break;
        case 2: pixel.y = 340;
            break;
        case 3: pixel.y = 310;
            break;
        case 4: pixel.y = 280;
            break;
        case 5: pixel.y = 250;
            break;
        case 6: pixel.y = 220;
            break;
        case 7: pixel.y = 190;
            break;
        case 8: pixel.y = 160;
            break;
        case 9: pixel.y = 130;
            break;
        case 10: pixel.y = 100;
            break;
        default: pixel.y = 550;
            break;        
    }
    return pixel;
}

//this function draws a marker.
void marker(coordinates markerloc_c){
  background();
  coordinates markerloc_p = convertCtoP(markerloc_c);
  setColour(blue);
  fillRect(markerloc_p.x, markerloc_p.y,30,30);
}

//this function draws the home.
void home(coordinates homeloc_c){
  background();
  coordinates homeloc_p = convertCtoP(homeloc_c);
  setColour(black);
  fillRect(homeloc_p.x,homeloc_p.y,30,30);
}

//this function draws a block
void block(coordinates blockloc_c){
  background();
  coordinates blockloc_p = convertCtoP(blockloc_c);
  setColour(red);
  fillRect(blockloc_p.x,blockloc_p.y,30,30);  
}

//this function converts the direction to an integer value, north -> 1, east -> 2, south -> 3, west -> 4.
int convertDtoN(char *direction){
    if(strcmp(direction, "north") == 0){
        return 1;
    }
    else if(strcmp(direction, "east") == 0){
        return 2;
    }
    else if (strcmp(direction,"south") == 0){
        return 3;
    }
    else if(strcmp(direction,"west") == 0){
        return 4;
    }
}

//this function returns a random struct with coordinates x and y between 1 to 10.
coordinates randompos()
{
    coordinates random = {0,0};
    random.x = (rand() % 10) + 1;
    random.y= (rand() % 10) + 1;
    return random;
}

