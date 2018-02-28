/*Написать и протестировать функцию largerOf, которая заменяет значение двух переменных типа double большим из этих двух значений.*/
#include <iostream>
using namespace std;
void largerOf(double *a, double *b) {
	if (*a > *b)*b = *a;
	if (*a < *b)*a = *b;
}
void main() {
	setlocale(LC_ALL, "rus");
	double num1, num2;
	cout << " Введите первое значение :";
	cin >> num1;
	cout << " Введите второе значение :";
	cin >> num2;
	largerOf(&num1, &num2);
	cout << " Значение 1 = " << num1 << " Значение 2 = " << num2 << endl;
	system("pause");
}
