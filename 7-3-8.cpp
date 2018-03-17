//Написать рекурсивную функцию, которая принимает двумерный массив целых чисел и количество сдвигов и выполняет круговой сдвиг массива вправо.
#include <iostream>
#include <time.h>
#define ROW 3
#define COL 4
using namespace std;
void randArr(int *a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++, a++) {
			*a = rand() % 21 - 10;
		}
	}
}
void printArr(int *a, int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++, a++) {
			printf(" %3d ", *a);
		}
		cout << endl;
	}
	
}
void shift(int x,int n, int a[][COL], int size) {
	int kol = n;
	int score = x;
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < COL; j++) {
			int tmp = a[i][j];
			a[i][j] = a[i][j - 1];
			a[i][j - 1] = tmp;
		}
	}
	score++;
	if(score<kol)shift(score,kol,a,ROW);
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arr[ROW][COL];
	int num;
	int count = 0;
	cout << " Двумерный массив \n";
	randArr(&arr[0][0], ROW, COL);
	printArr(&arr[0][0], ROW, COL);
	cout << " Введите количество сдвигов : ";
	cin >> num;
	cout << " Изменённый двумерный массив :\n";
	shift(count,num,arr,3);
	printArr(&arr[0][0], ROW, COL);
	system("pause");
}
