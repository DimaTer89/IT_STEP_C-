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
