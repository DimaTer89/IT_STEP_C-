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
void reform(int *&mas, int &size,int &posish,int &kol) {
	int *ptr = new int[size + kol];
	int j = 0;
	for (int i = 0; i < size; i++) {
		ptr[j] = mas[i];
		j++;
		if (i == posish) {
			for (int k = 0; k < kol; k++) {
				ptr[j] = (mas[k] = rand() % 21 - 10);
				j++;
			}
		}
	}
	delete[]mas;
	mas = ptr;
	size =size + kol;
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n, pos, kol;
	cout << " Введите размер массива : ";
	cin >> n;
	int *ptr;
	ptr = new int[n];
	randArr(ptr, n);
	cout << " Исходный массив \n";
	printArr(ptr, n);
	cout << " Введите с какой позиции добавить элемент : ";
	cin >> pos;
	cout << " Введите колчество элементов : ";
	cin >>kol;
	reform(ptr, n,pos,kol);
	printArr(ptr, n);
	delete[]ptr;
	ptr = NULL;
	system("pause");
}
