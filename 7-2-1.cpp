/*Описать функцию определения максимального элемента в одномерном массиве. С помощью этой функции найти максимум в каждой строке двумерного массива и вывести эти максимумы на консоль. 
Также с помощью этой функции найти максимальный элемент во всем двумерном массиве.*/
#include <iostream>
#include <time.h>
#define ROW 4
#define COL 5
using namespace std;
/*int maxArr(int, int);*/
void randArr(int *a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++,a++) {
			*a = rand() % 21 - 10;
			printf(" %3d ",*a);
		}
		cout << endl;
	}
}
void printArr(int *a, int n, int m) {
	int *ptr;
	ptr = a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++, a++) {
			printf(" %3d ",*a);
		}
		cout << endl;
	}
}
int maxArr(int *a, int n) {
	int maxEl = *a++;
	for(int i=1;i<n;i++,a++)
	{
		if (*a> maxEl) maxEl = *a;
	}
	return maxEl;
}
void oneMasrand(int *a, int size) {
	int *tmp;
	tmp = a;
	for (int i = 0; i < size; i++, a++) {
		*a = rand() % 21 - 10;
		cout << " " << *a << " ";
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int a[ROW][COL];
	int arr[ROW];
	cout << " Двумерный массив \n";
	randArr(&a[0][0],ROW,COL);
	cout << " Одномерный массив \n";
	oneMasrand(arr, ROW);
	cout << endl;
	cout<< " Максимальный элемент одномерного массива" << maxArr(arr, ROW)<<endl;
	for (int i = 0; i < ROW; i++)
	{
		cout << "Максимальный элемент  [ " << i + 1 << " ] строки = " << maxArr(a[i], COL) << endl;
	}
	system("pause");
}
