/*Даны два целых числа А и В. Вывести все числа от А до В в порядке возрастания, если А<В, или в порядке убывания в противном случае. Пример: ввод: 5 1 вывод: 5 4 3 2 1.*/
#include <iostream>
using namespace std;
void vyvod(int a, int b) {
	if (a == b) {
		cout << " " << b;
		return;
	}

	if (a < b) {
		
		cout << " " << a++;
		vyvod(a, b);
	}
	if (a > b) {
		cout << " " << a--;
		vyvod(a,b);
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	int num1, num2;
	cout << " Введите число А :";
	cin >> num1;
	cout << " Введите число B :";
	cin >> num2;
	vyvod(num1, num2);
	cout << endl;
	system("pause");
}
