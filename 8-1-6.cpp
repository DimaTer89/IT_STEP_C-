/*Написать функцию, которая уменьшает размер двумерной матрицы, удаляя из нее столбец. Измененная матрица должна занимать ровно столько памяти, сколько необходимо!
Проиллюстрировать работу этой функции:
1) Заполнить динамический двумерный массив случайными числами (размерность матрицы запросить у пользователя).
2) Запросить номер столбца, который будет удален.
3) Удалить столбец
5) Распечатать преобразованную матрицу.*/
#include <iostream>
#include <time.h>
using namespace std;
void randArr(int **mas,int row,int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			mas[i][j] = rand() % 101 - 50;
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
void udalCol(int **&mas, int &row, int &col, int stolb) {
	int **ptr = new int*[row];
	for (int i = 0; i < row; i++) {
		ptr[i] = new int[col - 1];
	}
	int k = 0;
	int l = 0;
	for (int i = 0; i < row; i++) {
		for (int  j= 0; j < col; j++) {
			if (j != stolb) {
				ptr[k][l] = mas[i][j];
				l++;
				
			}
		}
		l = 0;
		k++;
	}
	delete[]mas;
	mas = ptr;
	col -= 1;
}
void main() {
	setlocale(LC_ALL, "rus");
	int row, col,stolb;
	srand(time(0));
	cout << " Введите количество строк : ";
	cin >> row;
	cout << " Введите количество столбцов : ";
	cin >> col;
	int **mas;
	mas = new int*[row];
	for (int i = 0; i < row; i++) {
		mas[i] = new int[col];
	}
	randArr(mas, row, col);
	cout << " Исходный массив \n";
	printArr(mas, row, col);
	cout << " Введите номер столбца ,который нужно удалить : ";
	cin >> stolb;
	udalCol(mas, row, col, stolb);
	cout << " Преобразованный массив \n";
	printArr(mas, row, col);
	for (int i = 0; i < row; i++) {
		delete mas[i];
	}
	delete[]mas;
	system("pause");
}
