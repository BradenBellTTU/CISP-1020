#include "response.h"
#include "prompt.h"
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::string;
using std::ostream;
using std::istream;
using std::vector;

//Random question outputs
const string Prompt::outputs[] = {"What's next? ", "What now? ", "Choose carefully: ", "Make your choice: ", "How will you get out of this one? ", "Next action? ", "Choose your action carefully: ", "What do you want to do?", "Which one? ", "Your choice is...?"};

//Default constructor - sets question and id vars
Prompt::Prompt() {
	question = "";
	id = -1;
}

//1 param constructor - sets question and id vars
Prompt::Prompt(const string& s) {
	question = s;
	id = -1;
}

//Copy constructor
Prompt::Prompt(const Prompt& p) {
	question = p.question;
	id = p.id;
	responses = p.responses;
}

//Set question constructor - sets the question var
void Prompt::setQuestion(const string& q) {
	question = q;
}

//Set id constructor - sets the id var
void Prompt::setId(const int& i) {
	if (i >= 0) {
		id = i;
	}
	
	else {
		id = -1;
	}
}

//Overloaded output operator - Prints the current responses and a random outputs
ostream& operator<<(ostream& outStream, const Prompt& p) {
	
	srand(time(NULL)); //Seed randomness
	
	int randInt = rand() % 10; //Get rand int
	
	outStream << p.question << '\n'; //Output the question
	
	for (int i = 0; i < p.responses.size(); i++) { //print responses
		outStream << i << " " << p.responses[i] << '\n';
	}
	
	outStream << p.outputs[randInt]; //Print outputs
	
	return outStream; 
}

//Overloaded input operator - takes data and stores it into a Prompt
istream& operator>>(istream& inStream, Prompt& p) {
	char tempString[1000];
	Response tempResponse;
	char * token;
	
	p.clearResponses(); //Clear responses
	
	inStream.getline(tempString, 1000); //Read the file
	
	token = strtok(tempString, "|"); //Tokenize the file data
	p.id = atoi(token); //Set id
	token = strtok(NULL, "|"); //Tokenize the file data
	p.question = token; //Set question
	
	token = strtok(NULL, "|"); //Gets first response text
	
	while(token != NULL) { //While there is still data in the file lines
		tempResponse.setResponse(token); //Set response
		token = strtok(NULL, "|"); //Tokenize more data
		tempResponse.setIndex(atoi(token));//Set index
		p.addResponse(tempResponse); //Add a response
		token = strtok(NULL, "|");//Tokenize file data again
	}
	
	return inStream;
}

//Clear responses - clears the response vector (this would have been inline but was put here for debugging purposes
void Prompt::clearResponses() {
	responses.clear(); //Clear responses vector
}