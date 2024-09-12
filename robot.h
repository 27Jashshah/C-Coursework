#pragma once
#include "setup.h"
#include <stdbool.h>

void drawrobot(coordinates robot_c,int direction);
coordinates forward(coordinates robot, int direction);
bool canMoveForward(coordinates robot_c, int direction, coordinates blockloc1, coordinates blockloc2, coordinates blockloc3, coordinates blockloc4);
int right(coordinates robot_c, int direction);
int left(coordinates robot_c, int direction);
bool atMarker(coordinates robot, coordinates markerloc);
bool atHome(coordinates robot, coordinates homeloc);
bool pickupmarker(coordinates robot);
bool dropMarker(coordinates robot);
bool iscarryingmarker(coordinates robot);
void wayback(coordinates robot, int dir, char moves[9999], int i, coordinates markerloc1, coordinates markerloc2, coordinates homeloc, coordinates blockloc1, coordinates blockloc2, coordinates blockloc3, coordinates blockloc4);
