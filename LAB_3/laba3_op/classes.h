#include <string>
#include <iostream>
#include <iomanip>

#pragma once

using namespace std;

class Book {
private:
	string name;
	string author;
	int year;
	int pages;
public:

	Book();
	Book(string author, string name, int year, int pages);
	void print();
	int getYear();
	int getPages();
	string getName();
	string getAuthor();
	void setYear();
	void setPages();
	void setName();
	void setAuthor();
	void findBook(Book* arr, int size, int low, int upper);
	void operator=(const Book& other);
};

void sms();

