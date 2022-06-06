/*
    * File: lab1.cpp
    * Author: Braden Bell
    * Date: 6/1/2022
    * This program 
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/*Things that will be used in this program:
Files
getline() for the files
Array of 10 structures

main algorithm:
Print hello message
get file name and open it
Read jobs into array of structures
Sort the array of structures by title
do
	print menu and get option
		if option is 1
	seach by job title
		if option is 2
	search by job skill
*/

//Const vars
const bool debug = true;
const int MAX_SKILLS = 10;
const int MAX_STRING_LENGTH = 256;
const int MAX_JOBS = 10;


//Structures
struct Job {
	char jobTitle[MAX_STRING_LENGTH];
	int numSkills;
	char skills[MAX_SKILLS] [MAX_STRING_LENGTH];
	double salary;
	char company[MAX_STRING_LENGTH];
};

//Function prototypes
int readJobs(Job*);
void displayJobs(Job*, int, int index = -1);
int menu();
void searchByTitle(Job*, int);
void searchBySkill(Job*, int);
void selectionSort(Job*, int);
string convertToString(char*, int);
bool emptyTest(std::ifstream& pFile);


int main() {
	//Vars
	fstream inFileStream;
	Job jobsArray[MAX_JOBS];
	int numJobs = 0;
	bool menuLoop = true;
	char search[MAX_STRING_LENGTH];
	
	//Welcome the user
	cout << "Welcome to Jobs.com\n";

	//Popualte the jobs array
	numJobs = readJobs(jobsArray);
	if (numJobs == 0) {
		return 0;
	}
	//Sort the array alphabetically
	selectionSort(jobsArray, numJobs);

	//Main menu loop
	do {
		switch(menu()) {
			case 1:
				searchByTitle(jobsArray, numJobs);
				break;
			
			case 2:
				searchBySkill(jobsArray, numJobs);
				break;
			
			case 3:
				menuLoop = false;
				break;
			
			case 4:
				displayJobs(jobsArray, numJobs);
				break;
			
			default:
				cout << "\n\nInvalid option. Please try again.\n";
				break;
		
		}
	}
	while(menuLoop);
	
	cout << "Thank you for using Jobs.com\n";
	return 0;
}

/*
readjobs: reads jobs into array from input file
Parameters:
	jobsArray: array of job structures
	inFileStream: input file
Pre-condition: input file opened and is not empty
Return: number of jobs it read from files as an int
*/
int readJobs(Job* jobsArray) {
	int i = 0;
	int numSkills = 0;
	fstream inFileStream;
	string tempString = "";
	string inFileName;
	
    //Get file name from user
    cout << "Jobs file: ";
    cin >> inFileName;
    
    //Try to open file
    inFileStream.open(inFileName);

    //Verify that the user input was valid and the file opens correctly.
    //If not, then ask user for file name and try again
    if(inFileStream.fail()) {
        cout << "Input file " << inFileName << " does not exist.\n";
		cout << "Please contact the administrator.\n";
		return 0;
	}

	
	inFileStream.getline(jobsArray[i].jobTitle, MAX_STRING_LENGTH);
	while(!inFileStream.eof() && i < MAX_JOBS) {
		//Use cin to read jobsArray[i].numSkills
		inFileStream >> jobsArray[i].numSkills;
		inFileStream.ignore(256, '\n');
		//Read jobs[i].numSkills number of skills in a for loop
			for (int j = 0; j < jobsArray[i].numSkills; j++) {
				inFileStream.getline(jobsArray[i].skills[j], MAX_STRING_LENGTH);
			}
		
		inFileStream >> jobsArray[i].salary;
		inFileStream.ignore(256, '\n');
		
		inFileStream.getline(jobsArray[i].company, MAX_STRING_LENGTH);
		i++;
		if (i < MAX_JOBS) {
			inFileStream.getline(jobsArray[i].jobTitle, MAX_STRING_LENGTH);
		}
	}

	if (inFileStream.eof() && i == 0) {
	cout << inFileName << " is empty. Please contact the administrator.\n";
}
	return i;
}	
	
/*
menu: Displays the main menu to the user
Parameters:
	None
Pre-condition: None
Return: the user's choice via an int
*/
int menu() {
	int userInput = 0;
	
	//Displays main menu
	cout << "\n\n\n1. Search for job by title\n";
	cout << "2. Search for job by skill\n";
	cout << "3. Quit\n\n";
	//If debug mode is active, then print the main menu along with the debugging menu
	//And change input validation to debug mode
	if (debug) {
		cout << "Debug Menu Active\n";
		cout << "4. Print jobsArray[]\n";
		cout << "Option> ";
		cin >> userInput;
		while(cin.fail() || (userInput < 1 && userInput > 4)) {
			cout << "1. Search for job by title\n";
			cout << "2. Search for job by skill\n";
			cout << "3. Quit\n\n";
			cout << "Unexpected input. Please try again.\n";
			cout << "Option> ";
			cin >> userInput;
		}
	}
	
	//If debug mode is not active, then don't print debug menu and set input validation
	//to user mode
	else{
		cout << "Option> ";
		cin >> userInput;
		while(cin.fail() || (userInput < 1 && userInput > 3)) {
			cout << "1. Search for job by title\n";
			cout << "2. Search for job by skill\n";
			cout << "3. Quit\n\n";		
			cout << "Unexpected input. Please try again.\n";
			cout << "Option> ";
			cin.ignore();
			cin >> userInput;
		}
	}
	
	return userInput;
}

/*
searchByTitle: Searches jobsArray.jobTitle for jobs by user input
Parameters:
	jobsArray: array of job structures
	numJobs: the number of jobs in the array
Pre-condition: None
Return: None
*/
void searchByTitle(Job* jobsArray, int numJobs) {
	char* pch;
	char search[MAX_STRING_LENGTH];
	bool searchFound = false;
	cin.ignore();
	cin.getline(search, MAX_STRING_LENGTH);

	for (int i = 0; i < numJobs; i++) {
		pch = strstr(jobsArray[i].jobTitle, search);
		if (pch != NULL) {
			searchFound = true;
			displayJobs(jobsArray, numJobs, i);
		}
	}
	if(!searchFound) {
		cout << "\nThat search did not return any results.\n";
	}
}

void searchBySkill(Job* jobsArray, int numJobs) {
	char* pch;
	char search[MAX_STRING_LENGTH];
	bool searchFound = false;

	cin.ignore();
	cin.getline(search, MAX_STRING_LENGTH);

	for (int i = 0; i < numJobs; i++) {
		for (int j = 0; j < jobsArray[i].numSkills; j++) {
			pch = strstr(jobsArray[i].skills[j], search);
			if (pch != NULL) {
				searchFound = true;
				displayJobs(jobsArray, numJobs, i);
			}
		}
	}
}


/*
selectionSort: A selection sort algorithm that sorts the jobsArray in alphabetical order
Parameters:
	jobsArray: array of job structures
	numJobs: the number of jobs in the array
Pre-condition: None
Return: None
*/
void selectionSort(Job* jobsArray, int numJobs) {
	for (int i = 0; i < (numJobs - 1); i++) {
		int iMin = i;
		for (int j = (i + 1); j < numJobs; j++) {
			if (strcmp(jobsArray[i].jobTitle, jobsArray[j].jobTitle) > 0) {
				iMin = j;
			}
			Job temp = jobsArray[i];
			jobsArray[i] = jobsArray[iMin];
			jobsArray[iMin] = temp;
		}
	}
}

/*
displayJobs: prints the data in he array to console depending on the parameters passed to it
Parameters:
	jobsArray: array of job structures
	numJobs: the number of jobs in the array
	int: The index of which job needs to be printed.
		 If there is no index provided, it will print
		 the entire array
Pre-condition: None
Return: None
*/
void displayJobs(Job* jobsArray, int numJobs, int index) {
	//Default value of index is -1
	if (index == -1) {
		//Prints all data in jobsArray
		for (int i = 0; i < numJobs; i++) {
			cout << '\n' << jobsArray[i].jobTitle << '\n';
			cout << jobsArray[i].numSkills << '\n';
			for (int j = 0; j < jobsArray[i].numSkills; j++) {
				cout << jobsArray[i].skills[j] << '\n';
			}
			cout << jobsArray[i].salary << '\n';
			cout << jobsArray[i].company << '\n';
		}
	}

	//Prints just the data in the index provided by the user
	else {
		int i = index;
		cout << '\n' << jobsArray[i].jobTitle << '\n';
		cout << jobsArray[i].numSkills << '\n';
		for (int j = 0; j < jobsArray[i].numSkills; j++) {
			cout << jobsArray[i].skills[j] << '\n';
		}
		cout << jobsArray[i].salary << '\n';
		cout << jobsArray[i].company << '\n';
	}
}

bool emptyTest(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}