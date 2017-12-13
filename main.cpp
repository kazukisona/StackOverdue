#include <iostream>
#include "StackOverdue.cpp"
#include "Library.cpp"
#include "BookWarehouse.cpp"
#include "Accounts.cpp"
#include "Book.cpp"
#include "User.cpp"

using namespace std;

int main(int argc, char const *argv[]) {
	
	ifstream inputB, inputA;
	inputB.open("data/library.small/books.data");
	inputA.open("data/library.small/accounts.data");

	StackOverdue stack = StackOverdue(inputB, inputA);

	string command;

	// command processing
	while (stack.getSystemStatus()) {

		cout << "> ";
		cin >> command;

		if (command == "BROWSE") {
			stack.browse();
			cout << endl;
		} 
		else if (command == "BOOK") {
			stack.book();
			cout << endl;
		}
		else if (command == "SEARCH") {
			stack.searchBook();
			cout << endl;
		}
		else if (command == "ACCOUNTS") {
			stack.accounts();
			cout << endl;
		}
		else if (command == "ACCOUNT") {
			stack.account();
			cout << endl;
		} 
		else if (command == "CHECKOUT") {
			stack.checkout();
			cout << endl;
		}
		else if (command == "RENEW") {
			stack.renewBook();
			cout << endl;
		}
		else if (command == "RETURN") {
			//stack.returnBook();

		}
		else if (command == "RECOMMEND") {
			
		}
		else if (command == "ADDB") {
			stack.addB();
			cout << endl;
		}
		else if (command == "REMOVEB") {
			stack.removeB();
			cout << endl;
		}
		else if (command == "ADDA") {
			stack.addA();
			cout << endl;
		}
		else if (command == "REMOVEA") {
			stack.removeA();
			cout << endl;
		}
		else if (command == "SYSTEM") {
			stack.systemInfo();
			cout << endl;
		}
		else if (command == "TIME") {
			stack.time();
			cout << endl;
		}
		else if (command == "EXPORT") {
			
		}
		else if (command == "HELP") {
			stack.showHelp();
			cout << endl;
		}
		else if (command == "EXIT") {
			stack.exit();
		}
		else {
			// if no valid inputs, do nothing
			// and take another command 
		}
	}

	return 0;
}
