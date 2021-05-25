/*
    Tilemap manipulation prototype and their 
    implementation in "Tilemap.cpp"
*/


#ifndef _TILEMAP_HPP_
#define _TILEMAP_HPP_

#define COL 150
#define LIN 150

void reset(int tilemap[][COL], int columns, int lines);

void randomize(int tilemap[][COL], int columns, int lines);

void showConsole(int tilemap[][COL], int columns, int lines);

void checkNeighbour(int tilemap[][COL], int neighbour[][COL],int columns, int lines);

void updateTilemap(int tilemap[][COL], int neighbour[][COL], int columns, int lines);

#endif