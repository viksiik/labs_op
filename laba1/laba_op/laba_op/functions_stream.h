#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void main_string();                       //головна функція
void output_infile(string& str);          //вивід вхідного файлу
string input_record();                    //запис даних у файл
void changeText(string file);             //змінити текст(цифри вперед)
string replace_dublicates(string str);    //замінити дублікати
string add_text();                        //додати текст у файл
