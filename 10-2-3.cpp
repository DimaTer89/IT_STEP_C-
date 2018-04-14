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
	float num;
	cout << " Введите число :";
	cin >> num;
	FloatPoint.f = num;
	cout << " Введённое число в виде типа float = " << FloatPoint.f << endl;
	cout << " Введённое число в виде типа double = " <<hex<< FloatPoint.d << endl;
	cout << " Введённое число в виде типа long double = " << hex<<FloatPoint.l << endl;
	system("pause");
}
