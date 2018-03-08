/*Вывести цифры числа слева направо. Пример: ввод: 179 вывод: 1 7 9. Нельзя использовать массивы и циклы!*/
#include <iostream>
using namespace std;
void vyvod(int a) {
	if (a / 10) {
		int tmp = a % 10;
		a /= 10;
		vyvod(a);
		cout << " " << tmp;
	}
	else cout << " " << a;
}
void main() {
	setlocale(LC_ALL, "rus");
	int num;
	cout << " Введите число : ";
	cin >> num;
	vyvod(num);
	cout << endl;
	system("pause");
}
