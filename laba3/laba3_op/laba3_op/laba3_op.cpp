#include "classes.h"

/*Розробити клас Книга, який характеризується ПІБ автора,
назвою, роком видання, к-тю сторінок. Створити масив об'єктів даного класу.
Визначити найтовщу книгу, видану у вказаний період часу (діапазон років)*/

int main()
{
    int LEN, upper, low;
    Book str;

    cout << "Enter number of books:\t";
    cin >> LEN;

    Book *books = new Book[LEN];

    for (int i = 0; i < LEN;i++) {
        cout << "\nBOOK " << i + 1 << ":" << endl;
        getchar();
        cout << "Enter author:\t\t";
        books[i].setAuthor();
        cout << "Enter name of book:\t";
        books[i].setName();
        cout << "Enter year:\t\t";
        books[i].setYear();
        cout << "Enter number of pages:\t";
        books[i].setPages();
    }

    sms();

    for (int i = 0;i < LEN;i++) {
        books[i].print();
    }
    
    cout << "\n--Enter range of years--\n";
    cout << "start:\t";
    cin >> low;
    cout << "end:\t";
    cin >> upper;

    books[LEN].findBook(books, LEN, low, upper);

    delete[] books;
}

