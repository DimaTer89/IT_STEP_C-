/*Одномерный массив из 10 элементов инициализировать случайными числами от -9 до 9. Вывести исходный массив на консоль. Поменять местами первый отрицательный элемент и последний положительный.
Преобразованный массив также вывести на консоль. При работе с массивом использовать только указатели! Оформить в виде отдельных функций:
1) инициализацию массива, 2) вывод на консоль, 3) поиск первого отрицательного, 4) последнего положительного и 5) обмен местами двух элементов массива.*/
#include <iostream>
#include <time.h>
#define N 10
using namespace std;
void randArr(int *a, int size) {
	srand(time(0));
	for (int i = 0; i < size; i++, a++) {
		*a = rand() % 19 - 9;
		cout << " " << *a << " ";
	}
	cout << endl;
}
void printArr(int *a, int size) {
	for (int i = 0; i < size; i++, a++) {
		cout << " " << *a << " ";
	}
	cout << endl;
}
int fisNegel(int *a, int size) {
	for (int i = 0; i < size; i++, a++)
	{
		if (*a < 0) {
			return i;
		}
	}
}
int lastPol(int *a, int size) {
	int *ptr = a + size - 1;
	for (int i = size-1; i > 0; i--, ptr--) {
		if (*ptr > 0) {
			return i;
		}
	}
	
}
void zamena(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void main() {
	setlocale(LC_ALL, "rus");
	int arr[N];
	int neg,pol;
	int *nPtr, *Pptr;
	cout << " Сгенерированный массив\n";
	randArr(arr, N);
	cout << " Печать массива \n";
	printArr(arr, N);
	neg = fisNegel(arr, N);
	nPtr = arr + neg;
	pol = lastPol(arr, N);
	Pptr = arr + pol;
	zamena(nPtr,Pptr);
	cout << " Преобразованный массив :\n";
	printArr(arr, N);
	system("pause");
}
