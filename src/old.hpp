#pragma once
#include <cairo.h>
#include <cstdbool>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 960
#define MAX_MISSILES 100
#define NUM_STARS 300
#define NUM_ASTEROIDS 100

/*typedef struct {
    float x;
    float y;
    float xvel;
    float yvel;
    float angle;
    float size;
} Ship;

typedef struct {
    float x;
    float y;
    float xvel;
    float yvel;
    float angle;
    float size;
    bool draw;
} Missile;

typedef struct {
    int x;
    int y;
} Star;

typedef struct {
    float x;
    float y;
    float xvel;
    float yvel;
    float angle;
    float size;
    float spin;
    bool draw;
    int verts;
    int breaks;
} Asteroid;

Missile missiles[MAX_MISSILES];
Star stars[NUM_STARS];
Asteroid asteroids[NUM_ASTEROIDS];



void draw_stars(cairo_t*);
void init_stars();

// ship functions
void init_ship(Ship*);
void draw_ship(Ship*, cairo_t*);
void update_ship(Ship*, float);

// missile functions
void init_missiles();
void fire_missile(Ship*);
void update_missiles(float);
void draw_missiles(cairo_t*);

//asteroid functions
void spawn_asteroid();
void update_asteroids(float);
void draw_asteroids(cairo_t*);
void split_asteroid(int);
void reset_asteroid(int);
*/