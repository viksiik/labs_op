#include"functions.h"

void int_array(int size) {

    Array<int> array(size);
     cout << "Введіть елементи масиву:" <<  endl;

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
             cout << "Розмір масиву: " << array.getSize() <<  endl;
            break;
        }
        case 2: {
            int value;
             cout << "Значення елемента: ";
             cin >> value;
            int position = array.find(value);
            if (position != -1) {
                 cout << "Елемент знаходиться на позиції " << position+1 <<  endl;
            }
            else {
                 cout << "Елемент не знайдено" <<  endl;
            }
            break;
        }
        case 3: {
            int position, value;
             cout << "Позиція: ";
             cin >> position;
             cout << "Значення: ";
             cin >> value;
            array.insert(position-1, value);
             cout << "Елемент включено" <<  endl;
            break;
        }
        case 4: {
            int position;
             cout << "Позиція: ";
             cin >> position;
            array.remove(position-1);
             cout << "Елемент видалено" <<  endl;
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
             cout << "Вихід" <<  endl;
            break;
        }
        default: {
             cout << "Невірний вибір. Спробуйте ще раз." <<  endl;
            break;
        }
        }
    } while (choice != 6);
}

void double_array(int size) {

    Array<double> array(size);
     cout << "Введіть елементи масиву:" <<  endl;

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
             cout << "Розмір масиву: " << array.getSize() <<  endl;
            break;
        }
        case 2: {
            double value;
             cout << "Значення елемента: ";
             cin >> value;
            int position = array.find(value);
            if (position != -1) {
                 cout << "Елемент знаходиться на позиції " << position+1 <<  endl;
            }
            else {
                 cout << "Елемент не знайдено" <<  endl;
            }
            break;
        }
        case 3: {
            int position;
            double value;
             cout << "Позиція: ";
             cin >> position;
             cout << "Значення: ";
             cin >> value;
            array.insert(position-1, value);
             cout << "Елемент включено" <<  endl;
            break;
        }
        case 4: {
            int position;
             cout << "Позиція: ";
             cin >> position;
            array.remove(position-1);
             cout << "Елемент видалено" <<  endl;
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
             cout << "Вихід..." <<  endl;
            break;
        }
        default: {
             cout << "Невірний вибір. Спробуйте ще раз." <<  endl;
            break;
        }
        }
    } while (choice != 6);
}

void string_array(int size) {

    Array<char> array(size);
     cout << "Введіть елементи масиву:" <<  endl;

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
             cout << "Розмір масиву: " << array.getSize() <<  endl;
            break;
        }
        case 2: {
            char value;
             cout << "Значення елемента: ";
             cin >> value;
            int position = array.find(value);
            if (position != -1) {
                 cout << "Елемент знаходиться на позиції " << position+1 <<  endl;
            }
            else {
                 cout << "Елемент не знайдено" <<  endl;
            }
            break;
        }
        case 3: {
            int position;
            char value;
             cout << "Позиція: ";
             cin >> position;
             cout << "Значення: ";
             cin >> value;
            array.insert(position-1, value);
             cout << "Елемент включено" <<  endl;
            break;
        }
        case 4: {
            int position;
             cout << "Позиція: ";
             cin >> position;
            array.remove(position-1);
             cout << "Елемент видалено" <<  endl;
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
             cout << "Вихід..." <<  endl;
            break;
        }
        default: {
             cout << "Невірний вибір. Спробуйте ще раз." <<  endl;
            break;
        }
        }
    } while (choice != 6);
}

void char_array(int size) {

    Array< string> array(size);
     cout << "Введіть елементи масиву:" <<  endl;

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
             cout << "Розмір масиву: " << array.getSize() <<  endl;
            break;
        }
        case 2: {
             string value;
             cout << "Значення елемента: ";
             cin >> value;
            int position = array.find(value);
            if (position != -1) {
                 cout << "Елемент знаходиться на позиції " << position+1 <<  endl;
            }
            else {
                 cout << "Елемент не знайдено" <<  endl;
            }
            break;
        }
        case 3: {
            int position;
             string value;
             cout << "Позиція: ";
             cin >> position;
             cout << "Значення: ";
             cin >> value;
            array.insert(position-1, value);
             cout << "Елемент включено" <<  endl;
            break;
        }
        case 4: {
            int position;
             cout << "Позиція: ";
             cin >> position;
            array.remove(position-1);
             cout << "Елемент видалено" <<  endl;
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
             cout << "Вихід..." <<  endl;
            break;
        }
        default: {
             cout << "Невірний вибір. Спробуйте ще раз." <<  endl;
            break;
        }
        }
    } while (choice != 6);
}

void sms() {
     cout << "Меню:" <<  endl;
     cout << "1. Визначити розмір масиву" <<  endl;
     cout << "2. Визначити позицію елемента" <<  endl;
     cout << "3. Включити новий елемент у задану позицію" <<  endl;
     cout << "4. Видалити елемент з заданої позиції" <<  endl;
     cout << "5. Вивести елементи масиву" <<  endl;
     cout << "6. Вийти" <<  endl;
     cout << "Ваш вибір: ";
}