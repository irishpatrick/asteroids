#include "ship.hpp"
#define USE_MATH_DEFINES
#include <cmath>
#include "util.hpp"

Ship::Ship() {
    x = 0;
    y = 0;
    xvel = 0;
    yvel = 0;
    angle = 0;
}

Ship::~Ship() {

}

void Ship::fire() {
    Missile* m;
    for (int i=0; i<MAX_MISSILES; i++) {
        m = &missiles[i];
        if (!m->visible) {
            break;
        }
    }
    if (m == nullptr) {
        return;
    }

    m->visible = true;
    m->x = x;
    m->y = y;
    m->angle = angle - 90;
    m->xvel = 600 * cosf(rad(m->angle)) + xvel;
    m->yvel = 600 * sinf(rad(m->angle)) + yvel;
}

void Ship::update(float delta) {
    x += xvel * delta;
    y += yvel * delta;

    for (int i=0; i<MAX_MISSILES; i++) {
        missiles[i].update(delta);
    }
}

void Ship::draw(cairo_t* cr) {
    cairo_set_line_width(cr, 1);
    cairo_set_source_rgb(cr, 1, 1, 1);
    float px, py;

    px = x + cos(rad(150 + angle)) * size;
    py = y + sin(rad(150 + angle)) * size;
    cairo_move_to(cr, px, py);
    
    px = x + cos(rad(270 + angle)) * size;
    py = y + sin(rad(270 + angle)) * size;
    cairo_line_to(cr, px, py);

    px = x + cos(rad(30 + angle)) * size;
    py = y + sin(rad(30 + angle)) * size;
    cairo_line_to(cr, px, py);

    cairo_line_to(cr, x, y);
    cairo_close_path(cr);
    cairo_stroke(cr);

    for (int i=0; i<MAX_MISSILES; i++) {
        missiles[i].draw(cr);
    }
}
