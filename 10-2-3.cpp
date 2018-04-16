/*Объявите объединение floatingPoint с элементами float f, double d и long double l. Создайте три переменные типа floatingPoint.
Введите в них три значения: a) типа float, б) типа double, в) типа long double.
Каждая переменная-объединение должна быть распечатана как float, как double, как long double. Всегда ли значения печатаются правильно?*/
#include <iostream>
using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	union floatingPoint {
		float f;
		double d;
		long double l;
	}FloatPoint;
	float num1;
	double num2;
	long double num3;
	cout << " Введите число типа float : ";
	cin >> num1;
	FloatPoint.f = num1;
	cout << " Введённое число в виде типа float = " << FloatPoint.f << endl;
	cout << " Введите число типа double : ";
	cin >> num2;
	FloatPoint.d = num2;
	cout << " Введённое число в виде типа double = " << FloatPoint.d << endl;
	cout << " Введите число типа long double : ";
	cin >> num3;
	FloatPoint.l = num3;
	cout << " Введённое число в виде типа long double = " << FloatPoint.l << endl;
	system("pause");
}
