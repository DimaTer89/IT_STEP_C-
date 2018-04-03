//Вводится строка, которая состоит из слов, разделенных одним или несколькими пробелами. Поменять местами первое и последнее слово.
#include <iostream>
#include <Windows.h>
using namespace std;

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int N = 256;
	char string[N];
	cout << " Введите строку : ";
	gets_s(string, N);
	char* buf;
	char* ptr = strtok_s(string, " ", &buf);
	char* first;
	first = ptr;
	cout << " Первое слово " << first << endl;
	char*last;
	while (ptr != NULL) {
		last = ptr;
		ptr = strtok_s(NULL, " ", &buf);
	}
	cout << " Последнее слово : " << last << endl;
	
	cout << string << endl;
	system("pause");
}
