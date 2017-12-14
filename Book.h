/*
Author: Kazuki Sona
Date: 14th, Dec
Class: CSCI23500
Instructor: Simon Ayzman
Prgrram: Book.h
*/

#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <map>

using namespace std;

class Book {
public:
	// constructors
	Book() {};
	Book(unsigned int newId, string newTitle, string newAuthor, string newGenre, unsigned int newPop);
	~Book() {}; 

	// methods
	// mutator
	void setID(unsigned int newId) { ID = newId;} 
	void setTitle(string newTitle) { title = newTitle;} 
	void setAuthor(string newAuthor) { author = newAuthor;} 
	void setGenre(string newGenre) { genre = newGenre;} 
	void setCheckedUser(unsigned int newUser) { checkedUser = newUser; available = false;} 
	void setDueDate(unsigned int newDate) { dueDate = newDate;}
	void setNumRenewed(unsigned int newNumRenew) { numRenewed = newNumRenew;}
	void setOverdue() { overdue = true;}

	// accessor 
	int getID() const { return ID;} 
	string getTitle() const { return title;} 
	string getAuthor() const { return author;} 
	string getGenre() const { return genre;} 
	unsigned int getPopularity() const { return popularity;} 
	unsigned int getCheckedUser() const { return checkedUser;} 
	unsigned int getNumRenewed() const { return numRenewed;} 
	unsigned int getDueDate() const { return dueDate;} 
	bool isAvailable() const { return available;} 
	bool isOverdue() const { return overdue;}

	// other
	void display() const;
	void displayDetail(bool space=false) const;
	void clearChecked() { checkedUser=0; dueDate=0; available=true; overdue=false; numRenewed=0;} 
	void incrNumRenewed() { numRenewed++;}
	void renew() { dueDate += 5; incrNumRenewed();}
	bool alreadyChecked(unsigned int userid); 
	void addHistory(unsigned int userid); // put it into checked out history
	void incrPopularity() { popularity++;} 
	string outputFormat(); // make an output for exporting data

private:
	unsigned int ID;
	string title;
	string author;
	string genre;
	unsigned int popularity;
	unsigned int checkedUser; // ID of a user checked out this book
	unsigned int numRenewed;
	unsigned int dueDate;
	bool available;
	bool overdue;
	map<int, int> history; // history of checked users map<userid, count>
};

#endif