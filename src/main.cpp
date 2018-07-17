#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstdbool>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cairo.h>
#include <SDL.h>

#include "util.hpp"
#include "game.hpp"
#include "ship.hpp"
#include "game.hpp"

SDL_Window* window;
SDL_Surface* sdl_surf;
SDL_Surface* screen;

cairo_surface_t* cairo_surf;
cairo_t* cr;

Game game;

int init() {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        printf("error\n");
        return 1;
    }
    
    window = SDL_CreateWindow(
        "asteroids", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        SCREEN_WIDTH, 
        SCREEN_HEIGHT, 
        SDL_WINDOW_SHOWN
    );
    
    if (window == NULL) {
        printf("window error\n");
        return 1;
    }

    screen = SDL_GetWindowSurface(window);
    
    uint32_t rmask, gmask, bmask;
    #if SDL_BYTEORDER == SDL_BIG_ENDIAN
        rmask = 0xff000000;
        gmask = 0x00ff0000;
        bmask = 0x0000ff00;
        //amask = 0x000000ff;
    #else
        rmask = 0x000000ff;
        gmask = 0x0000ff00;
        bmask = 0x00ff0000;
        //amask = 0xff000000;
    #endif
    
    sdl_surf = SDL_CreateRGBSurface(
        0,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        32,
        rmask,
        gmask,
        bmask,
        0
    );

    SDL_LockSurface(sdl_surf);
    
    cairo_surf = cairo_image_surface_create_for_data(
        (uint8_t*)sdl_surf->pixels,
        CAIRO_FORMAT_RGB24,
        sdl_surf->w,
        sdl_surf->h,
        sdl_surf->pitch
    );
    cr = cairo_create(cairo_surf);

    game.init();
}

void update(float delta) {
    const uint8_t* keys = SDL_GetKeyboardState(NULL);
    game.update(delta, keys);
}

void draw() {
    clear(cr);

    game.draw(cr);

    SDL_UnlockSurface(sdl_surf);
    SDL_BlitSurface(sdl_surf, NULL, screen, NULL);
    SDL_LockSurface(sdl_surf);
}

void mainLoop() {
    SDL_Event e;
    uint32_t now, then;
    float delta;
    then = SDL_GetTicks();
    while (game.running) {
        now = SDL_GetTicks();
        delta = (float) (now - then);
        
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                game.running = false;
            }
        }

        update(delta/1000.0f);
        draw();

        SDL_UpdateWindowSurface(window);

        then = now;
    }
}

void cleanup() {
    SDL_FreeSurface(screen);
    SDL_DestroyWindow(window);
}

int main(int argc, char** argv) {
    printf("hello, world!\n");
    srand(time(NULL));
    
    init();
    mainLoop();
    cleanup();
    
    return 0;
}
