#pragma once

#include <cairo.h>
#include <vector>
#include "ship.hpp"
#include "missile.hpp"
#include "asteroid.hpp"
#include "util.hpp"

typedef struct {
    float x;
    float y;
} Star;

class Game {
public:
    Game();
    ~Game();

    void init();
    void update(float, const uint8_t*);
    void draw(cairo_t*);

    bool running;

private:
    Ship ship;
    std::vector<Asteroid> asteroids;
    Star stars[NUM_STARS];
};