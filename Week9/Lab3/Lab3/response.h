#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Response {
public:
	Response();
	Response(const string&, const int&);
	
	Response(const Response&);
	
	void setResponse(const string&);
	string getResponse() const {return response;}
	
	void setIndex(const int&);
	int getIndex() const {return index;}
	
	friend ostream& operator<<(ostream&, const Response&);
	
	friend class Prompt;
	
private:
	string response;
	int index;
};



















#endif