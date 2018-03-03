/*Написать функцию, которая в двумерном массиве вещественных чисел меняет знак элементов некоторого столбца на противоположный (номер столбца передавать в качестве параметра).
Использовать функцию для преобразования матрицы размером 4х5. Выполнить два варианта такой функции: a) функция, предназначенная для массивов с числом столбцов, равным 5;
б) универсальная функция, которую можно использовать при любом числе строк и столбцов.*/
#include <iostream>
#include <time.h>
#define ROW 4
#define COL 5
using namespace std;
void randArr(double *ptr, int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++, ptr++)
		{
			*ptr = rand() % 19 - 9.23;
			printf(" %5.2f ", *ptr);
		}
		cout << endl;
	}
}
void printArr(double *ptr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++, ptr++) {
			printf(" %5.2f ", *ptr);
		}
		cout << endl;
	}
}
void changeCol(int col,double mas[][COL], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < COL; j++) {
			if (col<=COL&&(j+1) == col) {
				mas[i][j] *= -1;
			}
		}
	}
}
void changePer(int col, double *ptr, int n, int m) {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++, ptr++) {
			if ((j + 1) == col) {
				*ptr *= -1;
			}
		}
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	double arr[ROW][COL];
	int num;
	cout << " Двумерный массив :\n";
	randArr(&arr[0][0], ROW, COL);
	cout << " Введите номер столбца :";
	cin >> num;
	changeCol(num,arr, ROW);
	cout << " Изменённый массив(для пяти столбцов) :\n";
	printArr(&arr[0][0], ROW, COL);
	printf("=====================================\n");
	randArr(&arr[0][0], ROW, COL);
	cout << " Введите номер столбца : ";
	cin >> num;
	cout << " Изменённый массив ( для любого числа столбцов) : \n";
	changePer(num, &arr[0][0], ROW, COL);
	printArr(&arr[0][0], ROW, COL);
	system("pause");
}
