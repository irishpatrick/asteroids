#pragma once

#include <cairo.h>
#include "util.hpp"

#define MAX_LEVEL 3

class Asteroid {
public:
    Asteroid();
    ~Asteroid();

    void reset(int);
    void update(float);
    void draw(cairo_t*);

    float x;
    float y;
    float xvel;
    float yvel;
    float angle;
    float spin;
    int points;
    int breaks;
    int radius;
    int size;
    int* point_list;
};