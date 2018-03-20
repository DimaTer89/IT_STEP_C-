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
void oladki(int a[], int *endPtr, int n) {
	int *mPtr = a;
	int *maxPtr = mPtr;
	int *xPtr = mPtr;
	int max = *maxPtr;
	int ind = 0;
	int kol = n;
	for (int i = 0; i < n; i++, maxPtr++) {
		if (*maxPtr > max) {
			max = *maxPtr;
			ind = i;
		}
	}
	int *pptr = a + ind;
	cout << max << " " << ind << endl;
	perevorot(pptr, endPtr);
	perevorot(a, endPtr);
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arr[N];
	randArr(arr, N);
	cout << " Массив \n";
	printArr(arr, N);
	int *endPtr = arr + N - 1;
	oladki(arr, endPtr, N);
	printArr(arr, N);
	system("pause");
}
