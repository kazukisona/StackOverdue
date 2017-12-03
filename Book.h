#ifndef BOOK_H
#define BOOK_H
#include <iostream>

using namespace std;

class Book {
public:
	// constructors
	Book();
	Book(int newId, string newTitle, string newAuthor, string newGenre);
	~Book() {};

	// methods
	// mutator
	void setID(unsigned int newId) { ID = newId;};
	void setTitle(string newTitle) { title = newTitle;};
	void setAuthor(string newAuthor) { author = newAuthor;};
	void setGenre(string newGenre) { genre = newGenre;};
	void incrPopularity() { popularity++;};
	void setCheckedUser(unsigned int newUser) { checkedUser = newUser;};

	// accessor 
	int getID() { return ID;};
	string getTitle() { return title;};
	string getAuthor() { return author;};
	string getGenre() { return genre;};
	int getPopularity() { return popularity;};
	int getCheckedUser() { return checkedUser;};

	// other
	void displayContents();
	void clearChecked() { checkedUser = 0; };
	
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