/*
Author: Kazuki Sona
Date: 14th, Dec
Class: CSCI23500
Instructor: Simon Ayzman
Prgrram: StackOverdue.h
*/

#ifndef STACKOVERDUE_H
#define STACKOVERDUE_H

#include <iostream>
#include "Library.h"

using namespace std;

class StackOverdue {
public:
	// constructor
	StackOverdue(): systemTime(1), systemStatus(true) { library = Library();}
	StackOverdue(ifstream& newBooks, ifstream& newUsers): 
			systemTime(1), systemStatus(true) {library = Library(newBooks, newUsers);}
	~StackOverdue() {}

	// methods
	// mutator
	void setTime(unsigned int newTime) { systemTime = newTime;}

	// accessor
	unsigned int getTime() { return systemTime;} // get system time
	bool getSystemStatus() { return systemStatus;} // get system status

	// commands
	void browse(); // BROWSE command
	void book(); // BOOK command
	void searchBook(); // SEARCH command
	void accounts(); // ACCOUNTS command
	void account(); // ACCOUNT command
	void checkout(); // CHECKOUT command
	void renewBook(); // RENEW command
	void returnBook(); // RETURN command
	void recommend(); // RECOMMEND command
	void addB(); // ADDB command
	void removeB(); // REMOVEB command
	void addA(); // ADDA command
	void removeA(); // REMOVEA command
	void time(); // TIME command
	void exportLibrary(); // EXPORT command
	void systemInfo(); // SYSTEM command
	void showHelp(); // HELP command
	void exit() { cout<<"Thank you for using StackOverdue!"<<endl; systemStatus=false;}  // EXIT command

	// utilities
	unsigned int askBookID(); // prompt to ask book ID
	unsigned int askUserID(); // prompt to ask user ID
	unsigned int getTotalBooks() { return library.getNumBooks();} // Returns total number of books in the library
	unsigned int getTotalAccounts() { return library.getNumUsers();} // Returns total number of accounts in the library
	
	// Returns true if there is a target(book, account) with a given id in the library
	bool isThereSomething(string target, unsigned int id);

private:
	unsigned int systemTime;
	bool systemStatus;
	Library library;
};

#endif