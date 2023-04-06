#pragma once
#pragma warning(disable: 4996)
#pragma warning(disable: 4146)

#include <stdio.h>
#include <iostream>

void main_ptr();                            //головна функція
char* output_infile_c(char* ptr);           //вивід вхідного файлу
char* input_record_c();                     //запис даних у файл
char* changeText_c(char* ptr);              //змінити текст(цифри вперед)
char* replace_dublicates_c(char* ptr);      //замінити дублікати
char* add_record_c();                       //додати запис у файл
void write_to_file_c();                     //записати у файл
