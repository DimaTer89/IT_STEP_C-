#include <iostream>
using namespace std;
struct apartament {
	int number;
	int rooms;
	double area;
	double value;
	int state;
};
void printOne(apartament a) {
	printf(" Номер %d \n", a.number);
	printf(" Количество комнат %d \n", a.rooms);
	printf(" Площадь %.2f \n", a.area);
	printf(" Стоимость %.2f \n", a.value);
	switch (a.state) {
	case 0:
		printf(" Свободна \n");
		break;
	case 1:
		printf(" Продана \n");
		break;
	case 2:
		printf(" Забронирована \n");
		break;
	}
	cout << " ============================ \n";
}
void print(apartament a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " Квартира № " << i + 1 << endl;
		printOne(a[i]);
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	int quantity = 10;
	apartament *apa = new apartament[quantity] {{ 1, 2, 19.35, 25.326, 0 },{ 2, 3, 25.36, 36.258, 1 },
	                                            { 3, 2, 18.78, 21.369, 2 },{ 45, 1, 13.25, 15.222, 0 },
	                                            { 125, 3, 26.35, 37.456, 1 },{ 85, 4, 30.00, 40.255, 0},
	                                            { 543, 3, 24.25, 35.255, 0 },{ 56, 2, 21.25, 19.258, 2},
	                                            { 99, 1, 12.25, 16.251, 1 },{ 3, 2, 22.36, 25.362, 1 }};
	print(apa, quantity);
	system("pause");
}
