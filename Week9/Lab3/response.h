#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::ostream;
using std::istream;

class Response {
public:
	//Constructors
	Response(); //Default constructor
	Response(const string&, const int&); //2 param constructor
	
	Response(const Response&); //Copy constructor
	
	//Response constructors
	void setResponse(const string&); 
	string getResponse() const {return response;}
	
	//Index constructors
	void setIndex(const int&);
	int getIndex() const {return index;}
	
	//Friend functions
	friend ostream& operator<<(ostream&, const Response&);
	friend class Prompt;
	
private:
	string response;
	int index;
};



















#endif