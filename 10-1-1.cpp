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
		cout << " Пункт назначения : "<<a[i].destination << endl;
		cout << " Номер рейса : "<<a[i].flightNumber << endl;
		cout << " Тип самолета: "<<a[i].airtype << endl;
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
			if (strcmp(ptr[i]->flightNumber,ptr[i + 1]->flightNumber)>0) {
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
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].destination, des) == 0) {
			flag = true;
			printOne(a[i]);
		}
	}
	if (flag == false)cout << " Заданный пункт назначения отсутвует. \n";
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int N = 5;
	Aeroflot domodedovo[N];
	vvod(domodedovo, N);
	cout << "===============================\n";
	sort(domodedovo, N);
	char des[30];
	cout << " Куда вы хотите прилететь : ";
	cin >> des;
	destin(domodedovo, N,des);
	system("pause");
}
