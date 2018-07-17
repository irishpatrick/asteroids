#pragma once

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 960
#define MAX_MISSILES 100
#define NUM_STARS 300
#define NUM_ASTEROIDS 100

#include <cairo.h>

float deg(float);
float rad(float);
int randint(int, int);
float xcoord(float);
float ycoord(float);

void clear(cairo_t*);