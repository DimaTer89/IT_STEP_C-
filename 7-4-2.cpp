/*Написать функцию, которая меняет порядок элементов передаваемого массива на обратный. Внутри функции запрещено использовать вспомогательный массив.
Использовать шаблон для реализации функций, работающих с различными типами массивов.*/
#include <iostream>
#include <time.h>
#define N 10
using namespace std;
template <typename T1>
void reserv(T1 *a, int  b) {
	T1 *ptr = a;
	T1 *xptr = a + b - 1;
	T1 tmp;
	while (ptr < xptr) {
		tmp = *ptr;
		*ptr = *xptr;
		*xptr = tmp;
		ptr++;
		xptr--;
	}
}
template <typename T>
void randArr(T *a, int b) {
	for (int i = 0; i < b; i++, a++) {
		*a = rand() % 51 - 10;
		
	}
}
template <typename T>
void printArr(T *a, int b) {
	for (int i = 0; i < b; i++, a++) {
		cout << " " << *a << " ";
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arr[N];
	double dArr[N];
	cout << " Одномерный массив целых чисел: \n";
	randArr(arr, N);
	printArr(arr, N);
	reserv(arr, N);
	cout << endl;
	cout << " Одномерный перобразованный массив целых чисел: \n";
	printArr(arr, N);
	cout << endl;
	cout << " Одномерный массив вещественных чисел: \n";
	randArr(dArr, N);
	printArr(dArr, N);
	cout << endl;
	cout << " Одномерный преобразованный массив вещественных чисел: \n";
	reserv(dArr, N);
	printArr(dArr, N);
	cout << endl;
	system("pause");
}
