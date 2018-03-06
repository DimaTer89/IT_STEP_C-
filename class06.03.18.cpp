#include <iostream>
using namespace std;
void vyvod(int n) {
	if (n <= 0)return;
	vyvod(n - 1);
	cout << n << " ";
}
void main() {
	setlocale(LC_ALL, "rus");
	cout << " Введите число : ";
	int n;
	cin >> n;
	vyvod(n);
	cout << endl;
	system("pause");
}
===========================
#include <iostream>
using namespace std;
int max(int x, int y) {
	return x > y?x:y;
}
double max(double x, double y) {
	return x > y ? x : y;
}
int max(int x, int y, int z) {
	int max = x > y ? x : y;
	max = z > max ? z : max;
	return max;
}
double max(double x, double y, double z) {
	double max = x > y ? x : y;
	max = z > max ? z : max;
	return max;
}void main() {
	int k = 5, j = 8, l = 4;
	double x = 0.5, y = 4.3, z = 9.6;
	setlocale(LC_ALL, "rus");
	cout << " Максимум из 5 и 4 = " << max(k, l) << endl;
	cout << " Максимум из 0.5 и 4.3 = " << max(x, y) << endl;
	cout << " Максимум из 5 и 4 и 8 = " << max(k, l, j) << endl; 
	cout << " Максимум из 0.5 и 4.3 и 9.6 = " << max(x, y, z) << endl;
	system("pause");
}
================================
#include <iostream>
using namespace std;
template <typename TT,typename TT1>
TT max(TT x, TT1 y){
	return x > y ? x : y;

}
template <typename TT>
TT max(TT x, TT y,TT z){
	TT max = x > y ? x : y;
	max = z > max ? z : max;
	return max;
}
void main() {
	int k = 5, j = 8, l = 4;
	double x = 0.5, y = 4.3, z = 9.6;
	setlocale(LC_ALL, "rus");
	cout << " Максимум из 5 и 4 = " << max(k, l) << endl;
	cout << " Максимум из 0.5 и 4.3 = " << max(x, y) << endl;
	cout << " Максимум из 5 и 4 и 8 = " << max(k, l, j) << endl; 
	cout << " Максимум из 0.5 и 4.3 и 9.6 = " << max(x, y, z) << endl;
	cout << max(k, z) << endl;
	system("pause");
}
========================================
#include <iostream>
using namespace std;
template <typename TT,typename TT1>
auto max(TT x, TT1 y)-> decltype(x+y){
	return x > y ? x : y;

}
template <typename TT>
TT max(TT x, TT y,TT z){
	TT max = x > y ? x : y;
	max = z > max ? z : max;
	return max;
}
void main() {
	int k = 5, j = 8, l = 4;
	double x = 0.5, y = 4.3, z = 9.6;
	setlocale(LC_ALL, "rus");
	cout << " Максимум из 5 и 4 = " << max(k, l) << endl;
	cout << " Максимум из 0.5 и 4.3 = " << max(x, y) << endl;
	cout << " Максимум из 5 и 4 и 8 = " << max(k, l, j) << endl; 
	cout << " Максимум из 0.5 и 4.3 и 9.6 = " << max(x, y, z) << endl;
	cout << max(k, z) << endl;
	system("pause");
}
============================================
#include <iostream>
using namespace std;
template <typename T>
T maxArray(T a[], int n) {
	T max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max)max = a[i];
	}
	return max;
}
void main() {
	setlocale(LC_ALL, "rus");
	int a[] = { 3,8,5,6,9,4 };
	double b[] = { 3.3,8.8,6.5 };
	char c[] = { 'd','y','m','a' };
	cout << maxArray(a, 6) << endl;
	cout << maxArray(b, 3) << endl;
	cout << maxArray(c, 4) << endl;
	system("pause");
}
=================================
#include <iostream>
using namespace std;
double integral(double a, double b, int n, double(*fptr)(double)) {
	double s = 0;
	double h = (b - a) / n;
	for (double x = a; x < b; x += h) {
		s += (*fptr)(x)*h;
	}
	return s;
}
void main() {
	double a = 2, b = 3.5;
	cout << integral(a, b, 50, sin) << endl;
	cout << integral(0, 4, 50, sqrt) << endl;
	system("pause");
}
==================================
#include <iostream>
using namespace std;
void vvod() {
	cout << " Ввод данных \n";
}
void vyvod() {
	cout << " Вывод данных \n";
}
void udal() {
	cout << " Удаление данных \n";
}
void quit() {
	cout << " Завершение работы \n";
	system("pause");
	exit(0);
}
int menu() {
	cout << " 1 - ввод данных \n";
	cout << " 2 - вывод данных \n";
	cout << " 3 - удаление данных \n";
	cout << " 4 - выход \n";
	cout << " Ваш выбор : ";
	int k;
	do {
		cin >> k;
		if (k < 1 || k>4)cout << " Неверно ! Повторите ввод !\n";
	} while (k < 1 || k>4);
	return k;
}
void main() {
	setlocale(LC_ALL, "rus");
	void(*fptr[4])() = { vvod,vyvod,udal,quit };
	int j;
	while (true) {
		j = menu();
		fptr[j-1]();
	}
}
================================
