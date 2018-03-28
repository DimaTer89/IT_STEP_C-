#include <iostream>
#include <time.h>
using namespace std;
void randArr(int **mas, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			mas[i][j] = rand() % 10;
		}
	}
}
void printArr(int **mas, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << mas[i][j] << " \t";
		}
		cout << endl;
	}
}
int maxelem(int *mas, int size) {
	int max = *mas;
	for (int i = 0; i < size; i++) {
		if (mas[i] > max) {
			max = mas[i];
		}
	}
	return max ;
}
int maxstrike(int **mas, int row,int col) {
	int index=0;
	int max = maxelem(mas[0], col);
	for (int i = 0; i < row; i++) {
		if ((maxelem(mas[i], col) > max)) {
			max = maxelem(mas[i], col);
			index = i;
		}
	}
	return index;
}
void dublmax(int **&mas, int &row, int col, int index) {
	int **ptr = new int*[row + 1];
	ptr[index] = new int[col];
	for (int i = 0; i < col; i++) {
		ptr[index][i] = mas[index][i];
	}
	int j = 0;
	for (int i = 0; i < row; i++) {
		if (i < index) {
			ptr[j] = mas[i];
			j++;
		}
		if (i == index)j++;
		if (i >= index) {
			ptr[j] = mas[i];
			j++;
		}
	}
	delete[]mas;
	mas = ptr;
	row += 1;

}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int row, col;
	cout << " Введите количество строк : ";
	cin >> row;
	cout << " Введите количество столбцов : ";
	cin >> col;
	int **mas = new int*[row];
	for (int i = 0; i < row; i++) {
		mas[i] = new int[col];
	}
	randArr(mas, row, col);
	cout << " Исходный массив \n";
	printArr(mas, row, col);
	int index = maxstrike(mas, row, col);
	dublmax(mas, row, col, index);
	cout << " Преобразованный массив \n";
	printArr(mas, row, col);
	for (int i = 0; i < row; i++) {
		delete mas[i];
	}
	delete[]mas;
	system("pause");
}
