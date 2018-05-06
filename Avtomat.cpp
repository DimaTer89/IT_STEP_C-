/*В закусочной стоит музыкальный автомат, который фиксирует статистику проигрываемых песен.
Каждый раз после исполнения песни информация о ней добавляется в простой текстовый файл в виде отдельной строки.
В строке указываются название песни, исполнитель и время звучания, разделенные косыми чертами.
Требуется подсчитать для каждой песни общую продолжительность ее звучания и вывести в результирующий файл список песен,
упорядоченный по этому общему времени (в порядке убывания: первыми выводятся песни, которые в общей сложности звучали больше всего).*/
#include <iostream>
#include <Windows.h>
#define MAX 64
#define N 256
using namespace std;
struct avtomat {
	char songname[MAX];
	char singername[MAX];
	double duration;
};
double time(double a, double b) {
	const int sec = 60;
	int min;
	int min1;
	min = a;
	min1 = b;
	double sec1;
	double sec2;
	int score;
	double d = a - min;
	d *= 100;
	double с = b - min1;
	с *= 100;
	sec1 = min * sec + d;
	sec2 = min1 * sec + с;
	int minute, secund;
	score = sec1 + sec2;
	minute = score / sec;
	secund = score % sec;
	double common = minute + secund / 100.;
	return common;
}
void printOne(avtomat a) {
	cout << " Название песни " << a.songname << endl;
	cout << " Исполнитель " << a.singername << endl;
	cout << " Продолжительность " << a.duration << endl;
}
void getFile(FILE* in, avtomat *a,int n) {
	char buffer[N];
	char *word, *next;
	for (int i = 0; i < n; i++, a++) {
		fgets(buffer, N, in);
		word = strtok_s(buffer, "/", &next);
		strcpy_s(a->songname, word);
		word = strtok_s(NULL, "/", &next);
		strcpy_s(a->singername, word);
		word = strtok_s(NULL, "/", &next);
		a->duration = atof(word);
	}
}
void print(avtomat *a, int n) {
	for (int i = 0; i < n; i++, a++) {
		cout << " Композиция № " << i + 1 << endl;
		cout << " Название песни: " << a->songname << endl;
		cout << " Исполнитель: " << a->singername << endl;
		cout << " Продолжительность: " << a->duration << endl;
	}
}
int repeat(avtomat a[], int n) {
	int rep = 0;
	for (int i = n - 1; i >0; i--) {
		for (int j = 0; j < i; j++) {
			if ((strcmp(a[i].songname, a[j].songname) == 0) && (strcmp(a[i].singername, a[j].singername) == 0))rep++;
			
		}
	}
	return rep;
}
void giveMas(avtomat *&a, int &n, int kol) {
	avtomat *mas = new avtomat[n - kol];
	int k = 0;
	for (int i = n - 1; i>=0; i--) {
		bool flag = false;
		for (int j = 0; j < i; j++) {
			if ((strcmp(a[i].songname, a[j].songname) == 0) && (strcmp(a[i].singername, a[j].singername) == 0)) {
				a[j].duration = time(a[j].duration, a[i].duration);
				flag = true;
			}
		}
		if (flag==false)mas[k++]= a[i];
	}
	delete[]a;
	a = mas;
	n =n - kol;
}
void giveFile(FILE* out, avtomat a[], int n) {
	for (int k = n - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			if (a[i].duration < a[i+1].duration) {
				avtomat tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		fprintf(out, "%s/", a[i].songname, sizeof(a[i].songname));
		fprintf(out, "%s/", a[i].singername, sizeof(a[i].singername));
		fprintf(out, "%.2lf\n", a[i].duration, sizeof(double));
	}
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE* in, *out;
	int kol = 0;
	if (fopen_s(&in, "Player.txt", "r") != NULL) {
		cout << " Не удалось открыть файл для чтения \n";
		system("pause");
		return;
	}
	if (fopen_s(&out, "Avtomat.txt", "w") != NULL) {
		cout << " Не удалось открыть файл для записи \n";
		system("pause");
		return;
	}
	char bufer[N];
	while (fgets(bufer, N, in) != NULL) {
		kol++;
	}
	fseek(in, 0L, SEEK_SET);
	avtomat *music = new avtomat[kol];
	getFile(in, music, kol);
	print(music, kol);
	int num = repeat(music, kol);
	giveMas(music, kol, num);
	giveFile(out, music, kol);
	fclose(in);
	fclose(out);
	system("pause");
}
