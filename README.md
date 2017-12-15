## Assignment 3 - StackOverdue

### Purpose
This probram allows librarian who needs to manage tons of books and user accounts in the system to process
ton of informations in a library.

### Compilation/Execution

To compile this program, use makefile provided:

	make

To execute this program.

	./StackOverdue <book file name> <account file name>

Both book and account data is available under 'data/' folder.

	./StackOverdue data/library.small/book.data data/library.small/account.data

### Design Description
#### Book:
`Book` class represents a data object which contains information about a book such as title, author, genre, popularity score. This class can holds history of a unique user who checked out this book instance in the past. Each book has an unique `ID`.
#### User:
`User` class represents a data object which contains information about a user such as name, checked out books. Each user has an unique `ID`. This class  maintains a history of what book this user checked out. The history will be used for recommendation.
#### BookWarehouse
`BookWarehouse` class is a representation of a collection of `Book` instances. Precisely it holds pointers of `Book` class, `Book*`. This class is for storing and making a book shelf for fast book retrieving and providing information of books. 
#### Accounts
`Accounts` class is a representation of a collection of `User` instances. This class has and keeps track of each user who is using this library system. This interface provides a way to manage accounts and provide collective information about them.
#### Library
`Library` class represents a main system and an interface with which `BookWarehouse` and `Accounts` instances are interacting to provide Library service such as browsing books and accounts, searching books, checkout, and return. 
#### StackOverdue
`StackOverduev` class is the top layer of the system which provides to deal with user command inputs or search term. It also manages system information like System time. 
