#include <iostream>
#include <time.h>
#include "include/functions.hpp"
#include "include/Tilemap.hpp"

#define X SDL_WINDOWPOS_CENTERED
#define Y SDL_WINDOWPOS_CENTERED
#define WIDTH 800
#define HEIGHT 600  // Coefficient: WIDTH / HEIGHT
#define LIN 150
#define COL 150
#define TICK 20
const int rectWidth = WIDTH/COL;
const int rectHeight = HEIGHT/LIN;

/*
    TILEMAP, NEIGHBOUR
*/
int Tilemap[LIN][COL] = {};
int Neighbour[LIN][COL] = {};

/* Window & Renderer of the application */
SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;
SDL_Event e;

/* 
    Keydown Values 
*/
#define KEYDOWN SDL_KEYDOWN
#define MOUSEDOWN SDL_MOUSEBUTTONDOWN
#define SPACE SDLK_SPACE
#define ESCAPE SDLK_ESCAPE
#define UP SDLK_UP
#define DOWN SDLK_DOWN
#define LEFT SDLK_LEFT
#define RIGHT SDLK_RIGHT
#define MOUSE_B_RIGTH SDL_BUTTON_RIGHT
#define MOUSE_B_LEFT SDL_BUTTON_LEFT
#define MOUSE_X e.button.x
#define MOUSE_Y e.button.y


/* Constant or predefined Colors */
const Color yellow = {251, 188, 5, 255};  // Hexa : #FBBC05
const Color gray = {20, 20, 20, 255};
const Color white = {180, 180, 180, 255};




/* Initialization of the SDL program */
void init(const char* windowTitle) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(windowTitle, X, Y, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_SOFTWARE);
}


/* Main loop for rendering the whole graphics components */
void loop() {
    bool quit = false;
    bool play = false;
    int current = 0;
    int passed = 0;
    int fps = TICK;

    randomize(Tilemap, COL, LIN);
    while (!quit) {
        SDL_PollEvent(&e);
        /* Quit handler */
        if (e.type == SDL_QUIT) quit = true;
        if (e.type == KEYDOWN) {
            /* Quit handler */
            if (e.key.keysym.sym == ESCAPE) {
                quit = true;
            }
            /* Play button */
            if (e.key.keysym.sym == SPACE) {
                play = (play == true ? false : true);
            }
            /* Random configuration */
            if (e.key.keysym.sym == UP) {
                randomize(Tilemap, COL, LIN);
            }
            /* Reset and clean the whole configuration */
            if (e.key.keysym.sym == DOWN) {
                reset(Tilemap, COL, LIN);
            }
            /* Speed handler */
            if (e.key.keysym.sym == LEFT) {     /* Decrease the speed by 2 */
                if (fps < 500) {
                    fps += 2;
                }
            }
            if (e.key.keysym.sym == RIGHT) {    /* Increase the speed by 2 */
                if (fps > 20) {
                    fps -= 2;
                }
            }
        }

        /* Click system */
        if (e.type == MOUSEDOWN) {
            if (e.button.button == MOUSE_B_LEFT) {
                for (int i=0; i<LIN; i++) {
                    for (int j=0; j<COL; j++) {
                        if (MOUSE_X > j*rectWidth && MOUSE_X < j*rectWidth+rectWidth
                        && MOUSE_Y > i*rectHeight && MOUSE_Y < i*rectHeight+rectHeight) {
                            Tilemap[i][j] = (Tilemap[i][j] == 1 ? 0 : 1);
                        }
                    }
                }
            }
        }
        
        current = SDL_GetTicks();

        drawTilemap(Tilemap, COL, LIN);
        if ((current - passed) >= fps) {

            if (play == true) {
                checkNeighbour(Tilemap, Neighbour, COL, LIN);
                updateTilemap(Tilemap, Neighbour, COL, LIN);
            }

            passed = current;
        } else SDL_Delay(fps - (current - passed));

        
        // Must set the Background Color for avoiding that
        // the rect won't be drawn
        setBgColor(gray);
        update();
    }
    finish();
}


/* 
    Drawing rectangle or quad figure:
        - position: x, y
        - dimension: width, height
        - texture; color
*/
void drawRect(int x, int y, int width, int height, Color color) {
    SDL_Rect rect = {x, y, width, height};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}


/* Setting the background color with "color" */
void setBgColor(Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}


/* Draw the whole Tilemap if Tilemap[i][j] == 1 */
void drawTilemap(int tilemap[][COL], int columns, int lines) {
    for (int i=0; i<lines; i++) {
        for (int j=0; j<columns; j++) {
            if (tilemap[i][j] == 1) drawRect(j*rectWidth, i*rectHeight, rectWidth, rectHeight, yellow);
        }
    }
}


/* Updating the screen at each changes in the program */
void update() {
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}


/* 
    Quit the SDL program:
        - Destroying the renderer (removing renderer allocation)
        - Destroying the window (removing window allocation)
        - For finally quit the whole SDL program
*/
void finish() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "\t\t\tThanks for playing ©Sbiab Fararano" << std::endl;
}