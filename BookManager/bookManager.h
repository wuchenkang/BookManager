#include <iostream>
#include <vector>
#include "book.h"

#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H
class BookManager {
public:
	void addBook(string = "", int = 0);
	bool deleteBook(string = "", int = 0);
	bool borrowBook(string = "", int = 0);
	bool returnBook(string = "", int = 0);
	inline int searchBook(string = "");
	inline void menu();
private:
	vector<Book> bookList;
	void printInformation(int);
	inline int findLocation(string);
};
#endif
