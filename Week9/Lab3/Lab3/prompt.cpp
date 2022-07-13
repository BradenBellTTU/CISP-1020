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

const string outputs[] = {""};

Prompt::Prompt() {
	question = "";
	id = -1;
}


Prompt::Prompt(const string& s) {
	question = s;
	id = -1;
}

Prompt::Prompt(const Prompt& p) {
	question = p.question;
	id = p.id;
	responses = p.responses;
}

void Prompt::setQuestion(const string& q) {
	question = q;
}

void Prompt::setId(const int& i) {
	if (i >= 0) {
		id = i;
	}
	
	else {
		id = -1;
	}
}

ostream& operator<<(ostream& outStream, const Prompt& p) {
	
	srand(time(NULL));
	
	int randInt = rand() % 1; //Change number once outputs are added
	
	outStream << question << '\n';
	for (int i = 0; i < responses.size(); i++) {
		outStream << i << " " << responses[i] << '\n';
	}
	
	outStream << p.outputs[randInt];
	
	return outStream;
}

istream& operator>>(istream& inStream, Prompt& p) {
	char tempString[1000];
	Response tempResponse;
	char * token;
	
	inStream.getline(tempString, 1000);
	
	token = strtok(tempString, "|");
	
	p.id = atoi(token);
	
	token = strtok(NULL, "|");
	
	p.question = token;
	
	token = strtok(NULL, "|"); //Gets first response text
	while(token != NULL) {
		tempResponse.response = token;
		
		token = strtok(NULL, "|");
		tempResponse.id = atoi(token);
		
		p.addResponse(tempResponse);
	}
}