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
		Prompt();
		Prompt(const string&);
		Prompt(const Prompt&);
		
		void setQuestion(const string&);
		string getQuestion() const {return question;}
		
		void setId(const int&);
		int getId() const {return id;}
		
		void addResponse (const Response& r)  {responses.push_back(r);}
		Response getResponse(const int& i) const {return responses[i];}
		void clearResponses() {responses.clear();}
		
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