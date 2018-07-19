#include "util.hpp"
#include "game.hpp"
#define USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>

float deg(float angle) {
    return angle * (180.0 / M_PI);
}

float rad(float angle) {
    return angle * (M_PI / 180.0);
}

int randint(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

float xcoord(float x) {
    return x / SCREEN_WIDTH;
}

float ycoord(float y) {
    return y / SCREEN_HEIGHT;
}

void clear(cairo_t* cr) {
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_paint(cr);
}

bool checkCollision(std::vector<Point>& a, std::vector<Point>& b) {
    
}