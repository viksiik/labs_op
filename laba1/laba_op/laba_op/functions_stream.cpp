#pragma once
#include "functions_stream.h"

using namespace std;

void main_string() {                                    
    string file;
    cout << "Now you are in Stream Mode" << endl;
    file = input_record();                               //ввести рядки тексту
    add_text();                                          //додати текст
    output_infile(file);                                 //вивести вміст вхідного файлу
    changeText(file);                                    //змінити текст
}


string input_record() {
    string in_file = "E:\\visual studio\\laba_op\\x64\\Debug\\in_file.txt";     //відкрити вхідний файл
    cout << "\nInput your text (press Enter and then * to stop):\n";
    ofstream fout(in_file);                                           
    string temp;
    int count = 0;
    while (temp.find(42) == string::npos) {                        //перевірка на "*" у рядку
        getline(cin, temp);                                           //ввід рядка
        if (count == 0 && temp.find(42) == string::npos)               //якщо count = 0 і немає "*"
            fout << temp;                                             //запис у файл без роздільника
        else if (temp.find(42) == string::npos)                           //якщо немає "*"
            fout << endl << temp;                                    //запис у файл з роздільником(endl)
        count++;
    }
    fout.close();                                                       //закриття вхідного файлу
    return in_file;
}

void output_infile(string& str) {
    ifstream fin("E:\\visual studio\\laba_op\\x64\\Debug\\in_file.txt");    //відкриття вхідного файлу

    if (!fin.is_open()) {                           //якщо файл не було вікрито, вивести помилку відкриття
        cout << "File doesn`t exist" << endl;
        fin.close();                               //закрити файл
    }
    else if (fin.is_open()) {                          //якщо файл було відкрито
        cout << "\nINPUT FILE:\n";
        while (getline(fin, str)) {                   //доки не досягнуто кінця файлу
            cout << str << endl;                        //вивести вміст вхідного файлу
        }
        fin.close();                                   //закрити вхідний файл
    }
}


void changeText(string str) {
    ifstream fin("E:\\visual studio\\laba_op\\x64\\Debug\\in_file.txt");              //відкриття вхідного файлу
    ofstream fout("E:\\visual studio\\laba_op\\x64\\Debug\\out_file.txt");            //відкриття вихідного файлу

    cout << "\nOUTPUT FILE:\n";
    while (getline(fin, str)) {                                        //доки не досягнуто кінця файлу
        string digits = "", nonDigits = "";
        for (int i = 0; i < str.length();i++)                       //поки і менше за довжину рядка
        {
            if (isdigit(str[i])) {                            //якщо символ - число, додати до рядка digits
                digits += str[i];
            }
            else {                                              //якщо символ - не число, додати до рядка nonDigits
                nonDigits = str[i] + nonDigits;
            }
        }

        string result = digits + nonDigits;                        //поєднання результату
        cout << replace_dublicates(result) << endl;                //вивід замінених дублікатів
        fout << replace_dublicates(result) << endl;                //запис замінених дублікатів у вихідний файл
    }
    fin.close();                   //закриття вхідного файлу
    fout.close();                  //закриття вихідного файлу

}

string replace_dublicates(string str) {
    string output;
    string replacedText;
    int count = 1;
    for (int i = 1; i < str.size(); i++) {                          
        if (str[i] == str[i - 1] && isdigit(str[i])) {              //порівняння сусідніх чисел
            count++;
        }
        else {
            if (count > 1) {
                replacedText += "(" + string(1, str[i - 1]) + ")";       //якщо більше одного числа - обмежити дужками
            }
            else {
                replacedText += str[i - 1];                   //додати попереднє значення
            }
            count = 1;
        }
    }
    if (count > 1) {                                                //якщо чисел 2 і більше
        replacedText += "(" + string(1, str[str.size() - 1]) + ")";         //додати дужки навколо останнього символу вхідного рядка в рядок replacedText
    }
    else {
        replacedText += str[str.size() - 1];             //додати останній символ вхідного рядка
    }
    return replacedText;
}

string add_text() {
    string in_file = "E:\\visual studio\\laba_op\\x64\\Debug\\in_file.txt";           //відкриття вхідного файлу
    string line;
    char choice;
    cout << "\nWould you like to add text? (y/n)      ";
    cin >> choice;                                                          //вибір чи додавати текст

    ofstream fout(in_file, ios_base::app);         //відкриття вхідного файлу для дозапису

    if (choice == 'y' || choice == 'Y') {                    //якщо так

        if (!fout.is_open()) {
            cout << "File doesn`t exist\n" << endl;              //вивести помилку про неможливість вікриття файлу
        }
        else if (fout.is_open()) {                                 //якщо правильно відкрито
            cout << "\nInput your text(press Enter and then * to stop) :\n";

            while (line != "*") {                       //поки line != "*"
                fflush(stdin);                          //очистити буфер
                getline(cin, line);                      //ввід рядків
                if (line != "*") {
                    fout << line << endl;                   //запис у вхідний файл
                }
            }
        }
    }
    else if (choice == 'n' || choice == 'N') {    }               //якщо ні, то нічого не робити
    else {
        cout << " Invalid data";                  //вивід про некоректність вводу
    }
    fout.close();                 //закриття вхідного файлу
    return in_file;
}

