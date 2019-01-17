#include "graph.h"

GRAPH::GRAPH() {}      												// Constructor that takes no parameter 
// end constructor

void GRAPH::setStation(int station, string name){    				   							 // Setting station name

	names[station] = name;

} // end function setStation

void GRAPH::findNameByID(int number){														// Finds the name of station by number

	if(number >= 1 && number <= 80 && names[number] != " "){									// If valid number received

		cout << endl;
		cout << "The name of station w/ ID " << number << " is " << names[number] << endl;	// Print the name of the station
		cout << endl;
	}
	else{

		cout << endl;																 			// Else state that invalid number was entered
		cout <<"Invalid station ID entered." << endl;
		cout << "ID must be between 1 - 80." << endl << endl;
	}

} // end function findNameByNumber

void GRAPH::findNumberByName(char station[]){											// Finds station number by station name

	int count = 0;																		// Counter variable to hold characters to be checked
		
	for(int i = 0; i<25; i++){															// Loop through array ignoring null, '-' or '_'

		if(station[i] != '\0' && station[i]!= '_'){										// If element holds character, increase count

			count++;
		}		
	}
		
	int loop = count + 1;																// Set loop to go count + 1 times								
	int match = 0;																		// Counter to hold matches found
	char upper;																			// Holds uppercase version of a character
	locale loc;																			// Required to use function toupper
		
	for (int i = 1; i <= 80; i++){														// Search through station names array
		
		for(int j = 0, k = 0; j < loop; j++, k++){										// Loop for as many characters as needed
						
			if((station[j] =='_')){														// If input in array sent is '_',skip to next element
				j++;
			}

			if(names[i][k] == '_'){														// If element in station name holds '_', skip to next element
				k++;
			}
																						
			if(station[j] == names[i][k] || station[j] == (upper = toupper(names[i][k], loc))){		// If a match is found, increase match
				
				match++;			
	
				if(match == count){															// If complete word match, break loop
					break;
				}
			}
		}

		if(match == count){																	// If complete word match, print station number

			cout <<endl;
			cout << names[i] <<"'s station id is " << i << "" << endl;
			cout << endl;
			break;
		}
		
		match = 0;																			// Reset match counter for next iteration
	}

	if(match < count){
		cout << endl;
		cout <<"A station of that name has not been found"<< endl;	
		cout << endl;																		// If match < count, state no match found
	}
		
} // end function findNumberByName

void GRAPH::initialize(char arr[]){															// initializes a char array to "_"'s

	for (int i = 0; i < 30;i++){
        	arr[i] = '_';
    }

} // end function initialize 

void GRAPH::printAll(){																		// Prints schedule for all trains

	cout << endl;
	cout <<"LIST OF ALL TRAIN STATIONS" << endl;
	cout <<"=======================" << endl;
	cout << "ID     STATION NAME \n\n";

	for(int i = 1; i <= 80; i++){															// Loop through the total number of stations
		cout << i  << "      " << names[i] << endl;
		cout << endl;
	}
} // end function printStation
