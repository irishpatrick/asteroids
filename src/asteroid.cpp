#include "asteroid.hpp"

Asteroid::Asteroid() {
    x = 0;
    y = 0;
    xvel = 0;
    yvel = 0;
}

Asteroid::~Asteroid() {

}

void Asteroid::update(float delta) {
    x += xvel * delta;
    y += yvel * delta;
}

void Asteroid::draw(cairo_t* cr) {
    
}