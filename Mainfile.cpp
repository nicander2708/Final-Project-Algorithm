#include <fstream>
#include <iostream>
#pragma once
#include "graph.h"
#include "graph.cpp"
#include "UserInterface.h"
#include "UserInterface.cpp"
#include "ShortestPath.cpp"
#include "ShortestTime.cpp"


using namespace std;

int main(){
	
	system("color 71");
	
	UserInterface UI;
	
	ifstream file;											// Setting up IO variable
	
	int source, destination;								// Holds source and destination read
	string arr, dest, name;									// Holds times and names read
	int stationNum;
	char stationName[25] ={0};
	int src, dst;
	
	GRAPH* g = NULL; // Creating graph ptr
	g = new GRAPH();

	file.open("Jabodetabek.dat");							
	if (!file.is_open())
	{
		cout << "Error: Failed to open input file\n";
		return 0;
	}
	
	// Reading station names and numbers into names array
	while (file >> source){                
		file >> name;
		g->setStation(source, name); 
	}
	file.close();


	UI.title();	// Display program intro

    int choice = 1; // Initializing choice to 1 to ensure it has a non 0 value  

	 while (choice != 0){
 
    	UI.options(); // Display user options
    	cin >> choice;
    	
    	switch(choice){

    		case 0:
    			cout << endl;
    			cout <<"Goodbye!" << endl;
    			break;

    		case 1: // Prints list of all the stations
        		 g->printAll();
        		break;

    		case 2:	// Finds name of station by station ID
    			cout << "Enter station id: ";
    			cin >> stationNum;
        		g->findNameByID(stationNum);
        		break;

        	case 3:	// Finds number of station by name      		
        		g->initialize(stationName);						// Reinitializes stationName for new name to be entered
	       		cout << "Enter station name: ";
        		cin >> stationName;
        		g->findNumberByName(stationName);
        		break;

        	case 4:
        		cout << "Enter departure station ID: ";	
				cin >> src;
				cout << "Enter destination station ID: ";
				cin >> dst;
				
				if(src <= 80 && dst <= 80){
					g->findNameByID(src);
					g->findNameByID(dst);
					shortestDistance("kereta_map.gr", src, dst);
				}
				
				else{
					cout << endl;
					cout << "Invalid station ID entered. ID must be between 1-80. \n\n";
	        		break;
	        	}
	        	break;		

	        case 5: 
				cout <<"Enter departure station id: ";
	        	cin >> src;
	        	cout <<"Enter destination station id: ";
	        	cin >> dst; 
	        	
	        	if(src <= 80 && dst <= 80){
		        	g->findNameByID(src);
					g->findNameByID(dst);
		        	shortestTime("kereta_time.gr", src, dst);
				}
				
				else{
					cout << endl;
					cout << "Invalid station ID entered. ID must be between 1-80. \n\n";
	        		break;
				}
				break;
			case 6: 
				cout <<"Enter departure station id: ";
	        	cin >> src;
	        	cout <<"Enter destination station id: ";
	        	cin >> dst; 
	        	
	        	if(src <= 80 && dst <= 80){
		        	g->findNameByID(src);
					g->findNameByID(dst);
		        	shortestDistanceB("kereta_map.gr", src, dst);
				}
				
				else{
					cout << endl;
					cout << "Invalid station ID entered. ID must be between 1-80. \n\n";
	        		break;
				}
	        	break;
			case 7: 
	        	cout <<"Enter departure station id: ";
	        	cin >> src;
	        	cout <<"Enter destination station id: ";
	        	cin >> dst; 
	        	
	        	if(src <= 80 && dst <= 80){
		        	g->findNameByID(src);
					g->findNameByID(dst);
		        	shortestTimeB("kereta_time.gr", src, dst);
				}
				
				else{
					cout << endl;
					cout << "Invalid station ID entered. ID must be between 1-80. \n\n";
	        		break;
				}
				

	        	break;

    		default:
        		cout <<"The number you have entered is invalid." << endl;
        		cout <<"Please try again."<< endl << endl;
	        	break;

         	
    	}
	}

	return 0;
}
