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
void myFun(double a, double b, double(*fPtr)(double)) {
	double h = (b - a) /10;
	for (double x=a;x<b+h;x+=h) {
		printf(" ||  %5.2f     ||  %5.2f     || \n",x,(*fPtr)(x));
	}
}
int menu() {
	cout << " Введите действие :\n";
	cout << " 1 - вывод значений от а до b функции y=x2 \n";
	cout << " 2 - вывод значений от а до b функции y=x*2+4 \n";
	int k;
	do {
		cin >> k;
		if (k < 0 || k>2)cout << " Ошибка ! Введите снова : ";
	} while (k < 0 || k>2);
	return k;
}
void main() {
	setlocale(LC_ALL, "rus");
	double num,num2;
	double(*mPtr[2])(double) = { two,fun };
	cout << " Введите диапозон 1 : ";
	cin >> num;
	cout << " Введите диапозон 2 : ";
	cin >> num2;
	int j;
	j = menu();
	printf(" ||     X      ||     Y      ||\n");
	myFun(num, num2, mPtr[j - 1]);
	system("pause");
}
