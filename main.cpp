#include <iostream>
#include "include/functions.hpp"
#include "include/Tilemap.hpp"


using namespace std;


int main()
{
    system("clear");
    cout << "\t\t\t\t\tGAME OF LIFE\n\n " << endl;
    cout << "\tTutorial: \n\t\t- press [SPACE] to play(or stop) \n"; 
    cout << "\t\t- press [ESCAPE] to quit \n"; 
    cout << "\t\t- click anywhere to place cell \n"; 
    cout << "\t\t- press [UP] to have a random configuration \n";
    cout << "\t\t- press [DOWN] to clean whole configuration \n";
    cout << "\t\t- press [LEFT or RIGHT] to decrease/increase the speed \n\n";
    cout << "\n\t\tGood game :') <(°_°)>\n\n ";
    cout << "\n\nProgram development(Sbiab Fararano) - game concept(John Horton Conway) - tools(SDL Library)\n\n\n";

    const char* windowTitle = "Game of Life : SDL2";

    init(windowTitle);
    loop();

    return 0;
}