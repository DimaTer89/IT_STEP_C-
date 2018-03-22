/*Написать функцию, которая увеличивает размер двумерной матрицы, добавляя в нее строку. Проиллюстрировать работу этой функции:
a) Заполнить динамический двумерный массив случайными числами (размерность матрицы запросить у пользователя).
b) Запросить номер строки, которая будет вставлена.
c) Вставить строку с помощью созданной функции
d) Заполнить эту строку нулями.
e) Распечатать преобразованную матрицу.*/
#include <iostream>
#include <time.h>
using namespace std;
void randArr(int **mas, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			mas[i][j] = rand() % 21 - 10;
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
	cout << endl;
}
void strNul(int **&mas, int &row, int &col,int strike) {
	int **ptr = new int*[row + 1];
	int j = 0;
	ptr[strike] = new int[col];
	for (int j = 0; j < col; j++) {
		ptr[strike][col] = 0;
	}
	for (int i = 0; i < row; i++) {
		if (i < strike) {
			ptr[j] = mas[i];
			
		}
		if (i == strike) j++;
		if (i >=strike) {
			ptr[j] = mas[i];
		}
		j++;
	}
	delete[]mas;
	mas = ptr;
	row += 1;
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
	cout << " Исходный массив \n";
	printArr(mas, row, col);
	int stroka;
	cout << " Введите номер строки которая будет добавлена : ";
	cin >> stroka;
	strNul(mas, row, col, stroka);
	printArr(mas, row, col);
	for (int i = 0; i < row; i++) {
		delete mas[i];
	}
	delete[]mas;
	system("pause");
}
