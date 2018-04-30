#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	const int N = 256;
	char string[N];
	int shifr;
	cout << " Введите строку : ";
	gets_s(string, N);
	cout << " Введите шифр ключа : ";
	cin >> shifr;
	int i = 0;
	while (string[i]!='\0') {
		while (string[i] == ' ')string[i++];
		while (string[i]!= ' '&&string[i]!= '\0') {
		    string[i]+=shifr;
			i++;
		}
	}
	cout << " Шифрованная строка : " << string << endl;
	int j = 0;
	while (string[j] != '\0') {
		while (string[j] == ' ')string[j++];
		while (string[j] != ' '&&string[j] != '\0') {
			string[j] -= shifr;
			j++;
		}
	}
	cout << " Дешифрованная строка : " << string << endl;
	system("pause");
}
