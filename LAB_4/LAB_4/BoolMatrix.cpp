#include "BoolMatrix.h"

int BoolMatrix::getRows() { return n; }
int BoolMatrix::getCols() { return m; }

void BoolMatrix::setSize(int n) {
    this->n = n;
    this->m = n;
}

BoolMatrix::BoolMatrix() {
    setSize(0);
    arr = nullptr;
}

BoolMatrix::BoolMatrix(const BoolMatrix& other) {
    setSize(other.n);
    arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            arr[i][j] = other.arr[i][j];
        }
    }
}

BoolMatrix::BoolMatrix(int n, int m):n(n),m(m) {
    setSize(getRows());
    srand(time(NULL));
    arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 2;
        }
    }
}

BoolMatrix::BoolMatrix(int size) {
    this->n = size;
    this->m = size;

    cout << endl;
    this->arr = new int* [n];
    for (int i = 0; i < n; i++) {
        this->arr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cout << "Enter element:  ";
            this->arr[i][j] = checkNumber();
        }
    }
}

BoolMatrix BoolMatrix::operator|(const BoolMatrix& other) {
    BoolMatrix result(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result.arr[i][j] = arr[i][j] | other.arr[i][j];
        }
    }
    return result;
}

void BoolMatrix::print() {
      for (int i = 0; i < this->n; i++) {
        for (int j = 0; j < this->n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
      }
}

void BoolMatrix::count(int size) {
    int counter = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (this->arr[i][j] == 1) {
                counter++;
            }
        }
    }
    cout << "Number of 1s:   " << counter << endl << endl;
}

BoolMatrix BoolMatrix::operator~() {
    int size = getRows();

    BoolMatrix result;
    result.setSize(size);

    result.arr = new int* [size];
    for (int i = 0; i < size; i++) {
        result.arr[i] = new int[size];
        for (int j = 0; j < size; j++) {
            result.arr[i][j] = !arr[i][j];
        }
    }
    return result;
}


int checkNumber() {
    int ch;
    do {
        fflush(stdin);
        cin >> ch;
        if (ch != 1 && ch != 0) {
            cout << "Wrong number. Try again:    ";
        }
    } while (ch != 1 && ch != 0);

    return ch;
}