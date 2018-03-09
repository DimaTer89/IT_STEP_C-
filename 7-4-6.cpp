/*Напишите 2 функции, каждая из которых принимает вещественный параметр и возвращает вещественное значение.
Пусть первая функция вычисляет y = x2 , а вторая – y = x*2+4, где x – входной параметр y – возвращаемое значение. 
Затем напишите функцию, которая принимает указатель на одну из этих функций, а также диапазон значений (от a до b) и выводит на экран 10 точек (координаты x и y) для этого диапазона.
Напишите меню, которое иллюстрирует работу этих функций.*/
#include <iostream>
using namespace std;
double two(double x) {
	double y;
	y = x * x;
	return y;
}
double fun(double x) {
	double y;
	y = x * 2 + 4;
	return y;
}
double myFun(double a, double b, double(*fPtr)(double)) {
	double low = a;
	double hihg = b;
	double s;
	for (double x = a; x < b; x++) {
		s = (*fPtr)(x);
	}
	return s;
}
void main() {
	setlocale(LC_ALL, "rus");
	double num,num2;
	cout << " Введите диапозон 1 : ";
	cin >> num;
	cout << " Введите диапозон 2 : ";
	cin >> num2;
	printf(" ||    X     ||     Y     ||\n");
	printf(" %3f      %3f     \n", num, myFun(num, num2, two));
	system("pause");
}
