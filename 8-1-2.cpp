/*Запросить у пользователя размеры двумерного массива. Выделить память под массив, заполнив его случайными числами от -5 до 5.
Найти максимальный элемент в каждой строке двумерного массива и вывести его на консоль.*/
#include <iostream>
#include <time.h>
using namespace std;
void randArr(int **mas, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			mas[i][j] = rand() % 11 - 5;
		}
	}
}
void printArr(int **mas, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << mas[i][j] << "\t";
		}
		cout << endl;
	}
}
void maxElem(int **mas, int row, int col) {
	for (int i = 0; i < row; i++) {
		int max = mas[i][0];
		for (int j = 0; j < col; j++) {
			if (mas[i][j] > max)max = mas[i][j];
		}
		cout << " Максимальный элемент " << i + 1 << " строки = " << max << endl;
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int row, col;
	int **mas;
	cout << " Введите количество строк : ";
	cin >> row;
	cout << " Введите количество столбцов : ";
	cin >> col;
	mas = new int*[row];
	for (int i = 0; i < row; i++) {
		mas[i] = new int[col];
	}
	randArr(mas, row, col);
	cout << " Двумерный массив \n";
	printArr(mas, row, col);
	maxElem(mas, row, col);
	for (int i = 0; i < row; i++) {
		delete mas[i];
	}
	delete[] mas;
	mas = NULL;
	system("pause");
}
