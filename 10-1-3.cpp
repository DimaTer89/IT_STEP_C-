/*Описать структуру Student(фамилия, группа, успеваемость (массив из 5 int)). Создать массив студентов и написать программу, позволяющую:
•	динамически изменять размер массива (добавлять или удалять запись о студенте с определенным номером);
•	выводить список отличников (>75% отл оценок);
•	выводить список двоечников (>50%  оценок 2 и 3);
•	выводить список студентов, отсортированный по фамилии;
•	выводить список студентов определенной группы, отсортированный по фамилии;
•	выводить список студентов, отсортированный по среднему баллу (отличники первые);
•	выполнять поиск по фамилии студента.*/
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
void vvod(Student a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Введите данные студента № " << i + 1 << endl;
		cout << " Фамилия : ";
		cin >> a[i].lastname;
		cout << " Группа : ";
		cin >> a[i].grupa;
		cout << " Успеваемость : \n";
		for (int k = 0; k < 5; k++) {
			cout << " Введите оценку : ";
			cin >> a[i].acadPer[k];
		}
		cout << "====================================\n";
	}
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
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << " Введите количество студентов \n";
	cin >> n;
	Student *gruppa=new Student[n];
	vvod(gruppa, n);
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
		cout << " 0 - выход. " << endl;
		cin >> menu;
		switch (menu) {
		case 2:
			printGood(gruppa, n);
			break;
		case 3:
			printMin(gruppa, n);
			break;
		case 4:
			sort(gruppa, n);
			break;
		}
	} while (menu != 0);
	system("pause");
}
