#include"functions.h"

void int_array(int size) {

    Array<int> array(size);
     cout << "������ �������� ������:" <<  endl;

    for (int i = 0; i < size; i++) {
        int value;
         cin >> value;
        array.insert(i, value);
    }

    int choice;
    do {
        sms();
         cin >> choice;

        switch (choice) {
        case 1: {
             cout << "����� ������: " << array.getSize() <<  endl;
            break;
        }
        case 2: {
            int value;
             cout << "�������� ��������: ";
             cin >> value;
            int position = array.find(value);
            if (position != -1) {
                 cout << "������� ����������� �� ������� " << position+1 <<  endl;
            }
            else {
                 cout << "������� �� ��������" <<  endl;
            }
            break;
        }
        case 3: {
            int position, value;
             cout << "�������: ";
             cin >> position;
             cout << "��������: ";
             cin >> value;
            array.insert(position-1, value);
             cout << "������� ��������" <<  endl;
            break;
        }
        case 4: {
            int position;
             cout << "�������: ";
             cin >> position;
            array.remove(position-1);
             cout << "������� ��������" <<  endl;
            break;
        }
        case 5: {
            typename Array<int>::Iterator iterator = array.getIterator();
            iterator.begin(array);
            while (!iterator.isEnd()) {
                 cout << iterator.value() << " ";
                iterator.next();
            }
             cout <<  endl;
            break;
        }
        case 6: {
             cout << "�����" <<  endl;
            break;
        }
        default: {
             cout << "������� ����. ��������� �� ���." <<  endl;
            break;
        }
        }
    } while (choice != 6);
}

void double_array(int size) {

    Array<double> array(size);
     cout << "������ �������� ������:" <<  endl;

    for (int i = 0; i < size; i++) {
        double value;
         cin >> value;
        array.insert(i, value);
    }

    int choice;
    do {
        sms();
         cin >> choice;

        switch (choice) {
        case 1: {
             cout << "����� ������: " << array.getSize() <<  endl;
            break;
        }
        case 2: {
            double value;
             cout << "�������� ��������: ";
             cin >> value;
            int position = array.find(value);
            if (position != -1) {
                 cout << "������� ����������� �� ������� " << position+1 <<  endl;
            }
            else {
                 cout << "������� �� ��������" <<  endl;
            }
            break;
        }
        case 3: {
            int position;
            double value;
             cout << "�������: ";
             cin >> position;
             cout << "��������: ";
             cin >> value;
            array.insert(position-1, value);
             cout << "������� ��������" <<  endl;
            break;
        }
        case 4: {
            int position;
             cout << "�������: ";
             cin >> position;
            array.remove(position-1);
             cout << "������� ��������" <<  endl;
            break;
        }
        case 5: {
            typename Array<double>::Iterator iterator = array.getIterator();
            iterator.begin(array);
            while (!iterator.isEnd()) {
                 cout << iterator.value() << " ";
                iterator.next();
            }

             cout <<  endl;
            break;
        }
        case 6: {
             cout << "�����..." <<  endl;
            break;
        }
        default: {
             cout << "������� ����. ��������� �� ���." <<  endl;
            break;
        }
        }
    } while (choice != 6);
}

void string_array(int size) {

    Array<char> array(size);
     cout << "������ �������� ������:" <<  endl;

    for (int i = 0; i < size; i++) {
        char value;
         cin >> value;
        array.insert(i, value);
    }

    int choice;
    do {
        sms();
         cin >> choice;

        switch (choice) {
        case 1: {
             cout << "����� ������: " << array.getSize() <<  endl;
            break;
        }
        case 2: {
            char value;
             cout << "�������� ��������: ";
             cin >> value;
            int position = array.find(value);
            if (position != -1) {
                 cout << "������� ����������� �� ������� " << position+1 <<  endl;
            }
            else {
                 cout << "������� �� ��������" <<  endl;
            }
            break;
        }
        case 3: {
            int position;
            char value;
             cout << "�������: ";
             cin >> position;
             cout << "��������: ";
             cin >> value;
            array.insert(position-1, value);
             cout << "������� ��������" <<  endl;
            break;
        }
        case 4: {
            int position;
             cout << "�������: ";
             cin >> position;
            array.remove(position-1);
             cout << "������� ��������" <<  endl;
            break;
        }
        case 5: {
            typename Array<char>::Iterator iterator = array.getIterator();
            iterator.begin(array);
            while (!iterator.isEnd()) {
                 cout << iterator.value() << " ";
                iterator.next();
            }
             cout <<  endl;
            break;
        }
        case 6: {
             cout << "�����..." <<  endl;
            break;
        }
        default: {
             cout << "������� ����. ��������� �� ���." <<  endl;
            break;
        }
        }
    } while (choice != 6);
}

void char_array(int size) {

    Array< string> array(size);
     cout << "������ �������� ������:" <<  endl;

    for (int i = 0; i < size; i++) {
         string value;
         cin >> value;
        array.insert(i, value);
    }

    int choice;
    do {
        sms();
         cin >> choice;

        switch (choice) {
        case 1: {
             cout << "����� ������: " << array.getSize() <<  endl;
            break;
        }
        case 2: {
             string value;
             cout << "�������� ��������: ";
             cin >> value;
            int position = array.find(value);
            if (position != -1) {
                 cout << "������� ����������� �� ������� " << position+1 <<  endl;
            }
            else {
                 cout << "������� �� ��������" <<  endl;
            }
            break;
        }
        case 3: {
            int position;
             string value;
             cout << "�������: ";
             cin >> position;
             cout << "��������: ";
             cin >> value;
            array.insert(position-1, value);
             cout << "������� ��������" <<  endl;
            break;
        }
        case 4: {
            int position;
             cout << "�������: ";
             cin >> position;
            array.remove(position-1);
             cout << "������� ��������" <<  endl;
            break;
        }
        case 5: {
            typename Array< string>::Iterator iterator = array.getIterator();
            iterator.begin(array);
            while (!iterator.isEnd()) {
                 cout << iterator.value() << " ";
                iterator.next();
            }
             cout <<  endl;
            break;
        }
        case 6: {
             cout << "�����..." <<  endl;
            break;
        }
        default: {
             cout << "������� ����. ��������� �� ���." <<  endl;
            break;
        }
        }
    } while (choice != 6);
}

void sms() {
     cout << "����:" <<  endl;
     cout << "1. ��������� ����� ������" <<  endl;
     cout << "2. ��������� ������� ��������" <<  endl;
     cout << "3. �������� ����� ������� � ������ �������" <<  endl;
     cout << "4. �������� ������� � ������ �������" <<  endl;
     cout << "5. ������� �������� ������" <<  endl;
     cout << "6. �����" <<  endl;
     cout << "��� ����: ";
}