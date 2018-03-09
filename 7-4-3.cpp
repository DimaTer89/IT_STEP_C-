/*Написать перегруженную функцию mySum для реализации различных способов сложения двух дробных чисел.Функция должна выводить результат сложения на консоль.Варианты перегрузки :
а) сложения десятичных дробей(с фиксированной точкой);
b) сложения натуральных дробей(каждое число задается числителем и знаменателем)*/
#include <iostream>
using namespace std;
void mySum(double a, double b) {
	printf(" Сумма %.2f и %.2f равна %.2f", a, b, a + b);
}
void mySum(int a, int b, int c, int d) {
	int num = a * d + c * b;
	int den = b * d;
	int gen = 1;
	while (gen <= num && gen <= den)
	{
		if (num % gen == 0 && den%gen == 0) {
			num /= gen;
			den /= gen;
			gen = 1;
		}
		gen++;
	}
	if (den - 1) printf("Сумма %d/%d и %d/%d равна %d/%d", a, b, c, d, num, den);
	else printf("Сумма %d/%d и %d/%d равна %d", a, b, c, d, num);

}
void main() {
	setlocale(LC_ALL, "rus");
	double num1, num2;
	cout << " Введите две десятичные дроби через пробел:";
	cin >> num1 >> num2;
	int chis1, chis2, znam1, znam2;
	cout << " Введите числители и знаменатели первого числа через пробел:";
	cin >> chis1 >> znam1;
	int *ptr;
	int vyvod = 0;
	ptr = &vyvod;
	cout << " Введите числители и знаменатели второго числа через пробел:";
	cin >> chis2 >> znam2;
	mySum(num1, num2);
	cout << endl;
	mySum(chis1, znam1, chis2, znam2);
	cout << endl;
	system("pause");
}
