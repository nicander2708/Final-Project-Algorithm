#include "UserInterface.h"
using namespace std;

void UserInterface::title(){
	
	cout << "=========================================================\n";
    cout << "                TRAIN STATION SIMULATION                 \n";
    cout << "=========================================================\n";
    cout << endl;
}

void UserInterface::options(){
	
	cout <<"Options - (Enter the number of your selected option)" << endl;					// User's options display
    cout <<"(1) - Print all station names" << endl;
    cout <<"(2) - Look up station name" << endl;
    cout <<"(3) - Look up station id" << endl;
    cout <<"(4) - Find route (Shortest distance)" << endl;
    cout <<"(5) - Find route (Shortest overall travel time)" << endl;
    cout <<"(6) - Find route (Shortest distance using bellman-ford)" << endl;
    cout <<"(7) - Find route (Shortest overall travel time using bellman-ford)" << endl;
    cout <<"(0) - Exit" << endl;
    cout << endl;
    cout <<"Enter option: ";
}
