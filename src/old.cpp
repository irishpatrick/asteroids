/*#include "game.hpp"
#include "util.hpp"
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

void init_missiles() {
    for (int i=0; i<MAX_MISSILES; i++) {
        missiles[i].draw = false;
    }
}

void init_ship(Ship* ship) {
    ship->x = 0;
    ship->y = 0;
    ship->xvel = 0;
    ship->yvel = 0;
    ship->angle = 0;
    ship->size = 12;
}

void update_ship(Ship* ship, float delta) {
    ship->x += ship->xvel * delta;
    ship->y += ship->yvel * delta;
}

void draw_ship(Ship* ship, cairo_t* cr) {
    cairo_set_line_width(cr, 1);
    cairo_set_source_rgb(cr, 1, 1, 1);
    float px, py;

    px = ship->x + cos(rad(150 + ship->angle)) * ship->size;
    py = ship->y + sin(rad(150 + ship->angle)) * ship->size;
    cairo_move_to(cr, (px), (py));
    
    px = ship->x + cos(rad(270 + ship->angle)) * ship->size;
    py = ship->y + sin(rad(270 + ship->angle)) * ship->size;
    cairo_line_to(cr, (px), (py));

    px = ship->x + cos(rad(30 + ship->angle)) * ship->size;
    py = ship->y + sin(rad(30 + ship->angle)) * ship->size;
    cairo_line_to(cr, (px), (py));

    cairo_line_to(cr, (ship->x), (ship->y));
    cairo_close_path(cr);
    cairo_stroke(cr);
}

void fire_missile(Ship* ship) {
    int index;
    for (int i=0; i<MAX_MISSILES; i++) {
        if (!missiles[i].draw) {
            index = i;
            break;
        }
    }

    Missile* m = &missiles[index];

    m->x = ship->x;
    m->y = ship->y;
    m->angle = ship->angle - 90;
    m->xvel = 600 * cosf(rad(m->angle)) + ship->xvel;
    m->yvel = 600 * sinf(rad(m->angle)) + ship->yvel;
    m->size = 10;
    m->draw = true;
}

void update_missiles(float delta) {
    for (int i=0; i<MAX_MISSILES; i++) {
        Missile* m = &missiles[i];
        if (!m->draw) {
            continue;
        }
        m->x += m->xvel * delta;
        m->y += m->yvel * delta;
    }
}

void draw_missiles(cairo_t* cr) {
    for (int i=0; i<MAX_MISSILES; i++) {
        Missile* m = &missiles[i];
        if (!m->draw) {
            continue;
        }

        cairo_set_line_width(cr, 1);
        cairo_set_source_rgb(cr, 1, 1, 1);
        cairo_move_to(cr, m->x, m->y);
        cairo_line_to(
            cr, 
            m->x + (cosf(rad(m->angle)) * m->size), 
            m->y + (sinf(rad(m->angle)) * m->size)
        );
        cairo_close_path(cr);
        cairo_stroke(cr);
    }
}

void init_stars() {
    for (int i=0; i<NUM_STARS; i++) {
        Star* s = &stars[i];
        s->x = randint(0, SCREEN_WIDTH);
        s->y = randint(0, SCREEN_HEIGHT);
    }
}

void draw_stars(cairo_t* cr) {
    for (int i=0; i<NUM_STARS; i++) {
        Star* s = &stars[i];
        int color = randint(0, 100);
        cairo_set_line_width(cr, 1);
        if (color == 6) {
            cairo_set_source_rgb(cr, 1, 1, 1);
        }
        else {
            cairo_set_source_rgb(cr, 0.6, 0.6, 0.6);
        }
        cairo_set_source_rgb(cr, 0.6, 0.6, 0.6);

        cairo_rectangle(cr, s->x, s->y, 1, 1);
        cairo_fill(cr);
    }
}

void spawn_asteroid() {
    Asteroid* a;
    for (int i=0; i<NUM_ASTEROIDS; i++) {
        a = &asteroids[i];
        if (!a->draw) {
            break;
        }
    }
    a->draw = true;
    a->spin = randint(-100, 100);
    int cx = SCREEN_WIDTH / 2;
    int cy = SCREEN_HEIGHT / 2;
    int radius = cx / 2 + 100;
    int angle = randint(0,360);
    a->x = radius * cosf(rad(angle));
    a->y = radius * sinf(rad(angle));
    a->angle = angle + 180;
    a->xvel = 50 * cosf(rad(a->angle));
    a->yvel = 50 * sinf(rad(a->angle));   
    a->verts = randint(5, 8);
    a->breaks = randint(1, 3);
}

void update_asteriods(float delta) {
    for (int i=0; i<NUM_ASTEROIDS; i++) {
        Asteroid* a = &asteroids[i];
        if (!a->draw) {
            continue;
        }
        a->x += a->xvel * delta;
        a->y += a->yvel * delta;
        a->angle += a->spin * delta;
    }
}*/