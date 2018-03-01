/*Написать функцию frame, которая выводит на экран рамку из звездочек. В качестве параметров функции должны передаваться координаты левого верхнего угла и размеры рамки.*/
#include <iostream>
using namespace std;
void frame(int , int , int , int );
void main() {
	setlocale(LC_ALL,"rus");
	int ocX, ocY, leight, high;
	cout << " Введите координату Х : ";
	cin >> ocX;
	cout << " Введите координату Y : ";
	cin >> ocY;
	cout << " Введите длину рамки : ";
	cin >> leight;
	cout << " Введите высоту рамки : ";
	cin >> high;
	frame(ocX, ocY, leight, high);
	system("pause");
}
void frame(int x, int y, int l, int h) {
	for (int i = 0; i < y; i++)cout << "\n";
	for (int i = 0; i < h; i++) {
		for (int i = 0; i < x; i++)cout << " ";
		for (int j = 0; j < l; j++) {
			if ((i > 0 && i < h - 1) && (j > 0 && j <= l - 2))
				cout << " ";
			else
				cout << "*";
		}
		cout << "\n";
	}
}
