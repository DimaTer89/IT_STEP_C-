//Введите строку. Замените каждый символ ';' на пару символов “.,”.
#include <iostream>
using namespace std;
void zamena(char* str) {
	while (*str) {
		if (*str == ';') {
			*str = '.';
			char*ptr = str + strlen(str);
			while (ptr >str) {
				*(ptr + 1) = *ptr;
				ptr--;
			}
			str++;
			*str = ',';
		}
		str++;
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	const int N = 128;
	char str[N];
	cout << " Введите строку : ";
	gets_s(str,N);
	cout << str << endl;
	zamena(str);
	cout << " Изменнённая строка : " << str << endl;
	system("pause");
}
