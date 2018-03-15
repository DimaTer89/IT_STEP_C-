#include <iostream>
#include <time.h>
#define ROW 4
#define COL 7
using namespace std;
bool simple(int a) {
	int b = a / 2;
	bool flag = false;
	int i = 2;
	while (i<b)
	{
		if ((a%i) == 0)
		{
			flag = true;
			break;
		}
		i++;
	}
	return flag;
}

int kolsimple(int *a, int size) {
	int kol = 0;
	for (int i = 0; i < size; i++, a++) {
		if (!simple(*a))kol++;
	}
	return kol;
}
void randArr(int *a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++, a++) {
			*a = rand() % 101;
		}
	}
}
void printArr(int *a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++, a++) {
			printf(" %3d ", *a);
		}
		cout << endl;
	}

}
void kolsimple(int *a, int n, int m) {

}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int twoArr[ROW][COL];
	cout << " Двумерный массив \n";
	randArr(twoArr[0], ROW, COL);
	printArr(&twoArr[0][0], ROW, COL);
	for (int i = 0; i < ROW; i++) {
		cout << " Простые числа для " << i + 1 << " строки = " << kolsimple(twoArr[i], COL) << endl;
	}
	system("pause");
}
