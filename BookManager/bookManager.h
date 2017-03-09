#include <iostream>
#include <vector>
#include "book.h"

#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H
class BookManager {
public:
	BookManager();
	void menu();
private:
	vector<Book> bookList;
	void addBook(string = "", int = 0);
	bool deleteBook(string = "", int = 0);
	bool borrowBook(string = "", int = 0);
	bool returnBook(string = "", int = 0);
	void saveFile();
	void readFile();
	inline int searchBook(string = "");
	void printInformation(int);
	inline int findLocation(string);
};
#endif
