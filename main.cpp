#include <iostream>
#include "StackOverdue.h"

using namespace std;

int main(int argc, char const *argv[]) {
	
	StackOverdue stack = StackOverdue();

	string command;

	while (stack.getSystemStatus()) {

		cout << "> ";
		cin >> command;

		// error handling for command

		if (command == "BROWSE") {
			stack.browse();
		}
	}

	return 0;
}
