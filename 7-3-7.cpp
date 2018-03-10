//Написать рекурсивный алгоритм сортировки методом выбора.
#include <iostream>
#include <time.h>
#define N 10
using namespace std;
void randArr(int *a, int size) {
	for (int i = 0; i < size; i++, a++) {
		*a = rand() % 21 - 10;
	}
}
void printArr(int *a, int size) {
	for (int i = 0; i < size; i++, a++) {
		cout << " " << *a;
	}
	cout << endl;
}
void sort(int a[], int left, int right) {
	int beg = left;
	int j = right;
	int k = beg + 1;
	int end = j - 1;
	int tmp;
	int imin = beg;
	while (k <= end) {
		if (a[imin] > a[k]) {
			imin = k;
			
		}
		k++;
	}
	tmp = a[beg];
	a[beg] = a[imin];
	a[imin] = tmp;
	beg++;
	if(beg<end)sort(a, beg, j);
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arr[N];
	randArr(arr, N);
	cout << " Массив : \n";
	printArr(arr, N);
	cout << " Отсортированный массив :\n";
	sort(arr, 0, N);
	printArr(arr, N);
	system("pause");
}
