#include <iostream>
#include <time.h>
#define N 10
using namespace std;
template <typename myT>
void randArr(myT arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 11+'a';
	}
}
template <typename PT>
void printArr(PT arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << " " << arr[i];
	}
	cout << endl;
}
template <typename SH>
void shift(int index, SH arr[], int size) {
	SH l = index+1;
	for (int i = l; i < size; i++) {
		SH tmp = arr[i];
		arr[i] = arr[i - 1];
		arr[i - 1] = tmp;
		if (i == size - 1)arr[i] = 0;
	}
}
void shift(int index, char arr[], int size) {
	char l = index + 1;
	for (int i = l; i < size; i++) {
		char tmp = arr[i];
		arr[i] = arr[i - 1];
		arr[i - 1] = tmp;
		if (i == size - 1)arr[i]=NULL;
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arr[N];
	int index;
	randArr(arr, N);
	cout << " Массив \n";
	printArr(arr, N);
	cout << " Введите индекс числа , которое нужно удалить ";
	cin >> index;
	shift(index, arr, N);
	printArr(arr, N);
	system("pause");
}
