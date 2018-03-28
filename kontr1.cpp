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
		cout <<" "<< mas[i]<<" ";
	}
	cout << endl;
}
void lastmax(int *&mas, int &size) {
	int max = *mas;
	int index;
	int kol;
	for (int i = 0; i <size; i++) {
		if (mas[i] >= max) {
			max = mas[i];
			index = i;
		}
	}
	kol =(size - index)-1;
	int *ptr = new int[size-kol];
	for (int i = 0; i <size-kol; i++) {
		ptr[i] = mas[i];
	}
	delete[]mas;
	mas = ptr;
	size-=kol;
}

void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int *mas;
	int size;
	cout << " Введите размер массива : ";
	cin >> size;
	mas = new int[size];
	randArr(mas, size);
	cout << " Исходный массив \n";
	printArr(mas, size);
	lastmax(mas, size);
	cout << " Преобразованный массив : \n";
	printArr(mas, size);
	delete[]mas;
	system("pause");
}
