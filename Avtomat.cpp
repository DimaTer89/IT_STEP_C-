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
====================================================
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
	int num = repeat(music, kol);
	giveMas(music, kol, num);
	giveFile(out, music, kol);
	fclose(in);
	fclose(out);
	system("pause");
}
==============================================
	#include <iostream>
using namespace std;
#define N 128
struct song {
	char name[N];
	char artist[N];
	double time;
	song* next;
};
song* parsing(char *buffer) {
	song*elem = new song;
	char *word, *next;
	word = strtok_s(buffer, "/", &next);
	strcpy_s(elem->name, word);
	word = strtok_s(NULL, "/", &next);
	strcpy_s(elem->artist, word);
	word = strtok_s(NULL, "/", &next);
	elem->time = atof(word);
	elem->next = NULL;
	return elem;
};
song* findPlace(song* elem, song* head) {
	while (head != NULL) {
		if (strcmp(head->name, elem->name) == 0 && strcmp(head->artist, elem->artist) == 0) {
			return head;
		}
		head = head->next;
	}
	return NULL;
};
void put(song *elem, song *&head) {
	elem->next = head;
	head = elem;
};
void readData(FILE* in, song *&head) {
	char buffer[N];
	while (fgets(buffer, N, in) != NULL) {
		song *elem = parsing(buffer);//разбор строки и создание песни
		song *place = findPlace(elem, head);//находит песню в списке.Возвращает 0, если такой песни нет
		if (place != NULL) {
			place->time += elem->time;
			delete elem;
		}
		else {
			put(elem, head);//поместить новую запись в список
		}
	}
};
void printData(FILE*out,song*head) {
	if (head == NULL) {
		cout << " Список пуст \n";
	}
	while (head != NULL) {
		cout << head->name << " " << head->artist << " " << head->time << endl;
		head = head->next;
	}
};
void creatMas(song *head, song **&mas, int &kol) {
	kol = 0;
	song *tmp = head;
	while (tmp != NULL) {
		kol++;
		tmp = tmp->next;
	}
	if (kol == 0) {
		cout << " Список пуст \n";
		system("pause");
		exit(0);
	}
	mas = new song*[kol];//выделяем память под массив указателей
	int i = 0;
	while (head != NULL) {
		mas[i] = head;
		i++;
		head = head->next;
	}
};
void mysort(song **mas, int kol) {
	for (int k =kol-1; k>0;k--) {
		for (int i = 0; i < k; i++) {
			if (mas[i]->time < mas[i + 1]->time) {
				song *tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
			}
		}
	}
};
void writeData(FILE*out, song*head) {
	song **mas;
	int kol;
	creatMas(head, mas, kol);//создание массива указателей на элементы списка
	mysort(mas, kol);
	for (int i = 0; i < kol; i++) {
		fprintf(out, "%s/%s/%.2f\n", mas[i]->name, mas[i]->artist, mas[i]->time);
	}
	delete[]mas;
};
void clear(song*&head) {
	while (head != NULL) {
		song*tmp = head;
		head = head->next;
		delete tmp;
	}
};//очистка списка памяти
void main() {
	setlocale(LC_ALL, "rus");
	FILE *in, *out;
	char filename[N];
	cout << " Введите имя файла для чтения : ";
	cin >> filename;
	if (fopen_s(&in, filename, "r") != NULL) {
		cout << " Не удалось открыть файл "<<filename<<" для чтения \n";
		system("pause");
		return;
	}
	cout << " Введите имя файла для записи : ";
	cin >> filename;
	if (fopen_s(&out, filename, "w") != NULL) {
		cout << " Не удалось открыть файл " << filename << " для записи \n";
		system("pause");
		return;
	}
	song* head = NULL;
	readData(in, head);// чтения данных из файла в список
	printData(out, head);//сортировка и запись результата в файл
	writeData(out, head);
	clear(head);//очистка списка памяти
	fclose(in);
	fclose(out);
	cout << " Работа успешно завершена \n";
	system("pause");
}
