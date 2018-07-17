#include "missile.hpp"
#define USE_MATH_DEFINES
#include <cmath>
#include "util.hpp"

Missile::Missile() {
    x = 0;
    y = 0;
    xvel = 0;
    yvel = 0;
    visible = false;
}

Missile::~Missile() {

}

void Missile::update(float delta) {
    x += xvel * delta;
    y += yvel * delta;
}

void Missile::draw(cairo_t* cr) {
    cairo_set_line_width(cr, 1);
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_move_to(cr, x, y);
    cairo_line_to(
        cr, 
        x + (cosf(rad(angle)) * SIZE), 
        y + (sinf(rad(angle)) * SIZE)
    );
    cairo_close_path(cr);
    cairo_stroke(cr);
}