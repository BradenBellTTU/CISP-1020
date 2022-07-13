#ifndef PROMPT_H
#define PROMPT_H

#include "response.h"
#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::ostream;
using std::istream;
using std::vector;

class Prompt {
	public:
		//Constructors
		Prompt(); //Default constructor
		Prompt(const string&);
		Prompt(const Prompt&);
		
		//Question constructors
		void setQuestion(const string&);
		string getQuestion() const {return question;}
		
		//Id constructors
		void setId(const int&);
		int getId() const {return id;}
		
		//Response constructors
		void addResponse (const Response& r)  {responses.push_back(r);}
		Response getResponse(const int& i) const {return responses[i];}
		void clearResponses();
		int getResponseSize() {return responses.size();}
		
		//friend functions
		friend ostream& operator<<(ostream&, const Prompt&);
		friend istream& operator>>(istream&, Prompt&);
		friend class Response;
		
	private:
		static const string outputs[];
		string question;
		int id;
		vector<Response> responses;
};


#endif