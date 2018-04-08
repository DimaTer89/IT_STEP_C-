/*2.Описать структуру Tovar (название товара, страна-производитель, цена). Создать массив товаров из 6 элементов.
Заполнить этот массив данными, запросив их  у пользователя. 
Затем запросить у пользователя название страны и подсчитать среднюю цену на товары из этой страны. Вывести список товаров, упорядоченный по названию товара.*/
#include <iostream>
#include <Windows.h>
using namespace std;
struct Tovar {
	char prod[30];
	char manCount[30];
	int price;
};
void printOne(Tovar a) {
	cout << " Название товара : " << a.prod << endl;
	cout << " Страна-производитель : " << a.manCount << endl;
	cout << " Цена : " << a.price << endl;
}
void vvod(Tovar a[],int n){
	for (int i = 0; i < n; i++) {
		cout << " Введите данные номер : " << i + 1 << endl;
		cout << " Название товара : ";
		cin >> a[i].prod;
		cout << " Страна-производитель : ";
		cin >> a[i].manCount;
		cout << " Цена : ";
		cin >> a[i].price;
		cout << "===============================\n";
	}
}
double medPrice(Tovar a[], int n,char* country) {
	double sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].manCount, country) == 0) {
			sum += a[i].price;
			count++;
		}
	}
	return (double)sum / count;
}
void sort(Tovar a[], int n,char*prizn) {
	int kol = 0;
	for (int i = 0; i < n; i++) {
		if(strcmp(a[i].manCount, prizn) == 0)kol++;
	}
	Tovar **ptr = new Tovar*[kol];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].manCount, prizn) == 0) {
			ptr[j++] = &a[i];
		}
	}
	for (int k = kol - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			if (strcmp(ptr[i]->prod, ptr[i + 1]->prod) > 0) {
				Tovar *tmp = ptr[i];
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < kol; i++) {
		printOne(*ptr[i]);
	}
	delete[]ptr;
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int N = 6;
	char country[30];
	Tovar list[N];
	vvod(list, N);
	do {
		cout << " Введите название страны : ";
		cin >> country;
		if (strcmp(list->manCount, country)>0 || strcmp(list->manCount, country)<0) {
			cout << " Нет такой страны .\n ";
		}
	} while (strcmp(list->manCount, country)>0|| strcmp(list->manCount, country)<0);
	cout << " Средняя сумма товара : " << medPrice(list, N,country) << endl;
	sort(list, N, country);
	cout << endl;
	system("pause");
}
