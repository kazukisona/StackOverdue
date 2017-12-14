/*
Author: Kazuki Sona
Date: 14th, Dec
Class: CSCI23500
Instructor: Simon Ayzman
Prgrram: User.h
*/

#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <map>
#include "Book.h"

using namespace std;

class User {
public:
	
	// constructors
	User() {}
	User(unsigned int newId, string newName) { ID = newId; name = newName; numCheckout=0; overdue=false;}
	User(unsigned int newId, string newName, unsigned int newNumChecked);
	~User() {}

	// methods
	// mutator
	void setID(unsigned int newId) { ID = newId;} 
	void setName(string newName) { name = newName;} 
	void setOverdue(bool newValue) { overdue = newValue;} 

	// accessor
	unsigned int getID() { return ID;} 
	string getName() { return name;} 
	unsigned int getNumOverdue();
	unsigned int getNumCheckout() { return numCheckout;} 

	// other
	bool rentBook(Book& book);
	bool returnBook(unsigned int bookId);
	// return all of checked out books 
	void returnAll();
	bool isOverdue() { return overdue;} 
	void renewBook();
	void display();
	void displayDetail();
	// display all of checked out books
	void displayBooks();
	// Returns true if a book with bookid is already checked out by this user
	bool alreadyRead(unsigned int bookid);
	string getFirstGenre() { return firstG;}
	string getSecondGenre() { return secondG;}
	string getFavAuthor() { return favAuthor;}
	// Calculate and set most and seconod most read Genre
	void setFavGenre();
	// Calculate and set most read Author
	void setFavAuthor();
	unsigned int getNumHistory() { return history.size();}
	string outputFormat(); // make an output for exporting data

private:
	unsigned int ID;
	string name;
	vector<Book*> checkedOuts;
	unsigned int numCheckout;
	unsigned int numOverdue;
	bool overdue;
	map<int, Book*> history; // what book this user checked out in the past
	string favAuthor; // most read author
	string firstG; // most read genre
	string secondG; // second most read genre
};

#endif