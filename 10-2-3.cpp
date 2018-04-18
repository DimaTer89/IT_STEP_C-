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
	cout << " Введите число : ";
	cin >> 	FloatPoint.f;
	cout << " Введённое число в виде типа float = " << FloatPoint.f << endl;
	cout << " Введённое число в виде типа double = " << FloatPoint.d << endl;
	cout << " Введённое число в виде типа long double = " << FloatPoint.l << endl;
	cout << " Введите число : ";
	cin >> FloatPoint.d;
	cout << " Введённое число в виде типа float = " << FloatPoint.f << endl;
	cout << " Введённое число в виде типа double = " << FloatPoint.d << endl;
	cout << " Введённое число в виде типа long double = " << FloatPoint.l << endl;
	cout << " Введите число : ";
	cin >> FloatPoint.l;
	cout << " Введённое число в виде типа float = " << FloatPoint.f << endl;
	cout << " Введённое число в виде типа double = " << FloatPoint.d << endl;
	cout << " Введённое число в виде типа long double = " << FloatPoint.l << endl;
	system("pause");
}
