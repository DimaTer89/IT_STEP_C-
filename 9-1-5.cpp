//Вводится строка, которая состоит из слов, разделенных одним или несколькими пробелами. Поменять местами первое и последнее слово.
#include <iostream>
using namespace std;
char* fis(char*str) {
	while (*str == ' ')str++;
	if (*str == '\0')return NULL;
	while (*str != ' '&&*str != '\0') {
		str++;
	}
	return str-1;
}
char* las(char*str) {
	char* tmp = str + strlen(str)-1;
	while (*tmp == ' ')tmp--;
	while (*tmp != ' ') {
		tmp--;
	}
	return tmp+1;
}
void mycat(char *&str,char *ptr, char*endptr) {
	while (ptr<endptr) {
		*str++ = *ptr++;
	}
}
void convert(char *s, char*s1, char*str,char*str1) {
	char *tmp = str1;
	mycat(tmp, s1, str + strlen(str));
	mycat(tmp, (s + 1), (s1 - 1));
	mycat(tmp,str,(s+1));
	*tmp = '\0';
}
void main() {
	setlocale(LC_ALL, "rus");
	const int N = 256;
	char str[N];
	char str1[N];
	cout << " Введите строку : ";
	gets_s(str, N);
	cout << " Исходная строка : \n";
	cout << str << endl;
	char* first = fis(str);
	char* last = las(str);
	convert(first, last, str, str1);
	puts(str1);
	system("pause");
}
