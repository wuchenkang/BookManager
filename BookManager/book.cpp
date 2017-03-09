#include "book.h"

Book::Book(string name, int amount) {
	setName(name);
	setAmount(amount);
	setAvailable(amount);
}

Book::Book(string name, int amount, int available) {
	setName(name);
	setAmount(amount);
	setAvailable(available);
}

void Book::setName(string _name) {
	name = _name;
}

string Book::getName() {
	return name;
}

void Book::setAmount(int _amount) {
	amount = _amount;
}

int Book::getAmount() {
	return amount;
}

void Book::setAvailable(int _available) {
	available = _available;
}

int Book::getAvailable() {
	return available;
}
