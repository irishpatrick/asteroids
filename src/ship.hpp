#pragma once

#include <cairo.h>
#include <iostream>
#include <string>
#include <vector>
#include "util.hpp"
#include "missile.hpp"

#define MAX_MISSILES 100

class Ship {
public:
    Ship();
    ~Ship();

    void update(float);
    void draw(cairo_t*);
    void fire();

    float x;
    float y;
    float xvel;
    float yvel;
    float angle;
    Point* points;

private:
    const int size = 12;
    Missile missiles[MAX_MISSILES];
};