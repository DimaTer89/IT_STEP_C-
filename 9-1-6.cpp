/*Напишите телефонный справочник. Пользователь вводит фамилию и телефон которые потом объединяются в одну строку
Данные должны занимать минимальное количество памяти. Реализовать меню с возможностью добавления, удаления, просмотра и сортировки записей*/
#include <iostream>
#include <Windows.h>
using namespace std;
void viev(char**mas, int n) {
	for (int i = 0; i < n; i++) {
		cout << mas[i] << endl;
	}
}
void sort(char**mas, int n) {
	for (int k = n - 1; k > 0; k--) {
		for (int i = 0; i < k; i++) {
			if (strcmp(mas[i], mas[i + 1]) > 0) {
				char *tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
			}
		}
	}
}
void plusKon(char **&mas, int &n) {
	char**ptr = new char*[n + 1];
	char secname[200];
	char phone[20];
	cout << " Введите фамилию : ";
	cin >> secname;
	cout << " Введите номер телефона : ";
	cin >> phone;
	int len = strlen(secname) + strlen(phone) + 3;
	char *tmp = new char[len];
	strcpy_s(tmp, len, secname);
	strcat_s(tmp, len, " ");
	strcat_s(tmp, len, phone);
	int j = 0;
	ptr[j++] = tmp;
	for (int i = 0; i < n; i++) {
		ptr[j++] = mas[i];
	}
	delete[]mas;
	mas = ptr;
	n++;
}
void minKon(char** &mas, int &n, int kon) {
	char**ptr = new char*[n - 1];
	int j = 0;
	for (int i = 0; i < kon - 1; i++) {
		ptr[j++] = mas[i];
	}
	for (int i = kon; i < n; i++) {
		ptr[j++] = mas[i];
	}
	delete[] mas;
	mas = ptr;
	n--;
}
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << " Введите количество данных : ";
	cin >> n;
	int menu;
	char **phone = new char*[n];
	char secondname[128];
	char telephone[20];
	for (int i = 0; i < n; i++) {
		cout << " Введите фамилию :";
		cin >> secondname;
		cout << " Введите номер телефона : ";
		cin >> telephone;
		int k = strlen(secondname) + strlen(telephone) + 5;
		char *tmp = new char[k];
		strcpy_s(tmp, k, secondname);
		strcat_s(tmp, k, " ");
		strcat_s(tmp, k, telephone);
		phone[i] = tmp;
	}
	do {
		cout << " Выберите желаемое действие от 1 до 4 , 0 - выход \n";
		cout << " 1 - добавить контакт \n";
		cout << " 2 - удаление контакта \n";
		cout << " 3 - просморт справочника \n";
		cout << " 4 - сортировка записей \n";
		cout << " 0 - выход \n";
		cin >> menu;
		switch (menu) {
		case 0:
			break;
		case 1:
			plusKon(phone, n);
			cout << " Успешно выполнено \n";
			break;
		case 2:
			if (n == 0) {
				cout << " В справочнике нет контактов , выберите пункт №1 , чтобы добавить контакт , потом можете перейти в это меню .";
				break;
			}
			int num;
			do {
				cout << " Выберите номер контакта для удаления :";
				cin >> num;
				if (num < 1||num > n)cout << " В справочнике нет контакта с таким номером , введите снова !\n";
			} while (num < 1||num > n);
			minKon(phone, n, num);
			cout << " Успешно выполнено \n";
			break;
		case 3:
			if (n == 0) {
				cout << " Нет контактов , внесите информацию , для этого выберите пункт №1 \n";
				break;
			}
			viev(phone, n);
			break;
		case 4:
			if (n == 0) {
				cout << " Нет контактов , внесите информацию , для этого выберите пункт №1 \n";
				break;
			}
			sort(phone, n);
			cout << " Успешно выполнено.\n";
			break;
		default:
			cout << " Нет такое команды , введите снова .\n";
			break;
		}
	} while (menu != 0);
	system("pause");
}
