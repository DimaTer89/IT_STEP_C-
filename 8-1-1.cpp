/*Сформировать и распечатать динамический одномерный массив (число элементов запросить у пользователя). Заполнить случайными числами от -5 до 5.
Удалить из массива все нулевые элементы. Новый массив должен занимать ровно столько памяти, сколько ему необходимо. Распечатать новый массив.*/
#include <iostream>
#include <time.h>
using namespace std;
void randArr(int *mas, int size) {
	for (int i = 0; i < size; i++) {
		mas[i] = rand() % 11 - 5;
	}
}
void printArr(int *mas, int size) {
	for (int i = 0; i < size; i++) {
		cout << " " << mas[i];
	}
	cout << endl;
}
void udalzero(int *&mas, int &size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (mas[i] == 0)count++;
	}
	cout << count << endl;
	int j = 0;
	int *ptr = new int[size - count];
	for (int i = 0; i < size; i++) {
		if (mas[i] != 0) {
			ptr[j] = mas[i];
			j++;
		}
	}
	delete[] mas;
	mas = ptr;
	size = size - count;
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
	cout << " Массив :\n";
	printArr(ptr, n);
	udalzero(ptr, n);
	cout << " Преобразованный массив : \n";
	printArr(ptr, n);
	delete[] ptr;
	ptr = NULL;
	system("pause");
}
