#include <iostream>
#include <time.h>
#define N 10
using namespace std;
template <typename myR>
void randArr(myR *a, int size) {
	for (int i = 0; i < size; i++, a++) {
		*a = rand() % 21 - 10;
	}
}
template <typename TT>
void printArr(TT *a, int size) {
	for (int i = 0; i < size; i++, a++) {
		cout << "  " << *a << endl;
	}
	cout << endl;
}
void sort(int *a, int *b) {
	bool flag;
	while (a < b) {
		if (*a > *(a + 1)) {
			int tmp = *a;
			*a = *(a + 1);
			*(a + 1) = tmp;
			flag = true;
			if (*(a + 1) > *(a + 2)) {
				int tMp = *(a + 1);
				*(a + 1) = *(a + 2);
				*(a + 2) = tMp;
			}
		}
		else {
			flag = false;
			a++;
		}
	}
}
		

void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arr[N];
	randArr(arr, N);
	cout << " Массив \n";
	printArr(arr, N);
	int *ptr;
	ptr = arr + N-1;
	sort(arr,ptr);
	cout << " Массив \n";
	printArr(arr, N);
	system("pause");
}
