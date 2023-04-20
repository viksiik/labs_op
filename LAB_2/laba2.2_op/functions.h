#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

void input_products(string filename);
void outputFile(string filename);
void expiration_products(string filename, string outfile);
void printRecentProducts(string filename);
void addProducts(string filename);
