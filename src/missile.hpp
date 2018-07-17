#pragma once

#include <cairo.h>

class Missile {
public:
    Missile();
    ~Missile();

    void update(float);
    void draw(cairo_t*);

    float x;
    float y;
    float xvel;
    float yvel;
    float angle;
    bool visible;
    const int SIZE = 10;
};