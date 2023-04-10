#include "functions.h"


int main()
{
	string infile = "products.bin";
	string outfile = "expire_products.bin";
	
	input_products(infile);
	addProducts(infile);
	outputFile(infile);
	
	expiration_products(infile, outfile);
	outputFile(outfile);

	cout << "\nProducts manufactured in the last 10 days:\n";
	printRecentProducts(infile);
}