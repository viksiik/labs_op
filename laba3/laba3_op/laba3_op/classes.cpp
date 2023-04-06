#include "classes.h"
//#pragma warning(disable:6385)

Book::Book() {
	year = pages = 0;
	name = author = "";
}

Book::Book(string author, string name, int year, int pages) {
	this->year = year;
	this->pages = pages;
	this->name = name;
	this->author = author;
};

void Book::print() {
	cout << setw(8) << author << setw(16) << name;
	cout << setw(12) << year << setw(11) << pages << endl;
};

int Book::getYear() {
	return year;
};

int Book::getPages() {
	return pages;
};

string Book::getName() {
	return name;
};

string Book::getAuthor() {
	return author;
};

void Book::setYear() {
	int year;
	cin >> year;
	this->year = year;
};

void Book::setPages() {
	int pages;
	cin >> pages;
	this->pages = pages;
};

void Book::setName() {
	string name;
	getline(cin, name);
	this->name = name;
};

void Book::setAuthor() {
	string author;
	getline(cin, author);
	this->author = author;
};

void Book::findBook(Book *arr, int size, int low, int upper) {
	Book* temp = new Book[size];
	Book *max = nullptr;
	int pages = 0;
	sms();

	for (int i = 0; i < size; i++) {
		if (arr[i].year >= low && arr[i].year <= upper) {
			temp[i] = arr[i];
			temp[i].print();
			if (temp[i].pages > pages) {
				max = &temp[i];
				pages = temp[i].pages;
			}
		}
	}

	cout << "\n\n----THE THICKEST BOOK----" << endl;
	sms();
	cout << setw(8) << max->author << setw(16) << max->name;
	cout << setw(12) << max->year << setw(11) << max->pages << endl;
};

void Book::operator=(const Book& other) {
	this->author = other.author;
	this->name = other.name;
	this->pages = other.pages;
	this->year = other.year;

};

void sms() {
	cout << endl << "   AUTHOR" << setw(13) << "NAME";
	cout << setw(14) << "YEAR" << setw(12) << "PAGES" << endl;
	cout << "---------------------------------------------------\n";
}

