/*
Author: Kazuki Sona
Date: 14th, Dec
Class: CSCI23500
Instructor: Simon Ayzman
Prgrram: Library.h
*/

#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <fstream>
#include "BookWarehouse.h"
#include "Accounts.h"

using namespace std;

class Library {
public:
	// constructors
	Library() {} 
	Library(ifstream& bFile, ifstream& aFile) {importBooks(bFile); importAccounts(aFile); currentTime=1;}
	~Library() {} 

	// method
	// accessor
	unsigned int getNumBooks() { return warehouse.getNumBooks();}; 
	unsigned int getNumUsers() { return accounts.getNumUsers();}; 

	// command related
	void browseAllBooks() { warehouse.displayAll();}  // display all contents in warehouse
	void browseAllAccounts() { accounts.displayAll();}  // display all contents in accounts
	// browse books in warehouse by a given order
	void browseBooks(string criteria) { warehouse.sortBooks(criteria);} 
	// browse accounts in accounts by a given order 
	void browseAccounts(string criteria) { accounts.sortAccounts(criteria);}  
	// search and display books criteria(title, author) with phrase
	void searchBooks(string criteria, string phrase) {warehouse.searchBooks(criteria, phrase);} 
	// find a specific book with an id and display the content of it
	void findBook(unsigned int bookId) {Book* b=warehouse.getBook(bookId); b->displayDetail(false);} 
	// find a specific account with an id and display the content of it
	void findAccount(unsigned int userId) {User* u=accounts.getUser(userId); u->displayDetail();}
	// checkout  
	void checkOut(unsigned int userId, unsigned int bookId); 
	// renew
	void renewBook(unsigned int userId); 
	// retern
	bool returnBook(unsigned int bookId);
	// add book instance to warehouse
	bool addBook(Book& book) { return warehouse.addBook(book);} 
	// create Book instance with given parameters and put it into the warehouse
	bool addBook(string newTitle, string newAuthor, string newGenre, unsigned int newPop=0); 
	// remove book from warehouse
	bool removeBook(unsigned int bookId); 
	// created an instance and add an account with newName
	bool addAccount(string newName); 
	// remove an account with userId
	bool removeAccount(unsigned int userId) { return accounts.delUser(userId);} 
	// make a recommendation to an account with userid
	void recommendation(unsigned int userid);
	
	// utilitie
	unsigned int getOverdueBooks() { return warehouse.getOverdueBooks();} 
	unsigned int getOverdueUsers() { return accounts.getOverdueUsers();} 
	void updateSystem(unsigned int timeAdded);
	bool checkDuplicates(string title, string author) { return warehouse.checkDuplicates(title, author);}
	bool isThereSomething(string target, unsigned int id);
	void exportBook(ofstream& output) { warehouse.exportBook(output);}
	void exportAccount(ofstream& output) { accounts.exportAccounts(output);}

private:
	BookWarehouse warehouse;
	Accounts accounts;
	unsigned int currentTime;

	// use it only in this class
	// import Books and Accoutns from the input files
	void importBooks(ifstream& newBooks); 
	void importAccounts(ifstream& newAccounts); 
};

#endif
