#pragma once
#pragma warning(disable: 4996)
#pragma warning(disable: 4146)

#include <stdio.h>
#include <iostream>

void main_ptr();                            //������� �������
char* output_infile_c(char* ptr);           //���� �������� �����
char* input_record_c();                     //����� ����� � ����
char* changeText_c(char* ptr);              //������ �����(����� ������)
char* replace_dublicates_c(char* ptr);      //������� ��������
char* add_record_c();                       //������ ����� � ����
void write_to_file_c();                     //�������� � ����
