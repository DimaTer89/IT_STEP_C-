/*Вводится строка, которая состоит из слов, разделенных одним или несколькими пробелами. 
Пробелы могут быть также перед первым и после последнего слова. 
Отредактировать строку: удалить все пробелы перед первым словом и после последнего слова. Между словами оставить ровно один пробел.*/
#include <iostream>
#include <Windows.h>
using namespace std;
void redux(char*str) {
	while (*str) {
		if (*str == ' '&&*(str+1)==' ') {
			char *tmp = str + 1;
			char *ptr = tmp + strlen(str);
			while (tmp < ptr) {
				*tmp = *(tmp + 1);
				tmp++;
			}
		}
		str++;
	}
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int N = 128;
	char str[N];
	cout << " Введите строку :";
	gets_s(str, N);
	cout << " Исходная строка :" << str << endl;
	redux(str);
	cout << " Преобразованная строка:" << str << endl;
	system("pause");
}
