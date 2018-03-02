/*Напишите функцию, которая определяет минимальный элемент массива (его значение и номер). Внутри функции запрещено использовать команды cin и cout.*/
#include <iostream>
#include <time.h>
#define N 10
using namespace std;
void randArr(int *ptr, int size) {
	srand(time(0));
	for (int i = 0; i < size; i++, ptr++) {
		*ptr = rand() % 19 - 9;
		cout << " " << *ptr << " ";
	}
	cout << endl;
}
void printArr(int *ptr, int size) {
	for (int i = 0; i < size; i++, ptr++) {
		cout << " " << *ptr << " ";
	}
	cout << endl;
}
int minArr(int *ptr, int size,int *ind) {
	int min = *ptr++;
	int index = 0;
	for (int i = 1; i < size; i++, ptr++) {
		if (*ptr < min) {
			min = *ptr;
			index=i;
		}
	}
	*ind = index;
	return min;
}
void main() {
	setlocale(LC_ALL, "rus");
	int arr[N];
	int indexEl = 0;
	int *inPtr;
	inPtr = &indexEl;
	cout << " Массив \n";
	randArr(arr, N);
	int min;
	min = minArr(arr, N, inPtr);
	cout << " Минимальный элемент массива = " << min <<" Номер элемента массива = " << indexEl<< endl;
	system("pause");
}
