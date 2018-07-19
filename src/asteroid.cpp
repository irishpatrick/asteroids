#include "asteroid.hpp"
#include "util.hpp"
#include <cmath>
#include <iostream>

Asteroid::Asteroid() {
    reset(0);
}

Asteroid::~Asteroid() {
    free(point_list);
}

void Asteroid::reset(int level) {
    if (point_list != nullptr) {
        free(point_list);
    }
    int multiplier = MAX_LEVEL - level;
    if (multiplier <= 0) {
        multiplier = 1;
    }

    float cx = SCREEN_WIDTH / 2;
    float cy = SCREEN_HEIGHT / 2;
    int a = randint(0, 3060);
    x = cosf(rad(a)) * 600 + cx;
    y = sinf(rad(a)) * 600 + cy;
    std::cout << x << "," << y << std::endl;
    a -= 180;
    spin = randint(-40, 40);
    int variance = randint(-40,40);
    xvel = cosf(rad(a + variance)) * 100;
    yvel = sinf(rad(a + variance)) * 100;
    points = randint(4, 8);
    breaks = randint(1, 3);
    radius = multiplier * randint(10, 30);
    point_list = (int*)malloc(points * sizeof(int));
    for (int i=0; i<points; i++) {
        point_list[i] = 360 / points * (i+1) + randint(-30,30);
    }
}

void Asteroid::update(float delta) {
    x += xvel * delta;
    y += yvel * delta;
    angle += spin * delta;
}

void Asteroid::draw(cairo_t* cr) {
    for (int i=0; i<points; i++) {
        float px, py;
        px = x + cosf(rad(angle + point_list[i])) * radius;
        py = y + sinf(rad(angle + point_list[i])) * radius;
        if (i == 0) {
            cairo_move_to(cr, px, py);
        } else {
            cairo_line_to(cr, px, py);
        }
    }
    cairo_close_path(cr);
    cairo_stroke(cr);
}