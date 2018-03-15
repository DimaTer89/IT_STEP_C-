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
void perevorot(int a[], int size, int *max) {
	int tmp;
	for (int i = *max; i<size - 1; i++) {
		tmp = a[i];
		a[i] = a[i + 1];
		a[i + 1] = tmp;
	}
}
void oladki(int a[], int size,int n) {
	int kol = size;
	int ind = n;
	int max = a[ind];
	for (int i = 1; i < size; i++) {
		if (a[i] > max)max = i;
	}
	cout << a[max] << endl;
	int *ptr;
	ptr = &max;
	perevorot(a, kol, ptr);
	int *nPtr = a;
	int *endPtr = a + size - 1;
	while (nPtr < endPtr) {
		int tmp;
		tmp = *nPtr;
		*nPtr = *endPtr;
		*endPtr = tmp;
		nPtr++;
		endPtr--;
	}


}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arr[N];
	randArr(arr, N);
	cout << " Массив \n";
	printArr(arr, N);
	int ind = 0;
	/*int *endPtr;
	endPtr = arr + N - 1;*/
	//perevorot(arr, endPtr);
	oladki(arr, N,ind);
	printArr(arr, N);
	system("pause");
}