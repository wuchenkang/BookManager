#include "bookManager.h"

void BookManager::addBook(string name, int amount) {
	int index = searchBook(name);
	if (index != -1) {
		bookList[index].setAvailable(bookList[index].getAvailable() + amount);
		bookList[index].setAmount(bookList[index].getAmount() + amount);
	}
	else {
		Book temp(name, amount);
		index = findLocation(name);
		bookList.insert(bookList.begin() + index, temp);
	}
}

bool BookManager::deleteBook(string name, int amount) {
	int index = searchBook(name);
	if (index == -1) {
		cout << "***Book not found!                      ***" << endl;
		return false;
	}
	if (amount < bookList[index].getAvailable()) {
		bookList[index].setAvailable(bookList[index].getAvailable() - amount);
		bookList[index].setAmount(bookList[index].getAmount() - amount);
		return true;
	}
	else if (amount = bookList[index].getAvailable()) {
		bookList.erase(bookList.begin() + index);
		return true;
	}
	else {
		cout << "***No enough books to deleted!       ***" << endl;
		return false;
	}
}

bool BookManager::borrowBook(string name, int amount) {
	int index = searchBook(name);
	if (index == -1) {
		cout << "***Book not found!                   ***" << endl;
		return false;
	}
	else {
		if (amount <= bookList[index].getAvailable()) {
			bookList[index].setAvailable(bookList[index].getAvailable() - amount);
			return true;
		}
		else {
			cout << "***No enough books to borrow!        ***" << endl;
			return false;
		}
	}
}

bool BookManager::returnBook(string name, int amount) {
	int index = searchBook(name);
	if (index == -1) {
		return false;
	}
	else {
		bookList[index].setAvailable(bookList[index].getAvailable() + amount);
	}
	return true;
}

int BookManager::searchBook(string name) {
	if (name == "") {
		cout << "Attention please! \"" << name << "\" is not a valid book name" << endl;
		return -1;
	}
	if (bookList.size() == 0) {
		return -1;
	}
	int a = 0, b = bookList.size() - 1;
	int c;
	while (a != b) {
		c = (a + b) / 2;
		if (bookList[c].getName() == name) {
			return c;
		}
		else if (bookList[c].getName() < name) {
			if (c == b) {
				return -1;
			}
			else {
				a = c + 1;
			}
		}
		else {
			if (c == a) {
				return -1;
			}
			else {
				b = c - 1;
			}
		}
	}
	if (bookList[a].getName() == name) {
		return a;
	}
	return -1;

}

void BookManager::menu() {

	cout << "****************************************" << endl;
	cout << "*          Book Manage System          *" << endl;
	cout << "* 1)Add a book         2)Delete a book *" << endl;
	cout << "* 3)Borrow a book      4)Return a book *" << endl;
	cout << "* 5)Search information 6)Exit          *" << endl;
	cout << "****************************************" << endl;

	char option;
	cin >> option;
	while (option < '1' || option > '6') {
		cout << "***Please enter a vaild number(0-6)! ***" << endl;
		while (getchar() != '\n');
		cin >> option;
	}

	string name;
	int amount;
	bool ok;
	int index;
	while (option != 6) {
		while (getchar() != '\n');
		amount = -1;
		switch (option) {
		case '1':
			cout << "***Please enter the name of the book ***" << endl;
			cout << "***and the amount of the book        ***" << endl;
			cout << "***in a new line                     ***" << endl;
			getline(cin, name);
			cin >> amount;
			while (cin.fail()) {
				cout << "***Please enter a integer number!    ***" << endl;
				cin.clear();
				cin.sync();
				while (getchar() != '\n');
				cin >> amount;
			}
			addBook(name, amount);
			cout << "***Add successfully!!!               ***" << endl;
			break;
		case '2':
			cout << "***Please enter the name of the book ***" << endl;
			cout << "***and the amount of the book        ***" << endl;
			getline(cin, name);
			cin >> amount;
			while (cin.fail()) {
				cout << "***Please enter a integer number!    ***" << endl;
				cin.clear();
				cin.sync();
				while (getchar() != '\n');
				cin >> amount;
			}
			ok = deleteBook(name, amount);
			if (ok) {
				cout << "***Delete successfully!!!            ***" << endl;
			}
			else {
				cout << "***Fail to delete the book!!!        ***" << endl;
			}
			break;
		case '3':
			cout << "***Please enter the name of the book ***" << endl;
			cout << "***and the amount of the book        ***" << endl;
			getline(cin, name);
			cin >> amount;
			while (cin.fail()) {
				cout << "***Please enter a integer number!    ***" << endl;
				cin.clear();
				cin.sync();
				while (getchar() != '\n');
				cin >> amount;
			}
			ok = borrowBook(name, amount);
			if (ok) {
				cout << "***Borrow successfully!!!            ***" << endl;
			}
			else {
				cout << "***Fail to borrow the book!!!        ***" << endl;
			}
			break;
		case '4':
			cout << "***Please enter the name of the book ***" << endl;
			cout << "***and the amount of the book        ***" << endl;
			getline(cin, name);
			cin >> amount;
			while (cin.fail()) {
				cout << "***Please enter a integer number!    ***" << endl;
				cin.clear();
				cin.sync();
				while (getchar() != '\n');
				cin >> amount;
			}
			ok = returnBook(name, amount);
			if (ok) {
				cout << "***Return successfully!!!            ***" << endl;
			}
			else {
				cout << "***Book not found!                   ***" << endl;
			}
			break;
		case '5':
			cout << "***Please enter the name of the book ***" << endl;
			getline(cin, name);
			index = searchBook(name);
			if (index == -1) {
				cout << "***Book not found!!!                 ***" << endl;
			}
			else {
				printInformation(index);
			}
			break;
		case '6':
			cout << endl << "Thank you for using our book manage system!" << endl;
			exit(0);
			break;
		default:
			break;
		}
		cout << "***Please choose what to do next     ***" << endl << endl;
		cout << "****************************************" << endl;
		cout << "*          Book Manage System          *" << endl;
		cout << "* 1)Add a book         2)Delete a book *" << endl;
		cout << "* 3)Borrow a book      4)Return a book *" << endl;
		cout << "* 5)Search information 6)Exit          *" << endl;
		cout << "****************************************" << endl;

		cin >> option;
		while (option < '1' || option > '6') {
			cout << "***Please enter a vaild number(0-6)! ***" << endl;
			while (getchar() != '\n');
			cin >> option;
		}
	}
}

void BookManager::printInformation(int bookIndex) {
	cout << "****************************************" << endl;
	cout << "Name:         " << bookList[bookIndex].getName() << endl;
	cout << "Amount:       " << bookList[bookIndex].getAmount() << endl;
	cout << "Now avaliable:" << bookList[bookIndex].getAvailable() << endl;
	cout << "****************************************" << endl;
}

inline int BookManager::findLocation(string name) {
	int index;
	if (bookList.size() == 0) {
		return 0;
	}
	else {
		int a = 0, b = bookList.size() - 1;
		index = (a + b) / 2;
		while (index != bookList.size() - 1 && !(name > bookList[index].getName() && name < bookList[index + 1].getName())) {
			if (name < bookList[index].getName()) {
				if (index == 0) {
					return 0;
				}
				else {
					b = index - 1;
				}
			}
			else {
				a = index + 1;
			}
			index = (a + b) / 2;
		}
	}

	return index + 1;
}