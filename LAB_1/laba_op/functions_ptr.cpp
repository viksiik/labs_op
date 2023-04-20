#pragma once
#include "functions_ptr.h"

using namespace std;

void main_ptr() {
    char* file = new char[100];

    cout << "Now you are in Pointer Mode\n";
    input_record_c();                           //������ ���

    add_record_c();                             //������ ���

    output_infile_c(file);                      //������� ���� �����
    changeText_c(file);                         //������ �����

    cout << "\nOUTPUT FILE:\n";
    write_to_file_c();                          //�������� � ����
}

char* input_record_c() {
    FILE* file;
    char* line;
    line = (char*)malloc(sizeof(char) * 600);                                   //������� ���'���

    file = fopen("E:\\visual studio\\laba_op\\x64\\Debug\\infile.txt", "wt");   //������� ������� ���� 

    cout << ("\nInput your text (press Enter and then * to stop):\n");

    do {                                                                        //���� ��� ������ ������
        fgets(line, sizeof(line), stdin);                                       //�� ����� "*"

        if (strcmp(line, "*\n") != 0) {                             //���� ����� �� ������ "*"
            fprintf(file, "%s", line);                              //�������� � ������� ����
        }
    } while (strcmp(line, "*\n") != 0);

    free(line);         //�������� ���'���
    fclose(file);       //������� ������� ����
    return line;

}

char* output_infile_c(char* ptr) {
    FILE* file;

    if ((file = fopen("E:\\visual studio\\laba_op\\x64\\Debug\\infile.txt", "rt")) == NULL) {  //�������� �������� ����� �� �������� ��������
        cout << "File doesn`t exist" << endl;                                                  //���� �������
        fclose(file);                                                                          //�������� �������� �����
    }
    else {
        file = fopen("E:\\visual studio\\laba_op\\x64\\Debug\\infile.txt", "rt");            //�������� �������� �����
        cout << "\nINPUT FILE:\n";
        while (fgets(ptr, strlen(ptr) + 1, file)) {                       //���� ����� �����
            cout << ptr;
        }
        fclose(file);                           //�������� �����
    }

    return ptr;
}

char* changeText_c(char* ptr) {
    int len = strcspn(ptr, "\n\r");               //������� ������� � ��������� ����� ��� ������� "\n\r"

    char buffer[400];
    strncpy(buffer, ptr, len);                       //��������� len � ����� ptr � ����� buffer  
    buffer[len] = '\0';

    char digits[400], otherChars[400];
    int numDigits = 0, numOtherChars = 0;

    for (int i = 0; i < len; i++) {                          //���� ��� ������ ���� �� ������� � �����
        if (isdigit(buffer[i])) {                            //�������� �� �����
            digits[numDigits++] = buffer[i];                 //���� ��� - �� ������ �� ������
        }
        else {
            otherChars[numOtherChars++] = buffer[i];          //������ ���� ������� �� ������
        }
    }

    digits[numDigits] = '\0';                         // ������ ������ ���� �����
    otherChars[numOtherChars] = '\0';                 //������ ������ ���� �����

    strcpy(ptr, digits);                              //��������� ������ ���� �� �����

    for (int i = numOtherChars - 1; i >= 0; i--) {
        strncat(ptr, &otherChars[i], 1);                 //������� ����� ������� �� �����(� ����������� �������)
    }

    return ptr;
}

char* replace_dublicates_c(char* ptr) {
    int len = strlen(ptr);                         //������� ����� ptr

    char result[100];
    int index = 0;

    for (int i = 0; i < len; i++) {              //���� ��� ����� ��������
        int count = 1;
        while (i < len - 1 && ptr[i] == ptr[i + 1] && isdigit(ptr[i])) {  //��������� ������� ���������� ���� � ������
            count++;
            i++;
        }
        if (count > 1) {                //���� ����� 1 �����, �������� ����� ������� ()
            result[index++] = '(';
            result[index++] = ptr[i];
            result[index++] = ')';
        }
        else {
            result[index++] = ptr[i];       //������ ������ �������� �����
        }
    }

    result[index] = '\0';              //������ ������ ����
    strcpy(ptr, result);               //��������� ��������� � ����
    return ptr;
}

char* add_record_c() {
    FILE* file;
    char* line;
    char choice;
    line = (char*)malloc(sizeof(char) * 600);                  //�������� ���'�� ��� line

    cout << "\nWould you like to add text? (y/n)      ";
    cin >> choice;                                             //���� ��� �������� ����������� ������
    getchar();                                                 //��������� ���������� �������(������� ����)

    file = fopen("E:\\visual studio\\laba_op\\x64\\Debug\\infile.txt", "a");       //�������� �������� �����
    
    if (choice == 'y' || choice == 'Y') {                  //���� ���������� ���� ������ ���. �����
        
        cout << ("\nInput your text (press Enter and then * to stop):\n\n");

        do {
            fgets(line, sizeof(line), stdin);            //��� �����

            if (strcmp(line, "*\n") != 0) {                 //���� �������� ����� �� ������ "*\n" �� �������� ���� � ����
                fprintf(file, "%s", line);
            }
        } while (strcmp(line, "*\n") != 0);                  //���� �� ������� "*"
    }
    else if (choice == 'n' || choice == 'N') {}             //���� � �� ����� �� ������

    else {                                        //������� ������� ��� ����������� ���
    cout << " Invalid data";
    }
    fclose(file);                                 //������� ������� ����
    free(line);                                   //������� ���'��� line
    return line;
}

void write_to_file_c() {
    FILE* inputFile = fopen("E:\\visual studio\\laba_op\\x64\\Debug\\infile.txt", "r");         //�������� �������� �����
    FILE* outputFile = fopen("E:\\visual studio\\laba_op\\x64\\Debug\\outfile.txt", "w");       //�������� ��������� �����

    char line[100];

    while (fgets(line, sizeof(line), inputFile) != NULL) {                    //���� �� ��������� ���� �������� �����
        char* changedLine = changeText_c(line);                               //������ ������� ��� ���� ������
        char* resultLine = replace_dublicates_c(changedLine);                 //������ ������� ��� ����� ��������
        fprintf(outputFile, "%s\n", resultLine);                              //����� ���������� � �������� ����
        cout << resultLine << endl;                                           //���� ����������
    }

    fclose(inputFile);       //�������� �������� �����
    fclose(outputFile);      //�������� ��������� �����
}

