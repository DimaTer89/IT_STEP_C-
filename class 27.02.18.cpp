#include <iostream>
using namespace std;
double gipotenuza(double, double);

void main()
{
	setlocale(LC_ALL, "rus");
	double gip1 = gipotenuza(2, 3);
	cout << " Гипотенуза для катетов 2 и 3 = " << gip1 << endl;
	double gip2 = gipotenuza(10, 12);
	cout << " Гипотенуза для катетов 10 и 12 = " << gip2 << endl;
	system("pause");
}
double gipotenuza(double kat1, double kat2) {
	double gip = sqrt(kat1*kat1 + kat2 + kat2);
	return gip;
}//////
// перестановка 
#include <iostream>
using namespace std;
void swap(int *x,int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void main()
{
	setlocale(LC_ALL, "rus");
	int a = 2, b = 3;
	cout << " До перестновки : а= " << a << " b= " << b << endl;
	swap(&a, &b);
	cout << " После перестновки : а= " << a << " b= " << b << endl;
	system("pause");
}
////////
//работа с массивами 
#include <iostream>
#include <time.h>
using namespace std;
void initArray(int[], int);
void printArray(int *, int);
int sumofArray(int[], int);
void main() {
	setlocale(LC_ALL, "rus");
	const int N = 10;
	int a[N];
	const int M = 5;
	int b[M];
	srand(time(0));
	initArray(a, N);
	initArray(b, M);
	cout << " Массив а\n";
	printArray(a, N);
	int sum = sumofArray(a, N);
	cout << " Его сумма = " << sum << endl;
	cout << " Массив b\n";
	printArray(b, M);
	cout << " Его сумма = " << sumofArray(b,M) << endl;
	system("pause");
}
void initArray(int x[], int n) {
	for (int i = 0; i < n; i++) {
		x[i] = rand() % 101;
	}
}
void printArray(int *x, int n) {
	for (int i = 0; i < n; i++, x++) {
		cout <<" "<< *x << " ";
	}
	cout << endl;
}
int sumofArray(int x[], int n) {
	int s = 0;
	for (int i = 0; i < n; i++, x++) {
		s += *x;
	}
	return  s;
}
/////
#include <iostream>
#include <time.h>
#define N 3
#define M 4
using namespace std;
void printArray(int x[][M], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < M; j++) {
			cout <<" "<< x[i][j]<<" ";
		}
		cout << endl;
	}
}
void zamena(int el, int *x, int n, int m) {
	for (int i = 0; i < n*m; i++,x++) {
		if (*x < el)*x = 0;
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	int a[N][M] = { 1,3,5,2,4,6,1,7,8,9,2,4 };
	cout << " Исходный массив :\n ";
	printArray(a, N);
	zamena(6, &a[0][0], N,M);
	cout << " Преобразованный массив :\n";
	printArray(a, N);
	system("pause");
}
/////////////
#include <iostream>
using namespace std;
#include <time.h>
int summa(int kol, ...) {
	int *p = &kol + 1;
	int sum = 0;
	for (int i = 0; i < kol; i++, p++) {
		sum += *p;
	}
	return sum;
}
void main() {
	setlocale(LC_ALL, "rus");
	cout << " Сумма пяти чисел = " << summa(5, 3, 8, 2, 7, 4) << endl;
	cout << " Сумма трёх числе = " << summa(3, 4, 2, 1) << endl;
	system("pause");
}
