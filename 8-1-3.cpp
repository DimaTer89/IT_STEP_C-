/*Сформировать одномерный динамический массив, и реализовать меню:
a) Добавления элемента в массив с заданной позиции.
b) Удаление заданного элемента массива.
c) Добавление нескольких элементов из массива, начиная с заданной позиции.
d) Удаление нескольких элементов из массива, начиная с заданной позиции.*/
#include <iostream>
#include <time.h>
using namespace std;
void randArr(int *mas, int size) {
	for (int i = 0; i < size; i++) {
		mas[i] = rand() % 21 - 10;
	}
}
void printArr(int *mas, int size) {
	for (int i = 0; i < size; i++) {
		cout << " "<<mas[i] << " ";
	}
	cout << endl;
}
void onePlus(int *&mas, int &size) {
	int  pos;
	cout << " Введите позицию : ";
	cin >> pos;
	int *ptr = new int[size+1];
	int j = 0;
	int k = 0;
	for (int i = 0; i < size; i++) {
		ptr[j] = mas[i];
		j++;
		if (i == pos) {
			ptr[j] = (mas[k] = rand() % 21 - 10);
			j++;
		}
	}
	delete[]mas;
	mas = ptr;
	size =size + 1;
}
void manyPlus(int *&mas, int &size) {
	int kol, pos;
	cout << " Введите позицию : ";
	cin >> pos;
	cout << " Введите количество : ";
	cin >> kol;
	int *ptr = new int[size + kol];
	int j = 0;
	for (int i = 0; i < size; i++) {
		ptr[j] = mas[i];
		j++;
		if (i == pos) {
			for (int k = 0; k < kol; k++) {
				ptr[j] = (mas[k] = rand() % 21 - 10);
				j++;
			}
		}
	}
	delete[]mas;
	mas = ptr;
	size = size + kol;
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n;
	cout << " Введите размер массива : ";
	cin >> n;
	int *ptr;
	ptr = new int[n];
	randArr(ptr, n);
	cout << " Исходный массив \n";
	printArr(ptr, n);
	manyPlus(ptr, n);
	printArr(ptr, n);
	onePlus(ptr, n);
	printArr(ptr,n);
	delete[]ptr;
	ptr = NULL;
	system("pause");
}
