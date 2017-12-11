#ifndef STACKOVERDUE_H
#define STACKOVERDUE_H

#include <iostream>
#include "Library.h"

using namespace std;

class StackOverdue {
public:
	StackOverdue(): systemTime(1), systemStatus(true) {}
	StackOverdue(ifstream& newBooks, ifstream& newUsers)
		: systemTime(1), systemStatus(true) {library = Library(newBooks, newUsers);}
	~StackOverdue() {}

	// methods
	// mutator
	void setTime(unsigned int newTime) { systemTime = newTime;} // implemented

	// accessor
	unsigned int getTime() { return systemTime;} // implemented
	bool getSystemStatus() { return systemStatus;} // implemented

	// commands
	void browse(); // implemented
	void book(); // implemented
	void searchBook(); // implemented
	void accounts(); // implemented
	void account(); // implemented
	void checkout(); // implemented
	void renewBook();
	void returnBook();
	void recommend();
	void addB();
	void removeB();
	void addA();
	void removeA();
	void time();
	void systemInfo();
	void showHelp(); // implemented
	void export();
	void exit() { cout<<"Thank you for using StackOverdue!"<<endl; systemStatus=false;}  // implemented

	// utilities
	unsigned int askBookID();
	unsigned int askUserID();
	unsigned int getTotalBooks();
	unsigned int getTotalAccounts();
	bool errorHandler();

private:
	unsigned int systemTime;
	bool systemStatus;
	Library library;
};

#endif