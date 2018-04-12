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
