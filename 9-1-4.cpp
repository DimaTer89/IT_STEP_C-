//Вводится строка, которая состоит из слов, разделенных одним или несколькими пробелами. Найти и распечатать самое длинное слово
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
	char*buf;
	char * pch = strtok_s(string, " ", &buf);  // получаем первое слово
	char *word; // самое длинное слово
	int length = strlen(pch);          // определяем длинну первого слова
	int maxLen = 0; // самое длинное слово
	while (pch != NULL)                         // пока есть слова
	{
		length = strlen(pch);        // определяем длинну слова
		if (maxLen < length)        // определяем самое длинное слово
		{
			maxLen = length;
			word = pch;              // сохраняем указатель на текущее слово
		}
		pch = strtok_s(NULL, " ",&buf); // получаем следующее слово
	}
	cout << " Самое длинное слово в строке : "<< word << endl;;
	system("pause");
}
