#pragma once

#include <cairo.h>

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
    int size;   

};