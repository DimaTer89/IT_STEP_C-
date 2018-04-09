/*Описать структуру с именем Aeroflot, содержащую следующие поля:
•	название пункта назначения рейса;
•	номер рейса;
•	тип самолета.
Написать программу, выполняющую следующие действия:
1)	Ввод данных в массив, состоящий из пяти элементов типа Atroflot (массив статический).
2)	Вывод списка рейсов, упорядоченных по возрастанию номера рейса.
3)	Поиск по пункту назначения (пункт назначения запрашивается у пользователя). Выводится список рейсов, вылетающих в данный пункт.*/
#include <iostream>
#include <Windows.h>
using namespace std;
struct Aeroflot {
	char destination[128];
	char flightNumber[30];
	char airtype[30];
};
void printOne(Aeroflot a) {
	cout << " Название пункта назначения рейса : " << a.destination << endl;
	cout << " номер рейса : " << a.flightNumber << endl;
	cout << " тип самолета : " << a.airtype << endl;
	cout << "==========================================\n";

}
void vvod(Aeroflot a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Введите данные " << i + 1 << endl;
		cout << " Название пункта назначения рейса : ";
		cin >> a[i].destination;
		cout << " номер рейса : ";
		cin >> a[i].flightNumber;
		cout << " тип самолета : ";
		cin >> a[i].airtype;
	}
}
void print(Aeroflot a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Пункт назначения : " << a[i].destination << endl;
		cout << " Номер рейса : " << a[i].flightNumber << endl;
		cout << " Тип самолета: " << a[i].airtype << endl;
		cout << "==========================================\n";
	}
}
void sort(Aeroflot a[], int n) {
	Aeroflot **ptr = new Aeroflot*[n];
	for (int i = 0; i < n; i++) {
		ptr[i] = &a[i];
	}
	for (int k = n - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			if (strcmp(ptr[i]->flightNumber, ptr[i + 1]->flightNumber)>0) {
				Aeroflot *tmp = ptr[i];
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
void destin(Aeroflot a[], int n, char *des) {
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].destination, des) == 0) {
			printOne(a[i]);
		}
	}
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menu;
	const int N = 5;
	Aeroflot domodedovo[N];
	bool flag = false;
	do {
		cout << " Выберите действие : \n";
		cout << " 1 - Ввод данных в массив, состоящий из пяти элементов типа Atroflot. \n";
		cout << " 2 - Вывод списка рейсов, упорядоченных по возрастанию номера рейса.\n";
		cout << " 3 - Поиск по пункту назначения (пункт назначения запрашивается у пользователя). Выводится список рейсов, вылетающих в данный пункт.\n";
		cout << " 0 - выход.\n";
		do {
			cin >> menu;
			if (menu < 0 || menu>3)cout << " Неверный ввод , введите снова : ";
		} while (menu < 0 || menu>3);
		switch (menu) {
		case 1:
			vvod(domodedovo, N);
			flag = true;
			break;
		case 2:
			if (flag == false) {
				cout << " Нет данных в массиве , выберите пункт №1 \n";
				break;
			}
			sort(domodedovo, N);
			break;
		case 3:
			if (flag == false) {
				cout << " Нет данных в массиве , выберите пункт №1 \n";
				break;
			}
			char des[30];
			do {
				cout << " Введите пункт назначения :";
				cin >> des;
				if (strcmp(domodedovo->destination, des) < 0 || strcmp(domodedovo->destination, des) > 0)cout << " Нет заданного пункта назначения , введите снова \n";
			} while (strcmp(domodedovo->destination, des) < 0 || strcmp(domodedovo->destination, des) > 0);
			destin(domodedovo,N, des);
		}
	} while (menu != 0);
	system("pause");
}
