#include <iostream>
#include <time.h>
#define N 10
using namespace std;
template <typename TT>
void randArr(TT *a, int size) {
	for (int i = 0; i < size; i++, a++) {
		*a = rand() % 21 - 10;
	}
}
template <typename T>
void printArr(T *a, int size) {
	for (int i = 0; i < size; i++, a++) {
		cout << " " << *a;
	}
	cout << endl;
}
void perevorot(int *ptr, int *endPtr) {
	int tmp;
	while (ptr < endPtr) {
		tmp = *ptr;
		*ptr = *endPtr;
		*endPtr = tmp;
		ptr++;
		endPtr--;
	}
}
void oladki(int *ptr, int *endPtr) {
	int *begPtr = ptr;
	int *max = ptr;
	while (ptr < endPtr) {
		if (*ptr > *max)max = ptr;
		ptr++;
	}
	cout << *max << endl;
	perevorot(max, endPtr);
	perevorot(begPtr, endPtr);
	/*ptr++;
	if (ptr < endPtr)oladki(ptr, endPtr);*/
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arr[N];
	randArr(arr, N);
	cout << " Массив \n";
	printArr(arr, N);
	int *ptr = arr;
	int *endPtr = arr + N-1;
	oladki(ptr, endPtr);
	printArr(arr, N);
	system("pause");
}
