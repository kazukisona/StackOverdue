#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <set>

using namespace std;

class Book {
public:
	// constructors
	Book() {};// implemented
	Book(unsigned int newId, string newTitle, string newAuthor, string newGenre, unsigned int newPop);
	~Book() {}; // implemented

	// methods
	// mutator
	void setID(unsigned int newId) { ID = newId;} // implemented
	void setTitle(string newTitle) { title = newTitle;} // implemented
	void setAuthor(string newAuthor) { author = newAuthor;} // implemented
	void setGenre(string newGenre) { genre = newGenre;} // implemented
	void incrPopularity() { popularity++;} // implemented
	void setCheckedUser(unsigned int newUser) { checkedUser = newUser; available = false;} // implemented
	void setDueDate(unsigned int newDate) { dueDate = newDate;}

	// accessor 
	int getID() const { return ID;} // implemented
	string getTitle() const { return title;} // implemented
	string getAuthor() const { return author;} // implemented
	string getGenre() const { return genre;} // implemented
	unsigned int getPopularity() const { return popularity;} // implemented
	unsigned int getCheckedUser() const { return checkedUser;} // implemented
	unsigned int getNumRenewed() const { return numRenewed;} // implemented
	unsigned int getDueDate() const { return dueDate;} // implemented
	bool isAvailable() const { return available;} // implemented

	// other
	void display() const;
	void clearChecked() { checkedUser = 0; available = true;} // implemented
	void incrNumRenewed() { numRenewed++;}// implemented
	void clearRenewed() { numRenewed = 0;}// implemented
	void renew() { dueDate += 5; incrNumRenewed();}// implemented

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

	// set for unique user
	// set<int, bool> histories;
};

// insert operator overloading << friend function

#endif