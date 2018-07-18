#include "asteroid.hpp"
#include "util.hpp"

Asteroid::Asteroid() {
    x = 0;
    y = 0;
    xvel = 0;
    yvel = 0;
    angle = 0;
    breaks = 0;
    points = 0;
    size = 0;
}

Asteroid::~Asteroid() {

}

void Asteroid::reset(int level) {

}

void Asteroid::update(float delta) {
    x += xvel * delta;
    y += yvel * delta;
}

void Asteroid::draw(cairo_t* cr) {
    
}