/*Программа удаляет из тестового файла все слова ”help!” и подсчитывает количество оставшихся слов. 
Имя исходного файла и имя файла-результата запрашиваются у пользователя.
Количество слов выводится на консоль. Все лишние пробелы между словами могут быть удалены.*/
#include <iostream>
#include <stdio.h>
using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	const int N = 256;
	FILE *in = NULL, *out = NULL;
	char filename[N], filename1[N];
	cout << " Введите имя файла ввода ";
	cin >> filename;
	cout << " Введите имя файла вывода ";
	cin >> filename1;
	fopen_s(&in, filename, "r");
	if (in == NULL) {
		cout << " Не удалось открыть файл ввода \n";
		system("pause");
		exit(0);
	}
	fopen_s(&out, filename1, "w");
	if (out == NULL) {
		cout << " Не удалось открыть файл ввывода \n";
		system("pause");
		exit(0);
	}
	char bufer[N];
	fgets(bufer, sizeof(bufer), in);
	cout << bufer;
	int kol = 0;
	char*buf;
    char *ptr=strtok_s(bufer, " \n", &buf);
	while (ptr!=NULL) {
		if (strcmp(ptr, "help")!=0) {
			fprintf(out, "%s ",ptr);
			kol++;
		}
		ptr = strtok_s(NULL, " \n", &buf);
	}
	cout << " В результирующем файле осталось " << kol << " cлов \n";
	if (fclose(in) != 0) {
		cout << " Не удалось закрыть файл ввода \n";
		system("pause");
		exit(1);
	}
	if (fclose(out) != 0) {
		cout << " Не удалось закрыть файл вывода \n";
		system("pause");
		exit(1);
	}
	system("pause");
}

