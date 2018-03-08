/*Дано слово, состоящее только из строчных латинских букв. Проверить, является ли это слово палиндромом. Вывести Yes или No. Пример:
Ввод: radar Вывод: Yes
Ввод: yes Вывод: No*/
#include <iostream>
#include <string>
using namespace std;
bool palindrom(char *a,char *b){
	if (*a == *b) {
		if (a < b) {
			a++;
			b--;
			palindrom(a, b);
		}
		else
			return true;
	}
	else
		return false;
}
void main() {
	setlocale(LC_ALL, "rus");
	char str[] = "rader";
	int len = strlen(str);
	char *ptr;
	ptr = str;
	char *eptr;
	eptr = str + len - 1;
	bool flag;
	flag = palindrom(ptr, eptr);
	if (flag)cout << "Yes" << endl;
	else cout << " No" << endl;
	system("pause");
}
