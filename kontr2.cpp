#include <iostream>
#include <time.h>
#define N 15
using namespace std;
template <typename TT>
void randArr(TT *a, int size) {
	for (int i = 0; i < size; i++, a++) {
		*a = rand() % 11+'a';
	}
}
template <typename myT>
void printArr(myT *a, int size) {
	for (int i = 0; i < size; i++, a++) {
		cout << " " << *a;
	}
	cout << endl;
}
template <typename DEL>
int udal(DEL sim, DEL a[], int size) {
	DEL *ptrArr, *ptrTmp;
	ptrArr = a;
	int counter = size;
	while (ptrArr < (a + size)) {
		ptrTmp = ptrArr;
		if (*ptrArr == sim) {
			counter--;
			size--;
			while (ptrTmp < (a + size))
			{
				*ptrTmp = *(ptrTmp + 1);
				ptrTmp++;
			}
			continue;
		}
		ptrArr++;
	}
	return counter;
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	char arr[N];
	char elem;
	randArr(arr, N);
	cout << " Массив \n";
	printArr(arr, N);
	cout << " Введите элемент :";
	cin >> elem;
	int kol = udal(elem, arr, N);
	cout << " Преобразованный массив \n";
	printArr(arr, kol);
	cout << " Осталось " << kol << " элементов .\n";
	system("pause");
}
