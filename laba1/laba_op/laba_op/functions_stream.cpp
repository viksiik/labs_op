#pragma once
#include "functions_stream.h"

using namespace std;

void main_string() {                                    
    string file;
    cout << "Now you are in Stream Mode" << endl;
    file = input_record();                               //������ ����� ������
    add_text();                                          //������ �����
    output_infile(file);                                 //������� ���� �������� �����
    changeText(file);                                    //������ �����
}


string input_record() {
    string in_file = "E:\\visual studio\\laba_op\\x64\\Debug\\in_file.txt";     //������� ������� ����
    cout << "\nInput your text (press Enter and then * to stop):\n";
    ofstream fout(in_file);                                           
    string temp;
    int count = 0;
    while (temp.find(42) == string::npos) {                        //�������� �� "*" � �����
        getline(cin, temp);                                           //��� �����
        if (count == 0 && temp.find(42) == string::npos)               //���� count = 0 � ���� "*"
            fout << temp;                                             //����� � ���� ��� ����������
        else if (temp.find(42) == string::npos)                           //���� ���� "*"
            fout << endl << temp;                                    //����� � ���� � �����������(endl)
        count++;
    }
    fout.close();                                                       //�������� �������� �����
    return in_file;
}

void output_infile(string& str) {
    ifstream fin("E:\\visual studio\\laba_op\\x64\\Debug\\in_file.txt");    //�������� �������� �����

    if (!fin.is_open()) {                           //���� ���� �� ���� ������, ������� ������� ��������
        cout << "File doesn`t exist" << endl;
        fin.close();                               //������� ����
    }
    else if (fin.is_open()) {                          //���� ���� ���� �������
        cout << "\nINPUT FILE:\n";
        while (getline(fin, str)) {                   //���� �� ��������� ���� �����
            cout << str << endl;                        //������� ���� �������� �����
        }
        fin.close();                                   //������� ������� ����
    }
}


void changeText(string str) {
    ifstream fin("E:\\visual studio\\laba_op\\x64\\Debug\\in_file.txt");              //�������� �������� �����
    ofstream fout("E:\\visual studio\\laba_op\\x64\\Debug\\out_file.txt");            //�������� ��������� �����

    cout << "\nOUTPUT FILE:\n";
    while (getline(fin, str)) {                                        //���� �� ��������� ���� �����
        string digits = "", nonDigits = "";
        for (int i = 0; i < str.length();i++)                       //���� � ����� �� ������� �����
        {
            if (isdigit(str[i])) {                            //���� ������ - �����, ������ �� ����� digits
                digits += str[i];
            }
            else {                                              //���� ������ - �� �����, ������ �� ����� nonDigits
                nonDigits = str[i] + nonDigits;
            }
        }

        string result = digits + nonDigits;                        //�������� ����������
        cout << replace_dublicates(result) << endl;                //���� �������� ��������
        fout << replace_dublicates(result) << endl;                //����� �������� �������� � �������� ����
    }
    fin.close();                   //�������� �������� �����
    fout.close();                  //�������� ��������� �����

}

string replace_dublicates(string str) {
    string output;
    string replacedText;
    int count = 1;
    for (int i = 1; i < str.size(); i++) {                          
        if (str[i] == str[i - 1] && isdigit(str[i])) {              //��������� ������ �����
            count++;
        }
        else {
            if (count > 1) {
                replacedText += "(" + string(1, str[i - 1]) + ")";       //���� ����� ������ ����� - �������� �������
            }
            else {
                replacedText += str[i - 1];                   //������ �������� ��������
            }
            count = 1;
        }
    }
    if (count > 1) {                                                //���� ����� 2 � �����
        replacedText += "(" + string(1, str[str.size() - 1]) + ")";         //������ ����� ������� ���������� ������� �������� ����� � ����� replacedText
    }
    else {
        replacedText += str[str.size() - 1];             //������ ������� ������ �������� �����
    }
    return replacedText;
}

string add_text() {
    string in_file = "E:\\visual studio\\laba_op\\x64\\Debug\\in_file.txt";           //�������� �������� �����
    string line;
    char choice;
    cout << "\nWould you like to add text? (y/n)      ";
    cin >> choice;                                                          //���� �� �������� �����

    ofstream fout(in_file, ios_base::app);         //�������� �������� ����� ��� ��������

    if (choice == 'y' || choice == 'Y') {                    //���� ���

        if (!fout.is_open()) {
            cout << "File doesn`t exist\n" << endl;              //������� ������� ��� ����������� ������� �����
        }
        else if (fout.is_open()) {                                 //���� ��������� �������
            cout << "\nInput your text(press Enter and then * to stop) :\n";

            while (line != "*") {                       //���� line != "*"
                fflush(stdin);                          //�������� �����
                getline(cin, line);                      //��� �����
                if (line != "*") {
                    fout << line << endl;                   //����� � ������� ����
                }
            }
        }
    }
    else if (choice == 'n' || choice == 'N') {    }               //���� �, �� ����� �� ������
    else {
        cout << " Invalid data";                  //���� ��� ������������ �����
    }
    fout.close();                 //�������� �������� �����
    return in_file;
}

