/*Предположим что, характеристикой строки целочисленной квадратной матрицы является сумма ее положительных элементов.
Переставляя указатели на строки заданной матрицы, расположить их в соответствии с ростом характеристик.
Размерность матрицы вводится пользователем, а значения являются случайными числами в диапазоне (-50 : 50).*/
#include <iostream>
#include <time.h>
using namespace std;
void randArr(int **mas, int kol) {
	for (int i = 0; i < kol; i++) {
		for (int j = 0; j < kol; j++) {
			mas[i][j] = rand() % 101 - 50;
		}
	}
}
void printArr(int **mas, int kol) {
	for (int i = 0; i < kol; i++) {
		for (int j = 0; j < kol; j++) {
			cout << mas[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
int sumPol(int *mas, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		if (mas[i] > 0)sum += mas[i];
	}
	return sum;
}
void sum(int **mas, int kol) {
	for (int i = 0; i < kol; i++) {
		cout << " Сумма положительных элементов " << i + 1 << " строки " << sumPol(mas[i], kol) << endl; ;
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int **mas;
	int kol;
	cout << " Введите размер квадратной матрицы : ";
	cin >> kol;
	mas = new int*[kol];
	for (int i = 0; i < kol; i++) {
		mas[i] = new int[kol];
	}
	randArr(mas, kol);
	cout << " Исходный массив : \n";
	printArr(mas, kol);
	sum(mas, kol);
	cout << endl;
	int *tmp = 0;
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i<kol-1; i++)
			if (sumPol(mas[i], kol) > sumPol(mas[i + 1], kol)) {
				tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
				flag = true;
			}
	}
	printArr(mas, kol);
	for (int i = 0; i < kol; i++) {
		delete mas[i];
	}
	delete mas;
	system("pause");
}
