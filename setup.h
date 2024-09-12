#pragma once
#include <stdbool.h>

typedef struct coordinates{
   int x;
   int y;
   bool carryingmarker; // only for the robot.
} coordinates;

void grid();
coordinates convertCtoP(coordinates coord);
void marker(coordinates markerloc_c);
void home(coordinates homeloc_c);
void block(coordinates blockloc_c);
int convertDtoN(char *direction);
coordinates randompos();
