/*В задачу из модуля 10 про успеваемость студентов добавить возможность сохранения информации в файле и загрузки из файла.
Первым числом в файле хранится текущее количество студентов, а затем информация о каждом студенте: фамилия, группа, массив из пяти оценок.
Для тестирования создать текстовый файл в редакторе «Блокнот».
При запуске программы автоматически загружаются данные из файла в динамический массив.
При выходе из программы предлагается сохранить текущие данные о студентах. При положительном ответе содержимое динамического массива переписывается в файл (с тем же именем).
Меню приложения должно содержать следующие пункты:
* добавить студента;
* удалить студента;
* вывести список отличников(>75% отл оценок);
* вывести список двоечников(>50% оценок 2 и 3);
* вывести список студентов, отсортированный по фамилии;
* вывести список студентов определенной группы, отсортированный по фамилии;
* вывести список студентов, отсортированный по среднему баллу (отличники первые);
* поиск по фамилии студента;
* сохранить данные в файл;
* загрузить данные из файла;
* выход.*/
#include <iostream>
#include <Windows.h>
using namespace std;
struct Student {
	char lastname[30];
	char grupa[12];
	int acadPer[5];
};
void printOne(Student a) {
	cout << " Фамилия : " << a.lastname << endl;
	cout << " Группа : " << a.grupa << endl;
	cout << " Успеваемость : ";
	for (int i = 0; i < 5; i++) {
		cout << " " << a.acadPer[i];
	}
	cout << endl;
}
double medBal(Student a[]) {
	double sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += a->acadPer[i];
	}
	return (double)sum / 5;
}
void sort(Student a[], int n) {
	Student **ptr = new Student*[n];
	for (int i = 0; i < n; i++) {
		ptr[i] = &a[i];
	}
	for (int k = n - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			if (strcmp(ptr[i]->lastname, ptr[i + 1]->lastname) > 0) {
				Student *tmp = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printOne(*ptr[i]);
	}
	delete[]ptr;
}
void print(Student a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Студент № " << i + 1 << endl;
		cout << " Фамилия : " << a[i].lastname << endl;
		cout << " Группа : " << a[i].grupa << endl;
		cout << " Успеваемость : ";
		for (int j = 0; j < 5; j++) {
			cout << " " << a[i].acadPer[j];
		}
		cout << endl;
		cout << "====================================\n";
	}
}
double medper(Student a, int n) {
	int kol = 0;
	for (int j = 0; j < 5; j++) {
		if ((a.acadPer[j]) == 5)kol++;
	}
	double sum = (double)kol / 5 * 100;
	return (double)sum;
}
double medBad(Student a, int n) {
	int kol = 0;
	for (int j = 0; j < 5; j++) {
		if (((a.acadPer[j]) == 2) || ((a.acadPer[j]) == 3))kol++;
	}
	double sum = (double)kol / 5 * 100;
	return (double)sum;
}
void printGood(Student a[], int n) {
	for (int i = 0; i < n; i++) {
		if (medper(a[i], n) > 75) {
			printOne(a[i]);
		}
	}

}
void printMin(Student a[], int n) {
	for (int i = 0; i < n; i++) {
		if (medBad(a[i], n) >50) {
			printOne(a[i]);
		}
	}

}
void sortGrup(Student a[], int n, char *prizn) {
	int kol = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].grupa, prizn) == 0)kol++;
	}
	Student **ptr = new Student*[kol];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].grupa, prizn) == 0)ptr[j++] = &a[i];
	}
	for (int k = kol - 1; k > 0; k--) {
		for (int j = 0; j < k; j++) {
			if (strcmp(ptr[j]->lastname, ptr[j + 1]->lastname) > 0) {
				Student *tmp;
				tmp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < kol; i++) {
		cout << " Студент № " << i + 1 << endl;
		printOne(*ptr[i]);
	}
	delete[]ptr;
}
void sortBal(Student a[], int n) {
	Student **ptr = new Student*[n];
	for (int i = 0; i < n; i++) {
		ptr[i] = &a[i];
	}
	for (int k = n - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			if (medBal(ptr[i])<medBal(ptr[i + 1])) {
				Student *tmp = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << " Студент № " << i + 1 << endl;
		printOne(*ptr[i]);
	}
	delete[]ptr;
}
void findStud(Student a[], int n, char *name) {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].lastname, name) == 0) {
			printOne(a[i]);
			flag = true;
		}
	}
	if (flag == false)cout << " Такого студента нет в списке \n";
}
void plusStud(Student *&a, int &n) {
	Student *ptr = new Student[n + 1];
	int j = 0;
	for (int i = 0; i < n; i++) {
		ptr[j++] = a[i];
	}
	cout << " Введите фамилию : ";
	cin >> ptr[j].lastname;
	cout << " Введите группу : ";
	cin >> ptr[j].grupa;
	cout << " Успеваемость (через пробел) : ";
	for (int k = 0; k < 5; k++) {
		cin >> ptr[j].acadPer[k];
	}
	delete[]a;
	a = ptr;
	n++;
}
void minStud(Student *&a, int &n, int num) {
	Student *ptr = new Student[n - 1];
	int j = 0;
	for (int i = 0; i < num - 1; i++) {
		ptr[j++] = a[i];
	}
	for (int i = num; i < n; i++) {
		ptr[j++] = a[i];
	}
	delete[]a;
	a = ptr;
	n--;
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE* in, *out;
	if (fopen_s(&in, "Блокнот.txt", "r") != NULL) {
		cout << " Не удалось загрузить данные из файла \n";
		system("pause");
		exit(1);
	}
	int n;
	fscanf_s(in, "%d\n", &n);
	Student *gruppa = new Student[n];
	const int N = 256;
	char buffer[N];
	for (int i = 0; i < n; i++) {
		fgets(buffer, sizeof(buffer), in);
		char *word, *next;
		word = strtok_s(buffer, " \n", &next);
		strcpy_s(gruppa[i].lastname, word);
		word = strtok_s(NULL, " \n", &next);
		strcpy_s(gruppa[i].grupa, word);
		for (int j = 0; j < 5; j++) {
			word = strtok_s(NULL, " \n", &next);
			gruppa[i].acadPer[j] = atoi(word);
		}
	}
	fclose(in);
	print(gruppa, n);
	int menu;
	do {
		cout << " Введите действие : \n";
		cout << " 1 - динамически изменять размер массива (добавлять или удалять запись о студенте с определенным номером)" << endl;
		cout << " 2 - выводить список отличников (>75% отл оценок)" << endl;
		cout << " 3 - выводить список двоечников (>50%  оценок 2 и 3)" << endl;
		cout << " 4 - выводить список студентов, отсортированный по фамилии" << endl;
		cout << " 5 - выводить список студентов определенной группы, отсортированный по фамилии" << endl;
		cout << " 6 - выводить список студентов, отсортированный по среднему баллу (отличники первые)" << endl;
		cout << " 7 - выполнять поиск по фамилии студента" << endl;
		cout << " 8 - просмотр списка " << endl;
		cout << " 9 - сохранить данные в файл " << endl;
		cout << " 10 - загрузить данные из файла " << endl;
		cout << " 0 - выход. " << endl;
		cin >> menu;
		switch (menu) {
		case 1:
			int k;
			cout << " Выберите одно из действий : \n";
			cout << " 1 - добавить запись о студенте .\n";
			cout << " 2 - удалить запись о студенте . \n";
			cin >> k;
			switch (k) {
			case 1:
				plusStud(gruppa, n);
				cout << " Успешно выполнено \n";
				break;
			case 2:
				int num;
				cout << " Введите позицию студента : ";
				do {
					cin >> num;
					if (num<1 || num>n)cout << " Нет такой позиции , введите снова : ";
				} while (num<1 || num>n);
				minStud(gruppa, n, num);
				cout << " Успешно выполнено \n";
				break;
			}
			break;
		case 2:
			printGood(gruppa, n);
			break;
		case 3:
			printMin(gruppa, n);
			break;
		case 4:
			sort(gruppa, n);
			break;
		case 5:
			char grup[10];
			cout << " Введите имя группы : ";
			cin >> grup;
			sortGrup(gruppa, n, grup);
			break;
		case 6:
			sortBal(gruppa, n);
			break;
		case 7:
			char name[30];
			cout << " Введите фамилию студента : ";
			cin >> name;
			findStud(gruppa, n, name);
			break;
		case 8:
			print(gruppa, n);
			break;
		case 9:
			char answer;
			cout << " Желаете ли сохранить данные в файл ? (y/n):";
			cin >> answer;
			if (answer == 'y') {
				if (fopen_s(&in, "Блокнот.txt", "w") != NULL) {
					cout << " Не удалось открыть файл для записи \n";
					system("pause");
					exit(1);
				}
				fprintf(in, "%d\n", n);
				for (int i = 0; i < n; i++) {
					fprintf(in, "%s ", gruppa[i].lastname, sizeof(gruppa[i].lastname));
					fprintf(in, "%s  ", gruppa[i].grupa, sizeof(gruppa[i].grupa));
					for (int j = 0; j < 5; j++) {
						fprintf(in, "%d ", gruppa[i].acadPer[j], sizeof(int));
					}
					fputs("\n", in);
				}
			}
			menu = 0;
			break;
		case 10:
			char filename[N];
			cout << " Введите имя файла ввода : ";
			cin>>filename;
			if (fopen_s(&out, filename, "r") != NULL) {
				cout << " Не удалось открыть файл вывода \n";
				system("pause");
				exit(1);
			}
			fscanf_s(out, "%d\n", &n);
			Student * grup1 = new Student[n];
			for (int i = 0; i < n; i++) {
				fgets(buffer, sizeof(buffer), out);
				char *word, *next;
				word = strtok_s(buffer, " \n", &next);
				strcpy_s(grup1[i].lastname, word);
				word = strtok_s(NULL, " \n", &next);
				strcpy_s(grup1[i].grupa, word);
				for (int j = 0; j < 5; j++) {
					word = strtok_s(NULL, " \n", &next);
					grup1[i].acadPer[j] = atoi(word);
				}
			}
			fclose(out);
			gruppa = grup1;
			break;
		}
	} while (menu != 0);
	delete[]gruppa;
	system("pause");
}
