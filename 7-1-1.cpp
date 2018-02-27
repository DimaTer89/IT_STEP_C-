//Написать функцию, которая возвращает истину, если ее аргумент – простое целое число, и ложь, если не простое. Простое число – это число, которое делиться ТОЛЬКО на 1 и на себя (2, 5, 7, 11 и т.д.). 
#include <iostream>
using namespace std;
bool simpleNumber(int a) {
	for (int i = 2; i < a; i++)
		if (a%i == 0)return false;
	return true;
}
void main() {
	setlocale(LC_ALL, "rus");
	int number;
	cout << " Введите число :";
	cin >> number;
	if (simpleNumber(number))cout <<" True !\n";
	else cout << " False \n";
	system("pause");
}
