#include"functions.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    cout << "Введіть розмір масиву: ";
    cin >> size;

    int typeChoice;
    cout << "Виберіть тип масиву: " <<  endl;
    cout << "1. int" <<  endl;
    cout << "2. double" <<  endl;
    cout << "3. string" <<  endl;
    cout << "4. char" <<  endl;
    cout << "Ваш вибір: ";
    cin >> typeChoice;

    if (typeChoice == 1) {
        int_array(size);
    }
    else if (typeChoice == 2) {
        double_array(size);
    }
    else if (typeChoice == 3) {
        char_array(size);
    }
    else if (typeChoice == 4) {
        string_array(size);
    }
    else {
        cout << "Невірний вибір типу масиву. Програма завершується." <<  endl;
    }

    return 0;
}
