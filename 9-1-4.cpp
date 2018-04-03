//Вводится строка, которая состоит из слов, разделенных одним или несколькими пробелами. Найти и распечатать самое длинное слово
#include <iostream>
using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	char string[200];
	cout << " Введите строку : ";
	gets_s(string, 200);
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
