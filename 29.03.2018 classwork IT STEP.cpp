Замена символов 
#include <iostream>
using namespace std;
void zamena(char* str) {
	while (*str) {
		if (*str == '.') {
			*str = '!';
		}
		str++;
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	const int N = 128;
	char str[N];
	cout << " Введите строку : ";
	gets_s(str, N);
	zamena(str);
	cout << " Изменённая строка : \n";
	puts(str);
	system("pause");
}
==========================
функция копирование
#include <iostream>
using namespace std;
void mycpy(char* des, char* source) {
	while (*source) {
		*des++ = *source++;
	}
	*des = '\0';
}
void main() {
	setlocale(LC_ALL, "rus");
	const int N = 128;
	char str1[N],str2[N];
	cout << " Введите первую строку : ";
	cin >> str1;
	cout << " Введите вторую строку : ";
	cin >> str2;
	//strcpy_s(str1, str2);
	mycpy(str1, str2);
	cout << " Первая строка : \n";
	cout << str1 << endl;
	system("pause");
}
==================================
Имя файла
#include <iostream>
using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	const int N = 128;
	char filename[N];
	char name[N]="";
	cout << " Введите имя файла с расширением : ";
	cin >> filename;
	char* point = strstr(filename, ".txt");
	if (point) {
		cout << " Это текстовый файл \n";
		strncpy_s(name, filename, point - filename);
		cout << " Его имя : " << name << endl;
	}
	else {
		cout << " Это не текстовый файл \n";
	}
	system("pause");
}
=================================
дублирует все буквы А
#include <iostream>
using namespace std;
void insert(char* str, char* place, char what) {
	char*ptr = str + strlen(str);
	while (ptr >= place) {
		*(ptr + 1) = *ptr;
		ptr--;
	}
	*place = what;
}
void main() {
	setlocale(LC_ALL, "rus");
	const int N = 128;
	char str[N];
	cout << " Введите строку : ";
	gets_s(str,N);
	char *tmp = str;
	while (*tmp) {
		if (*tmp == 'a') {
			insert(str, tmp, 'a');
			tmp++;
		}
		tmp++;
	}
	cout << " Преобразованная строка : \n";
	cout << str << endl;
	system("pause");
}
======================================
подсчёт слов
#include <iostream>
using namespace std;

void main() {
	setlocale(LC_ALL, "rus");
	const int N = 128;
	char str[N];
	cout << " Введите строку : ";
	gets_s(str,N);
	int k = 0;
	char*ptr = str; //на начало строки 
	while (*ptr) {// пока не конец строки
		// пропускаем пробелы до начала
		while (*ptr == ' ')ptr++;
		if (*ptr == '\0')break;
		k++;//увеличиваем счётчик слов 
		//пропустить буквы слова 
		while (*ptr != ' '&&*ptr != '\0')ptr++;
	}
	cout << " Количество слов = " << k << endl;
	system("pause");
}
===========================================
#include <iostream>
using namespace std;

void main() {
	setlocale(LC_ALL, "rus");
	const int N = 128;
	char str[N];
	cout << " Введите строку : ";
	gets_s(str,N);
	int k = 0;
	char*ptr = str; //на начало строки 
	while (*ptr) {// пока не конец строки
		// пропускаем пробелы до начала
		while (*ptr == ' ')ptr++;
		if (*ptr == '\0')break;
		k++;//увеличиваем счётчик слов 
		//пропустить буквы слова 
		while (*ptr != ' '&&*ptr != '\0')ptr++;
	}
	cout << " Количество слов = " << k << endl;
	char*buf;
	ptr = strtok_s(str, " ", &buf);
	while (ptr!=NULL) {
		cout << ptr << endl;
		ptr = strtok_s(NULL, " ", &buf);
	}
	system("pause");
}
===========================================
список студентов
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <Windows.h>
void print(char** spisok, int n) {
	for (int i = 0; i < n; i++) {
		cout << spisok[i] << endl;
	}
}
void sort(char** spisok, int n) {
	for (int k = n - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			if (strcmp(spisok[i], spisok[i + 1]) > 0) {
				char*tmp = spisok[i];
				spisok[i] = spisok[i + 1];
				spisok[i + 1] = tmp;
			}
		}
	}
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << " Введите количество студентов : ";
	cin >> n;
	char** spisok = new char*[n];
	char name[200];
	char secondname[200];
	char lastname[200];
	for (int i = 0; i < n; i++) {
		cout << " Введите данные студента " << i + 1 << ":\n";
		cout << " Фамилия : ";
		cin >> lastname;
		cout << " Имя : ";
		cin >> name;
		cout << " Отчество : ";
		cin >> secondname;
		int k = strlen(lastname) + strlen(name) + strlen(secondname) + 3;
		char *tmp = new char[k];
		strcpy(tmp,lastname);
		strcat(tmp, " ");
		strcat(tmp, name);
		strcat(tmp, " ");
		strcat(tmp,secondname);
		strcat(tmp, " ");
		spisok[i] = tmp;
	}
	print(spisok, n);
	sort(spisok, n);
	cout << " Отсортированный список : \n";
	print(spisok, n);
	system("pause");
}
=========================================
#include <iostream>
using namespace std;
#include <Windows.h>
void print(char** spisok, int n) {
	for (int i = 0; i < n; i++) {
		cout << spisok[i] << endl;
	}
}
void sort(char** spisok, int n) {
	for (int k = n - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			if (strcmp(spisok[i], spisok[i + 1]) > 0) {
				char*tmp = spisok[i];
				spisok[i] = spisok[i + 1];
				spisok[i + 1] = tmp;
			}
		}
	}
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << " Введите количество студентов : ";
	cin >> n;
	char** spisok = new char*[n];
	char name[200];
	char secondname[200];
	char lastname[200];
	for (int i = 0; i < n; i++) {
		cout << " Введите данные студента " << i + 1 << ":\n";
		cout << " Фамилия : ";
		cin >> lastname;
		cout << " Имя : ";
		cin >> name;
		cout << " Отчество : ";
		cin >> secondname;
		int k = strlen(lastname) + strlen(name) + strlen(secondname) + 3;
		char *tmp = new char[k];
		
		strcpy_s(tmp,k,lastname);
		strcat_s(tmp,k, " ");
		strcat_s(tmp,k, name);
		strcat_s(tmp,k, " ");
		strcat_s(tmp,k,secondname);
		puts(tmp);
		spisok[i] = tmp;
	}
	print(spisok, n);
	sort(spisok, n);
	cout << " Отсортированный список : \n";
	print(spisok, n);
	system("pause");
}
