Структуры
#include <iostream>
using namespace std;
struct avto {
	char nomer[10];
	char marka[20];
	double volume;
	char color[30];
};
void main() {
	setlocale(LC_ALL, "rus");
	avto myavto = { "33-44 GM","toyota",4.5,"red" };
	cout << " Номер : " << myavto.nomer << endl;
	cout << " Марка : " << myavto.marka << endl;
	cout << " Объём двигателя : " << myavto.volume << endl;
	cout << " Цвет : " << myavto.color << endl;
	system("pause");
}
============================================
#include <iostream>
using namespace std;
struct avto {
	char nomer[10];
	char marka[20];
	double volume;
	char color[30];
};
void print(avto a) {
	cout << " Номер : " << a.nomer << endl;
	cout << " Марка : " << a.marka << endl;
	cout << " Объём двигателя : " << a.volume << endl;
	cout << " Цвет : " << a.color << endl;
}
void main() {
	setlocale(LC_ALL, "rus");
	avto myavto = { "33-44 GM","toyota",4.5,"red" };
	print(myavto);
	system("pause");
}
===============================================
массив структур
#include <iostream>
using namespace std;
struct avto {
	char nomer[20];
	char marka[20];
	double volume;
	char color[30];
};
void print(avto a[],int n) {
	for (int i = 0; i < n; i++) {
		cout << " Номер : " << a[i].nomer << endl;
		cout << " Марка : " << a[i].marka << endl;
		cout << " Объём двигателя : " << a[i].volume << endl;
		cout << " Цвет : " << a[i].color << endl;
		cout << "==============================\n";
	}
}
void printOne(avto a) {
	cout << " Номер : " << a.nomer << endl;
	cout << " Марка : " << a.marka << endl;
	cout << " Объём двигателя : " << a.volume << endl;
	cout << " Цвет : " << a.color << endl;
}
void vvod(avto a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Введите данные автомобиля  " << i + 1<<" :\n";
		cout << " Номер : ";
		cin >> a[i].nomer;
		cout << " Марка : ";
		while (cin.get() != '\n');
		cin >> a[i].marka;
		cout << " Объём двигателя : ";
		while (cin.get() != '\n');
		cin >> a[i].volume;
		cout << " Цвет : ";
		while (cin.get() != '\n');
		cin >> a[i].color;
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	const int N = 3;
	avto garag[N];
	char color[30];
	vvod(garag, N);
	print(garag,N);
	cout << " Введите цвет : ";
	cin >> color;
	for (int i = 0; i < N; i++) {
		if (strcmp(garag[i].color, color) == 0) {
			printOne(garag[i]);
		}
	}
	system("pause");
}
========================================
#include <iostream>
using namespace std;
struct avto {
	char nomer[20];
	char marka[20];
	double volume;
	char color[30];
};
void print(avto a[],int n) {
	for (int i = 0; i < n; i++) {
		cout << " Номер : " << a[i].nomer << endl;
		cout << " Марка : " << a[i].marka << endl;
		cout << " Объём двигателя : " << a[i].volume << endl;
		cout << " Цвет : " << a[i].color << endl;
		cout << "==============================\n";
	}
}
void printOne(avto a) {
	cout << " Номер : " << a.nomer << endl;
	cout << " Марка : " << a.marka << endl;
	cout << " Объём двигателя : " << a.volume << endl;
	cout << " Цвет : " << a.color << endl;
}
void vvod(avto a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Введите данные автомобиля  " << i + 1<<" :\n";
		cout << " Номер : ";
		cin >> a[i].nomer;
		cout << " Марка : ";
		while (cin.get() != '\n');
		cin >> a[i].marka;
		cout << " Объём двигателя : ";
		while (cin.get() != '\n');
		cin >> a[i].volume;
		cout << " Цвет : ";
		while (cin.get() != '\n');
		cin >> a[i].color;
	}
}
void printsort(avto a[], int n) {
	avto** ptr = new avto*[n];
	// инициализировать массив указателей 
	for (int i = 0; i < n; i++) {
		ptr[i] = &a[i];
	}
	//сортировка 
	for (int k = n - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			if (ptr[i]->volume < ptr[i + 1]->volume) {
				avto* tmp;
				tmp = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = tmp;
			}
		}
	}
	//печать в отсортированном порядке
	for (int i = 0; i < n; i++) {
		printOne(*ptr[i]);
	}
	delete[]ptr;
}
void main() {
	setlocale(LC_ALL, "rus");
	const int N = 3;
	avto garag[N];
	char color[30];
	vvod(garag, N);
	print(garag,N);
	cout << " Введите цвет : ";
	cin >> color;
	for (int i = 0; i < N; i++) {
		if (strcmp(garag[i].color, color) == 0) {
			printOne(garag[i]);
		}
	}
	printsort(garag, N);
	system("pause");
}
=============================================
