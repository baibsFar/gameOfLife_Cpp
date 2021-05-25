#include <iostream>
#include <time.h>
#include "include/Tilemap.hpp"

#define COL 150
#define LIN 150


void reset(int tilemap[][COL], int columns, int lines) {
    for (int i=0; i<lines; i++) {
        for (int j=0; j<columns; j++) {
            tilemap[i][j] = 0;
        }
    }
}

void randomize(int tilemap[][COL], int columns, int lines) {
    srand(time(NULL));
    for (int i=0; i<lines; i++) {
        for (int j=0; j<columns; j++) {
            int randomNbr = (rand() % (50 - 0 + 1));
            tilemap[i][j] = (randomNbr%2==0 ? 1 : 0);
        }
    }
}

void showConsole(int tilemap[][COL], int columns, int lines) {
    for (int i=0; i<lines; i++) {
        for (int j=0; j<columns; j++) {
            std::cout << " " << tilemap[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void checkNeighbour(int tilemap[][COL], int neighbour[][COL], int columns, int lines) {
    for (int i=0; i<lines; i++) {
        for (int j=0; j<columns; j++) {
            if (i>=0 && i<lines && j>=0 && j<columns) {
                int neighbourCounter = 0;
                if (i == 0) {
                    if (j == 0) {
                        for (int posy=i; posy<=i+1; posy++) {
                            for (int posx=j; posx<=j+1; posx++) {
                                if (tilemap[posy][posx] == 1 && (posy != i || posx != j)) {
                                    neighbourCounter++;
                                }
                            }
                        }
                    }
                    else if (j == columns-1) {
                        for (int posy=i; posy<=i+1; posy++) {
                            for (int posx=j-1; posx<=j; posx++) {
                                if (tilemap[posy][posx] == 1 && (posy != i || posx != j)) {
                                    neighbourCounter++;
                                }
                            }
                        }
                    }
                    else {
                        for (int posy=i; posy<=i+1; posy++) {
                            for (int posx=j-1; posx<=j+1; posx++) {
                                if (tilemap[posy][posx] == 1 && (posy != i || posx != j)) {
                                    neighbourCounter++;
                                }
                            }
                        }
                    }
                }
                else if (i == lines-1) {
                    if (j == 0) {
                        for (int posy=i-1; posy<=i; posy++) {
                            for (int posx=j; posx<=j+1; posx++) {
                                if (tilemap[posy][posx] == 1 && (posy != i || posx != j)) {
                                    neighbourCounter++;
                                }
                            }
                        }
                    }
                    else if (j == columns-1) {
                        for (int posy=i-1; posy<=i; posy++) {
                            for (int posx=j-1; posx<=j; posx++) {
                                if (tilemap[posy][posx] == 1 && (posy != i || posx != j)) {
                                    neighbourCounter++;
                                }
                            }
                        }
                    }
                    else {
                        for (int posy=i-1; posy<=i; posy++) {
                            for (int posx=j-1; posx<=j+1; posx++) {
                                if (tilemap[posy][posx] == 1 && (posy != i || posx != j)) {
                                    neighbourCounter++;
                                }
                            }
                        }
                    }
                }
                else {
                    if (j == 0) {
                        for (int posy=i-1; posy<=i+1; posy++) {
                            for (int posx=j; posx<=j+1; posx++) {
                                if (tilemap[posy][posx] == 1 && (posy != i || posx != j)) {
                                    neighbourCounter++;
                                }
                            }
                        }
                    }
                    else if (j == columns-1) {
                        for (int posy=i-1; posy<=i+1; posy++) {
                            for (int posx=j-1; posx<=j; posx++) {
                                if (tilemap[posy][posx] == 1 && (posy != i || posx != j)) {
                                    neighbourCounter++;
                                }
                            }
                        }
                    }
                    else {
                        for (int posy=i-1; posy<=i+1; posy++) {
                            for (int posx=j-1; posx<=j+1; posx++) {
                                if (tilemap[posy][posx] == 1 && (posy != i || posx != j)) {
                                    neighbourCounter++;
                                }
                            }
                        }
                    }
                }
                neighbour[i][j] = neighbourCounter;
            }
        }
    }
}

void updateTilemap(int tilemap[][COL], int neighbour[][COL], int columns, int lines) {
    for (int i=0; i<lines; i++) {
        for (int j=0; j<columns; j++) {
            if (neighbour[i][j] == 3) tilemap[i][j] = 1;
            if (neighbour[i][j] == 2) tilemap[i][j] = tilemap[i][j];
            if (neighbour[i][j] < 2 || neighbour[i][j] > 3) tilemap[i][j] = 0;
        }
    }
}