﻿
#include "functions_stream.h"
#include "functions_ptr.h"

/* ЗАВДАННЯ:
    створити текстовий файл.
    Слова у тексті відділені пробілами, комами, крапками.
    Перетворити рядки тексту так, щоб спочатку в них йшли усі цифри, які містяться у рядку
    (у порядку їхнього слідування), а потім інші символи (у порядку,
    зворотньому порядку їхнього слідування).

    Усі замінені рядки вхідного файлу переписати у новий текстовий файл.
    У кожному рядку нового файлу видалити цифри-дублікати, обмеживши круглими дужками цифру, що повторюється.
    Наприклад, послідовність 35527444432 повинна бути замінена на послідовність 3(5)27(4)32.
    Вивести вміст вхідного і вихідного файлів*/

int main(int argc, char* argv[])
{
    if (argc >= 3 && (strcmp(argv[2], "FileStream") == 0)) {            //Якщо argc більше або дорівнює 3 І третій аргумент командного рядка є FileStream
        main_string();                                                  //виклик основної функції з бібліотеки "functions_stream.h"
    }
    else if (argc >= 3 && (strcmp(argv[2], "FilePointer") == 0)) {      //Якщо argc більше або дорівнює 3 І третій аргумент командного рядка є FilePointer
        main_ptr();                                                     //виклик основної функції з бібліотеки "functions_ptr.h"
    }
    else {
        cout << "Invalid data\n";                                       //помилка про некоректність вводу
    }
    system("pause");                                                    //системна "пауза", жде натискання клавіші
    return 0;
}

