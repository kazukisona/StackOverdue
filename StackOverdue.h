#ifndef STACKOVERDUE_H
#define STACKOVERDUE_H

#include <iostream>
#include "Library.h"

using namespace std;

class StackOverdue {
public:
	StackOverdue(): systemTime(0), systemStatus(true) {}
	StackOverdue(ifstream& newBooks, ifstream& newUsers)
		: systemTime(0), systemStatus(true) {library = Library(newBooks, newUsers);}
	~StackOverdue() {}

	// methods
	// commands
	void browse();
	void book();
	void search();
	void accounts();
	void account();
	void checkout();
	void renewBook();
	void returnBook();
	void recommend();
	void addB();
	void removeB();
	void addA();
	void removeA();
	void time();
	void systemInfo();
	void showHelp();
	void export();
	void exit();

	// mutator
	void setTime(unsigned int newTime) { systemTime = newTime;} // implemented

	// accessor
	unsigned int getTime() { return systemTime;} // implemented
	bool getSystemStatus() { return systemStatus;}
	bool errorHandler();
	
private:
	unsigned int systemTime;
	bool systemStatus;
	Library library;
};

#endif