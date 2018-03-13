/*Дано натуральное число N. Вычислить сумму его цифр. Нельзя использовать массивы и циклы!*/
#include <iostream>
using namespace std;
int sum(int a) {
	if (a < 10)return a;
	return sum(a / 10) + a % 10;
}
void main() {
	setlocale(LC_ALL, "rus");
	int chis;
	cout << " Введите число : ";
	cin >> chis;
	cout << " Сумма цифр числа = " << sum(chis) << endl;
	system("pause");
}
