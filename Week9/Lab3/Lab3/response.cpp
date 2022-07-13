#include "response.h"
#include <string>
#include <iostream>

using std::string;
using std::ostream;

Response::Response() {
	response = "";
	index = -1;
}

Response::Response(const string& r, const int& i) {
	response = r;
	if (i >= 0) {
		index = i;
	}
	
	else {
		index = -1;
	}
}

Response::Response(const Response& r) {
	response = r.response;
	index = r.index;
}

void Response::setResponse(const string& s) {
	response = s;
}

void Response::setIndex(const int& i) {
	if (i >= 0) {
		index = i;
	}
	
	else {
		index = -1;
	}
}

ostream& operator<<(ostream& outStream, const Response& r) {
	outStream << r.response;
	return outStream;
}