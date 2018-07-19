#include "game.hpp"
#include <cmath>
#include <SDL.h>

bool space_down = false;

Game::Game() {
    running = true;
}

Game::~Game() {

}

void Game::init() {
    ship.x = SCREEN_WIDTH / 2;
    ship.y = SCREEN_HEIGHT / 2;

    for (int i=0; i<NUM_STARS; i++) {
        stars[i].x = randint(0, SCREEN_WIDTH);
        stars[i].y = randint(0, SCREEN_HEIGHT);
    }

    test.reset(1);
    //test.x = 200;
    //test.y = 200;
    asteroids.push_back(test);
}

void Game::update(float delta, const uint8_t* keys) {
    bool up = keys[SDL_SCANCODE_UP];
    bool down = keys[SDL_SCANCODE_DOWN];
    bool left = keys[SDL_SCANCODE_LEFT];
    bool right = keys[SDL_SCANCODE_RIGHT];
    bool space = keys[SDL_SCANCODE_SPACE];
    bool escape = keys[SDL_SCANCODE_ESCAPE];

    if (escape) {
        running = false;
    }

    if (left) {
        ship.angle -= 300 * delta;
    }

    if (right) {
        ship.angle += 300 * delta;
    }

    if (up) {
        ship.xvel += 2 * cosf(rad(ship.angle - 90));
        ship.yvel += 2 * sinf(rad(ship.angle - 90));
    }

    if (space) {
        if (!space_down) {
            space_down = true;
            ship.fire();
        }
    } else {
        space_down = false;
    }

    ship.update(delta);
    for (auto& e : asteroids) {
        e.update(delta);
    }
}

void Game::draw(cairo_t* cr) {
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

    ship.draw(cr);
    
    for (auto& e : asteroids) {
        e.draw(cr);
    }
}