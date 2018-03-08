/*Вывести цифры числа справа налево. Пример: ввод: 179 вывод: 9 7 1. Нельзя использовать массивы и циклы!*/
#include <iostream>
using namespace std;
void vyvod(int a) {
	if (a / 10) {
		cout << " " << a % 10;
		vyvod(a / 10);
	}
	else cout << " "<<a;
}
void main() {
	setlocale(LC_ALL, "rus");
	int num;
	cout << " Введите число :";
	cin >> num;
	vyvod(num);
	cout << endl;
	system("pause");
}
