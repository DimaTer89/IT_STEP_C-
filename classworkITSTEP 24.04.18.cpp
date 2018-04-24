#include <iostream>
using namespace std;
#include <stdio.h>
void main() {
	setlocale(LC_ALL, "rus");
	FILE *in=NULL, *out=NULL;
	const int N = 128;
	char filename1[N], filename2[N];
	cout << " Введите имя файла для ввода : ";
	cin >> filename1;
	cout << " Введите имя файла для вывода : ";
	cin >> filename2;
	if (fopen_s(&in, filename1, "r") != 0) {
		cout << " Ошибка открытия файла ввода \n";
		system("pause");
		exit(0);
	}
	fopen_s(&out, filename2, "w");
	if (out == NULL) {
		cout << " Ошибка открытия файла ввода \n";
		system("pause");
		exit(0);
	}
	/*int c = getc(in);
	while (c != EOF) {
		putc(c, out);
		c = getc(in);
	}*/
	char buffer[N];
	while (fgets(buffer, sizeof(buffer), in) != 0) {
		fputs(buffer, out);
	}
	if (fclose(in) != 0) {
		cout << " Ошибка закрытия файл ввода \n";
		system("pause");
		exit(0);
	}
	if (fclose(out) != 0) {
		cout << " Ошибка закрытия файл ввода \n";
		system("pause");
		exit(0);
	}
	system("pause");
}
===========================================
#include <iostream>
using namespace std;
#include <stdio.h>
void main() {
	setlocale(LC_ALL, "rus");
	FILE *in=NULL, *out=NULL;
	const int N = 128;
	char filename1[N], filename2[N];
	cout << " Введите имя файла для ввода : ";
	cin >> filename1;
	cout << " Введите имя файла для вывода : ";
	cin >> filename2;
	if (fopen_s(&in, filename1, "r") != 0) {
		cout << " Ошибка открытия файла ввода \n";
		system("pause");
		exit(0);
	}
	fopen_s(&out, filename2, "w");
	if (out == NULL) {
		cout << " Ошибка открытия файла ввода \n";
		system("pause");
		exit(0);
	}
	/*int c = getc(in);
	while (c != EOF) {
		putc(c, out);
		c = getc(in);
	}*/
	char buffer[N];
	/*while (fgets(buffer, sizeof(buffer), in) != 0) {
		fputs(buffer, out);
	}*/
	/*while (fscanf_s(in, " %s ", buffer,sizeof(buffer))!= EOF) {
		fprintf(out, " %s", buffer);
	}*/
	double x;
	int k;
	char ch;
	fscanf_s(in, "%lf", &x, sizeof(double));
	fscanf_s(in, "%d", &k, sizeof(int));
	fscanf_s(in, "%*c%c", &ch, sizeof(char));
	fscanf_s(in, "%s", buffer, sizeof(buffer));
	cout << " x= " << x << " k= " << k << " ch= " << ch << " buffer= " << buffer << endl;
	if (fclose(in) != 0) {
		cout << " Ошибка закрытия файл ввода \n";
		system("pause");
		exit(0);
	}
	if (fclose(out) != 0) {
		cout << " Ошибка закрытия файл ввода \n";
		system("pause");
		exit(0);
	}
	system("pause");
}
================================================
#include <iostream>
#define MAX 50
using namespace std;
struct student {
	char fam[MAX];
	char name[MAX];
	char group[MAX];
	double srBall;
};
void getStudent(FILE *in, student *st) {
	char buffer[MAX * 6];
	fgets(buffer,sizeof(buffer),in);
	char *word, *next;
	word = strtok_s(buffer, " \n", &next);
	strcpy_s(st->fam, word);
	word = strtok_s(NULL, " \n", &next);
	strcpy_s(st->name, word);
	word = strtok_s(NULL, " \n", &next);
	strcpy_s(st->group, word);
	word = strtok_s(NULL, " \n", &next);
	st->srBall = atof(word);
}
void print(student *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i].fam << " " << a[i].name << " ";
		cout<< " " << a[i].group << " " << a[i].srBall<<endl;
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	FILE *in, *out;
	if (fopen_s(&in, "data.txt", "r") != 0) {
		cout << " Не удалось открыть файл для чтения \n";
		system("pause");
		exit(0);
	}
	if (fopen_s(&out, "result.txt", "w") != 0) {
		cout << " Не удалось закрыть файл для чтения \n";
		system("pause");
		exit(0);
	}
	int n;
	fscanf_s(in, "%d\n", &n, sizeof(int));
	cout << n << endl;
	student *spisok = new student[n];
	int kolG11 = 0;
	for (int i = 0; i < n; i++) {
		getStudent(in, spisok + i);
		if (strcmp(spisok[i].group, "G11") == 0)kolG11++;
	}
	print(spisok, n);
	fprintf(out, "%d\n", kolG11);
	for (int i = 0; i < n; i++) {
		if (strcmp(spisok[i].group, "G11") == 0) {
			fprintf(out, "%s ", spisok[i].fam, sizeof(spisok[i].fam));
			fprintf(out, "%s ", spisok[i].name, sizeof(spisok[i].name));
			fprintf(out, "%s ", spisok[i].group, sizeof(spisok[i].group));
			fprintf(out, "%.1f \n", spisok[i].srBall, sizeof(double));
		}
	}
	fclose(in);
	fclose(out);
	system("pause");
}
