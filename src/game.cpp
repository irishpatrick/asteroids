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
    ship.draw(cr);
    for (auto& e : asteroids) {
        e.draw(cr);
    }
}