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
	unsigned char RAM : 2;
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
}
void vvod(PC &a) {
	char tmp;
	cout << " Корпус АТ- 0, АТХ -1 : ";
	cin >> tmp;
	a.korp = tmp;
	cout << " Видео на борту - 0 , видеокарта - 1 :";
	cin >> tmp;
	a.video = tmp;
	cout << " Процессор : 1 ядро - 1, 2 ядра - 2, 3 ядра - 3, 4 ядра - 4 : ";
	cin >> tmp;
	a.CPU = tmp;
	cout << " Оперативная память : 1 планка - 1 , 2 планки - 2, 3 планки - 3 , 4 планки - 4 : ";
	cin >> tmp;
	a.RAM = tmp;
}
void findATX(PC a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i].korp == 1) {
			printOne(a[i]);
		}
		cout << " ============================= \n";
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	int n;
	int menu;
	cout << " Введите количество записей : ";
	cin >> n;
	PC *config = new PC[n];
	for (int i = 0; i < n; i++) {
		vvod(config[i]);
	}
	do {
		cout << " Выберите операцию \n";
		cout << " 1 - Печать всех записей \n";
		cout << " 2 - Поиск и печать записей о компьютерах с корпусом ATX \n";
		cout << " 0 - выход \n";
		cin >> menu;
		switch (menu) {
		case 1:
			for (int i = 0; i < n; i++) {
				printOne(config[i]);
			}
			break;
		case 2:
			cout << " Конфигурации с корпусом АТХ : \n";
			findATX(config, n);
			break;
		}
	} while (menu != 0);
	delete[]config;
	system("pause");
}
=========================================================================
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
	unsigned char CPU : 2;
	unsigned char RAM : 2;
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
void vvod(PC &a) {
	char tmp;
	cout << " Корпус АТ- 0, АТХ -1 : ";
	cin >> tmp;
	a.korp = tmp;
	cout << " Видео на борту - 0 , видеокарта - 1 :";
	cin >> tmp;
	a.video = tmp;
	cout << " Процессор : 1 ядро - 1, 2 ядра - 2, 3 ядра - 3, 4 ядра - 4 : ";
	cin >> tmp;
	a.CPU = tmp;
	cout << " Оперативная память : 1 планка - 1 , 2 планки - 2, 3 планки - 3 , 4 планки - 4 : ";
	cin >> tmp;
	a.RAM = tmp;
}
void findATX(PC a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i].korp == 1) {
			printOne(a[i]);
		}
		cout << " ============================= \n";
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	int n;
	int menu;
	cout << " Введите количество записей : ";
	cin >> n;
	PC *config = new PC[n];
	for (int i = 0; i < n; i++) {
		vvod(config[i]);
		cout << "===================================\n";
	}
	do {
		cout << " Выберите операцию \n";
		cout << " 1 - Печать всех записей \n";
		cout << " 2 - Поиск и печать записей о компьютерах с корпусом ATX \n";
	//	cout << " 3 - добавить запись \n";
		//cout << " 4 - удалить запись \n";
		cout << " 0 - выход \n";
		cin >> menu;
		switch (menu) {
		case 1:
			for (int i = 0; i < n; i++) {
				cout << " Конфигурация № " << i + 1 << endl;
				printOne(config[i]);
			}
			break;
		case 2:
			cout << " Конфигурации с корпусом АТХ : \n";
			findATX(config, n);
			break;
		/*case 3:
			int m = n + 1;
			PC *config2 = new PC[m];
			for (int i = 0; i < n; i++) {
				config2[i] = config[i];
			}
			for (int i = 0; i < 1; i++) {
					vvod(config2[i]);
			}
			delete[]config;
			config = config2;
			n = m;
			break;
		case 4:
			int num;
			int l = n - 1;
			PC *config3 = new PC[l];
			cout << " Введите номер конфигурации : ";
			cin >> num;
			int j = 0;
			for (int i = 0; i <num-1 ; i++) {
				config3[j++] = config[i];
			}
			for (int i = num; i < n; i++) {
				config3[j++] = config[i];
			}
			delete[]config;
			config = config3;
			n = l;
			break;*/
		}
	} while (menu != 0);
	delete[]config;
	system("pause");
}
