#include <string>
#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book {
public:
	Book(string, int);
	Book(string, int, int);
	void setName(string);
	string getName();
	void setAmount(int);
	int getAmount();
	void setAvailable(int);
	int getAvailable();
private:
	string name;
	int amount;
	int available;
};
#endif
