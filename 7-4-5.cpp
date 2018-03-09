/*Реализовать 3 функции, каждая из которых принимает вещественное число и возвращает вещественное число. 
Первая функция вычисляет квадратный корень числа, вторая – куб числа, третья – синус числа. В главной функции создайте массив из 3-х указателей на эти функции. 
Добавьте меню, в котором пользователь может выбрать желаемую операцию. Напишите программу без использования операторов if и switch.*/
#include <iostream>
using namespace std;
double sqr(double a) {
	return sqrt(a);
}
double cube(double a) {
	return (a * a * a);
}
double ang(double a) {
	return sin(a);
}
int menu() {
	cout << " Выберите желаемую операцию \n";
	cout << " 1 - вычесляет квадратный корень числа \n";
	cout << " 2 - возводит число в куб \n";
	cout << " 3 - вычесляет синус числа \n";
	int k;
	do {
		cin >> k;
		if (k < 0 || k>3)cout << " Ошибка ! Введите снова \n";
	} while (k < 0 || k>3);
	return k;
}
void main() {
	setlocale(LC_ALL, "rus");
	double num;
	double(*fPtr[3])(double) = {sqr,cube,ang };
	cout << " Введите число :";
	cin >> num;
	int j;
	j = menu();
	printf(" Ваш результат = %.3f \n", fPtr[j - 1](num));
	system("pause");
}
