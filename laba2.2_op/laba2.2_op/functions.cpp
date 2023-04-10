#include "functions.h"

struct Product {
	string name;
	string manufactureDate;
	string expirationDate;
	double price = 0;
};

void input_products(string filename) {
    ofstream fout(filename, ios::binary);

    if (!fout.is_open()) {
        cout << "Error openning the file";
    }
    else {
        Product input;
        cout << "Enter product name:\t\t\t";
        getline(cin, input.name);
        cout << "Enter date of manufacture (dd.mm.yyyy): ";
        getline(cin, input.manufactureDate);
        cout << "Enter expiry date (dd.mm.yyyy):\t\t ";
        getline(cin, input.expirationDate);
        cout << "Enter price: \t\t\t\t";
        cin >> input.price;

        fout << input.name << " ";
        fout << input.manufactureDate << " ";
        fout << input.expirationDate << " " << input.price << " " << endl;
    }
    fout.close();

}

void outputFile(string filename) {
	ifstream fin(filename, ios::binary);
	string line;
    if (!fin.is_open()) {
        cout << "Error openning the file";
    }
    else {
        cout << "\nPRODUCTS:" << endl;
        cout << "-----------------------------------------\n";
        while (getline(fin, line)) {
            cout << line << endl;
        }
        cout << "-----------------------------------------\n";
    }
	fin.close();
}

void expiration_products(string filename, string outfile) {
    time_t now = time(nullptr);
    tm tenDaysAgo = *localtime(&now);
    tenDaysAgo.tm_mday -= 10;
    time_t tenDaysAgoTime = mktime(&tenDaysAgo);

    ifstream inFile(filename, ios::binary);
    if (!inFile.is_open()) {
        cout << "Error openning the file";
    }
    else {
        string line;
        ofstream outFile(outfile, ios::binary); // створення файлу
        if (!outFile.is_open()) {
            cout << "Error openning the file";
        }
        else {
            while (getline(inFile, line)) {
                size_t pos;
                string field;
                int fieldIndex = 0;

                Product product;
                while ((pos = line.find(" ")) != string::npos) {
                    field = line.substr(0, pos);

                    switch (fieldIndex) {
                    case 0:
                        product.name = field;
                        break;
                    case 1:
                        product.manufactureDate = field;
                        break;
                    case 2:
                        product.expirationDate = field;
                        break;
                    case 3:
                        product.price = stoi(field);
                        break;
                    }

                    line.erase(0, pos + 1);
                    fieldIndex++;
                }

                int year, month, day;
                sscanf(product.expirationDate.c_str(), "%d.%d.%d", &day, &month, &year);
                tm expirationDate = { 0, 0, 0, day, month - 1, year - 1900 };
                time_t expirationTime = mktime(&expirationDate);

                if (expirationTime < now) { // перевірка чи товари вже прострочені
                    continue;
                }

                double timeLeftPercent = difftime(expirationTime, now) * 100.0 / difftime(expirationTime, tenDaysAgoTime);

                if (timeLeftPercent < 10.0) {
                    outFile << product.name << " " << product.manufactureDate << " " << product.expirationDate << " " << product.price << " " << endl;
                }
            }
            outFile.close();
        }
    }
    inFile.close();
    // закриття файлу
}

void printRecentProducts(string filename) {
    time_t now = time(nullptr);
    tm tenDaysAgo = *localtime(&now);
    tenDaysAgo.tm_mday -= 10;
    time_t tenDaysAgoTime = mktime(&tenDaysAgo);

    ifstream inFile(filename, ios::binary);
    if (!inFile.is_open()) {
        cout << "Error openning the file";
    }
    else {
        string line;
        while (getline(inFile, line)) {
            size_t pos;
            string field;
            int fieldIndex = 0;

            Product product;
            while ((pos = line.find(" ")) != string::npos) {
                field = line.substr(0, pos);

                switch (fieldIndex) {
                case 0:
                    product.name = field;
                    break;
                case 1:
                    product.manufactureDate = field;
                    break;
                case 2:
                    product.expirationDate = field;
                    break;
                case 3:
                    product.price = stoi(field);
                    break;
                }

                line.erase(0, pos + 1);
                fieldIndex++;
            }


            int year, month, day;
            sscanf(product.manufactureDate.c_str(), "%d.%d.%d", &day, &month, &year);
            tm manufactureDate = { 0, 0, 0, day, month - 1, year - 1900 };
            time_t manufactureTime = mktime(&manufactureDate);

            if (manufactureTime >= tenDaysAgoTime) {
                cout << product.name << " " << product.manufactureDate << " ";
                cout << product.expirationDate << " " << product.price << " " << endl;
            }
        }
    }
    inFile.close();
}

void addProducts(string filename) {
    ofstream fout(filename, ios::binary | ios::app);
    int choice = 1;
    if (!fout.is_open()) {
        cout << "Error openning the file";
    }
    else {
        Product input;
        do {
            cout << "\nPress 1 if you want to add product, 0 - to stop:   ";
            cin >> choice;

            if (choice == 1) {
                getchar();
                cout << "Enter product name:\t\t\t";
                getline(cin, input.name);
                cout << "Enter date of manufacture (dd.mm.yyyy): ";
                getline(cin, input.manufactureDate);
                cout << "Enter expiry date (dd.mm.yyyy):\t\t ";
                getline(cin, input.expirationDate);
                cout << "Enter price: \t\t\t\t";
                cin >> input.price;

                fout << input.name << " ";
                fout << input.manufactureDate << " ";
                fout << input.expirationDate << " " << input.price << " " << endl;
            }

        } while (choice == 1);
    }
    fout.close();
}