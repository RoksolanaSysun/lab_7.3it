#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
void ShiftRight(int** a, const int rowCount, const int colCount, int shift);
void ShiftDown(int** a, const int rowCount, const int colCount, int shift);
int RowWithMostZeroes(int** a, const int rowCount, const int colCount);

int main() {
    srand((unsigned)time(NULL));

    int rowCount, colCount, shift;
    bool shiftRight;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Input(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    cout << "Enter shift amount (x): "; cin >> shift;
    cout << "Shift right? (1 for yes, 0 for down): "; cin >> shiftRight;

    if (shiftRight) {
        ShiftRight(a, rowCount, colCount, shift);
    }
    else {
        ShiftDown(a, rowCount, colCount, shift);
    }

    Print(a, rowCount, colCount);

    int rowWithZeroes = RowWithMostZeroes(a, rowCount, colCount);
    if (rowWithZeroes != -1) {
        cout << "Row with most zeroes: " << rowWithZeroes << endl;
    }
    else {
        cout << "No zeroes in the matrix." << endl;
    }

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void ShiftRight(int** a, const int rowCount, const int colCount, int shift) {
    for (int i = 0; i < rowCount; i++) {
        for (int s = 0; s < shift; s++) {
            int temp = a[i][colCount - 1];
            for (int j = colCount - 1; j > 0; j--) {
                a[i][j] = a[i][j - 1];
            }
            a[i][0] = temp;
        }
    }
}

void ShiftDown(int** a, const int rowCount, const int colCount, int shift) {
    for (int j = 0; j < colCount; j++) {
        for (int s = 0; s < shift; s++) {
            int temp = a[rowCount - 1][j];
            for (int i = rowCount - 1; i > 0; i--) {
                a[i][j] = a[i - 1][j];
            }
            a[0][j] = temp;
        }
    }
}

int RowWithMostZeroes(int** a, const int rowCount, const int colCount) {
    int maxZeroes = 0;
    int rowIndex = -1;

    for (int i = 0; i < rowCount; i++) {
        int zeroCount = 0;
        for (int j = 0; j < colCount; j++) {
            if (a[i][j] == 0)
                zeroCount++;
        }
        if (zeroCount > maxZeroes) {
            maxZeroes = zeroCount;
            rowIndex = i;
        }
    }

    return rowIndex;
}