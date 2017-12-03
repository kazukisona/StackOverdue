#ifndef STACKOVERDUE_H
#define STACKOVERDUE_H

#include <iostream>
#include "Library.h"

using namespace std;

class StackOverdue {
public:
	void browse();
	void book();
	void search();
	void accounts();
	void account();
	void checkout();
	void renew();
	void return();
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

	void setTime(unsigned int newTime) { systemTime = newTime;}; // implemented
	unsigned int getTime() { return systemTime;}; // implemented
	void errorHandler();
	
private:
	unsigned int systemTime;
};

#endif