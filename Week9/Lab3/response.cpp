#include "response.h"
#include <string>
#include <iostream>

using std::string;
using std::ostream;

//Default constructor - sets response and index vars
Response::Response() {
	response = "";
	index = -1;
}

//2 argument constructor - sets response and index vars
Response::Response(const string& r, const int& i) {
	response = r;
	if (i >= 0) {
		index = i;
	}
	
	else {
		index = -1;
	}
}

//Copy constructor
Response::Response(const Response& r) {
	response = r.response;
	index = r.index;
}

//Set response - sets the respose var
void Response::setResponse(const string& s) {
	response = s;
}

//Set index - sets the index var
void Response::setIndex(const int& i) {
	if (i >= 0) {
		index = i;
	}
	
	else {
		index = -1;
	}
}

//Overloaded output operator - prints response
ostream& operator<<(ostream& outStream, const Response& r) {
	outStream << r.response;
	return outStream;
}