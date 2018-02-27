/*Написать функцию, которая сравнивает два целых числа и возвращает результат сравнения в виде одного из знаков: >, < или = .*/
#include <iostream>
using namespace std;
char versus(int, int);
void main() {
	setlocale(LC_ALL, "rus");
	int num1, num2;
	cout << " Введите число 1 : ";
	cin >> num1;
	cout << " Введите число 2 : ";
	cin >> num2;
	cout <<"Число  a "<< versus(num1, num2) << " числа b "<< endl;
	system("pause");
}
char versus(int a, int b) {
	if (a > b)return '>';
	if (a < b)return '<';
	else return '=';
}
