/*Дано натуральное число N. Вычислить сумму его цифр. Нельзя использовать массивы и циклы!*/
#include <iostream>
using namespace std;
int sum(int a, int *ptr) {
	if (a / 10) {
		*ptr += a % 10;
		a /= 10;
		sum(a, ptr);
	}
	else return *ptr += a;
}
void main() {
	setlocale(LC_ALL, "rus");
	int chis;
	int cif = 0;
	cout << " Введите число : ";
	cin >> chis;
	cout << " Сумма цифр числа = " << sum(chis,&cif) << endl;
	system("pause");
}
