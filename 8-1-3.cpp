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
		cout << " " << mas[i] << " ";
	}
	cout << endl;
}
void onePlus(int *&mas, int &size) {
	int  pos;
	do {
		cout << " Введите позицию : ";
		cin >> pos;
		if (pos<0 || pos>(size - 1))cout << " Ошибка ! Введите снова : ";
	} while (pos<0 || pos>(size - 1));
	int *ptr = new int[size + 1];
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
	size += 1;
}
void oneMinus(int *&mas, int &size) {
	int pos;
	do {
		cout << " Введите позицию удаленния элемента : ";
		cin >> pos;
		if (pos<0 || pos>(size - 1))cout << " Ошибка ! Введите снова : ";
	} while (pos<0 || pos>(size - 1));
	int *ptr = new int[size - 1];
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (i != pos) {
			ptr[j] = mas[i];
			j++;
		}
	}
	delete[]mas;
	mas = ptr;
	size -= 1;
}
void manyPlus(int *&mas, int &size) {
	int kol, pos;
	do {
		cout << " Введите позицию : ";
		cin >> pos;
		if (pos<0 || pos>(size - 1))cout << " Ошибка ! Введите снова : ";
	} while (pos<0 || pos>(size - 1));
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
	size += kol;
}
void manyMinus(int *&mas, int &size) {
	int pos,kol;
	do {
		cout << " Введите позицию удаленния элемента : ";
		cin >> pos;
		if (pos<0 || pos>(size - 1))cout << " Ошибка ! Введите снова : ";
	} while (pos<0 || pos>(size - 1));
	cout << " Введите количество элементов : ";
	cin >> kol;
	int *ptr = new int[size - kol];
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (i < pos||i>=pos+kol) {
			ptr[j] = mas[i];
			j++;
		}
	}
	delete[]mas;
	mas = ptr;
	size -= kol;
}
int menu() {
	cout << " 1 - Добавления элемента в массив с заданной позиции. " << endl;
	cout << " 2 - Удаление заданного элемента массива." << endl;
	cout << " 3 - Добавление нескольких элементов из массива, начиная с заданной позиции." << endl;
	cout << " 4 - Удаление нескольких элементов из массива, начиная с заданной позиции." << endl;
	int menu;
	do {
		cout << " Введите номер операции : ";
		cin >> menu;
		if (menu < 1 || menu>4)cout << " Ошибка ! Введите снова : ";
	} while (menu < 1 || menu>4);
	return menu;
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n;
	void(*fPtr[4])(int *&mas, int &n) = { onePlus,oneMinus,manyPlus,manyMinus };
	cout << " Введите размер массива : ";
	cin >> n;
	int *ptr;
	ptr = new int[n];
	randArr(ptr, n);
	cout << " Исходный массив \n";
	printArr(ptr, n);
	int j;
	j = menu();
	fPtr[j - 1](ptr, n);
	printArr(ptr, n);
	delete[]ptr;
	ptr = NULL;
	system("pause");
}
