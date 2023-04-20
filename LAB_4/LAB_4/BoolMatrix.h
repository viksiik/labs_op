#pragma once
#include <string>
#include <iostream>

using namespace std;

class BoolMatrix
{
private:
	int n;
	int m;
	int **arr = {};
public:
	int getRows();
	int getCols();

	void setSize(int n);
	BoolMatrix();
	BoolMatrix(int n, int m);
	BoolMatrix(int size);
	BoolMatrix(const BoolMatrix& other);

	BoolMatrix operator|(const BoolMatrix& other);
	BoolMatrix operator~();

	void print();
	void count(int size);
};

int checkNumber();