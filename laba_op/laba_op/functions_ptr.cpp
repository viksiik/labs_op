#pragma once
#include "functions_ptr.h"

using namespace std;

void main_ptr() {
    char* file = new char[100];

    cout << "Now you are in Pointer Mode\n";
    input_record_c();                           //ввести дані

    add_record_c();                             //додати дані

    output_infile_c(file);                      //вивести вміст файлу
    changeText_c(file);                         //змінити текст

    cout << "\nOUTPUT FILE:\n";
    write_to_file_c();                          //записати у файл
}

char* input_record_c() {
    FILE* file;
    char* line;
    line = (char*)malloc(sizeof(char) * 600);                                   //виділити пам'ять

    file = fopen("E:\\visual studio\\laba_op\\x64\\Debug\\infile.txt", "wt");   //відкрити вхідний файл 

    cout << ("\nInput your text (press Enter and then * to stop):\n");

    do {                                                                        //цикл для запису тексту
        fgets(line, sizeof(line), stdin);                                       //до знака "*"

        if (strcmp(line, "*\n") != 0) {                             //якщо рядок не містить "*"
            fprintf(file, "%s", line);                              //записати у вхідний файл
        }
    } while (strcmp(line, "*\n") != 0);

    free(line);         //звільнити пам'ять
    fclose(file);       //закрити вхідний файл
    return line;

}

char* output_infile_c(char* ptr) {
    FILE* file;

    if ((file = fopen("E:\\visual studio\\laba_op\\x64\\Debug\\infile.txt", "rt")) == NULL) {  //відкриття вхідного файла та перевірка відкриття
        cout << "File doesn`t exist" << endl;                                                  //вивід помилки
        fclose(file);                                                                          //закриття вхідного файлу
    }
    else {
        file = fopen("E:\\visual studio\\laba_op\\x64\\Debug\\infile.txt", "rt");            //відкриття вхідного файлу
        cout << "\nINPUT FILE:\n";
        while (fgets(ptr, strlen(ptr) + 1, file)) {                       //вивід вмісту файлу
            cout << ptr;
        }
        fclose(file);                           //закриття файлу
    }

    return ptr;
}

char* changeText_c(char* ptr) {
    int len = strcspn(ptr, "\n\r");               //довжина підрядка у вихідному рядку без символів "\n\r"

    char buffer[400];
    strncpy(buffer, ptr, len);                       //копіювання len з рядка ptr в буфер buffer  
    buffer[len] = '\0';

    char digits[400], otherChars[400];
    int numDigits = 0, numOtherChars = 0;

    for (int i = 0; i < len; i++) {                          //цикл для пошуку цифр та символів у тексті
        if (isdigit(buffer[i])) {                            //перевірка на цифри
            digits[numDigits++] = buffer[i];                 //якщо так - то додати до буферу
        }
        else {
            otherChars[numOtherChars++] = buffer[i];          //додати інші символи до буферу
        }
    }

    digits[numDigits] = '\0';                         // додати символ кінця рядка
    otherChars[numOtherChars] = '\0';                 //додати символ кінця рядка

    strcpy(ptr, digits);                              //копіювання масиву цифр до файла

    for (int i = numOtherChars - 1; i >= 0; i--) {
        strncat(ptr, &otherChars[i], 1);                 //вставка інших символів до файла(у зворотньому порядку)
    }

    return ptr;
}

char* replace_dublicates_c(char* ptr) {
    int len = strlen(ptr);                         //довжина рядка ptr

    char result[100];
    int index = 0;

    for (int i = 0; i < len; i++) {              //цикл для заміни дублікатів
        int count = 1;
        while (i < len - 1 && ptr[i] == ptr[i + 1] && isdigit(ptr[i])) {  //підрахунок повторів одинакових цифр у рядках
            count++;
            i++;
        }
        if (count > 1) {                //якщо більше 1 цифри, обмежити цифру дужками ()
            result[index++] = '(';
            result[index++] = ptr[i];
            result[index++] = ')';
        }
        else {
            result[index++] = ptr[i];       //інакше просто записати цифру
        }
    }

    result[index] = '\0';              //додати символ кінця
    strcpy(ptr, result);               //скопіювати результат у файл
    return ptr;
}

char* add_record_c() {
    FILE* file;
    char* line;
    char choice;
    line = (char*)malloc(sizeof(char) * 600);                  //виділення пам'яті для line

    cout << "\nWould you like to add text? (y/n)      ";
    cin >> choice;                                             //вибір для введення додаткового тексту
    getchar();                                                 //видвлення останнього символу(символу кінця)

    file = fopen("E:\\visual studio\\laba_op\\x64\\Debug\\infile.txt", "a");       //відкриття вхідного файлу
    
    if (choice == 'y' || choice == 'Y') {                  //якщо користувач хоче ввести дод. текст
        
        cout << ("\nInput your text (press Enter and then * to stop):\n\n");

        do {
            fgets(line, sizeof(line), stdin);            //ввід рядка

            if (strcmp(line, "*\n") != 0) {                 //якщо введений рядок не містить "*\n" то записати його у файл
                fprintf(file, "%s", line);
            }
        } while (strcmp(line, "*\n") != 0);                  //поки не введено "*"
    }
    else if (choice == 'n' || choice == 'N') {}             //якщо ні то нічого не робити

    else {                                        //вивести помилку про некоректний ввід
    cout << " Invalid data";
    }
    fclose(file);                                 //закрити вхідний файл
    free(line);                                   //звільний пам'ять line
    return line;
}

void write_to_file_c() {
    FILE* inputFile = fopen("E:\\visual studio\\laba_op\\x64\\Debug\\infile.txt", "r");         //відкриття вхідного файлу
    FILE* outputFile = fopen("E:\\visual studio\\laba_op\\x64\\Debug\\outfile.txt", "w");       //відкриття вихідного файлу

    char line[100];

    while (fgets(line, sizeof(line), inputFile) != NULL) {                    //поки не досягнуто кінця вхідного файлу
        char* changedLine = changeText_c(line);                               //виклик функції для зміни тексту
        char* resultLine = replace_dublicates_c(changedLine);                 //виклик функції для заміни дублікатів
        fprintf(outputFile, "%s\n", resultLine);                              //запис результату у вихідний файл
        cout << resultLine << endl;                                           //вивід результату
    }

    fclose(inputFile);       //закриття вхідного файлу
    fclose(outputFile);      //закриття вихідного файлу
}

