/*Вводится строка, которая состоит из слов, разделенных одним или несколькими пробелами.
Пробелы могут быть также перед первым и после последнего слова.
Отредактировать строку: удалить все пробелы перед первым словом и после последнего слова. Между словами оставить ровно один пробел.*/
#include <iostream>
#include <Windows.h>
using namespace std;
void redux(char*str) {
	char *beginStr = str;
	while (*str != '\0')
	{
		while (*str == ' ')
		{
			str++;
		}
		while (*str != ' ' && *str != '\0')
		{
			*beginStr = *str;
			beginStr++;
			str++;
		}
		*beginStr = ' ';
		beginStr++;
	}
	beginStr-=2;
	*beginStr = '\0';
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
	cout << " Преобразованная строка:" << str;
	system("pause");
}
