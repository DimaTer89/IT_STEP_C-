//Написать рекурсивную функцию, которая принимает двумерный массив целых чисел и количество сдвигов и выполняет круговой сдвиг массива вправо.
#include <iostream>
#include <time.h>
using namespace std;
void printArr(int *a, int n,int m) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++, a++) {
			printf(" %3d ", *a);
		}
		cout << endl;
	}
	cout << endl;
}
void shift(int n, int a[][4], int size) {
	int k = 0;
	while (k < n){
		for (int i = 0; i < size; i++) {
			for (int j = 1; j < 4; j++) {
				int tmp = a[i][j];
				a[i][j] = a[i][j - 1];
				a[i][j - 1] = tmp;
			}
		}
	k++;
    }
}
void print(int *a, int size) {
	for (int i = 0; i < size; i++, a++) {
		cout << " " << *a;
	}
	cout << endl;
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	//int arr1[4] = { 4,5,6,7 };
	//cout << " Одномерный массив \n";
	//print(arr1, 4);
	int num;
	//int *pPtr = arr1 + 1;
	cout << " Введите количество сдвигов : ";
	cin >> num;
	//shift(num,pPtr, 4);
	//print(arr1, 4);
	int arr[3][4] = { 4,5,6,7,1,2,4,1,4,5,6,9 };
	cout << " Двумерный массив \n";
	printArr(&arr[0][0], 3, 4);
	shift(num,arr,3);
	printArr(&arr[0][0], 3, 4);
	system("pause");
}
