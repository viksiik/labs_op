#include "BoolMatrix.h"

/*Визначити клас "Булева матриця" (BoolMatrix) розмірності n x m.
Реалізувати для нього декілька конструкторів, геттери, метод підрахунку числа одиниць у матриці.
Перевантажити оператори диз'юнкції ("|") та інверсії ("~") компонент матриць.
Створити три булеві матриці (М1, М2, М3), використовуючи різні конструктори.
Визначити матрицю М3 як диз'юнкцію матриць М1 та М2 (М3 = М1 v М2).
Знайти інверсію матриці М3. У отриманій матриці М3 підрахувати число одиниць.*/


int main()
{
    int rows = 0, cols = 0;
    cout << "Enter size of matrix:   ";
    cin >> rows;
    cols = rows;

    BoolMatrix M1(rows, cols);
    M1.setSize(rows);
    int size = M1.getRows();

    cout << "\nMatrix #1:\n";
    M1.print();

    BoolMatrix M2(size);
    cout << "\nMatrix #2:\n";
    M2.print();

    BoolMatrix M3(M1);
    cout << "\nMatrix #3:\n";
    M3 = M1 | M2;
    M3.print();
    M3.count(size);

    BoolMatrix M4;
    cout << "Changed matrix:\n";
    M4 = ~M3;
    M4.print();
    M4.count(size);

    return 0;
}