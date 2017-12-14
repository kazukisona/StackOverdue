#ifndef MAIN_CPP
#define MAIN_CPP
#include <iostream>
#include <fstream>
#include "StackOverdue.h"

using namespace std;

string toUpper(string str);

int main(int argc, char const *argv[]) {
	
	ifstream inputB, inputA;

	if (argc != 3) {
		if (argv[1]) {
			inputB.open(argv[1]);

			if (inputB.fail()) {
				cout << "Could not find file \"" << argv[1] << "\". Skipping." << endl;
				inputB.open("blank.book.data");
			}
			else
				cout << "Loading books from \"" << argv[1] << "\"." << endl; 
		}
		else {
			cout << "No books provided." << endl;
			cout << "No accounts provided." << endl;
			inputB.open("blank.book.data");
			inputA.open("blank.account.data");
		}	
	}
	else {
		inputB.open(argv[1]);
		if (inputB.fail()) {
			cout << "Could not find file \"" << argv[1] << "\". Skipping." << endl;
			inputB.open("blank.book.data"); // dummy data
		}
		else {
			cout << "Loading books from \"" << argv[1] << "\"." << endl;
		}

		inputA.open(argv[2]);
		if (inputA.fail()) {
			cout << "Could not find file \"" << argv[2] << "\". Skipping." << endl;
			inputA.open("blank.account.data"); // dummy data
		}
		else {
			cout << "Loading accounts from \"" << argv[2] << "\"." << endl;
		}
	}

	StackOverdue stack = StackOverdue(inputB, inputA);
	cout << endl;
	string command;

	// command processing
	while (stack.getSystemStatus()) {

		cout << "> ";
		cin >> command;

		if (toUpper(command) == "BROWSE") {
			stack.browse();
			cout << endl;
		} 
		else if (toUpper(command) == "BOOK") {
			stack.book();
			cout << endl;
		}
		else if (toUpper(command) == "SEARCH") {
			stack.searchBook();
			cout << endl;
		}
		else if (toUpper(command) == "ACCOUNTS") {
			stack.accounts();
			cout << endl;
		}
		else if (toUpper(command) == "ACCOUNT") {
			stack.account();
			cout << endl;
		} 
		else if (toUpper(command) == "CHECKOUT") {
			stack.checkout();
			cout << endl;
		}
		else if (toUpper(command) == "RENEW") {
			stack.renewBook();
			cout << endl;
		}
		else if (toUpper(command) == "RETURN") {
			stack.returnBook();
			cout << endl;
		}
		else if (toUpper(command) == "RECOMMEND") {
			stack.recommend();
			cout << endl;
		}
		else if (toUpper(command) == "ADDB") {
			stack.addB();
			cout << endl;
		}
		else if (toUpper(command) == "REMOVEB") {
			stack.removeB();
			cout << endl;
		}
		else if (toUpper(command) == "ADDA") {
			stack.addA();
			cout << endl;
		}
		else if (toUpper(command) == "REMOVEA") {
			stack.removeA();
			cout << endl;
		}
		else if (toUpper(command) == "SYSTEM") {
			stack.systemInfo();
			cout << endl;
		}
		else if (toUpper(command) == "TIME") {
			stack.time();
			cout << endl;
		}
		else if (toUpper(command) == "EXPORT") {
			stack.exportLibrary();
			cout << endl;
		}
		else if (toUpper(command) == "HELP") {
			stack.showHelp();
			cout << endl;
		}
		else if (toUpper(command) == "EXIT") {
			stack.exit();
		}
		else {
			// if no valid inputs
			cout << "Invalid command." << endl;
			cout << endl;
			// and take another command 
		}
	}

	return 0;
}

string toUpper(string str) {
	string lowercase = "";
	for (int i = 0; i < str.length(); ++i) {
		lowercase += toupper(str[i]);
	}
	return lowercase;
}

#endif
