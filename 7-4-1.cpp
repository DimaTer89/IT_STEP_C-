/*Напишите перегруженную функцию myArea, которая вычисляет площадь
а) квадрата (один параметр)
b) прямоугольника (два параметра)*/
#include <iostream>
using namespace std;
double myArea(double x) {
	return x * x;
}
double myArea(double x, double y) {
	return x * y;
}
void main() {
	setlocale(LC_ALL, "rus");
	double x, y;
	cout << " Введите Х :";
	cin >> x;
	cout << " Введите Y :";
	cin >> y;
	cout << " Площадь квадрата = " << myArea(x) << endl;
	cout << " Площадь прямоугольника = " << myArea(x, y) << endl;
	system("pause");
}
