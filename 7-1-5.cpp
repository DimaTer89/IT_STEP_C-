/*Напишите функцию, которая принимает целое число и возвращает количество цифр в числе и процент четных цифр*/
#include <iostream>
using namespace std;
int countAnProc(int, double *);
void main() {
	setlocale(LC_ALL, "rus");
	int numb;
	double per = 0;
	double *perc;
	cout << " Введите число : ";
	cin >> numb;
	perc = &per;
	int kol;
	kol=countAnProc(numb,perc);
	cout << " Количество цифр в числе = " << kol << endl;
	cout << " Процент чётных цифр в числе = " << per << endl;
	system("pause");
}
int countAnProc(int a, double *b) {
	int count = 0;
	int countEl = 0;
	if (a == 0) {
		*b = 100;
		return 1;
	}
	while (a > 0) {
		countEl++;
		if (a % 2 == 0)
			count++;
		a /= 10;
	}
	*b = (double)100 / countEl*count;
	return countEl;
}
