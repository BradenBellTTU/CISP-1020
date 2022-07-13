/*
    * File: Lab3.cpp
    * Author: Braden Bell
    * Date: 7/13/2022
    * This program is for lab 3. It is a game engine for a text based adventure game.
*/


#include <iostream>
#include <vector>
#include "prompt.h"
#include "response.h"
#include <fstream>

using namespace std;

int main() {
	//Vars
	int userChoice = -1, i = 0;
	fstream inFileStream; //File stream
	vector<Prompt> gamePrompts; //Primary game vector
	Prompt tempPrompt; //Temporary Prompt
	
	inFileStream.open("GameInput.csv"); //Attempt to open the file
	
	
	if (!inFileStream.is_open()) { //Check to see if the file opened successfully
		cout << "Error: file not found, provide a file in the current directory and try again\n"; //Error message
		return 1; //Return error state
	}

	
	
	//Read all data from the file
	while(!inFileStream.eof()) {
		inFileStream >> tempPrompt; //Read into a temporary prompt because we're using vectors
		gamePrompts.push_back(tempPrompt); //Put temp data into the real gamePrompt
	}
	inFileStream.close(); //Close file 
	
	
	
	
	cout << gamePrompts[0] << '\n'; //Display first question to user
	
	cin >> userChoice; //Get user choice
	
	while(cin.fail() || userChoice < 0 || userChoice >= gamePrompts[i].getResponseSize()) { //Input checking
		cin.clear();//Clear the cin buffer in case of cin.fail case
		cin.ignore(255, '\n'); //More clearing
		cout << "Error: unexpected input. Please try again.\n"; //Error message
		cin >> userChoice; //Get user input again
	}
	
	i = gamePrompts[i].getResponse(userChoice).getIndex(); //Update i to correct index
	
	
	
	while(i != -1) { //While not in an exit case:
		cout << gamePrompts[i]; //Display the question
		
		cin >> userChoice; //Get user choice
		
		while(cin.fail() || userChoice < 0 || userChoice >= gamePrompts[i].getResponseSize()) { //Input checking
			cin.clear(); //Clear the cin buffer in case of cin.fail case
			cin.ignore(255, '\n'); //More clearing
			cout << "Error: unexpected input. Please try again.\n"; //Display error message to user
			cin >> userChoice; //Get user choice again
		}
		i = gamePrompts[i].getResponse(userChoice).getIndex(); //Update i to correct index
	}
	
	
	cout << "\nGoodbye.\n"; //Goodbye message
	return 0; //Exit program :)
}

