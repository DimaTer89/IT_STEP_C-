/*Разработайте структуру, содержащую битовые поля. Структура должна хранить информацию о конфигурации компьютера.
Например, корпус AT – 0, ATX – 1; видео на борту – 0 , видеокарта – 1 и т.д. Создайте массив записей о компьютерах из 5 элементов. Реализуйте следующий функционал:
· Печать всех записей;
· Поиск и печать записей о компьютерах с корпусом ATX.
По желанию реализуйте хранение данных в виде динамического массива. Добавьте функции добавления записи о компьютере и удаления записи о компьютере.*/
#include <iostream>
using namespace std;
struct PC {
	unsigned char korp : 1;
	unsigned char video : 1;
	unsigned char CPU : 3;
	unsigned char RAM : 3;
};
void printOne(PC a) {
	cout << " Корпус АТ- 0, АТХ -1 : ";
	printf("%d\n", a.korp);
	cout << " Видео на борту - 0 , видеокарта - 1 : ";
	printf("%d\n", a.video);
	cout << " Процессор : 1 ядро - 1, 2 ядра - 2, 3 ядра - 3, 4 ядра - 4 : ";
	printf("%d\n", a.CPU);
	cout << " Оперативная память : 1 планка - 1 , 2 планки - 2, 3 планки - 3 , 4 планки - 4 : ";
	printf("%d\n", a.RAM);
	cout << "===================================\n";
}
void print(PC a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Корпус АТ- 0, АТХ -1 : ";
		printf("%d\n", a[i].korp);
		cout << " Видео на борту - 0 , видеокарта - 1 : ";
		printf("%d\n", a[i].video);
		cout << " Процессор : 1 ядро - 1, 2 ядра - 2, 3 ядра - 3, 4 ядра - 4 : ";
		printf("%d\n", a[i].CPU);
		cout << " Оперативная память : 1 планка - 1 , 2 планки - 2, 3 планки - 3 , 4 планки - 4 : ";
		printf("%d\n", a[i].RAM);
		cout << "===================================\n";
	}
}
void vvod(PC a[],int n) {
	char tmp;
	for (int i = 0; i < n; i++) {
		cout << " Корпус АТ- 0, АТХ -1 : ";
		cin >> tmp;
		a[i].korp = tmp;
		cout << " Видео на борту - 0 , видеокарта - 1 : ";
		cin >> tmp;
		a[i].video = tmp;
		cout << " Процессор : 1 ядро - 1, 2 ядра - 2, 3 ядра - 3, 4 ядра - 4 : ";
		cin >> tmp;
		a[i].CPU = tmp;
		cout << " Оперативная память : 1 планка - 1 , 2 планки - 2, 3 планки - 3 , 4 планки - 4 : ";
		cin >> tmp;
		a[i].RAM = tmp;
	}
}
void findATX(PC a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i].korp == 1) {
			printOne(a[i]);
		}
		cout << " ============================= \n";
	}
}
void dobConf(PC *&a, int &n) {
	PC*ptr = new PC[n+1];
	int j = 0;
	for (int i = 0; i < n; i++) {
		ptr[j++] = a[i];
	}
	char tmp;
	cout << " Корпус АТ- 0, АТХ -1 : ";
	cin >> tmp;
	ptr[j].korp = tmp;
	cout << " Видео на борту - 0 , видеокарта - 1 :";
	cin >> tmp;
	ptr[j].video = tmp;
	cout << " Процессор : 1 ядро - 1, 2 ядра - 2, 3 ядра - 3, 4 ядра - 4 : ";
	cin >> tmp;
	ptr[j].CPU = tmp;
	cout << " Оперативная память : 1 планка - 1 , 2 планки - 2, 3 планки - 3 , 4 планки - 4 : ";
	cin >> tmp;
	ptr[j].RAM = tmp;
	delete[]a;
	a = ptr;
	n++;
}
void udalConf(PC *&a, int &n,int poz) {
	PC *ptr = new PC[n-1];
	int j = 0;
	for (int i = 0; i < poz - 1; i++) {
		ptr[j++] = a[i];
	}
	for (int i = poz; i < n; i++) {
		ptr[j++] = a[i];
	}
	delete[]a;
	a = ptr;
	n--;
}
void main() {
	setlocale(LC_ALL, "rus");
	int n;
	int menu;
	cout << " Введите количество записей : ";
	cin >> n;
	PC *config = new PC[n];
	vvod(config, n);
	do {
		cout << " Выберите операцию \n";
		cout << " 1 - Печать всех записей \n";
		cout << " 2 - Поиск и печать записей о компьютерах с корпусом ATX \n";
		cout << " 3 - добавить запись \n";
		cout << " 4 - удалить запись \n";
		cout << " 0 - выход \n";
		cin >> menu;
		switch (menu) {
		case 1:
			print(config, n);
			break;
		case 2:
			cout << " Конфигурации с корпусом АТХ : \n";
			findATX(config, n);
			break;
		case 3:
			dobConf(config, n);
			break;
		case 4:
			int poz;
			do {
				cout << " Введите позицию : ";
				cin >> poz;
				if (poz<1 || poz>n)cout << " Неверная позиция , введите снова \n";
			} while (poz<1 || poz>n);
			udalConf(config, n, poz);
			break;
		}
	} while (menu != 0);
	delete[]config;
	system("pause");
}
