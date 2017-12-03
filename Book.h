#ifndef BOOK_H
#define BOOK_H
#include <iostream>

using namespace std;

class Book {
public:
	// constructors
	Book();
	Book(int newId, string newTitle, string newAuthor, string newGenre);
	~Book() {}; // implemented

	// methods
	// mutator
	void setID(unsigned int newId) { ID = newId;} // implemented
	void setTitle(string newTitle) { title = newTitle;} // implemented
	void setAuthor(string newAuthor) { author = newAuthor;} // implemented
	void setGenre(string newGenre) { genre = newGenre;} // implemented
	void incrPopularity() { popularity++;} // implemented
	void setCheckedUser(unsigned int newUser) { checkedUser = newUser;} // implemented

	// accessor 
	int getID() { return ID;} // implemented
	string getTitle() { return title;} // implemented
	string getAuthor() { return author;} // implemented
	string getGenre() { return genre;} // implemented
	int getPopularity() { return popularity;} // implemented
	int getCheckedUser() { return checkedUser;} // implemented

	// other
	void displayContents();
	void clearChecked() { checkedUser = 0; } // implemented
	
private:
	unsigned int ID;
	string title;
	string author;
	string genre;
	unsigned int popularity;
	unsigned int checkedUser; // ID of a user checked out this book
};

// insert operator overloading << friend function

#endif