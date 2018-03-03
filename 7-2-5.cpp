/*Напишите функцию, с переменным количеством аргументов, которая в качестве обязательного параметра принимает тип действия и количество переменных 
и выполняет выбранное действие над этими переменными. «+» - сложение, «*» - умножение, «s» - среднее арифметическое.
Например:
double R = calc(‘s’,5,3,4,5,3,7);
cout<<R;
На экране мы увидим 4.4.*/
#include <iostream>
using namespace std;
double calc(char op, int kol, ...) {
	int sum = 0, proiz = 1;
	int count = 0;
	int *ptr;
	ptr = &kol+1;
	for (int i = 0; i < kol; i++, ptr++) {
		sum += *ptr;
		count++;
	}
	ptr = &kol+1;
	for(int j=0;j<kol;j++,ptr++) {
		proiz *= *ptr;
	
	}
	switch (op) {
	case '+': return sum; break;
	case '*': return proiz; break;
	case 's': return (double)sum / count; break;
	}
	cout << " Ошибка ! ";
	return 1;
}
void main() {
	setlocale(LC_ALL, "rus");
	double R =calc('+', 5, 3, 6, 5, 4, 7, 8, 9, 7, 4, 1, 2);
	cout << " "<<R<<" " <<endl;
	system("pause");
}
==================================================================
	/*Напишите функцию, с переменным количеством аргументов, которая в качестве обязательного параметра принимает тип действия и количество переменных 
и выполняет выбранное действие над этими переменными. «+» - сложение, «*» - умножение, «s» - среднее арифметическое.
Например:
double R = calc(‘s’,5,3,4,5,3,7);
cout<<R;
На экране мы увидим 4.4.*/
#include <iostream>
#include <time.h>
#define N 15
using namespace std;
void randArr(double *ptr, int size) {
	for (int i = 0; i < size; i++, ptr++) {
		*ptr = rand() % 21 - 10;
		cout << " " << *ptr << " ";
	}
	cout << endl;
}
double calc(char op, int kol, double *ptr,...) {
	double sum = 0;
	int count = 0;
	int proiz = 1;
	for (int i = 0; i < kol; i++, ptr++) {
		proiz *= *ptr;
		sum += *ptr;
		count++;
	}
	switch (op) {
	case '+': return sum; break;
	case '*': return proiz; break;
	case 's': return (double)sum / count; break;
	}
	cout << " Ошибка !!!\n";
	return 1;
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	double arr[N];
	char oper;
	int kol;
	cout << " Массив \n";
	randArr(arr, N);
	do {
		cout << " Введите действие : ";
		cin >> oper;
	} while (oper != 's'&&oper != '+'&&oper != '*');
	cout << " Введите количество переменных : ";
	cin >> kol;
	double R = calc(oper, kol, arr);
	cout << " Результат = " << R << endl;
	system("pause");
}
