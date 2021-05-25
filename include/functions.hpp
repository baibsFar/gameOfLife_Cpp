#ifndef _FUNCTIONS_HPP_
#define _FUNCTIONS_HPP_
#include <SDL2/SDL.h>
#include <stdbool.h>

#define COL 150

typedef struct Color Color;
struct Color {
    int r;
    int g;
    int b;
    int a; // Opacity 0 -> 255
};

void init(const char* windowTitle);

void loop();

void drawRect(int x, int y, int width, int height, Color color);

void setBgColor(Color color);

void drawTilemap(int tilemap[][COL], int columns, int lines);

void update();

void finish();

#endif // !1