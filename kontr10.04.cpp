#include <iostream>
using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	const int N = 128;
	const int M = 30;
	char str[N];
	int count = 0;
	cout << " Введите строку : ";
	gets_s(str,N);
	char word[M];
	cout << " Введите слово : ";
	gets_s(word);
	char* buf;
	char *ptr = strtok_s(str, " ", &buf);
	while (ptr != NULL) {
		if (strcmp(ptr, word) == 0)count++;
		ptr = strtok_s(NULL, " ", &buf);
	}
	cout << " Заданное слово встречается " << count << " раз \n";
	system("pause");
}
